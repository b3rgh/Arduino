let serial;
let value;

function setup() {
  createCanvas(windowWidth, windowHeight);
  serial = new p5.SerialPort();
  serial.list();  // prints list of available ports
  serial.open('/dev/tty.usbmodem1411');  // replace with your arduino's serial port
  serial.on('data', getValues);
  frameRate(30);
}

function draw() {
  clear();
  noStroke();
  fill(50);
  console.log(value);
  circle(windowWidth/2, windowHeight/2, value);
}

function getValues() {
  let values = serial.readBytes()
  if(values) {
    for (let i = 0; i < values.length; i++) {
      value = values[i];
    }
  }
}