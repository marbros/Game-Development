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