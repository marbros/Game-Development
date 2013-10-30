$(document).ready(function() {

	var direct;

	window.addEventListener('keyup',
    function(e){
        keys[e.keyCode] = false;
    },false);

    $(document).keydown(function(e) {
        var key = e.which;

        if (key == "37" && direct != "right") {
        	direct = "left";
        } else if (key == "38" && direct != "down") {
        	direct = "up";	
        } else if (key == "39" && direct != "left") {
        	direct = "right";	
        } else if (key == "40" && direct != "up") {
        	direct = "down";
        } 
    })

})