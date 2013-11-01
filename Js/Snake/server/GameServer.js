var _ = require('underscore');
var Board = require('./models/Board');
var PlayerCollection = require('./models/PlayerCollection');
var FoodCollection = require('./models/FoodCollection');

var GameServer = function (options) {
    this.initialize(options);
};

module.exports = GameServer;
