//Gravity off
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

//with Gravity
var yVel = 0;
var gravity = 1.2;
var isJumping = false;
 
function jump() {
    if (isJumping == false) {
        yVel = -15;
        isJumping = true;
    }
}
