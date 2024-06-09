#include "ofApp.h"

//--------------------------------------------------------------

ofSerial device;
void ofApp::setup(){
    device.setup("/dev/ttyUSB0", 115200);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(device.available() > 0){
        std::cout << readInt32(&device) << std::endl;
    }

}


//--------------------------------------------------------------
void ofApp::draw(){

}
//--------------------------------------------------------------
ofSerial* ofApp::setupSerial(int deviceN){
    ofSerial serial;
    serial.setup("/dev/ttyUSB1", 9600);
    ofSerial* _serial = &serial;
    return _serial;
}
//--------------------------------------------------------------
int32_t ofApp::readInt32(ofSerial* _device){
    int bytesRequired = 4;
	unsigned char bytes[4];
	int bytesRemaining = bytesRequired;
	int32_t myByte = 0;
    int32_t ret = -1;
    while ( bytesRemaining > 0 ){
        if(_device->available() > 0){
            
            int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = _device->readBytes( &bytes[bytesArrayOffset],bytesRemaining);
            
            if ( myByte == OF_SERIAL_NO_DATA ){
                std::cout << "unsure" << std::endl;
            }
            else if ( myByte == OF_SERIAL_ERROR ){
                printf("an error occurred");
            }

            else{
                ret = (int32_t)(bytes[3] << 24 | bytes[2] << 16 | bytes[1] << 8 | bytes[0]);
            }

            bytesRemaining -= result;
        }
    }
    return ret;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
