var jumpSpeed = 1000;
function jump() {
    character.y -= 25;
    setTimeout(function () {
        character.y = characterGround;
        stage.update();
    }, jumpSpeed);
}
function gameloop(){
    jump();
}