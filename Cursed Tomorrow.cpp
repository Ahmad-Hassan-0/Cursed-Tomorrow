#include "raylib.h"
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int screenWidth = 1422;
const int screenHeight = 800;
int speed = 5.0f;
float StickManHeight = 102;
float StickManWidth = 60;
int x = 0;  //change it to get mainscreen
Vector2 StickPosition = { (float)screenWidth / 1.2, (float)screenHeight / 2 };
bool startPosition = false;
float counter = 1000;
bool telly = true;
float gravity = 6;
bool space = false;
float jumpHeight = 13;
float jumpDelay = 28;
bool boolPngs = true;
float logPositionY = 250;
float buttonPositionY = 380;
bool showWelcome = true;
bool alive = true;
bool logMove = false;
bool logMoveOnlyOnce = true;
float spaceLayers = 0.0;
int delayMeter = 0;
bool spaceGate = false;
bool warningScreen = true;
bool level1Start = true;
bool level5Start = true;
bool quote = true;
float ping = 30;
float pingMeter = 0;
float tempPositionx = 0;
float tempPositiony = 0;
float variable = 2.2;
int commonIterator = 0;
int commonIterator_Endgame = 0;
bool popNow = true;
//int jumpScareCounter1 = 0;
//int jumpScareCounter2 = 0;
//int jumpScareCounter3 = 0;
double result = 0;

enum Delays { DEALY_SCREEN = 180 , DEALY_SCREEN_COMECLOSER = 30};

class Audio;
class PNGS;
class Character;
class Stages;
class Levels;
deque <Texture2D> Textures;
deque<Texture2D> ::iterator itr = Textures.begin();


class GetCharacterValues {
private:
    int MovementCounter = 0;
public:

    vector<char> moveCharacter(string string) {

        deque <char> stack;
        deque<char> ::iterator itr = stack.begin();
        vector <char> str(string.begin(), string.end());
        vector <char> result(string.size());
        vector <char> ::iterator rslt_itr = result.begin();

        for (vector <char> ::iterator str_itr = str.begin(); str_itr !=
            str.end(); str_itr++) {
    
            if (*str_itr == 'Y') {
                stack.push_front(*str_itr);
            }
            else if (*str_itr == 'X') {
                while (stack.front() != '-99') {
                    stack.pop_front();
                }
                stack.pop_front();
            }
        }
        while (!stack.empty()) {
            *rslt_itr = stack.front();
            rslt_itr--;
            stack.pop_front();
        }
        return result;
    }
    double evaluatePosition_Gate(vector<char> position_of_x_axis) {
        deque<double> stack;
        double var1_x = 0;
        double var2 = 0;

        int i = 0;
        for (vector<char> ::iterator post_itr = position_of_x_axis.begin(); post_itr
            != (position_of_x_axis.end() - MovementCounter); post_itr++) {
            if (*post_itr >= '1' && *post_itr <= '800') {
                stack.push_front((*post_itr));
            }
            else {
               
                var1_x = stack.front();
       
                switch (*post_itr) {
                case '54':
                    stack.push_front(pow(var2, var1_x));
                    break;
                case '1':
                    stack.push_front(var2 - var1_x);
                    break;
                }
            }
            //cout << "\n\n front : " << stack.front() << " ";
        }
        return stack.front();
    }
};

//class Audio {
//public:
//    Music levelMusic = LoadMusicStream("audio/levelMusic.mp3");
//
//    void playLevelMusic() {
//        if (x >= 4) {
//            PlayMusicStream(levelMusic);
//        }
//    }
//};

/*

DSA concpets to Implement 

Stack
Queue
Dequeue
Trees


*/

