#include "BeaconFormula.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

string inph = ""; // Input for layer height
string inpL = ""; // Input for length
string inpW = ""; // Input for width
string inpm = ""; // Input for maximum layer
string inpbeta = ""; // Input for beta

int activebox = 0;
    
string outb_l;
string outb;

/*Mouse Callback Function Start*/
int boxhx = 20;
int boxhy = 600;
int boxhw = 500;
int boxhh = 40;

int boxLx = 20;
int boxLy = 650;
int boxLw = 500;
int boxLh = 40;
    
int boxWx = 20;
int boxWy = 700;
int boxWw = 500;
int boxWh = 40;
    
int boxmx = 20;
int boxmy = 750;
int boxmw = 500;
int boxmh = 40;

int boxbetax = 20;
int boxbetay = 800;
int boxbetaw = 500;
int boxbetah = 40;

int CalculateBoxx = 20;
int CalculateBoxy = 880;
int CalculateBoxw = 60;
int CalculateBoxh = 60;

void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {

        if (x >= boxhx && x <= boxhx + boxhw &&
            y >= boxhy && y <= boxhy + boxhh) {
            activebox = 1;

        } else if (x >= boxLx && x <= boxLx + boxLw &&
                   y >= boxLy && y <= boxLy + boxLh) {
            activebox = 2;

        } else if (x >= boxWx && x <= boxWx + boxWw &&
                   y >= boxWy && y <= boxWy + boxWh) {
            activebox = 3;

        } else if (x >= boxmx && x <= boxmx + boxmw &&
                   y >= boxmy && y <= boxmy + boxmh) {
            activebox = 4;

        } else if (x >= boxbetax && x <= boxbetax + boxbetaw &&
                   y >= boxbetay && y <= boxbetay + boxbetah) {
            activebox = 5;

        } else if (x >= CalculateBoxx && x <= CalculateBoxx + CalculateBoxw &&
                   y >= CalculateBoxy && y <= CalculateBoxy + CalculateBoxh) {
            activebox = 6;

        } else {
            activebox = 0;
        }
    }
}
/*Mouse Callback Function End*/

