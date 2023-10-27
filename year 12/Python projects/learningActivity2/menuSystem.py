'''**********************************************************************************
* Modular menu system program
*
* Author: Joseph Healy
* Last Updated: 28/10/2023
*
*
**********************************************************************************'''

'''
This program requires a development build of the arcade library for python
see: https://api.arcade.academy/en/development/get_started/install/source.html
for installation instructions.

Take this Mr Legge:
https://api.arcade.academy/en/development/programming_guide/pygame_comparison.html

This development build is much, much faster than pygame now! 

BTW, the link in their installation guide is a lie! That version breaks this code.

Install it directly from the github source version:
https://github.com/pythonarcade/arcade/releases/tag/3.0.0-dev.26

Ironically, because we are using a dev build, the default textures that come with
arcade aren't all available, therefore we need to make some of our own temporary
textures.

Useful resources for teaching me how to do this:
Menu stuff - https://api.arcade.academy/en/development/tutorials/menu/index.html
'''

# TODO: Make the menu save states!

import arcade
import arcade.gui # needed for UI elements!
import pathlib # Needed for accessing our game assets!

# Getting our current folder path
currPath = str(pathlib.Path(__file__).parent)

SCREEN_WIDTH = 1200
SCREEN_HEIGHT = 720
SCREEN_TITLE = "Your game title here"
'''
0 is potato
1 is very low
2 is low
3 is medium
4 is high
5 is very high
'''
TEXTURE_QUALITY = 4 # This currently cannot be set via in-app settings



class mainGame(arcade.View):
    '''
    Main game class
    '''
    def __init__(self):
        super().__init__()

        # Required for all of the code that uses UI elements
        self.uiManager = arcade.gui.UIManager()
        self.uiManager.enable()

        switch_menu_button = arcade.gui.UIFlatButton(text="Pause", width=150)
        @switch_menu_button.event("on_click")
        def on_click_switch_button(event):
            main_game = menuView(self)
            self.window.show_view(main_game)

        self.anchor = self.uiManager.add(arcade.gui.UIAnchorLayout())

        self.anchor.add(
            anchor_x="center_x",
            anchor_y="center_y",
            child=switch_menu_button,
        )

    # called when our view is hidden, we should disable our uiManager
    def on_hide_view(self):
        self.uiManager.disable()

    # Set the background colour and enable our uiManager for drawing 
    def on_show_view(self):
        arcade.set_background_color(arcade.color.DARK_BLUE_GRAY)

        self.uiManager.enable()

    # Called whenever we're rendering on the screen
    def on_draw(self):
        # Clear the screen
        self.clear()

        # Draw the uiManager (our handler for UI elements)
        self.uiManager.draw()


