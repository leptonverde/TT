var   WebChannel = {
  sendProgram: function(json, callback){
    parser.load(json, true);
    callback(true);
  },
  stopProgram: function(){
    parser.stop();
  }

};

(function(){
  parser.message.connect(function(mess){
    var c = document.getElementById("consola");
    c.innerHTML += "<p>" + mess + "</p>";
  });
})();