class PNGS {
public:
    Texture2D mainScreenPng = LoadTexture("mainScreen/mainScreen.png");
    Texture2D newGamePng = LoadTexture("mainScreen/newGame.png");
    Texture2D levelsPng = LoadTexture("mainScreen/levels.png");
    Texture2D creditsPng = LoadTexture("mainScreen/credits.png");
    Texture2D StickManPng = LoadTexture("mainScreen/StickManPng.png");
    //level template
    Texture2D templateBackground = LoadTexture("levelTemplate/templateBackground.png");
    Texture2D topBarPNG = LoadTexture("levelTemplate/topBar.png");
    Texture2D barUpPNG = LoadTexture("levelTemplate/barUp.png");
    Texture2D trayPNG = LoadTexture("levelTemplate/tray.png");
    Texture2D logPNG = LoadTexture("levelTemplate/log.png");
    Texture2D topBoxPNG = LoadTexture("levelTemplate/topBox.png");
    Texture2D bBoxPNG = LoadTexture("levelTemplate/bBox.png");
    Texture2D trayL1PNG = LoadTexture("levelTemplate/trayL1.png");
    Texture2D trayR1PNG = LoadTexture("levelTemplate/trayR1.png");
    Texture2D trayL2PNG = LoadTexture("levelTemplate/trayL2.png");
    Texture2D trayR2PNG = LoadTexture("levelTemplate/trayR2.png");
    Texture2D barDownPNG = LoadTexture("levelTemplate/barDown.png");
    Texture2D boxRBPNG = LoadTexture("levelTemplate/boxRB.png");
    Texture2D bottomPNG = LoadTexture("levelTemplate/bottom.png");
    Texture2D midTray1PNG = LoadTexture("levelTemplate/midTray1.png");
    Texture2D midTray2PNG = LoadTexture("levelTemplate/midTray2.png");
    Texture2D buttonPNG = LoadTexture("levelTemplate/button.png");
    Texture2D threeTeethDownPNG = LoadTexture("levelTemplate/threeTeethDown.png");
    Texture2D threeTeethRightPNG = LoadTexture("levelTemplate/threeTeethRight.png");
    Texture2D teethDownPNG = LoadTexture("levelTemplate/teethDown.png");
    Texture2D sixTeethRightPNG = LoadTexture("levelTemplate/sixTeethRight.png");
    Texture2D teethUpPNG = LoadTexture("levelTemplate/teethUp.png");
    Texture2D fiveTeethLeftPNG = LoadTexture("levelTemplate/fiveTeethLeft.png");
    Texture2D backButtonPNG = LoadTexture("levelTemplate/backButton.png");
    Texture2D youDiedPNG = LoadTexture("levelTemplate/youDied.png");
    Texture2D longGrassPNG = LoadTexture("levelTemplate/longGrass.png");

    //Credit screen
    Texture2D creditBackgroundPNG = LoadTexture("creditScreen/creditBackground.png");
    Texture2D backButtonBlackPNG = LoadTexture("creditScreen/backButtonBlack.png");

    //Level Select

    Texture2D box1PNG = LoadTexture("levelSelector/box1.png");
    Texture2D box2PNG = LoadTexture("levelSelector/box2.png");
    Texture2D box3PNG = LoadTexture("levelSelector/box3.png");
    Texture2D box4PNG = LoadTexture("levelSelector/box4.png");
    Texture2D box5PNG = LoadTexture("levelSelector/box5.png");
    Texture2D box6PNG = LoadTexture("levelSelector/box6.png");
    Texture2D selectorBackgroundPNG = LoadTexture("levelSelector/selectorBackground.png");

    //Level Afters
    Texture2D afterLevel1PNG = LoadTexture("levelSelector/afterLevel1.png");
    Texture2D afterLevel2PNG = LoadTexture("levelSelector/afterLevel2.png");
    Texture2D afterLevel3PNG = LoadTexture("levelSelector/afterLevel3.png");
    Texture2D afterLevel4PNG = LoadTexture("levelSelector/afterLevel4.png");
    Texture2D afterLevel5PNG = LoadTexture("levelSelector/afterLevel5.png");
    Texture2D afterLevel6PNG = LoadTexture("levelSelector/afterLevel6.png");

    Texture2D PNG1 = LoadTexture("levelSelector/1.png");
    Texture2D PNG2 = LoadTexture("levelSelector/2.png");
    Texture2D PNG3 = LoadTexture("levelSelector/3.png");

    Texture2D behindYouPNG = LoadTexture("levelSelector/behindYou.png");
    Texture2D escapePNG = LoadTexture("levelSelector/escape.png");

    Texture2D quotePNG = LoadTexture("levelSelector/quote.png");
    Texture2D warningPNG = LoadTexture("levelSelector/warning.png");
    Texture2D jumpScarePNG = LoadTexture("levelSelector/jumpScare.png");
    Texture2D blankPNG = LoadTexture("levelSelector/blank.png");

    // JumpScareBitmaps

