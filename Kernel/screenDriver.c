#include <video_vm.h>
#include <screenDriver.h>
static int x = 0;
static int y = 0;

static void scrollDown();

void drawCharAt(char character, int fontColor, int backgroundColor){
    if(x == getScreenWidth()){
        if(y == getScreenHeight()){
            scrollDown();
        }
        else{
            x = 0;
            y++;
        }
    }
    drawChar(x,y,character,fontColor,backgroundColor);
}

void scrollDown(){

}