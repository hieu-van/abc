const unsigned long bits = 14;
// Order of pins, most significant bit comes first
const byte pins[bits] = {1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 0};

String decToBin(const unsigned long x) {
	String ret;
	unsigned long dvnd = x;
	unsigned long quo;

	do {
		ret = String(dvnd % 2) + ret;
		quo = dvnd / 2;
		dvnd = quo;
	} while (quo > 0);

	while (ret.length() < bits)
		ret = '0' + ret;
	
	return ret;
}

void dispBin(const String bin) {
	for (unsigned long i = 0; i < bin.length(); i++)
		switch (bin[i]) {
			case '0':
				digitalWrite(pins[i], LOW);
				break;
			case '1':
				digitalWrite(pins[i], HIGH);
				break;
		}
}

void setup() {
	for (unsigned long i = 0; i < bits; i++) {
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], LOW);
	}
}

void loop() {
	for (unsigned long i = 0; i < long(pow(2, bits)); i++) {
		dispBin(decToBin(i));
		delay(1000);
	}
}
