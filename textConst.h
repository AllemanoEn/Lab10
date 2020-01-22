#include <string>

// GAMES KEYS
const char KEY_START = 's';
const char KEY_QUIT = 'q';
const char KEY_INSTRUCTION = 'i';
const char KEY_UP = 'w';
const char KEY_DOWN = 's';
const char KEY_LEFT = 'a';
const char KEY_RIGHT = 'd';
const char KEY_MENU = 'm';
const char KEY_HIGHSCORE = 'h';
const char KEY_SEARCHPLAYER = 'p';

// MENU 
const std::string TXT_HELLO = "Hello, press ";
const std::string TXT_PRESS = "Press ";
const std::string TXT_START = " to Start!";
const std::string TXT_QUIT = " to Quit";
const std::string TXT_INSTRUCTION = " for Instructions";
const std::string TXT_SEARCHPLAYER = " to search a player and see his score";
const std::string TXT_HIGHSORE = " to see all player highscore classification.";

const std::string MENU_WELCOME = "WELCOME TO SNAKE CONSOLE!";
const std::string MENU_START = TXT_HELLO + KEY_START + TXT_START;
const std::string MENU_QUIT = TXT_PRESS + KEY_QUIT + TXT_QUIT;
const std::string MENU_INSTRUCTION = TXT_PRESS + KEY_INSTRUCTION + TXT_INSTRUCTION;
const std::string MENU_SEARCHPLAYER = TXT_PRESS + KEY_SEARCHPLAYER + TXT_SEARCHPLAYER;
const std::string MENU_HIGHSCORE = TXT_PRESS + KEY_HIGHSCORE + TXT_HIGHSORE;
const std::string MENU_SCORE = "Your Previous Score: ";

// INSTRUCTION
const std::string TXT_USE = "Use the ";
const std::string TXT_KEY = " key to ";
const std::string TXT_KEY_QUIT = " any time during the game to EXIT.";
const std::string TXT_KEY_MENU = " key to go MENU.";
const std::string TXT_GO_UP = "go UP.";
const std::string TXT_GO_DOWN = "go DOWN.";
const std::string TXT_GO_LEFT = "turn LEFT.";
const std::string TXT_GO_RIGHT = "turn RIGHT.";

const std::string INSTR_UP = TXT_USE + KEY_UP + TXT_KEY + TXT_GO_UP;
const std::string INSTR_LEFT = TXT_USE + KEY_LEFT + TXT_KEY + TXT_GO_LEFT;
const std::string INSTR_DOWN = TXT_USE + KEY_DOWN + TXT_KEY + TXT_GO_DOWN;
const std::string INSTR_RIGHT = TXT_USE + KEY_RIGHT + TXT_KEY + TXT_GO_RIGHT;
const std::string INSTR_EXIT = TXT_USE + KEY_QUIT + TXT_KEY_QUIT;
const std::string INSTR_MENU = TXT_USE + KEY_MENU + TXT_KEY_MENU;

// GAMES CHAR
const std::string BORDER = "#";
const std::string SNAKE_HEAD = "O";
const std::string FRUIT = "F";
const std::string SNAKE_TAIL = "o";
const std::string ACTUAL_SCORE = "Actual score : ";