(function () {
    "use strict";

    Game.PlayersView = Backbone.View.extend({

        initialize : function (options) {
            this.ctx = options.ctx;
            this.players = options.players;
            this.board = options.board;
            this.listenTo(this.players, 'reset', this.render);
        },

        color : function (player) {
            return player.get('username') === Game.username ? "#00FEFF" : "#FF0065";
        },

    });

}());