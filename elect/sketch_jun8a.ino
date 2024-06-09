// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

int32_t counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;

void setup() {
        
	// Set encoder pins as inputs
	pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
	pinMode(SW, INPUT_PULLUP);

	// Setup Serial Monitor
	Serial.begin(115200);

	// Read the initial state of CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {
        
	// Read the current state of CLK
	currentStateCLK = digitalRead(CLK);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (currentStateCLK != lastStateCLK){

		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (digitalRead(DT) != currentStateCLK) {
			counter ++;
		} else {
			counter --;
		}
		Serial.write((uint8_t*)&counter, sizeof(counter));
	}
	// Remember last CLK state
	lastStateCLK = currentStateCLK;
	// Put in a slight delay to help debounce the reading
	delay(1);
}