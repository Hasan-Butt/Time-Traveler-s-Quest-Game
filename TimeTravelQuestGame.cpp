
//................(Few instructions).......................
//1.You can shift era any time by Pressing 'T'.
//2.All bridges are broken in present era.
//3.Your job is to find hidden keys, hints and exit the maze.
//..........................................................

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
using namespace std;
using namespace sf;
enum GameState { PLAYING, GAME_OVER, WIN, LOGO};
GameState gameState = LOGO;

const int rows = 22;
const int cols = 19;

char pastGrid[rows][cols] = {
    
//    0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 0
    {'w', 'e', 'p', 'p', 'p', 'd', 'w', 'w', 's', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 1
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'p', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'w'},// 2
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w'},// 3
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 4
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w'},// 5
    {'w', 'l', 'l', 'l', 'l', 'l', 'w', 'w', 'b', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 6
    {'w', 'w', 'w', 'w', 'w', 'l', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 7
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 8
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 9
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'w', 'w'},// 10
    {'w', 'k', 'p', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 11
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'p', 'b', 'w', 'w', 'w', 'w'},// 12
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w'},// 13
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'd', 'p', 'p', 'd', 'w', 'w', 'w', 'w'},// 14
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'w'},// 15
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 16
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'p', 'p', 'b', 'w', 'p', 'k', 'w'},// 17
    {'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'p', 'w', 'w'},// 18
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'w'},// 19
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'j', 'w', 'w', 'w', 'w', 'p', 'w'},// 20
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 21                                                    },
    	
};

char presentGrid[rows][cols] = {
    //0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 0
    {'w', 'e', 'p', 'p', 'p', 'd', 'w', 'w', 's', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 1
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'p', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'w'},// 2
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w'},// 3
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 4
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w'},// 5
    {'w', 'k', 'l', 'l', 'l', 'l', 'w', 'w', 'b', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 6
    {'w', 'w', 'w', 'w', 'w', 'l', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 7
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 8
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 9
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'w', 'w'},// 10
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 11
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'p', 'b', 'w', 'w', 'w', 'w'},// 12
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w'},// 13
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'd', 'p', 'p', 'd', 'w', 'w', 'w', 'w'},// 14
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 'w', 'p', 'p', 'p', 'p', 'k', 'w'},// 15
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 16
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'd', 'p', 'p', 'b', 'w', 'p', 'k', 'w'},// 17
    {'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'p', 'w', 'w'},// 18
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'w'},// 19
    {'w', 'w', 'k', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w'},// 20
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 21                                                    },
    	
};

//Copy of them to reinitialize

const char initialPastGrid[rows][cols] = {
	 // same grid as before...
//    0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 0
    {'w', 'e', 'p', 'p', 'p', 'd', 'w', 'w', 's', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 1
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'p', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'w'},// 2
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w'},// 3
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 4
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w'},// 5
    {'w', 'l', 'l', 'l', 'l', 'l', 'w', 'w', 'b', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 6
    {'w', 'w', 'w', 'w', 'w', 'l', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 7
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 8
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 9
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'w', 'w'},// 10
    {'w', 'k', 'p', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 11
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'p', 'b', 'w', 'w', 'w', 'w'},// 12
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w'},// 13
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'd', 'p', 'p', 'd', 'w', 'w', 'w', 'w'},// 14
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'w'},// 15
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 16
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'p', 'p', 'b', 'w', 'p', 'k', 'w'},// 17
    {'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'p', 'w', 'w'},// 18
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'w'},// 19
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'j', 'w', 'w', 'w', 'w', 'p', 'w'},// 20
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 21                                                    },
    	
};