    Texture2D jumpScarePNG01 = LoadTexture("levelSelector/Bitmap01.png");
    Texture2D jumpScarePNG02 = LoadTexture("levelSelector/Bitmap02.png");
    Texture2D jumpScarePNG03 = LoadTexture("levelSelector/Bitmap03.png");
    Texture2D jumpScarePNG04 = LoadTexture("levelSelector/Bitmap04.png");
    Texture2D jumpScarePNG05 = LoadTexture("levelSelector/Bitmap05.png");
    Texture2D jumpScarePNG06 = LoadTexture("levelSelector/Bitmap06.png");
    Texture2D jumpScarePNG07 = LoadTexture("levelSelector/Bitmap07.png");
    Texture2D jumpScarePNG08 = LoadTexture("levelSelector/Bitmap08.png");
    Texture2D jumpScarePNG09 = LoadTexture("levelSelector/Bitmap09.png");
    Texture2D jumpScarePNG10 = LoadTexture("levelSelector/Bitmap10.png");
    Texture2D jumpScarePNG11 = LoadTexture("levelSelector/Bitmap11.png");
    Texture2D jumpScarePNG12 = LoadTexture("levelSelector/Bitmap12.png");
    Texture2D jumpScarePNG13 = LoadTexture("levelSelector/Bitmap13.png");
    Texture2D jumpScarePNG14 = LoadTexture("levelSelector/Bitmap14.png");
    Texture2D jumpScarePNG15 = LoadTexture("levelSelector/Bitmap15.png");
    Texture2D jumpScarePNG16 = LoadTexture("levelSelector/Bitmap16.png");
    Texture2D jumpScarePNG17 = LoadTexture("levelSelector/Bitmap17.png");
    Texture2D jumpScarePNG18 = LoadTexture("levelSelector/Bitmap18.png");
    Texture2D jumpScarePNG19 = LoadTexture("levelSelector/Bitmap19.png");

    PNGS() {

        Textures.push_front(warningPNG);
        Textures.push_front(quotePNG);
        Textures.push_front(mainScreenPng);
        Textures.push_front(afterLevel6PNG);
        Textures.push_front(PNG1);
        Textures.push_front(PNG2);
        Textures.push_front(PNG3);
        Textures.push_front(behindYouPNG);
        Textures.push_front(blankPNG);
        Textures.push_front(jumpScarePNG01);
        Textures.push_front(jumpScarePNG02);
        Textures.push_front(jumpScarePNG03);
        Textures.push_front(jumpScarePNG04);
        Textures.push_front(jumpScarePNG05);
        Textures.push_front(jumpScarePNG06);
        Textures.push_front(jumpScarePNG07);
        Textures.push_front(jumpScarePNG08);
        Textures.push_front(jumpScarePNG09);
        Textures.push_front(jumpScarePNG10);
        Textures.push_front(jumpScarePNG11);
        Textures.push_front(jumpScarePNG12);
        Textures.push_front(jumpScarePNG13);
        Textures.push_front(jumpScarePNG14);
        Textures.push_front(jumpScarePNG15);
        Textures.push_front(jumpScarePNG16);
        Textures.push_front(jumpScarePNG17);
        Textures.push_front(jumpScarePNG18);
        Textures.push_front(jumpScarePNG19);
        //Textures.push_front(blankPNG);
    }



};

class Character {

public:

    void jump() {

        if (counter - jumpDelay > jumpHeight && IsKeyDown(KEY_SPACE))
        {
            space = true;
            counter = 0;
        }

        if (counter == jumpHeight)
        {
            space = false;
        }

        if (space)
        {
            StickPosition.y -= 19;
        }
    }

    void move() {

        if (IsKeyDown(KEY_RIGHT)) StickPosition.x += speed;
        if (IsKeyDown(KEY_LEFT)) StickPosition.x -= speed;
        //if (IsKeyDown(KEY_UP)) StickPosition.y -= speed;
        //if (IsKeyDown(KEY_DOWN)) StickPosition.y += speed;

        if (StickPosition.x <= 42) StickPosition.x -= 0.8f;
        if (StickPosition.x >= 1310) StickPosition.x -= 1.0f;
        if ((StickPosition.y >= (GetScreenHeight() - StickManHeight))) StickPosition.y = screenHeight - StickManHeight;
        if ((StickPosition.y <= 40)) StickPosition.y = 40;
    }

