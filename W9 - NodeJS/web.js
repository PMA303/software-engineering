var http = require('http');
var fs = require('fs');

// JSON server

function handle_incoming_request (req, res) {

    console.log("INCOMING REQUEST: " + req.method + " " + req.url);


    load_sensor_data(function(err, readings){

    if (err) { 

       console.log("Couldn't read file");

    }

	
	// An array is used to parse the sensorlog data into the required JSON format

    var array = readings;
    array = array.toString('ascii', 0, array.length);
    array = array.split(",");

    for(i in array) {
		console.log(array[i]);
	}

    var text1 = '{"temperature":'+'"'+array[0]+'",';
    var text2 = '"humidity":'+'"'+array[1]+'",';
    var text3 = '"wind speed":'+'"'+array[2]+'",';
    var text4 = '"time":'+'"'+array[3]+'",';
    var text5 = '"location":'+'"'+array[4]+'"}';

    var sensorText = text1 + text2 + text3 + text4 + text5;

    var obj = JSON.parse(sensorText);
	
	
	// The returned data string is of type application/JSON

    res.writeHead(200, { "Content-Type" : "application/json" });
    res.end(JSON.stringify(obj));

   });
}


// File system read command used to read the contents of the sensorlog

function load_sensor_data(callback) {

   fs.readFile(

   "sensorlog.txt",'utf8',

   function (err, readings) {

   if (err) {

   callback(err);

return;

}

callback(null, readings);

}

);

}

// Create http server to display the console.log on port 8080

var s = http.createServer(handle_incoming_request);

s.listen(8080);
