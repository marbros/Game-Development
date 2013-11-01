var _ = require('underscore');
var Board = require('./models/Board');
var PlayerCollection = require('./models/PlayerCollection');
var FoodCollection = require('./models/FoodCollection');

var GameServer = function (options) {
    this.initialize(options);
};

GameServer.prototype = {

    initialize : function (options) {
        this.io = options.io;

        this.board = new Board();
        this.players = new PlayerCollection();
        this.foodCollection = new FoodCollection();

        this.updateDataFields = {players : true};  //information to send on the next update event

        this.bindModelEvents();
        this.bindSocketsEvents();
    },

};

module.exports = GameServer;
