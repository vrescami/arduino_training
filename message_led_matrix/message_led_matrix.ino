
const int col[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int row[8] = {A4, A3, A2, A1, 13, 12, 11, 10};


int getSymbolIndex(const char input) {
  switch (input) {
    case 'A':case 'a': return  0; break;
    case 'B':case 'b': return  1; break;
    case 'C':case 'c': return  2; break;
    case 'D':case 'd': return  3; break;
    case 'E':case 'e': return  4; break;
    case 'F':case 'f': return  5; break;
    case 'G':case 'g': return  6; break;
    case 'H':case 'h': return  7; break;
    case 'I':case 'i': return  8; break;
    case 'J':case 'j': return  9; break;
    case 'K':case 'k': return 10; break;
    case 'L':case 'l': return 11; break;
    case 'M':case 'm': return 12; break;
    case 'N':case 'n': return 13; break;
    case 'O':case 'o': return 14; break;
    case 'P':case 'p': return 15; break;
    case 'Q':case 'q': return 16; break;
    case 'R':case 'r': return 17; break;
    case 'S':case 's': return 18; break;
    case 'T':case 't': return 19; break;
    case 'U':case 'u': return 20; break;
    case 'V':case 'v': return 21; break;
    case 'W':case 'w': return 22; break;
    case 'X':case 'x': return 23; break;
    case 'Y':case 'y': return 24; break;
    case 'Z':case 'z': return 25; break;
    case '0': return 26; break;
    case '1': return 27; break;
    case '2': return 28; break;
    case '3': return 29; break;
    case '4': return 30; break;
    case '5': return 31; break;
    case '6': return 32; break;
    case '7': return 33; break;
    case '8': return 34; break;
    case '9': return 35; break;
    case '?': return 36; break;
    case '!': return 37; break;
    case ' ': return 38; break;
    case ',': return 39; break;
    case '.': return 40; break;
    case '`': return 41; break;
    default: return -1; break;
  }
}

const int symbols[][8] = {
  {B00000000,
   B00111100,
   B01100110,
   B01100110,
   B01111110,
   B01100110,
   B01100110,
   B00000000},
  {B00000000,
   B01111100,
   B01100110,
   B01111100,
   B01100110,
   B01100110,
   B01111100,
   B00000000},
  {B00000000,
   B00111100,
   B01100010,
   B01100000,
   B01100000,
   B01100010,
   B00111100,
   B00000000},
  {B00000000,
   B01111100,
   B01100110,
   B01100110,
   B01100110,
   B01100110,
   B01111100,
   B00000000},
  {B00000000,
   B01111110,
   B01100000,
   B01111000,
   B01111000,
   B01100000,
   B01111110,
   B00000000},
  {B00000000,
   B01111110,
   B01100000,
   B01111000,
   B01111000,
   B01100000,
   B01100000,
   B00000000},
  {B00000000,
   B01111110,
   B01100010,
   B01100000,
   B01101110,
   B01100010,
   B01111110,
   B00000000},
  {B00000000,
   B01100110,
   B01100110,
   B01111110,
   B01111110,
   B01100110,
   B01100110,
   B00000000},
  {B00000000,
   B00111100,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00111100,
   B00000000},
  {B00000000,
   B00111100,
   B00011000,
   B00011000,
   B00011000,
   B01011000,
   B01111000,
   B00000000},
  {B00000000,
   B01100110,
   B01101100,
   B01111000,
   B01111000,
   B01101100,
   B01100110,
   B00000000},
  {B00000000,
   B01100000,
   B01100000,
   B01100000,
   B01100000,
   B01111100,
   B01111100,
   B00000000},
  {B00000000,
   B01000010,
   B01100110,
   B01111110,
   B01011010,
   B01000010,
   B01000010,
   B00000000},
  {B00000000,
   B01000010,
   B01100010,
   B01110010,
   B01011010,
   B01001110,
   B01000110,
   B00000000},
  {B00000000,
   B00111100,
   B01100110,
   B01100110,
   B01100110,
   B01100110,
   B00111100,
   B00000000},
  {B00000000,
   B01111100,
   B01100110,
   B01100110,
   B01111100,
   B01100000,
   B01100000,
   B00000000},
  {B00000000,
   B00111100,
   B01100110,
   B01100110,
   B01100110,
   B01101100,
   B00111110,
   B00000000},
  {B00000000,
   B01111100,
   B01100110,
   B01100110,
   B01111100,
   B01101100,
   B01100110,
   B00000000},
  {B00000000,
   B00111110,
   B01100000,
   B01111100,
   B00111110,
   B00000110,
   B01111100,
   B00000000},
  {B00000000,
   B01111110,
   B01111110,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00000000},
  {B00000000,
   B01100110,
   B01100110,
   B01100110,
   B01100110,
   B01100110,
   B01111110,
   B00000000},
  {B00000000,
   B01100110,
   B01100110,
   B01100110,
   B01100110,
   B00111100,
   B00011000,
   B00000000},
  {B00000000,
   B01000010,
   B01000010,
   B01011010,
   B01111110,
   B01100110,
   B01000010,
   B00000000},
  {B00000000,
   B01100110,
   B00111100,
   B00011000,
   B00011000,
   B00111100,
   B01100110,
   B00000000},
  {B00000000,
   B01100110,
   B01100110,
   B00111100,
   B00011000,
   B00011000,
   B00011000,
   B00000000},
  {B00000000,
   B01111110,
   B01000110,
   B00001100,
   B00011000,
   B00110010,
   B01111110,
   B00000000},
  {B00000000,
   B00011100,
   B00110110,
   B00110110,
   B00110110,
   B00110110,
   B00011100,
   B00000000},
  {B0000000,
   B00001100,
   B00011100,
   B00001100,
   B00001100,
   B00001100,
   B00011110,
   B00000000},
  {B00000000,
   B00011100,
   B00100110,
   B00000110,
   B00001100,
   B00011000,
   B00111110,
   B00000000},
  {B00000000,
   B00011100,
   B00100110,
   B00001110,
   B00001100,
   B00100110,
   B00011100,
   B00000000},
  {B00000000,
   B00001100,
   B00010100,
   B00100100,
   B00111110,
   B00000100,
   B00000100,
   B00000000},
  {B00000000,
   B00111110,
   B00110000,
   B00110000,
   B00111110,
   B00000110,
   B00111110,
   B00000000},
  {B00000000,
   B00111110,
   B00110000,
   B00110000,
   B00111110,
   B00100110,
   B00111110,
   B00000000},
  {B00000000,
   B00111110,
   B00100010,
   B00000110,
   B00001100,
   B00011000,
   B00110000,
   B00000000},
  {B00000000,
   B00011100,
   B00110110,
   B00011100,
   B00111110,
   B00110110,
   B00011100,
   B00000000},
  {B00000000,
   B00011100,
   B00110110,
   B00011110,
   B00000110,
   B00100110,
   B00011100,
   B00000000},
  {B00000000,
   B01111100,
   B01001100,
   B00011000,
   B00010000,
   B00000000,
   B00010000,
   B00000000},
  {B00000000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00000000,
   B00011000,
   B00000000},
  {B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000},
  {B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00110000},
  {B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00000000},
  {B00000000,
   B00110110,
   B00110110,
   B00000000,
   B01000000,
   B01100000,
   B00111110,
   B00000000}
};

// TODO: pass this by reference, instead of having it global
int msg_matrix [8][16];
const int REPS_DELAY=200;

void clearScreen() {
  for (int reps=0; reps<REPS_DELAY; reps++){
    for (int i=0; i<8; i++){
      digitalWrite(row[i], LOW);
      digitalWrite(col[i], HIGH);
    }
  }
}

void displaySymbolFromMatrix(int col_offset) {
  for (int reps=0; reps<REPS_DELAY; reps++){
    for (int r = 0; r<8; r++) {
      digitalWrite(row[r], HIGH);
  
      for (int c=0; c<8; c++) {
        if (msg_matrix[r][c+col_offset]) {
          digitalWrite(col[c], LOW);
          digitalWrite(col[c], HIGH);
        }
      }
  
      digitalWrite(row[r], LOW);
    }
  }

}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int i=0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

void pushNextSymbol(int symbol_index) {
  for (int r=0; r<8; r++) {
    for (int c=0; c<8; c++) {
      msg_matrix[r][c] = msg_matrix[r][c+8];
      msg_matrix[r][c+8] = (symbols[symbol_index][r] & (B10000000 >> c)) ? 1 : 0;
    }
  }
}

// the loop function runs over and over again forever
void loop() {  
  String input = "hello, world! `";
  
  pushNextSymbol(getSymbolIndex(input[0]));

  int current_symbol=1;
  while (current_symbol < input.length()) {
    pushNextSymbol(getSymbolIndex(input[current_symbol++]));
    for (int i=0; i<8; i++) {
      displaySymbolFromMatrix(i);
    }
  }

  pushNextSymbol(getSymbolIndex(' '));
  for (int i=0; i<8; i++) {
      displaySymbolFromMatrix(i);
  }

  pushNextSymbol(getSymbolIndex(input[0]));
  for (int i=0; i<8; i++) {
      displaySymbolFromMatrix(i);
  }
}
