'''**********************************************************************************
* Maths game program
*
* Author: Joseph Healy
* Last Updated: 17/10/2023
*
*
**********************************************************************************'''

import arcade
import arcade.gui # needed for UI elements!

SCREEN_WIDTH = 1200
SCREEN_HEIGHT = 720
SCREEN_TITLE = "Maths Number Game by Joseph Healy"

class quitView(arcade.View):
    '''
    Quit view class
    '''
    def __init__(self):
        self.uiManager = arcade.gui.UIManager()
        self.uiManager.enable()
        
        self.verticalUIContainer = arcade.gui.UIBoxLayout(space_between=20)

        confirmButton = arcade.gui.UIFlatButton(text="Quit", width=200)
        confirmButton.on_click = self.on_confirmButtonClick
        self.verticalUIContainer.add(confirmButton)

        self.uiManager.add(
            arcade.gui.UIAnchorWidget(
                anchor_x="center_x",
                anchor_y="center_y",
                child=self.verticalUIContainer
            )
        )

class mainMenu(arcade.View):
    '''
    Main menu view class
    '''
    def __init__(self):
        # Required for all of the code that uses UI elements
        self.uiManager = arcade.gui.UIManager()
        self.uiManager.enable()
        
        self.verticalUIContainer = arcade.gui.UIBoxLayout(space_between=20)

       
        playButton = arcade.gui.UIFlatButton(text="Play", width=200)
        playButton.on_click = self.on_playButtonClick
        self.verticalUIContainer.add(playButton)

        optionsButton = arcade.gui.UIFlatButton(text="Options", width=200)
        optionsButton.on_click = self.on_optionsButtonClick
        self.verticalUIContainer.add(optionsButton)

        helpButton = arcade.gui.UIFlatButton(text="Help", width=200)
        helpButton.on_click = self.on_helpButtonClick
        self.verticalUIContainer.add(helpButton)

        quitButton = arcade.gui.UIFlatButton(text="Quit", width=200)
        quitButton.on_click = self.on_quitButtonClick
        self.verticalUIContainer.add(quitButton)

        self.uiManager.add(
            arcade.gui.UIAnchorWidget(
                anchor_x="center_x",
                anchor_y="center_y",
                child=self.verticalUIContainer
            )
        )

    # These functions will be called everytime the user 
    # presses the start button 
    def on_playButtonClick(self, event): 
        print("Play Button is clicked")
    
    def on_optionsButtonClick(self, event): 
        print("Options Button is clicked") 

    def on_helpButtonClick(self, event): 
        print("Help Button is clicked") 

    def on_quitButtonClick(self, event): 
        arcade.exit()

    # This HAS to be named "on_draw()", I want it to be onDraw tho...
    # Function to draw on the screen!
    def on_draw(self):
        arcade.start_render()
        self.uiManager.draw()



class numberGame(arcade.Window):
    '''
    Main Application class.
    '''
    def __init__(self):
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, resizable=True)

        arcade.set_background_color(arcade.color.ALICE_BLUE) 

        start_view = mainMenu()
        self.show_view(start_view)
        start_view.setup()



def main():
    numberGame()
    arcade.run()

if __name__ == "__main__":
    main()