const char initialPresentGrid[rows][cols] = {
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 0
    {'w', 'e', 'p', 'p', 'p', 'd', 'w', 'w', 's', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 1
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'p', 'p', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'w'},// 2
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w'},// 3
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 4
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w'},// 5
    {'w', 'k', 'l', 'l', 'l', 'l', 'w', 'w', 'b', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 's', 'w'},// 6
    {'w', 'w', 'w', 'w', 'w', 'l', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 7
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 8
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 9
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'w', 'w'},// 10
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 's', 'w'},// 11
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'p', 'b', 'w', 'w', 'w', 'w'},// 12
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w'},// 13
    {'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'd', 'p', 'p', 'd', 'w', 'w', 'w', 'w'},// 14
    {'w', 'w', 'w', 'd', 'p', 'p', 'p', 'p', 'd', 'w', 'w', 'p', 'w', 'p', 'p', 'p', 'p', 'k', 'w'},// 15
    {'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 16
    {'w', 'w', 'w', 'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'd', 'p', 'p', 'b', 'w', 'p', 'k', 'w'},// 17
    {'w', 'w', 'p', 'p', 'p', 'p', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'p', 'w', 'w'},// 18
    {'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'd', 'p', 'p', 'p', 'w'},// 19
    {'w', 'w', 'k', 'w', 'w', 'w', 'w', 'w', 'p', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'p', 'w'},// 20
    {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},// 21                                                    },
    	
};

Vector2i playerPos(17, 21);  // Player's current position
bool hasKey = false;  // Key status
bool isInPast = false;  // Time era (past or present)
bool haslifejacket =false; //life jacket Status
bool riddle1=false;
bool riddle2=false;
bool riddle3=false;
bool s1=false,s2=false,s3=false;
int warning1=0,warning2=0,warning3=0,warning4=0;
sf::Clock gameClock;
const int MAX_SCORES = 5;
float playerTime = 0.f;


// Function declaration
bool askRiddle(RenderWindow &window, Text &displayText, Font &font, string riddle, string correctAnswer);
void resetGame();
void resetMap();
void handleGameOver(RenderWindow& window);
void handleWin(RenderWindow& window);
void handlemainscreen(RenderWindow& window);
void handleCREDIT(RenderWindow& window);
void handleinstruc(RenderWindow& window);
void updateLeaderboard(float playerTime, float scores[], int &count);
void displayLeaderboard(RenderWindow& window, const float scores[], int count, float playerTime);

bool moveUpPressed = false, moveDownPressed = false, moveLeftPressed = false, moveRightPressed = false, tKeyPressed = false;


int main() {
    const int tileSize = 40;
    const int windowWidth = cols * tileSize;
    const int windowHeight = rows * tileSize;
    const int spriteSheetRows = 4;  // 4 rows for different directions
    const int spriteSheetCols = 3;  // 3 columns for different frames
    const int spriteWidth = 256;    // Width of each frame
    const int spriteHeight = 256;   // Height of each frame
    
    
    
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Time Traveler's Quest");
    
    
    // Load textures
    Texture brickTexture, pathTexture, keyTexture, doorTexture, bridgeTexture, waterTexture, lifejacketTexture, playerTexture, shinepathTexture, exitTexture;
    if (!brickTexture.loadFromFile("brick_wall.png") ||
        !pathTexture.loadFromFile("path.png") ||
        !keyTexture.loadFromFile("key.png") ||
        !doorTexture.loadFromFile("door.png") ||
        !playerTexture.loadFromFile("player.png")||
		!bridgeTexture.loadFromFile("bridge.png")||
		!waterTexture.loadFromFile("water.png")||
		!lifejacketTexture.loadFromFile("lifejacket.png")||
		!shinepathTexture.loadFromFile("shinepath.png")||
		!exitTexture.loadFromFile("exit.png")){
        std::cerr << "Failed to load one or more textures." << std::endl;
        return -1;
    }

    Font text;
    if (!text.loadFromFile("text.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        return -1;
    }
   
    Text message;
    message.setFont(text);
    message.setString("Welcome to the Game!");
    message.setCharacterSize(30);
    message.setFillColor(Color::White);
    message.setPosition(10, 10);
    
    
    
     // Load sound buffer
    sf::SoundBuffer gameStartBuffer;
    sf::SoundBuffer doorOpenBuffer;
    sf::SoundBuffer waterBuffer;
    sf::SoundBuffer keyBuffer;
    sf::SoundBuffer jacketBuffer;
    sf::SoundBuffer eraBuffer;
    sf::SoundBuffer warningBuffer;
    
    if (!gameStartBuffer.loadFromFile("gamestartsound.wav")||
	    !doorOpenBuffer.loadFromFile("dooropen.flac")||
		!waterBuffer.loadFromFile("watersound.wav")||
		!keyBuffer.loadFromFile("keysound.wav")||
		!jacketBuffer.loadFromFile("jacketsound.wav")||
		!eraBuffer.loadFromFile("erasound.wav")||
		!warningBuffer.loadFromFile("warningsound.wav")) {  
        std::cerr << "Failed to load one or more sound files." << std::endl;
        return -1;
    }

    // Create sound object and play the sound
    sf::Sound gameStartSound;
    sf::Sound doorOpenSound;
    sf::Sound waterSound;
    sf::Sound keySound;
    sf::Sound jacketSound;
    sf::Sound eraSound;
    sf::Sound warningSound;
    
    gameStartSound.setBuffer(gameStartBuffer);
    doorOpenSound.setBuffer(doorOpenBuffer);
    waterSound.setBuffer(waterBuffer);
    keySound.setBuffer(keyBuffer);
    jacketSound.setBuffer(jacketBuffer);
    eraSound.setBuffer(eraBuffer);
    warningSound.setBuffer(warningBuffer);
    
    gameStartSound.play();  // Plays the sound once


    // Create sprites 
    
    // 1.Import,2.Create, 3.Display 
    Sprite wallSprite(brickTexture);
    Sprite pathSprite(pathTexture);
    Sprite keySprite(keyTexture);
    Sprite doorSprite(doorTexture);
    Sprite playerSprite(playerTexture);
    Sprite bridgeSprite(bridgeTexture);
    Sprite waterSprite(waterTexture);
    Sprite lifejacketSprite(lifejacketTexture);
    Sprite shinepathSprite(shinepathTexture);
    Sprite exitSprite(exitTexture);
   

    // Set the scale of sprites
    wallSprite.setScale(0.5f, 0.5f);
    pathSprite.setScale(1.3f, 1.3f);
    keySprite.setScale(0.07f, 0.09f);
    doorSprite.setScale(1.3f, 1.3f);
    bridgeSprite.setScale(0.2f,0.3f);
    playerSprite.setScale(0.17f, 0.17f);
    waterSprite.setScale(1.3f, 1.3f);
    lifejacketSprite.setScale(0.25f,0.25f);
    shinepathSprite.setScale(0.2f,0.2f);
    exitSprite.setScale(0.15f,0.25f);
   
    
    // Set the texture rect for the player's starting frame (default is Up)
    playerSprite.setTextureRect(IntRect(0, 3 * spriteHeight, spriteWidth, spriteHeight)); // Row 3: Up
    
   
	
    while (window.isOpen()) {
	
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        
        //Game states
        if(gameState == LOGO){
        handlemainscreen(window);
		}
		
        if(gameState == GAME_OVER){
      	handleGameOver(window);
    	}
       else if(gameState == WIN){
       handleWin(window);
		}

       if(gameState == PLAYING){
       // Handle player movement (with keys)
       
       
if (Keyboard::isKeyPressed(Keyboard::Up) && !moveUpPressed && playerPos.y > 0) {
    playerSprite.setTextureRect(IntRect(0, 3 * spriteHeight, spriteWidth, spriteHeight)); // Row 3: Up

    // Get the next tile in the direction of movement
    char nextTile = isInPast ? pastGrid[playerPos.y - 1][playerPos.x] : presentGrid[playerPos.y - 1][playerPos.x];

    // Check if the player can move to the next tile
    if (nextTile != 'w' && (nextTile != 'd' || hasKey)) {  // Don't move into walls; move into door only if player has key
        if (nextTile == 'b' && !isInPast) {
            if(nextTile == presentGrid[17][14]) warning1++;
        	if(nextTile == presentGrid[12][14]) warning2++;
        	if(nextTile == presentGrid[6][8]) warning3++;
        	warningSound.play();
            message.setString("The Bridge is broken!");
            moveUpPressed = true;
            if(warning1==2 || warning2==2 || warning3==2){
            	gameState=GAME_OVER;
			}
            continue;  // Skip further processing this frame
        }

        // Door logic
        if (nextTile == 'd') {
            if (hasKey) {
                pastGrid[playerPos.y - 1][playerPos.x] = 'p';
                presentGrid[playerPos.y - 1][playerPos.x] = 'p';
                hasKey = false;
                doorOpenSound.play();
                message.setString("You unlocked the door!");
            } else {
                message.setString("You need a key to open this door!");
                moveUpPressed = true;
                continue;
            }
        }

        // Water logic
        if (nextTile == 'l' && !haslifejacket) {
        	warningSound.play();
            message.setString("Ahead is Water!");
            warning4++;
            if(warning4 == 2){
            	gameState = GAME_OVER;
            	continue;
			}
            moveUpPressed = true;
            continue;
        }
        

        // Move the player
        playerPos.y -= 1;
        moveUpPressed = true;
        
        //Surprize path logic
        	
        if (((playerPos.x == 16 || playerPos.x == 15) && playerPos.y == 10)||
		((playerPos.x == 16 || playerPos.x == 15 )&& playerPos.y == 5)||
		(playerPos.x == 9 && (playerPos.y == 2 || playerPos.y == 3))){
			warningSound.play();
        	message.setString("Ahead is two paths choose wisely and chose right path. \n You CAN FALL IN PIT!!!");
		}
		
		//game over
		if((playerPos.x==17 && playerPos.y==9)||(playerPos.x==17 && playerPos.y==4)||(playerPos.x==8 && playerPos.y==1)){
			gameState=GAME_OVER;
			continue;
		}
		
		//Surprize path
		if((playerPos.x == 10 && playerPos.y == 1) || 
		(playerPos.x == 17 && playerPos.y == 6) || 
		(playerPos.x == 17 && playerPos.y == 11)){
			if(!s1 && playerPos.x == 10 && playerPos.y == 1){
				s1=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			}
			else if(!s2 && playerPos.x == 17 && playerPos.y == 6){
				s2=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			} 
			else if(!s3 && playerPos.x == 17 && playerPos.y == 11){
			s3=true;
			hasKey=true;
			keySound.play();
			message.setString("You have got the key!");
			}
		}	


        // Check key or life jacket pickup and replace it with wall
        char currentTile = isInPast ? pastGrid[playerPos.y][playerPos.x] : presentGrid[playerPos.y][playerPos.x];
        if (currentTile == 'k' || currentTile == 'j') {
                if (currentTile == 'k') {
                    hasKey = true;
                    keySound.play();
                    message.setString("You picked up the key!");
                } else if (currentTile == 'j') {
                    haslifejacket = true;
                    message.setString("You picked up the life jacket!");
                }
                pastGrid[playerPos.y][playerPos.x] = 'w';
                presentGrid[playerPos.y][playerPos.x] = 'w';
             
        }
        
        //Water sound
        if(currentTile == 'l'){
        	waterSound.play();
		}
       
         // Riddle position check
        if ((playerPos.x == 11 && playerPos.y == 15) ||
            (playerPos.x == 12 && playerPos.y == 6) ||
            (playerPos.x == 8 && playerPos.y == 14)) {

            bool riddleAnswered = false;
            
            if(playerPos.x == 11 && playerPos.y == 15 && !riddle1){
            Text displayText;
            string riddle = "What has keys but can't open locks?";
            string correctAnswer = "piano"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
		    if(playerPos.x == 12 && playerPos.y == 6 && !riddle2){
				Text displayText;
            string riddle = "What comes once in a minute, twice in a moment,\nbut never in a thousand years?";
            string correctAnswer = "m"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
			if(playerPos.x == 8 && playerPos.y == 14 && !riddle3){
				Text displayText;
            string riddle = "I am an odd number. Take away one letter, and I become even. What am I?";
            string correctAnswer = "seven"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
	
            if (riddleAnswered) {
                // Unlock the door after the riddle is answered correctly
                doorOpenSound.play();
                message.setString("The door opens!");
                pastGrid[playerPos.y-1][playerPos.x] = 'p';  // Change the tile to indicate the door is unlocked
                presentGrid[playerPos.y-1][playerPos.x] = 'p';  // Update both grids
                if(playerPos.x == 11 && playerPos.y == 15)riddle1=true;
                if(playerPos.x == 12 && playerPos.y == 6)riddle2=true;
                if(playerPos.x == 8 && playerPos.y == 14)riddle3=true;
             
            } else {
                
                message.setString("The door remains locked if you answered wrong !");
            }
        }
    }
}


// Repeat for Down, Left, Right keys (with similar fixes)


if (Keyboard::isKeyPressed(Keyboard::Down) && !moveDownPressed && playerPos.y < rows - 1) {
    playerSprite.setTextureRect(IntRect(0, 0, spriteWidth, spriteHeight)); // Row 0: Down

    // Get the next tile in the direction of movement
    char nextTile = isInPast ? pastGrid[playerPos.y + 1][playerPos.x] : presentGrid[playerPos.y + 1][playerPos.x];

    // Check if the player can move to the next tile
    if (nextTile != 'w' && (nextTile != 'd' || hasKey)) {  // Don't move into walls; move into door only if player has key
        if (nextTile == 'b' && !isInPast) {
           	if(nextTile == presentGrid[17][14]) warning1++;
        	if(nextTile == presentGrid[12][14]) warning2++;
        	if(nextTile == presentGrid[6][8]) warning3++;
        	warningSound.play();
            message.setString("The Bridge is broken!");
            moveUpPressed = true;
            if(warning1==2 || warning2==2 || warning3==2){
            	gameState=GAME_OVER;
			}
            continue;  
        }

        // Door logic
        if (nextTile == 'd') {
            if (hasKey) {
                pastGrid[playerPos.y + 1][playerPos.x] = 'p';
                presentGrid[playerPos.y + 1][playerPos.x] = 'p';
                hasKey = false;
                doorOpenSound.play();
                message.setString("You unlocked the door!");
            } else {
                message.setString("You need a key to open this door!");
                moveDownPressed = true;
                continue;
            }
        }

        // Water logic
        if (nextTile == 'l' && !haslifejacket) {
        	warningSound.play();
            message.setString("Ahead is Water!");
            moveDownPressed = true;
            continue;
        }

        // Move the player
        playerPos.y += 1;
        moveDownPressed = true;
        
        //Surprize path logic
         if (((playerPos.x == 16 || playerPos.x == 15) && playerPos.y == 10)||
		((playerPos.x == 16 || playerPos.x == 15 )&& playerPos.y == 5)||
		(playerPos.x == 9 && (playerPos.y == 2 || playerPos.y == 3))){
			warningSound.play();
        	message.setString("Ahead is two paths choose wisely and chose right path. \n You CAN FALL IN PIT!!!");
		}
		//game over
		if((playerPos.x==17 && playerPos.y==9)||(playerPos.x==17 && playerPos.y==4)||(playerPos.x==8 && playerPos.y==1)){
			gameState=GAME_OVER;
			continue;
		}
		if((playerPos.x == 10 && playerPos.y == 1) || 
		(playerPos.x == 17 && playerPos.y == 6) || 
		(playerPos.x == 17 && playerPos.y == 11)){
			if(!s1 && playerPos.x == 10 && playerPos.y == 1){
				s1=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			}
			else if(!s2 && playerPos.x == 17 && playerPos.y == 6){
				s2=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			} 
			else if(!s3 && playerPos.x == 17 && playerPos.y == 11){
			s3=true;
			hasKey=true;
			keySound.play();
			message.setString("You have got the key!");
			}
		}	


        // Check key or life jacket pickup
        char currentTile = isInPast ? pastGrid[playerPos.y][playerPos.x] : presentGrid[playerPos.y][playerPos.x];
        if (currentTile == 'k' || currentTile == 'j') {
                if (currentTile == 'k') {
                    hasKey = true;
                    keySound.play();
                    message.setString("You picked up the key!");
                } else if (currentTile == 'j') {
                    haslifejacket = true;
                    message.setString("You picked up the life jacket!");
                }
                pastGrid[playerPos.y][playerPos.x] = 'w';
                presentGrid[playerPos.y][playerPos.x] = 'w';
            
        }
        
        //Water sound
        if(currentTile == 'l'){
        	waterSound.play();
		}
		
        // Riddle position check
        if ((playerPos.x == 11 && playerPos.y == 15) ||
            (playerPos.x == 12 && playerPos.y == 6) ||
            (playerPos.x == 8 && playerPos.y == 14)) {
             
            bool riddleAnswered = false;
            if(playerPos.x == 11 && playerPos.y == 15 && !riddle1){
            Text displayText;
            string riddle = "What has keys but can't open locks?";
            string correctAnswer = "piano"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
		    if(playerPos.x == 12 && playerPos.y == 6 && !riddle2){
				Text displayText;
            string riddle = "What comes once in a minute, twice in a moment,\nbut never in a thousand years?";
            string correctAnswer = "m"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
			if(playerPos.x == 8 && playerPos.y == 14 && !riddle3){
				Text displayText;
            string riddle = "I am an odd number. Take away one letter, and I become even. What am I?";
            string correctAnswer = "seven"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}

            if (riddleAnswered) {
                // Unlock the door after the riddle is answered correctly
                doorOpenSound.play();
                message.setString("The door opens!");
                pastGrid[playerPos.y+1][playerPos.x] = 'p';  // Change the tile to indicate the door is unlocked
                presentGrid[playerPos.y+1][playerPos.x] = 'p';  // Update both grids
                if(playerPos.x == 11 && playerPos.y == 15)riddle1=true;
                if(playerPos.x == 12 && playerPos.y == 6)riddle2=true;
                if(playerPos.x == 8 && playerPos.y == 14)riddle3=true;
            } else {
                
                message.setString("The door remains locked if you answered wrong !");
            }
        }
    }
}




if (Keyboard::isKeyPressed(Keyboard::Left) && !moveLeftPressed && playerPos.x > 0) {
    playerSprite.setTextureRect(IntRect(0, 1 * spriteHeight, spriteWidth, spriteHeight)); // Row 2: Left

    // Get the next tile in the direction of movement
    char nextTile = isInPast ? pastGrid[playerPos.y][playerPos.x - 1] : presentGrid[playerPos.y][playerPos.x - 1];

    // Check if the player can move to the next tile
    if (nextTile != 'w' && (nextTile != 'd' || hasKey)) {  // Don't move into walls, but move into door if player has key
        if (nextTile == 'b' && !isInPast) {
           	if(nextTile == presentGrid[17][14]) warning1++;
        	if(nextTile == presentGrid[12][14]) warning2++;
        	if(nextTile == presentGrid[6][8]) warning3++;
        	warningSound.play();
            message.setString("The Bridge is broken!");
            moveUpPressed = true;
            if(warning1==2 || warning2==2 || warning3==2){
            	gameState=GAME_OVER;
			}
            continue;  // Skip further processing this frame
        }

        // Door logic
        if (nextTile == 'd') {
            if (hasKey) {
                // Replace door with a path ('p') in both eras
                pastGrid[playerPos.y][playerPos.x - 1] = 'p';
                presentGrid[playerPos.y][playerPos.x - 1] = 'p';
                hasKey = false;  // Key is consumed after opening the door
                doorOpenSound.play();
                message.setString("You unlocked the door!");
            } else {
                message.setString("You need a key to open this door!");
                moveLeftPressed = true;
                continue;
            }
        }

        // Water logic
        if (nextTile == 'l' && !haslifejacket) {
        	warningSound.play();
            message.setString("Ahead is Water!");
            moveLeftPressed = true;
            continue;
        }
        
        // Move the player
        playerPos.x -= 1;
        moveLeftPressed = true;
        
        //Winning
        if(playerPos.x==1 && playerPos.y==1){
        	playerTime = gameClock.getElapsedTime().asSeconds();
        	gameState=WIN;
        	continue;
        	
		}
        
        
        
        //Surprize path logic
         if (((playerPos.x == 16 || playerPos.x == 15) && playerPos.y == 10)||
		((playerPos.x == 16 || playerPos.x == 15 )&& playerPos.y == 5)||
		(playerPos.x == 9 && (playerPos.y == 2 || playerPos.y == 3))){
			warningSound.play();
        	message.setString("Ahead is two paths choose wisely and chose right path. \n You CAN FALL IN PIT!!!");
		}
		//game over
		if((playerPos.x==17 && playerPos.y==9)||(playerPos.x==17 && playerPos.y==4)||(playerPos.x==8 && playerPos.y==1)){
			gameState=GAME_OVER;
			continue;
		}
		if((playerPos.x == 10 && playerPos.y == 1) || 
		(playerPos.x == 17 && playerPos.y == 6) || 
		(playerPos.x == 17 && playerPos.y == 11)){
			if(!s1 && playerPos.x == 10 && playerPos.y == 1){
				s1=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			}
			else if(!s2 && playerPos.x == 17 && playerPos.y == 6){
				s2=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			} 
			else if(!s3 && playerPos.x == 17 && playerPos.y == 11){
			s3=true;
			hasKey=true;
			keySound.play();
			message.setString("You have got the key!");
			}
		}	

        // Check key or life jacket pickup after moving
        char currentTile = isInPast ? pastGrid[playerPos.y][playerPos.x] : presentGrid[playerPos.y][playerPos.x];
        if (currentTile == 'k' || currentTile == 'j') {
            
                if (currentTile == 'k') {
                    hasKey = true;
                    keySound.play();
                    message.setString("You picked up the key!");
                } else if (currentTile == 'j') {
                    haslifejacket = true;
                    message.setString("You picked up the life jacket!");
                }
                // Replace the tile with a path ('p') in both eras
                pastGrid[playerPos.y][playerPos.x] = 'w';
                presentGrid[playerPos.y][playerPos.x] = 'w';   
        }
        
        //Water sound
        if(currentTile == 'l'){
        	waterSound.play();
		}
		
        // Riddle position check
        if ((playerPos.x == 11 && playerPos.y == 15) ||
            (playerPos.x == 12 && playerPos.y == 6) ||
            (playerPos.x == 8 && playerPos.y == 14)) {

            bool riddleAnswered = false;
            if(playerPos.x == 11 && playerPos.y == 15 && !riddle1){
            Text displayText;
            string riddle = "What has keys but can't open locks?";
            string correctAnswer = "piano"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
		    if(playerPos.x == 12 && playerPos.y == 6 && !riddle2){
				Text displayText;
            string riddle = "What comes once in a minute, twice in a moment,\nbut never in a thousand years?";
            string correctAnswer = "m"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
			if(playerPos.x == 8 && playerPos.y == 14 && !riddle3){
				Text displayText;
            string riddle = "I am an odd number. Take away one letter, and I become even. What am I?";
            string correctAnswer = "seven"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}

            if (riddleAnswered) {
                // Unlock the door  after the riddle is answered correctly
                doorOpenSound.play();
                message.setString("The door opens!");
                pastGrid[playerPos.y][playerPos.x-1] = 'p';  // Change the tile to indicate the door is unlocked
                presentGrid[playerPos.y][playerPos.x-1] = 'p';  // Update both grids
                if(playerPos.x == 11 && playerPos.y == 15)riddle1=true;
                if(playerPos.x == 12 && playerPos.y == 6)riddle2=true;
                if(playerPos.x == 8 && playerPos.y == 14)riddle3=true;
            } else {
                
                message.setString("The door remains locked if you answered wrong !");
            }
        }
    }
}



if (Keyboard::isKeyPressed(Keyboard::Right) && !moveRightPressed && playerPos.x < cols - 1) {
    playerSprite.setTextureRect(IntRect(0, 2 * spriteHeight, spriteWidth, spriteHeight)); // Row 0: Right

    // Get the next tile in the direction of movement
    char nextTile = isInPast ? pastGrid[playerPos.y][playerPos.x + 1]:presentGrid[playerPos.y][playerPos.x + 1];

    // Check if the player can move to the next tile
    if (nextTile != 'w' && (nextTile != 'd' || hasKey)) {  // Don't move into walls, but move into door if player has key
        if (nextTile == 'b' && !isInPast) {
            if(nextTile == presentGrid[17][14]) warning1++;
        	if(nextTile == presentGrid[12][14]) warning2++;
        	if(nextTile == presentGrid[6][8]) warning3++;
        	warningSound.play();
            message.setString("The Bridge is broken!");
            moveUpPressed = true;
            if(warning1==2 || warning2==2 || warning3==2){
            	gameState=GAME_OVER;
			}
            continue;  
        }

        // Door logic
        if (nextTile == 'd') {
            if (hasKey) {
                // Replace door with a path ('p') in both eras
                pastGrid[playerPos.y][playerPos.x + 1] = 'p';
                presentGrid[playerPos.y][playerPos.x + 1] = 'p';
                hasKey = false;  // Key is consumed after opening the door
                doorOpenSound.play();
                message.setString("You unlocked the door!");
            } else {
                message.setString("You need a key to open this door!");
                moveRightPressed = true;
                continue;
            }
        }

        // Water logic
        if (nextTile == 'l' && !haslifejacket) {
        	warningSound.play();
            message.setString("Ahead is Water!");
            moveRightPressed = true;
            continue;
        }
        
        
        
        // Move the player
        playerPos.x += 1;
        moveRightPressed = true;
        
        //Surprize path logic
         if (((playerPos.x == 16 || playerPos.x == 15) && playerPos.y == 10)||
		((playerPos.x == 16 || playerPos.x == 15 )&& playerPos.y == 5)||
		(playerPos.x == 9 && (playerPos.y == 2 || playerPos.y == 3))){
			warningSound.play();
        	message.setString("Ahead is two paths choose wisely and chose right path. \n You CAN FALL IN PIT!!!");
		}
		
		//game over
		if((playerPos.x==17 && playerPos.y==9)||(playerPos.x==17 && playerPos.y==4)||(playerPos.x==8 && playerPos.y==1)){
			gameState=GAME_OVER;
			continue;
		}
		
		if((playerPos.x == 10 && playerPos.y == 1) || 
		(playerPos.x == 17 && playerPos.y == 6) || 
		(playerPos.x == 17 && playerPos.y == 11)){
			if(!s1 && playerPos.x == 10 && playerPos.y == 1){
				s1=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			}
			else if(!s2 && playerPos.x == 17 && playerPos.y == 6){
				s2=true;
				hasKey=true;
				keySound.play();
			    message.setString("You have got the key!");
			} 
			else if(!s3 && playerPos.x == 17 && playerPos.y == 11){
			s3=true;
			hasKey=true;
			keySound.play();
			message.setString("You have got the key!");
			}
		}	


        // Check key or life jacket pickup after moving
        char currentTile = isInPast ? pastGrid[playerPos.y][playerPos.x] : presentGrid[playerPos.y][playerPos.x];
        if (currentTile == 'k' || currentTile == 'j') {
                if (currentTile == 'k') {
                    hasKey = true;
                    keySound.play();
                    message.setString("You picked up the key!");
                } else if (currentTile == 'j') {
                    haslifejacket = true;
                    jacketSound.play();
                    message.setString("You picked up the life jacket!");
                }
                // Replace the tile with a path ('p') in both eras
                pastGrid[playerPos.y][playerPos.x] = 'w';
                presentGrid[playerPos.y][playerPos.x] = 'w';
        }
        
        //water sound
        if(currentTile == 'l'){
        	waterSound.play();
		}
		
        // Riddle position check
        if((playerPos.x == 11 && playerPos.y == 15) ||
            (playerPos.x == 12 && playerPos.y == 6) ||
            (playerPos.x == 8 && playerPos.y == 14)) {
           	
            bool riddleAnswered = false;	
            if(playerPos.x == 11 && playerPos.y == 15 && !riddle1){
            Text displayText;
            string riddle = "What has keys but can't open locks?";
            string correctAnswer = "piano"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
		    if(playerPos.x == 12 && playerPos.y == 6 && !riddle2){
			Text displayText;
            string riddle = "What comes once in a minute, twice in a moment,\nbut never in a thousand years?";
            string correctAnswer = "m"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}
			if(playerPos.x == 8 && playerPos.y == 14 && !riddle3){
			Text displayText;
            string riddle = "I am an odd number. Take away one letter, and I become even. What am I?";
            string correctAnswer = "seven"; 
            riddleAnswered = askRiddle(window, displayText, text, riddle, correctAnswer);
			}

            if (riddleAnswered) {
                // Unlock the door  after the riddle is answered correctly
                doorOpenSound.play();
                message.setString("The door opens!");
                pastGrid[playerPos.y][playerPos.x+1] = 'p';  // Change the tile to indicate the door is unlocked
                presentGrid[playerPos.y][playerPos.x+1] = 'p';  // Update both grids
                if(playerPos.x == 11 && playerPos.y == 15)riddle1=true;
                if(playerPos.x == 12 && playerPos.y == 6)riddle2=true;
                if(playerPos.x == 8 && playerPos.y == 14)riddle3=true;
            } else {
                
                message.setString("The door remains locked if you answered wrong !");
            }
        }
    }
}


// Reset the movement flags once the key is released
if (!Keyboard::isKeyPressed(Keyboard::Up)) {
    moveUpPressed = false;
}
if (!Keyboard::isKeyPressed(Keyboard::Down)) {
    moveDownPressed = false;
}
if (!Keyboard::isKeyPressed(Keyboard::Left)) {
    moveLeftPressed = false;
}
if (!Keyboard::isKeyPressed(Keyboard::Right)) {
    moveRightPressed = false;
}

        // Handle time shift (T key)
       if (Keyboard::isKeyPressed(Keyboard::T) && !tKeyPressed) {
    isInPast = !isInPast;  // Toggle between past and present
    eraSound.play();
    message.setString(isInPast ?"You have shifted to the past.":"You have shifted to the present.");
    tKeyPressed = true;  // Set the flag to true
}

if (!Keyboard::isKeyPressed(Keyboard::T)) {
    tKeyPressed = false;  // Reset the flag when the key is released
}

        // Clear window and draw
        window.clear();

    // Draw the grid based on the era
    // Apply a dull color effect for the past grid
       
sf::Color dullColor(100, 100, 100);  // Grayish color for dull effect 

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        float x = j * tileSize;
        float y = i * tileSize;

        // Check if the player is in the past
        if (isInPast) {
            // Apply dull effect for the past grid
            if (pastGrid[i][j] == 'w') {
                wallSprite.setColor(dullColor); // Dull effect for walls
                wallSprite.setPosition(x, y);
                window.draw(wallSprite);
            } else if (pastGrid[i][j] == 'p') {
                pathSprite.setColor(dullColor); 
                pathSprite.setPosition(x, y);
                window.draw(pathSprite);
            } else if (pastGrid[i][j] == 'k') {
                keySprite.setColor(dullColor);
                keySprite.setPosition(x, y);
                window.draw(keySprite);
            } else if (pastGrid[i][j] == 'd') {
                doorSprite.setColor(dullColor);
                doorSprite.setPosition(x, y);
                window.draw(doorSprite);
            }else if (pastGrid[i][j] == 'b'){
            	bridgeSprite.setColor(dullColor);
            	bridgeSprite.setPosition(x, y);
            	window.draw(bridgeSprite);
			}else if(pastGrid[i][j] == 'l'){
				waterSprite.setColor(dullColor);
				waterSprite.setPosition(x, y);
				window.draw(waterSprite);
			}else if(pastGrid[i][j] == 'j' ){
				lifejacketSprite.setColor(dullColor);
				lifejacketSprite.setPosition(x, y);
				window.draw(lifejacketSprite);
			}else if(pastGrid[i][j] == 's'){
				shinepathSprite.setColor(dullColor);
				shinepathSprite.setPosition(x, y);
				window.draw(shinepathSprite);
			}else if(pastGrid[i][j] == 'e'){
				exitSprite.setColor(dullColor);
				exitSprite.setPosition(x, y);
				window.draw(exitSprite);
			}
        } else {
            // Draw normal (bright) graphics for the present grid
            if (presentGrid[i][j] == 'w') {
                wallSprite.setColor(sf::Color::White); // Normal color
                wallSprite.setPosition(x, y);
                window.draw(wallSprite);
            } else if (presentGrid[i][j] == 'p') {
                pathSprite.setColor(sf::Color::White); 
                pathSprite.setPosition(x, y);
                window.draw(pathSprite);
            } else if (presentGrid[i][j] == 'k') {
                keySprite.setColor(sf::Color::White);
                keySprite.setPosition(x, y);
                window.draw(keySprite);
            } else if (presentGrid[i][j] == 'd') {
                doorSprite.setColor(sf::Color::White);
                doorSprite.setPosition(x, y);
                window.draw(doorSprite);
            } else if (presentGrid[i][j] == 'b'){
            	bridgeSprite.setColor(sf::Color::White);
            	bridgeSprite.setPosition(x, y);
            	window.draw(bridgeSprite);
			}else if(presentGrid[i][j] == 'l'){
				waterSprite.setColor(sf::Color::White);
				waterSprite.setPosition(x, y);
				window.draw(waterSprite);
			}else if(presentGrid[i][j] == 's'){
				shinepathSprite.setColor(sf::Color::White);
				shinepathSprite.setPosition(x, y);
				window.draw(shinepathSprite);
			}else if(presentGrid[i][j] == 'e'){
				exitSprite.setColor(sf::Color::White);
				exitSprite.setPosition(x, y);
				window.draw(exitSprite); 
			}
        }
    }
}

        // Draw the player sprite
        playerSprite.setPosition(playerPos.x * tileSize, playerPos.y * tileSize);
        window.draw(playerSprite);
        window.draw(message);

        window.display();
    }
}

    return 0;
}
// Function for riddle
 bool askRiddle(RenderWindow &window, Text &displayText, Font &font, string riddle, string correctAnswer) {
    char playerAnswer[100]= "";  
    int answerLength= 0;        
    bool isCorrect= false;      

    displayText.setFont(font);
    displayText.setCharacterSize(24);
    displayText.setFillColor(Color::White);
    displayText.setString("Riddle: " + riddle);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return false;
            }
            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && answerLength > 0) { // Backspace
                    playerAnswer[--answerLength] ='\0';
                } else if (event.text.unicode =='\r') { // Enter key
                    for (int i=0; i<answerLength; i++) {
                        playerAnswer[i] =tolower(playerAnswer[i]);
                    }
                    // Check the answer
                    if (strcmp(playerAnswer,correctAnswer.c_str()) == 0) {
                        displayText.setString("Correct! The door opens.");
                        isCorrect =true;
                        return true; // Correct answer
                    } else {
                        displayText.setString("Incorrect! The door remains locked.");
                        return false; // Incorrect answer
                    }
                } else if (event.text.unicode <128 && answerLength< 99) { // Valid input
                    playerAnswer[answerLength++] =static_cast<char>(event.text.unicode);
                    playerAnswer[answerLength] ='\0';
                }
                // Update the display text with current input
                displayText.setString("Riddle: " +riddle +"\nYour Answer: "+ playerAnswer);
            }
        }

        window.clear();
        window.draw(displayText);
        window.display();
    }

    return false; // Default set to false if window unexpectedly closes
}

//Function for reset
void resetGame() {
    // Reset player position
    playerPos.x = 17;
    playerPos.y = 20;

    // Reset inventory
hasKey = false;  
isInPast = false; 
haslifejacket =false; 
riddle1=false;
riddle2=false;
riddle3=false;
s1=s2=s3=false;
warning1=0;
warning2=0;
warning3=0;
warning4=0;
gameClock.restart();
    // Reset game grids
    resetMap(); // Function to restore grids to initial state
}

//Function for reset grid

void resetMap(){
	
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pastGrid[i][j] = initialPastGrid[i][j];
            presentGrid[i][j] = initialPresentGrid[i][j];
        }
    }
}

//Function for gameover window

void handleGameOver(RenderWindow& window) {
    // Load Game Over screen
    Texture gameOverTexture;
    gameOverTexture.loadFromFile("gameover.png");
    Sprite gameOverSprite(gameOverTexture);
    gameOverSprite.setScale(0.95f,1.1f);
    
     // Load sound buffer
    sf::SoundBuffer gameoverBuffer;
    if (!gameoverBuffer.loadFromFile("gameover.wav")) {  // Replace with your sound file
        std::cerr << "Failed to load sound file." << std::endl;
        return ;
    }

    
    sf::Sound gameoverSound;
    gameoverSound.setBuffer(gameoverBuffer);
    gameoverSound.play();  // Plays the sound once

    // Display Game Over screen
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

        // Check for Enter key press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            resetGame();    
            gameState = PLAYING; // Return to playing state
            return;          // Exit this loop
        }
    }
        window.clear();
        window.draw(gameOverSprite);
        window.display();
    }
}


