#include <stdio.h>
#include <stdbool.h>

int main() {
    const bool RENDER_FOG_OF_WAR = true;
    bool *fog_ptr;
    fog_ptr = (bool*)&RENDER_FOG_OF_WAR;
    *fog_ptr = false;
    printf("RENDER_FOG_OF_WAR = %d", RENDER_FOG_OF_WAR);

    return 0;
}