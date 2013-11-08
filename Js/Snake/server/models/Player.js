var Backbone = require('backbone');
var _ = require('underscore');

var Player = Backbone.Model.extend({

    defaults : {
        score : 0,
        maxScore : 0
    },

    initialize : function (attributes) {
        var parts = [
            {x : 0, y : 0}
        ];
        var direction = { x : 1, y : 0};

        this.set({
            id : attributes.socket.id,
            parts : parts,
            direction : direction
        });
    },

    movePosition : function () {
        var board = this.get('board');

        var newPart = _.clone(this.attributes.parts[0]);

        this.calculateNewDirection();
        newPart.x = newPart.x + this.attributes.direction.x;
        newPart.y = newPart.y + this.attributes.direction.y;

        // control game limits
        if (newPart.x < 0) {
            newPart.x = board.get('x');
        } else if (newPart.x >= board.get('x')) {
            newPart.x = 0;
        }

        if (newPart.y < 0) {
            newPart.y = board.get('y');
        } else if (newPart.y >= board.get('y')) {
            newPart.y = 0;
        }

        this.lastRemovedPart = this.attributes.parts.pop();
        this.attributes.parts.unshift(newPart);
    },

    calculateNewDirection : function () {

    },

    die : function () {

    },

    eat : function () {

    },

    toJSON : function () {
        return {
            id : this.id,
            parts : this.attributes.parts,
            direction : this.attributes.direction,
            username : this.attributes.username
        };
    }

});

module.exports = Player;