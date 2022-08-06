class MorseCode {
  private:
    int unitTiming = 400;

    String decodeChar(char alpha) {
      switch (alpha) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-.";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        default:  return "/";
      }
    }

  public:
    void translate(String input, void (*blinkOn)(int), void (*blinkOff)(int)) {
      for (int i = 0; i < input.length(); i++) {
        String decoded = decodeChar(input[i]);
        
        for (int j = 0; j < decoded.length(); j++) {
          char symbol = char(decoded[j]);

          if (symbol == '.') {
            blinkOn(unitTiming);
            blinkOff(unitTiming);
          } else if (symbol == '-') {
            blinkOn(unitTiming * 3);
            blinkOff(unitTiming);
          } else if (symbol == '/') {
            blinkOff(unitTiming * 3);
          }
        }
        blinkOff(unitTiming * 3);
      }
    }
};

void blinkOn(int unitTiming) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(unitTiming);
}

void blinkOff(int unitTiming) {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(unitTiming);
}

MorseCode morseCode = MorseCode();

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  morseCode.translate("cau sergej", &blinkOn, &blinkOff);
}