//Win widow appear function

void handleWin(RenderWindow& window) {
    // Load Win screen
    Texture winTexture;
    winTexture.loadFromFile("win.png");
    Sprite winSprite(winTexture);
    winSprite.setScale(0.95f,1.1f);
    float scores[MAX_SCORES + 1];
    int count = 0;
    // Load sound buffer
    sf::SoundBuffer gameStartBuffer;
    if (!gameStartBuffer.loadFromFile("gamestartsound.wav")) {  // Replace with your sound file
        std::cerr << "Failed to load sound file." << std::endl;
        return ;
    }

    //Sound
    sf::Sound gameStartSound;
    gameStartSound.setBuffer(gameStartBuffer);
    gameStartSound.play();  // Plays the sound once

    // Display Win screen
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        
        // Check for Enter key press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        	updateLeaderboard(playerTime, scores, count);
        	displayLeaderboard(window,scores,count,playerTime);
            return;
        }
    }
        window.clear();
        window.draw(winSprite);
        window.display();
    }
}

// LOGO window

// Main Screen Function
void handlemainscreen(RenderWindow &window) {
    Texture mainscreenTexture;
    mainscreenTexture.loadFromFile("mainscreen.png");
    Sprite mainscreenSprite(mainscreenTexture);
    mainscreenSprite.setScale(0.95f, 1.1f);
    
    bool enterPressed = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type ==Event::KeyPressed &&event.key.code ==sf::Keyboard::Return &&!enterPressed) {
                enterPressed = true;
                handleCREDIT(window);
                return;  // Exit the current function and move to CREDIT window
            }
        }

        window.clear();
        window.draw(mainscreenSprite);
        window.display();
    }
}