    void StickMan(PNGS png1) {

        BeginDrawing();


        if (x != 9) {

            DrawTexture(png1.StickManPng, StickPosition.x, StickPosition.y, WHITE);
            tempPositionx = StickPosition.x;
            tempPositiony = StickPosition.y;
        }
        else
        {
            pingMeter += 1;

            if (pingMeter < ping)
            {
                DrawTexture(png1.StickManPng, StickPosition.x, StickPosition.y, WHITE);
                tempPositionx = StickPosition.x;
                tempPositiony = StickPosition.y;
            }
            else {

                DrawTexture(png1.StickManPng, tempPositionx, tempPositiony, WHITE);

                if (pingMeter > ping * 2)
                {
                    pingMeter = 0;
                }
            }


        }

        EndDrawing();
    }

    void gravityFunction() {
        StickPosition.y += gravity; //Gravity
    }
};

class Stages : public Character {

public:

    void stageSelect(PNGS png1) {

        BeginDrawing();

        DrawTexture(png1.selectorBackgroundPNG, 0, 0, WHITE);

        DrawTexture(png1.box1PNG, 200, 200, WHITE);
        DrawTexture(png1.box2PNG, 600, 200, WHITE);
        DrawTexture(png1.box3PNG, 1000, 200, WHITE);
        DrawTexture(png1.box4PNG, 200, 500, WHITE);
        DrawTexture(png1.box5PNG, 600, 500, WHITE);
        DrawTexture(png1.box6PNG, 1000, 500, WHITE);
        DrawTexture(png1.backButtonPNG, 60, 40, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 200, 200, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 4;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 600, 200, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 5;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 1000, 200, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 6;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 200, 500, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 7;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 600, 500, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 8;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 1000, 500, 217, 211 })) //Button 1
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 9;
            }
        }

        EndDrawing(); // if levels gives you problem then try shifting it upwords or anywhere else

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 60, 40, 96, 55 })) //Button Collider
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 0;
                showWelcome = true;
                alive = true;
            }
        }

    }

    void logOperation() {

        if (logMove && logMoveOnlyOnce) {
            logPositionY -= 4;
            if (logPositionY <= 80) {
                logMove = false;
                logMoveOnlyOnce = false;
            }
        }
    }

    void buttonOperation() {

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 667, buttonPositionY, 91 , 23 }))
        {
            buttonPositionY += 1.6;
            if (buttonPositionY > 350 && (x == 5) || (x == 7) || (x == 9)) {
                logMove = true;
            }
        }
        if ((!(CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 667, 380, 91 , 23 }))) && buttonPositionY > 381)
        {
            buttonPositionY -= 1.6;
        }
    }

    void backBotton() {

        if ((CheckCollisionPointRec(GetMousePosition(), Rectangle{ 660, 32, 96, 55 }) || IsKeyPressed(KEY_BACKSPACE)))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_BACKSPACE))
            {
                x = 0;
                showWelcome = true;
                alive = true;
                logPositionY = 250;
                logMoveOnlyOnce = true;
                level1Start = true;
                buttonPositionY = 380; ////////
            }
        }
    }

    void youDied(PNGS png1) {

        DrawTexture(png1.youDiedPNG, 0, 0, WHITE);
        DrawTexture(png1.backButtonPNG, 660, 32, WHITE);
        StickPosition.x = 42;    //Fliker Effect
        StickPosition.y = 340;   //Fliker Effect
        backBotton();
        alive = false;
    }

    void spikeCollisions(PNGS png1) {

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 664, 112,84 , 22 })) youDied(png1);
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 664, 425,84 , 22 })) youDied(png1);
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 368, 261,79 , 22 })) youDied(png1);
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 982, 277,82 , 22 })) youDied(png1);
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 942,  41,82 , 22 })) youDied(png1);

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 392, 37, 25, 20 })) youDied(png1); //Teeth Down
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1356, 64, 36, 171 })) youDied(png1); // 5 Teeth Left
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 48, 120, 32, 95 })) youDied(png1); // 3 Teeth Right
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 48, 515, 30, 186 })) youDied(png1); // 6 Teeth Right

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 716, 716, 36, 36 })) youDied(png1); //teeth UP
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 847, 723, 36, 36 })) youDied(png1); //2nd Teeth Up
    }

    void collisions(PNGS png1) {

        //Top Mid Box

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 635, 23, 150 , 93 }))
        {
            StickPosition.y = 116;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 620, 24, 13, 92 }))
        {
            StickPosition.x = 620 - StickManWidth;
        }

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 788, 24, 13, 92 }))
        {
            StickPosition.x = 745 + StickManWidth;
        }

        // Creepy entery
        if (StickPosition.x <= 0)
        {
            StickPosition.x -= 1.0f;

            if (StickPosition.x <= -60)
            {
                StickPosition.x = 1450;
                StickPosition.y = 500;
            }
        }

        //Bottom Bar
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1, 745, 1421 , 234 }))
        {
            StickPosition.y = 640;
        }


        //Left Tray 1 UP
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 336, 238, 160, 8 }))
        {
            StickPosition.y = (238 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 326, 262, 174, 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 322, 246, 14, 23 }))
        {
            StickPosition.x = (316 - StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 488, 244, 14, 23 }))
        {
            StickPosition.x = (444 + StickManWidth);
        }

        //Right Tray 1 UP
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 960, 248, 130, 8 }))
        {
            StickPosition.y = (248 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 959, 261, 131, 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 950, 250, 7, 23 }))
        {
            StickPosition.x = (830 + StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1095, 250, 7, 23 }))
        {
            StickPosition.x = (1035 + StickManWidth);
        }

        //Left Tray 2 Down
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 331, 515, 140 , 10 }))
        {
            StickPosition.y = (515 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 330, 544, 150, 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 322, 520, 14, 23 }))
        {
            StickPosition.x = (316 - StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 470, 520, 14, 23 }))
        {
            StickPosition.x = (420 + StickManWidth);
        }

        //Right Tray 2 Down
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 962, 527, 131 , 10 }))
        {
            StickPosition.y = (527 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 955, 555, 150 , 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 952, 534, 5, 23 }))
        {
            StickPosition.x = (830 + StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1105, 528, 7, 23 }))
        {
            StickPosition.x = (1040 + StickManWidth);
        }

        // mid Box Bottom

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 737, 663, 120 , 80 }))
        {
            StickPosition.y = (663 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 727, 663, 13 , 80 }))
        {
            StickPosition.x = (720 - StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 855, 663, 13 , 80 }))
        {
            StickPosition.x = (805 + StickManWidth);
        }


        //b Right Box

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1230, 620, 200 , 50 }))
        {
            StickPosition.y = (620 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1218, 623, 121 , 121 }))
        {
            StickPosition.x = (1217 - StickManWidth);
        }


        // DrawRectangle(1221, 623, 200, 121, RED);
        // 
         // Tray below Door Right

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1230, 444, 210 , 10 }))
        {
            StickPosition.y = (444 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1220, 475, 219 , 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1218, 456, 14, 23 }))
        {
            StickPosition.x = (1218 - StickManWidth);
        }


        // Tray below Door Left

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 0, 444, 210 , 10 }))
        {
            StickPosition.y = (444 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 0, 475, 210 , 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 210, 468, 14, 23 }))
        {
            StickPosition.x = (160 + StickManWidth);
        }

        // Mid Trays

        //Tray 1

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 556, 400, 309 , 10 }))
        {
            StickPosition.y = (400 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 555, 423, 319 , 10 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 545, 406, 14, 23 }))
        {
            StickPosition.x = (540 - StickManWidth);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 858, 406, 14, 23 }))
        {
            StickPosition.x = (810 + StickManWidth);
        }

        //BUTTON WILL BE PROGRAMMED ACCORDING TO THE PROGRAM//

        //top trays

        //Left 

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 0, 232, 210 , 10 }))
        {
            StickPosition.y = (232 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 0, 262, 219 , 11 }))
        {
            space = false;
        }

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 210, 238, 14, 23 }))
        {
            StickPosition.x = (160 + StickManWidth);
        }


        //Right  
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1228, 232, 210 , 10 }))
        {
            StickPosition.y = (232 - StickManHeight);
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1218, 262, 219 , 11 }))
        {
            space = false;
        }
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1216, 238, 14, 23 }))
        {
            StickPosition.x = (1218 - StickManWidth);
        }


        // Log / Door

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1220, logPositionY, 34, 208 }))
        {
            StickPosition.x = (1220 - StickManWidth);
        }

    }

    void levelTemplate(PNGS png1) {

        if (alive) {
            DrawTexture(png1.templateBackground, 0, 0, WHITE);

            //Teeths
            DrawTexture(png1.threeTeethDownPNG, 655, 116, WHITE);
            DrawTexture(png1.threeTeethDownPNG, 655, 425, WHITE);
            DrawTexture(png1.threeTeethDownPNG, 355, 261, WHITE);
            DrawTexture(png1.threeTeethDownPNG, 973, 277, WHITE);
            DrawTexture(png1.threeTeethDownPNG, 933, 41, WHITE);

            DrawTexture(png1.teethDownPNG, 386, 41, WHITE);
            DrawTexture(png1.fiveTeethLeftPNG, 1344, 61, WHITE);
            DrawTexture(png1.threeTeethRightPNG, 53, 110, WHITE);
            DrawTexture(png1.sixTeethRightPNG, 54, 500, WHITE);

            DrawTexture(png1.teethUpPNG, 692, 703, WHITE);
            DrawTexture(png1.teethUpPNG, 867, 703, WHITE);

            DrawTexture(png1.topBarPNG, 5, -20, WHITE);          //Ceiling  
            DrawTexture(png1.topBoxPNG, 620, 25, WHITE);
            DrawTexture(png1.barUpPNG, 0, 0, WHITE);             //left Side bar
            DrawTexture(png1.barUpPNG, 1378, 0, WHITE);          //Right side bar
            DrawTexture(png1.longGrassPNG, 43, 195, WHITE);
            DrawTexture(png1.longGrassPNG, 1220, 195, WHITE);
            DrawTexture(png1.trayPNG, 0, 232, WHITE);            //left tray above door
            DrawTexture(png1.trayPNG, 1220, 232, WHITE);         //right tray aove door

            if (x != 8) {
                DrawTexture(png1.logPNG, 1220, logPositionY, WHITE); //DOOR
            }
            else {
                DrawTexture(png1.logPNG, 1220, 250, WHITE);
            }

            DrawTexture(png1.trayL1PNG, 320, 233, WHITE);
            DrawTexture(png1.trayR1PNG, 945, 239, WHITE);
            DrawTexture(png1.trayL2PNG, 320, 510, WHITE);
            DrawTexture(png1.trayR2PNG, 948, 520, WHITE);
            //bottom tray
            DrawTexture(png1.buttonPNG, 655, buttonPositionY, WHITE);
            DrawTexture(png1.midTray2PNG, 640, 390, WHITE);
            DrawTexture(png1.midTray1PNG, 550, 400, WHITE);
            DrawTexture(png1.trayPNG, 0, 444, WHITE);
            DrawTexture(png1.trayPNG, 1220, 444, WHITE);
            DrawTexture(png1.barDownPNG, 0, 444, WHITE);
            DrawTexture(png1.barDownPNG, 1378, 444, WHITE);
            DrawTexture(png1.bottomPNG, 1, 625, WHITE);
            DrawTexture(png1.bBoxPNG, 730, 660, WHITE);
            DrawTexture(png1.boxRBPNG, 1220, 620, WHITE);
            DrawTexture(png1.longGrassPNG, 1220, 585, WHITE);
            DrawTexture(png1.backButtonPNG, 660, 32, WHITE);


        }
        collisions(png1);
        spikeCollisions(png1);
    }

    void credits(PNGS png1) {


        BeginDrawing();

        DrawTexture(png1.creditBackgroundPNG, 0, 0, WHITE);
        DrawTexture(png1.backButtonBlackPNG, 60, 40, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 60, 40, 96, 55 }))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                x = 0;
                showWelcome = true;
                alive = true;
            }
        }

        EndDrawing();
    }

};