class menuView(arcade.View):
    '''
    Main menu view class
    '''
    def __init__(self, main_view):
        super().__init__()

        # Required for all of the code that uses UI elements
        self.uiManager = arcade.gui.UIManager()
        self.uiManager.enable()
        
        # Adding our buttons to the scene
        resume_button = arcade.gui.UIFlatButton(text="Resume", width=150)
        new_game_button = arcade.gui.UIFlatButton(text="New Game", width=150)
        help_button = arcade.gui.UIFlatButton(text="Help", width=150)
        options_button = arcade.gui.UIFlatButton(text="Options", width=150)
        arcade_pygame_button = arcade.gui.UIFlatButton(text="Arcade > Pygame", width=150)
        highscores_button = arcade.gui.UIFlatButton(text="High Scores", width=150)
        exit_button = arcade.gui.UIFlatButton(text="Exit", width=310)

        # Initialising a grid, this allows us to arrange "widgets" in specific formations
        self.grid = arcade.gui.UIGridLayout(column_count=2, row_count=4, horizontal_spacing=10, vertical_spacing=20)

        # Adding our buttons to the grid layout
        self.grid.add(resume_button, col_num=0, row_num=0)
        self.grid.add(new_game_button, col_num=1, row_num=0)
        self.grid.add(help_button, col_num=0, row_num=1)
        self.grid.add(options_button, col_num=1, row_num=1)
        self.grid.add(arcade_pygame_button, col_num=0, row_num=2)
        self.grid.add(highscores_button, col_num=1, row_num=2)
        # col_span, HTML reference!
        self.grid.add(exit_button, col_num=0, row_num=3, col_span=2)

        # create an anchor that we use position our menu elements, in this case the exact center
        self.anchor = self.uiManager.add(arcade.gui.UIAnchorLayout())

        # add our menu elements to the anchor
        self.anchor.add(
            anchor_x="center_x",
            anchor_y="center_y",
            child=self.grid,
        )

        self.main_view = main_view

        # Create an event listener for the button, fire a function, profit?
        @resume_button.event("on_click")
        def on_click_resume_button(event):
            self.window.show_view(self.main_view)

        @new_game_button.event("on_click")
        def on_click_new_game_button(event):
            main_view = mainGame()
            self.window.show_view(main_view)

        @exit_button.event("on_click")
        def on_click_exit_button(event):
            arcade.exit()

        @options_button.event("on_click")
        def on_click_options_button(event):
            '''
            Example use of the pop-up menu system.
            You first need to initialise the menu seen in the first line.
            After that you will have access to a plethora of options to add your
            own menu elements to this pop-up menu. 
            '''
            options_menu = subMenu(400, 300)
            options_menu.createText("Options Menu", 30, 20)
            options_menu.createToggle("Enable Sound Effects", 5)
            options_menu.createDropdown(["Potato", "Very Low", "Low", "Medium", "High", "Very High"], "Texture Quality", 5)
            options_menu.addBackButton()

            # Add everything to our uiManager
            self.uiManager.add(
                options_menu,
                # Render this above everything else!
                layer=1
            )

        @highscores_button.event("on_click")
        def on_click_highscores_button(event):
            highscores_menu = subMenu(400, 300)
            self.uiManager.add(
                highscores_menu,
                # Render this above everything else!
                layer=1
            )

    # Run when we swap to this view
    def on_show_view(self):
        arcade.set_background_color(arcade.color.DARK_BLUE_GRAY)

    # This HAS to be named "on_draw()", I want it to be onDraw tho...
    # Function to draw on the screen!
    def on_draw(self):
        # Drawing this view
        self.clear()
        arcade.start_render()
        self.uiManager.draw()



