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

    bindModelEvents : function () {
    },

    bindSocketsEvents : function () {
        var self = this;
        this.io.sockets.on('connection', function (socket) {
            socket.on('addPlayer', _.bind(self.onSocketAddPlayer, self, socket));
            socket.on('disconnect', _.bind(self.onSocketDisconnect, self, socket));
            socket.on('keydown', _.bind(self.onSocketKeydown, self, socket));
        });
    },

    onSocketAddPlayer : function (socket, username) {
        console.log('Add player' + username);
        this.players.add({username : username, socket : socket, board : this.board});
        if (this.players.length === 1) {
            this.startIntervals();
        }
    },

    onSocketDisconnect : function (socket) {
    },

    onSocketKeydown : function (socket, key) {
    },

    detectCollisions : function () {

    },

    updateData : function () {

    },

    gameLoop : function () {

    },

    addFood : function () {

    },

    startIntervals : function () {

    },

    stopIntervals : function () {

    }
};

module.exports = GameServer;
