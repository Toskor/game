#include <iostream>
#include <bullsandcows.h>


int main(int argc, char *argv[])
{

    try {
        BullsAndCows game = BullsAndCows();
        game.game();
    }
    catch (Exception e) {
        exit(1);
    }



}