int main() {
    cout << "Welcome to the Beacon Formula Calculator (Netherite Edition) <3\n"; //Initialization message

    Mat BeaconLayerFormula = imread("image/BeaconLayerFormula.png");  //Load BeaconLayerFormula.png
    Mat BeaconFormula = imread("image/BeaconFormula.png");  //Load BeaconFormula.png

    Mat canvas(1100, 1674, CV_8UC3, Scalar(255, 255, 255));
    BeaconLayerFormula.copyTo(canvas(Rect(0, 0, BeaconLayerFormula.cols, BeaconLayerFormula.rows)));
    BeaconFormula.copyTo(canvas(Rect(652, 0, BeaconFormula.cols, BeaconFormula.rows)));
    
    rectangle(canvas, Point(20, 600), Point(520, 640), Scalar(128, 128, 128), -1); //Box for layer height input
    rectangle(canvas, Point(20, 650), Point(520, 690), Scalar(128, 128, 128), -1); //Box for length input
    rectangle(canvas, Point(20, 700), Point(520, 740), Scalar(128, 128, 128), -1); //Box for width input
    rectangle(canvas, Point(20, 750), Point(520, 790), Scalar(128, 128, 128), -1); //Box for maximum layer input
    rectangle(canvas, Point(20, 800), Point(520, 840), Scalar(128, 128, 128), -1); //Box for beta

    rectangle(canvas, Point(20, 880), Point(80, 940), Scalar(128, 128, 128), -1); //Calculate button
    
    rectangle(canvas, Point(20, 950), Point(520, 990), Scalar(128, 128, 128), -1); //Box for beacon layer output
    rectangle(canvas, Point(20, 1000), Point(520, 1040), Scalar(128, 128, 128), -1); //Box for beacon output
    
    
    Ptr<freetype::FreeType2> font = freetype::createFreeType2(); //Create a FreeType text-rendering object and store it in font
    font->loadFontData("font/Minecraft.ttf", 0); //Load Minecraft font

    font->putText(canvas, "h = ", Point(30,600), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output h
    font->putText(canvas, "L = ", Point(30,650), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output L
    font->putText(canvas, "W = ", Point(30,700), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output W
    font->putText(canvas, "m = ", Point(30,750), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output m
    font->putText(canvas, "beta = ", Point(30,800), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output beta
    font->putText(canvas, "=", Point(30,880), 28, Scalar(255,255,255), -1, LINE_AA, false); //=
    font->putText(canvas, "b_l = ", Point(30,950), 28, Scalar(255,255,255), -1, LINE_AA, false); //b_l
    font->putText(canvas, "b = ", Point(30,1000), 28, Scalar(255,255,255), -1, LINE_AA, false); //b
    
    
    namedWindow("The Beacon Formula Calculator (Netherite Edition)", WINDOW_NORMAL);
    resizeWindow("The Beacon Formula Calculator (Netherite Edition)", 1400, 900);
    setMouseCallback("The Beacon Formula Calculator (Netherite Edition)", mouseCallback);
    
    /*Icon Start*/
    HWND hwnd = FindWindowA(NULL, "The Beacon Formula Calculator (Netherite Edition)");
    HICON hIcon = (HICON)LoadImageA(NULL, "icon/icon.ico", IMAGE_ICON, 256, 256, LR_LOADFROMFILE);

    if (hwnd && hIcon) {
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }
    /*Icon End*/
   
    bool running = true;
    
    while (running) {
        Mat loopcanvas = canvas.clone();

        font->putText(loopcanvas, inph, Point(150,600), 28, Scalar(255,255,255), -1, LINE_AA, false); //Input h
        font->putText(loopcanvas, inpL, Point(150,650), 28, Scalar(255,255,255), -1, LINE_AA, false); //Input L
        font->putText(loopcanvas, inpW, Point(150,700), 28, Scalar(255,255,255), -1, LINE_AA, false); //Input W
        font->putText(loopcanvas, inpm, Point(150,750), 28, Scalar(255,255,255), -1, LINE_AA, false); //Input m
        font->putText(loopcanvas, inpbeta, Point(150,800), 28, Scalar(255,255,255), -1, LINE_AA, false); //Input beta
        
        font->putText(loopcanvas, outb_l, Point(150,950), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output b_l
        font->putText(loopcanvas, outb, Point(150,1000), 28, Scalar(255,255,255), -1, LINE_AA, false); //Output b
        
        imshow("The Beacon Formula Calculator (Netherite Edition)", loopcanvas); //Update the screen


        int key = waitKey(20);

        if ((key >= '0' && key <= '9') || key == '-') {
            if (activebox == 1) {
                if ((key >= '0' && key <= '9') || (key == '-' && inph.empty()))
                    inph += (char)key;
            }
            else if (activebox == 2) {
                if ((key >= '0' && key <= '9') || (key == '-' && inpL.empty()))
                    inpL += (char)key;
            }
            else if (activebox == 3) {
                if ((key >= '0' && key <= '9') || (key == '-' && inpW.empty()))
                    inpW += (char)key;
            }
            else if (activebox == 4) {
                if ((key >= '0' && key <= '9') || (key == '-' && inpm.empty()))
                    inpm += (char)key;
            }
            else if (activebox == 5) {
                if ((key >= '0' && key <= '9') || (key == '-' && inpbeta.empty()))
                    inpbeta += (char)key;
            }
        }

        if (key == 8) { // backspace
            if (activebox == 1 && !inph.empty()) {inph.pop_back();}
            else if (activebox == 2 && !inpL.empty()) {inpL.pop_back();}
            else if (activebox == 3 && !inpW.empty()) {inpW.pop_back();}
            else if (activebox == 4 && !inpm.empty()) {inpm.pop_back();}
            else if (activebox == 5 && !inpbeta.empty()) {inpbeta.pop_back();}
        }

        if (activebox == 6) {
            
            /*String Integer Converter Start*/
            int h_0 = stoi(inph);
            int L = stoi(inpL);
            int W = stoi(inpW);
            int m = stoi(inpm);
            int beta = stoi(inpbeta);
            /*String Integer Converter End*/
        
            if (L == 0 || W == 0 || m == 0) {
                cout << "Error Calculating: Area does not exist!\n";
                outb_l = "ERROR";
                outb = "ERROR";
                            
                MessageBoxA(NULL, "Area does not exist!", "Error Calculating", MB_OK | MB_ICONERROR);
                            
            } else if (h_0 < 0 || L < 0 || W < 0 || m < 0 || beta < 0) {
                cout << "Error Calculating: Negative Dimentions!\n";
                outb_l = "ERROR";
                outb = "ERROR";
                            
                MessageBoxA(NULL, "Negative Dimentions!", "Error Calculating", MB_OK | MB_ICONERROR);

            } else if (beta >= L*W) {
                cout << "Error Calculating: Beacon(s) do not exist!\n";
                outb_l = "ERROR";
                outb = "ERROR";
                            
                MessageBoxA(NULL, "Beacon(s) do not exist!", "Error Calculating", MB_OK | MB_ICONERROR);
                            
            } else {
                outb_l = to_string(b_l(h_0, L, W));
                outb = to_string(b(L, W, m, beta));

                cout << "Calculated\n Beacon Layer = " << outb_l << "\n Beacon Sum = " << outb << "\n";
            }
        
            activebox = 0; //Stops spams
        }

        if (getWindowProperty("The Beacon Formula Calculator (Netherite Edition)", WND_PROP_VISIBLE) < 1) {
        running = false;
        }
    }

    return 0;
}