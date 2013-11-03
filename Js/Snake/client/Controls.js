/* global $,_ , Backbone, Game */

(function () {
    "use strict";

    var KEY_NAMES = { LEFT : 37, RIGHT : 39, UP : 38, DOWN : 40};
    var KEY_NAMES_INV = _.invert(KEY_NAMES);

    Game.Controls = function () {
        this.initialize();
    };

    Game.Controls.prototype = {

        initialize : function () {
            this.keys = {};
            _.each(KEY_NAMES, function (value, key) {
                this.keys[key] = false;
            }, this);
        },

        start : function () {
            $(document).on('keydown.gameControl', _.bind(this.keydown, this));
            $(document).on('keyup.gameControl', _.bind(this.keyup, this));
        },

        stop : function () {
            $(document).off(".gameControl");
        },


    };


    _.extend(Game.Controls.prototype, Backbone.Events);

}());