class Levels : public Stages {

public:
    void level1(PNGS png1) { //dont touch it 1

        if (level1Start)
        {
            logPositionY = 100;
            level1Start = false;
        }

        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 667, buttonPositionY, 91 , 23 }))
        {
            logPositionY = 240;
        }
        buttonOperation();
        levelTemplate(png1);
        StickMan(png1);
        gravityFunction();
        move();
        jump();
        backBotton();
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {
            logMoveOnlyOnce = true;
            x = 11;
            level1Start = true;
        }
    }

    void level2(PNGS png1) {  // inverted contralls 2

        // jump
        if (counter - jumpDelay > jumpHeight && IsKeyDown(KEY_RIGHT))
        {
            space = true;
            counter = 0;
        }

        if (counter == jumpHeight)
        {
            space = false;
        }

        if (space)
        {
            StickPosition.y -= 19;
        }
        // 
        if (IsKeyDown(KEY_LEFT)) StickPosition.x += speed;
        if (IsKeyDown(KEY_SPACE)) StickPosition.x -= speed;

        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }

        buttonOperation();
        levelTemplate(png1);
        StickMan(png1);
        logOperation();
        gravityFunction();
        backBotton();

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {
            logMoveOnlyOnce = true;
            x = 12;
        }

    }

    void level3(PNGS png1) { // bye bye (press back button)


        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }
        buttonOperation();

        levelTemplate(png1);
        StickMan(png1);
        // logOperation();
        gravityFunction();
        move();
        jump();
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {

        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_BACKSPACE))
        {
            logMoveOnlyOnce = true;
            x = 13;
        }

    }

    void level4(PNGS png1) { // Fast Wind

        StickPosition.x -= 2.0;
        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }
        buttonOperation();
        levelTemplate(png1);
        StickMan(png1);
        logOperation();
        gravityFunction();
        backBotton();
        move();
        jump();
        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {
            logMoveOnlyOnce = true;
            logPositionY = 250;
            x = 14;
        }
    }

    void level5(PNGS png1) { // no eyes

        if (level5Start)
        {
            logPositionY = 100;
            level5Start = false;
        }

        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }

        buttonOperation();
        levelTemplate(png1);
        StickMan(png1);
        gravityFunction();
        backBotton();
        move();
        jump();

        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {
            logMoveOnlyOnce = true;
            x = 15;
        }

    }

    void level6(PNGS png1) {

        if (startPosition)
        {
            StickPosition.x = screenWidth / 10.1;
            StickPosition.y = screenHeight / 2.0;
            startPosition = false;
        }

        buttonOperation();
        levelTemplate(png1);
        logOperation();
        StickMan(png1);
        move();
        jump();
        gravityFunction();
        backBotton();


        if (CheckCollisionRecs(Rectangle{ StickPosition.x, StickPosition.y, 65, 102 }, Rectangle{ 1350, 300, 14, 120 })) /////////continue form here
        {
            x = 16;
        }
    }

    void gameEnd(PNGS png1) {

        BeginDrawing();
        spaceLayers += 1;

        if (popNow) {
            Textures.pop_back();
            popNow = false;
        }

        if ((spaceLayers >= (DEALY_SCREEN_COMECLOSER * variable)) && (commonIterator_Endgame < 24)) {
            
            Textures.pop_back();

            switch (commonIterator_Endgame) {

            case 0:
                variable *= 0.7; // timing of 1
                break;
            case 1:
                variable *= 0.7; // timing of 2
                break;
            case 2:
                variable *= 0.7; // timing of 3
                break;
            case 3:
                variable *= 1; // timing of behind yo
                break;
            case 4:
                variable *= 1; // Blank of im behind you
                break;
            default:
                variable *= 0.2;
                break;
            }
         
            spaceLayers = 0;
            commonIterator_Endgame++;
            cout << commonIterator_Endgame;
        }

        DrawTexture(Textures.back(), 0, 0, WHITE);

        EndDrawing();
    }

};