// Credit Window Function
void handleCREDIT(RenderWindow &window) {
    Texture creditTexture;
    creditTexture.loadFromFile("credit.png");
    Sprite creditSprite(creditTexture);
    creditSprite.setScale(0.75f, 0.85f);
    bool enterPressed = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type ==Event::KeyPressed&& event.key.code == sf::Keyboard::Return &&!enterPressed) {
                enterPressed = true;
                handleinstruc(window);
                return;  // Exit the current function and move to Instruction window
            }
        }

        window.clear();
        window.draw(creditSprite);
        window.display();
    }
}

// Instruction Window Function
void handleinstruc(RenderWindow &window) {
    Texture instrucTexture;
    instrucTexture.loadFromFile("instruc.png");
    Sprite instrucSprite(instrucTexture);
    instrucSprite.setScale(0.75f, 0.85f);
   
    bool enterPressed = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type ==Event::KeyPressed&&event.key.code ==sf::Keyboard::Return&&!enterPressed) {
                enterPressed =true;
                gameState = PLAYING;
                gameClock.restart();
                return;  // Exit the current function and transition to the main game
            }
        }

        window.clear();
        window.draw(instrucSprite);
        window.display();
    }
}
void updateLeaderboard(float playerTime, float scores[], int &count) {
    const int MAX_SCORES = 5;
    count = 0;

    // Step 1: Read the leaderboard file
    std::ifstream inputFile("leaderboard.txt");
    if (inputFile.is_open()) {
        while (count < MAX_SCORES && inputFile >> scores[count]) {
            count++;
        }
        inputFile.close();
    } else {
        std::cout << "Failed to open the leaderboard file. Creating a new one.\n";
    }

    // Step 2: Add the player's time
    scores[count] = playerTime;
    count++;

    // Step 3: Sort the scores in descending order (lower time is better)
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (scores[i] > scores[j]) {
                // Swap scores[i] and scores[j]
                float temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    // Step 4: Keep only the top 5 scores
    if (count > MAX_SCORES) {
        count = MAX_SCORES;
    }

    // Step 5: Write the updated leaderboard back to the file
    std::ofstream outputFile("leaderboard.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            outputFile << fixed << setprecision(2) << scores[i] << "\n";
        }
        outputFile.close();
    } else {
        std::cout << "Failed to write to the leaderboard file.\n";
    }
}
void displayLeaderboard(RenderWindow& window, const float scores[], int count, float playerTime) {
    Font font;
    if (!font.loadFromFile("text.ttf")) {
        cerr << "Failed to load font." << endl;
        return;
    }

    // Display player's time
    Text playerTimeText;
    playerTimeText.setFont(font);

    // Convert playerTime to string using ostringstream
    ostringstream playerTimeStream;
    playerTimeStream << fixed << setprecision(2) << playerTime;
    string playerTimeStr=playerTimeStream.str();
    playerTimeText.setString("Your Escape Time: " + playerTimeStr + " seconds");

    playerTimeText.setCharacterSize(28);
    playerTimeText.setFillColor(Color::Yellow);
    playerTimeText.setPosition(100, 50);

    // Display leaderboard title
    Text leaderboardTitle;
    leaderboardTitle.setFont(font);
    leaderboardTitle.setString("Top 5 Scores:");
    leaderboardTitle.setCharacterSize(28);
    leaderboardTitle.setFillColor(Color::White);
    leaderboardTitle.setPosition(100, 100);

    
    window.clear();

    
    window.draw(playerTimeText);

    
    window.draw(leaderboardTitle);

    // Display leaderboard scores
    for (int i=0; i<count; ++i) {
        Text text;
        text.setFont(font);

        // Convert index and score to strings using ostringstream
        ostringstream indexStream, scoreStream;
        indexStream <<(i+1);  // Convert index to string
        scoreStream << fixed << setprecision(2) << scores[i];

        string indexStr=indexStream.str();
        string scoreStr=scoreStream.str();

        text.setString(indexStr + ". " + scoreStr + " seconds");
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        text.setPosition(100, 150+i*30);
        window.draw(text);  
    }

    // Display the "Press Enter to play again" message
    Text playAgainText;
    playAgainText.setFont(font);
    playAgainText.setString("\nPress Enter to play again.");
    playAgainText.setCharacterSize(24);
    playAgainText.setFillColor(Color::Green);
    playAgainText.setPosition(100, 150+count*30); // Position it after the last score
    window.draw(playAgainText);  

    
    window.display();

    
    bool waitingForKeyPress=true;
    while (window.isOpen() && waitingForKeyPress) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            // Check for Enter key press event
            if (event.type==Event::KeyPressed && event.key.code==Keyboard::Return) {
                waitingForKeyPress=false; // Stop waiting for Enter key
                resetGame();    
                gameState = PLAYING;
                return;
                
            }
        }
    }
}




