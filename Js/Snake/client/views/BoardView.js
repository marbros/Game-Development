(function () {
    "use strict";

    Game.BoardView = Backbone.View.extend({

        initialize : function (options) {
            this.ctx = options.ctx;
            this.board = options.board;
            this.listenTo(this.board, "change", this.render);
        },

        draw : function () {
            var cellWidth = this.board.get('cellWidth');
            var cellHeight = this.board.get('cellHeight');
            var boardWidth = this.board.get('x') * cellWidth;
            var boardHeight = this.board.get('y') * cellHeight;
        },

    });

}());