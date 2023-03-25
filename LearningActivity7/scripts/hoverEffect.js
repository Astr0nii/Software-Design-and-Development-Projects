var cards = document.querySelectorAll(".card");


cards.forEach((card) => {
    card.addEventListener("mousemove", (event) =>
    {
        var rect = card.getBoundingClientRect();
        var x = event.clientX - rect.left - rect.width / 2;
        var y = event.clientY - rect.top - rect.width / 2;

        var rotateX = y / -(rect.height / 2);
        var rotateY = x / (rect.width / 2);

        card.style.transform =
        "perspective(4rem) rotateX(" + rotateX + "deg) rotateY(" + rotateY + "deg) scale(1.2)";
    });

    card.addEventListener("mouseleave", () =>
    {
        card.style.transform = "";
    });
});
    