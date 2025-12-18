#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "ESP32server";
const char* password = "coque636297610";

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "state";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>PASAPALABRA A MESTRA SILVIA</title>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
        html {font-family: Arial;display: inline-block;text-align: center;background: linear-gradient(#0051FF,#00D8FF);color: #FFFFFF;}
        *{margin:0 0 0 0px;}
        h2 {font-size: 2.5rem;margin-top: 1.0rem;}
        p {font-size: 1.5rem;margin-top: 0.0rem;margin-bottom: 0.5rem;}
        h4 {font-size: 2.0rem;margin: 0.5rem 0.0rem 0.1rem 0.0rem;}
        main {max-width: 640px;margin: 0 auto;padding-bottom: 25px;}
        header {background-color: #143ab8; color: white;height: 1rem;overflow:hidden;position: relative;margin-top: 1rem;margin-left: 5rem;margin-right: 5rem;margin-bottom: 1rem;padding-bottom: 0rem;border-style: solid;border-radius: 5px;}
        header p {margin-top: 2rem;margin-right: 2rem;padding-bottom: 1rem;}
        header img {float: left;margin-top: 1rem;}
        .block {display: inline-block;align-items: center;border-radius: 50px;background-color: rgb(5, 1, 253);margin: 1rem 1rem 1rem 1rem;border-color: #FFFFFF;border-style: solid;}
        .switch {position: relative;display: inline-block;width: 120px;height: 68px;margin: 1rem 1rem 1rem 1rem;}
        .switch input {display: none;}
        .slider {position: absolute;top: 0;left: 0;right: 0;bottom: 0;background-color: #5549f7;border-radius: 6px;}
        .slider:before {position: absolute;content: "";height: 52px;width: 52px;left: 8px;bottom: 8px;background-color: #ffffff;-webkit-transition: .4s;transition: .4s;border-radius: 3px;}
        input:checked + .slider {background-color: #00b351;}
        input:checked + .slider:before {-webkit-transform: translateX(52px);-ms-transform: translateX(52px);transform: translateX(52px);}
  </style>
</head>

<body>
  <header>
    <img src="./data/silvilogo.png" alt="Logo de Silvia">
    <p>Actividade da mestra Silvia</p>
  </header>
  <main>
    <img src="./data/silvilogo.png" alt="Logo de Silvia">
    <p>Actividade da mestra Silvia</p>
    %BUTTONPLACEHOLDER%
  </main>
<script>function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  if(element.checked){ xhr.open("GET", "/update?output="+element.id+"&state=1", true); }
  else { xhr.open("GET", "/update?output="+element.id+"&state=0", true); }
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<div class=\"block\"><h4>A</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"0\" " + outputState(0) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>B</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"1\" " + outputState(1) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>C</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"2\" " + outputState(2) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>D</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"3\" " + outputState(3) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>E</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"4\" " + outputState(4) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>F</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"5\" " + outputState(5) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>G</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"12\" " + outputState(12) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>H</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"13\" " + outputState(13) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>I</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"14\" " + outputState(14) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>L</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"15\" " + outputState(15) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>M</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"16\" " + outputState(16) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>N</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"17\" " + outputState(17) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>Ñ</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"18\" " + outputState(18) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>O</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"19\" " + outputState(19) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>P</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"21\" " + outputState(21) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>Q</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"22\" " + outputState(22) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>R</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"23\" " + outputState(23) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>S</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"25\" " + outputState(25) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>T</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"26\" " + outputState(26) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>U</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"27\" " + outputState(27) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>V</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"32\" " + outputState(32) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>X</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"33\" " + outputState(33) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>Y</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"34\" " + outputState(34) + "><span class=\"slider\"></span></label></div>";
    buttons += "<div class=\"block\"><h4>Z</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"35\" " + outputState(35) + "><span class=\"slider\"></span></label></div>";
    return buttons;
  }
  return String();
}

String outputState(int output){
  if(digitalRead(output)){
    return "checked";
  }
  else {
    return "";
  }
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(0, OUTPUT);
digitalWrite(0, LOW);

pinMode(1, OUTPUT);
digitalWrite(1, LOW);

pinMode(2, OUTPUT);
digitalWrite(2, LOW);

pinMode(3, OUTPUT);
digitalWrite(3, LOW);

pinMode(4, OUTPUT);
digitalWrite(4, LOW);

pinMode(5, OUTPUT);
digitalWrite(5, LOW);

pinMode(12, OUTPUT);
digitalWrite(12, LOW);

pinMode(13, OUTPUT);
digitalWrite(13, LOW);

pinMode(14, OUTPUT);
digitalWrite(14, LOW);

pinMode(15, OUTPUT);
digitalWrite(15, LOW);

pinMode(16, OUTPUT);
digitalWrite(16, LOW);

pinMode(17, OUTPUT);
digitalWrite(17, LOW);

pinMode(18, OUTPUT);
digitalWrite(18, LOW);

pinMode(19, OUTPUT);
digitalWrite(19, LOW);

pinMode(21, OUTPUT);
digitalWrite(21, LOW);

pinMode(22, OUTPUT);
digitalWrite(22, LOW);

pinMode(23, OUTPUT);
digitalWrite(23, LOW);

pinMode(25, OUTPUT);
digitalWrite(25, LOW);

pinMode(26, OUTPUT);
digitalWrite(26, LOW);

pinMode(27, OUTPUT);
digitalWrite(27, LOW);

pinMode(32, OUTPUT);
digitalWrite(32, LOW);

pinMode(33, OUTPUT);
digitalWrite(33, LOW);

pinMode(34, OUTPUT);
digitalWrite(34, LOW);

pinMode(35, OUTPUT);
digitalWrite(35, LOW);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage1;
    String inputMessage2;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      digitalWrite(inputMessage1.toInt(), inputMessage2.toInt());
    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }
    Serial.print("GPIO: ");
    Serial.print(inputMessage1);
    Serial.print(" - Set to: ");
    Serial.println(inputMessage2);
    request->send(200, "text/plain", "OK");
  });

  // Start server
  server.begin();
}

void loop() {

}