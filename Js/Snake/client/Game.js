(function () {
    "use strict";

    var Game = window.Game = {};

    Game.main = function (options) {
        this.username = options.username;
        this.$el = $(options.el);

        this.board = new Backbone.Model();
        this.players = new Backbone.Collection();
        this.food = new Backbone.Collection();
        this.scores = new Backbone.Collection();

        this.boardCanvasCtx = this.$el.find('.boardCanvas')[0].getContext("2d");
        this.playersCanvasCtx = this.$el.find('.playersCanvas')[0].getContext("2d");
        this.foodCanvasCtx = this.$el.find('.foodCanvas')[0].getContext("2d");

        this.boardCanvasView = new Game.BoardView({ctx : this.boardCanvasCtx, board : this.board});
        this.playersView = new Game.PlayersView({ctx : this.playersCanvasCtx, players : this.players, board : this.board});
        this.foodView = new Game.FoodView({ctx : this.foodCanvasCtx, board : this.board, food : this.food});

        var scoresViewEl = this.$el.find('.scoresContainer tbody');
        this.scoresView = new Game.ScoresView({el : scoresViewEl, collection : this.scores});
    };

}());