class subMenu(arcade.gui.UIMouseFilterMixin, arcade.gui.UIAnchorLayout):
    '''
    Class for creating pop-up windows!
    '''

    # layout our menu elements in a central position!
    widget_layout = arcade.gui.UIBoxLayout(align="center")

    def __init__(self, WINDOW_HEIGHT: int, WINDOW_WIDTH: int):
        super().__init__(size_hint=(1,1))

        # Unlike the tutorial we want scalable windows!
        self.WINDOW_HEIGHT = WINDOW_HEIGHT
        self.WINDOW_WIDTH = WINDOW_WIDTH

        # Setup an arcade frame which will be our pop-up menu
        frame = self.add(arcade.gui.UIAnchorLayout(width=WINDOW_WIDTH, height=WINDOW_HEIGHT, size_hint=None))
        frame.with_padding(all=20)

        # Add a background to the frame
        frame.with_background(texture=arcade.gui.NinePatchTexture(
            left=7,
            right=7,
            bottom=7,
            top=7,
            texture=arcade.load_texture(
                currPath + "/resources/dark_blue_gray_panel.png"
            )
        ))

        self.widget_layout = arcade.gui.UIBoxLayout(align="center")

        
        frame.add(child=self.widget_layout, anchor_x="center_x", anchor_y="top")

    
    def addBackButton(self):
        # Make sure our back button scales with window size :)
        back_button = arcade.gui.UIFlatButton(text="Go Back", width=self.WINDOW_WIDTH/2)
        back_button_space = arcade.gui.UISpace(height=20, color=arcade.color.DARK_BLUE_GRAY) # Customizable white-space
        
        # Honestly I have no idea why, but we need to handle on_click detection this way to not throw goofiness in the console
        back_button.on_click = self.on_click_back_button

        self.widget_layout.add(back_button_space)
        self.widget_layout.add(back_button)

    def createText(self, title: str, spacing: int, font_size: int):
        title_label = arcade.gui.UILabel(text=title, align="center", font_size=font_size, multiline=False)
        title_label_space = arcade.gui.UISpace(height=spacing, color=arcade.color.DARK_BLUE_GRAY) # Customizable white-space

        self.widget_layout.add(title_label)
        self.widget_layout.add(title_label_space)
        
    def createInputBox(self, default_text: str, spacing: int):
        input_text_widget = arcade.gui.UIInputText(text=default_text, width=self.WINDOW_WIDTH/2).with_border()
        input_text_widget_space = arcade.gui.UISpace(height=spacing, color=arcade.color.DARK_BLUE_GRAY) # Customizable white-space

        self.widget_layout.add(input_text_widget)
        self.widget_layout.add(input_text_widget_space)

    def createToggle(self, toggle_text: str, spacing: int):
        # Load different textures based on texture quality setting!
        if TEXTURE_QUALITY < 3:
            on_texture = arcade.load_texture(currPath + "/resources/circle_switch_on.png")
        elif TEXTURE_QUALITY < 5:
            on_texture = arcade.load_texture(currPath + "/resources/circle_switch_on_hq.png")
        else:
            on_texture = arcade.load_texture(currPath + "/resources/circle_switch_on_vhq.png")

        off_texture = arcade.load_texture(currPath + "/resources/circle_switch_off.png")

        toggle_label = arcade.gui.UILabel(text=toggle_text)
        toggle = arcade.gui.UITextureToggle(
            on_texture=on_texture,
            off_texture=off_texture,
            width=20,
            height=20,
        )

        toggle_group = arcade.gui.UIBoxLayout(vertical=False, space_between=5)
        toggle_group.add(toggle)
        toggle_group.add(toggle_label)

        toggle_group_space = arcade.gui.UISpace(height=spacing, color=arcade.color.DARK_BLUE_GRAY)

        self.widget_layout.add(toggle_group)
        self.widget_layout.add(toggle_group_space)

    def createDropdown(self, dropdown_options: list[str], dropdown_text: str, spacing: int):
        self.createText(dropdown_text, 5, 15) # Create a title for our dropdown box, arcade doesn't support this by default????
        dropdown = arcade.gui.UIDropdown(default=dropdown_options[0], options=dropdown_options, height=20, width=self.WINDOW_WIDTH/2)
        self.widget_layout.add(dropdown)
    
    def createSlider(self, slider_text: str, spacing: int):
        slider_label = arcade.gui.UILabel(text=slider_text)
        pressed_style = arcade.gui.UISlider.UIStyle(filled_bar=arcade.color.GREEN, unfilled_bar=arcade.color.RED)
        default_style = arcade.gui.UISlider.UIStyle()
        style_dict = {"press": pressed_style, "normal": default_style, "hover": default_style, "disabled": default_style}
        slider = arcade.gui.UISlider(value=50, width=self.WINDOW_WIDTH/2, style=style_dict)
        self.widget_layout.add(slider_label)
        self.widget_layout.add(slider)


    # Removes the button from our widget layout
    # The manager will respond to events normally (like it previously did).
    def on_click_back_button(self, event):
        if self.parent is not None:
            self.parent.remove(self)



def main():
    window = arcade.Window(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, resizable=True)
    main_view = mainGame()
    window.show_view(main_view)

    arcade.run()

if __name__ == "__main__":
    main()
