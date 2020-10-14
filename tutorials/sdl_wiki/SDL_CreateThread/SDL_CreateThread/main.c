//https://wiki.libsdl.org/SDL_CreateThread
//函数解释
#include <stdio.h>
#include "SDL.h"

/* Very simple thread - counts 0 to 9 delaying 50ms between increments */
static int TestThread(void *ptr)
{
    int cnt;
    
    for (cnt = 0; cnt < 10; ++cnt) {
        printf("Thread counter: %d\n", cnt);
        SDL_Delay(50);
    }
    
    return cnt;
}

int main(int argc, char *argv[])
{
    SDL_Thread *thread;
    int         threadReturnValue;
    
    printf("Simple SDL_CreateThread test:\n");
    
    /* Simply create a thread */
    thread = SDL_CreateThread(TestThread, "TestThread", (void *)NULL);
    
    if (NULL == thread) {
        printf("SDL_CreateThread failed: %s\n", SDL_GetError());
    } else {
        SDL_WaitThread(thread, &threadReturnValue);
        printf("Thread returned value: %d\n", threadReturnValue);
    }
    
    return 0;
}