int main(void)
{
    Levels showing;
    //Audio play;
    InitWindow(screenWidth, screenHeight, "...Cursed---Tomorrow... by B-Ted");
    InitAudioDevice();
    SetTargetFPS(60);

    Music levelMusic = LoadMusicStream("audio/levelMusic.mp3");
    //Music mainMusic = LoadMusicStream("audio/main.mp3");
    //Main Screen PNGs

    PNGS png;
    //Stickman

    //Template Screen

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        counter += 1;  //Frame Counter
        /*jumpScareCounter1 += 1;
        jumpScareCounter2 += 1;
        jumpScareCounter3 += 1;*/
        PlayMusicStream(levelMusic);
        UpdateMusicStream(levelMusic);

        if (showWelcome)
        {

            //Buttons
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 170, 80, 216, 34 }))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    x = 1;
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 210, 160, 118, 33 }))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    x = 2;
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 195, 240, 150, 34 }))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    x = 3;
                }
            }

            //MainSceen

            BeginDrawing();

            delayMeter += 1;

            if ((delayMeter >= (DEALY_SCREEN * variable)) && (commonIterator < 2)) {
                Textures.pop_back();
                variable *= 1.7;
                commonIterator++;
            }

            DrawTexture(Textures.back(), 0, 0, WHITE);

            if (commonIterator >= 2) {
                DrawTexture(png.newGamePng, 170, 80, WHITE);
                DrawTexture(png.levelsPng, 210, 160, WHITE);
                DrawTexture(png.creditsPng, 195, 240, WHITE);

            }

          /*  if ((delayMeter < DEALY_SCREEN * 4) && warningScreen) {
                DrawTexture(Textures.back(), 0, 0, WHITE);
            }

            if ((delayMeter <= DEALY_SCREEN * 2) && warningScreen) {
                DrawTexture(png.warningPNG, 0, 0, WHITE);
            }

            if ((delayMeter >= (DEALY_SCREEN * 4) && warningScreen)) {
                warningScreen = false;
            }*/

            EndDrawing();

            if (x != 0) {
                showWelcome = false;
            }
            startPosition = true;
        }

        switch (x)
        {
        case 1:
            delayMeter = 0;
            showing.level1(png);
            break;

        case 2:
            showing.stageSelect(png);
            break;

        case 3:
            showing.credits(png);
            break;

        case 4:
            showing.level1(png); // Level 1
            break;

        case 5:
            showing.level2(png); // Level 2
            break;

        case 6:
            showing.level3(png); // Level 3
            break;

        case 7:
            showing.level4(png); // Level 4
            break;

        case 8:
            showing.level5(png); // Level 5
            break;

        case 9:
            showing.level6(png); // Level 6
            break;

        case 10:
            showing.level6(png); // Level 6 after
            break;

        case 11:
        {
            delayMeter += 1;

            BeginDrawing();
            DrawTexture(png.afterLevel1PNG, 0, 0, WHITE); // afterLevel1
            EndDrawing();

            if (delayMeter >= DEALY_SCREEN) {
                logPositionY = 250;
                StickPosition.x = screenWidth / 10.1;
                StickPosition.y = screenHeight / 2.0;
                delayMeter = 0.0;
                x = 5;
            }
        }
        break;

        case 12:
        {
            delayMeter += 1;

            BeginDrawing();
            DrawTexture(png.afterLevel2PNG, 0, 0, WHITE); // afterLevel2
            EndDrawing();
            if (delayMeter >= DEALY_SCREEN) {
                logPositionY = 250;
                StickPosition.x = screenWidth / 10.1;
                StickPosition.y = screenHeight / 2.0;
                delayMeter = 0.0;
                x = 6;
            }
        }
        break;

        case 13:
        {
            delayMeter += 1;

            BeginDrawing();
            DrawTexture(png.afterLevel3PNG, 0, 0, WHITE); // afterLevel3
            EndDrawing();

            if (delayMeter >= DEALY_SCREEN) {
                logPositionY = 250;
                StickPosition.x = screenWidth / 10.1;
                StickPosition.y = screenHeight / 2.0;
                delayMeter = 0.0;
                x = 7;
            }
        }
        break;

        case 14:
        {
            delayMeter += 1;

            BeginDrawing();
            DrawTexture(png.afterLevel4PNG, 0, 0, WHITE); // afterLevel4
            EndDrawing();
            if (delayMeter >= DEALY_SCREEN) {
                logPositionY = 250;
                StickPosition.x = screenWidth / 10.1;
                StickPosition.y = screenHeight / 2.0;
                delayMeter = 0.0;
                x = 8;
            }
        }
        break;

        case 15:
        {
            delayMeter += 1;

            BeginDrawing();
            DrawTexture(png.afterLevel5PNG, 0, 0, WHITE); // afterLevel5
            EndDrawing();
            if (delayMeter >= DEALY_SCREEN) {
                logPositionY = 250;
                StickPosition.x = screenWidth / 10.1;
                StickPosition.y = screenHeight / 2.0;
                delayMeter = 0.0;
                x = 9;
            }
        }
        break;

        case 16:
        {
            showing.gameEnd(png);
        }
        break;

        CloseWindow();

        return 0;
        }
    }
}

