/*
 * function: BR_CODEIN_ProfileUpdateActorVisible
 * address: 0x021E0E4C
 * packet: pkt_ov183_021E0E4C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj00143.h"
void BR_CODEIN_ProfileUpdateActorVisible(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj00143 *)p)->f23C; i++) {
        if (i >= ((struct Obj00143 *)p)->f248 && i < ((struct Obj00143 *)p)->f24C)
            *(int *)(p + i * 28 + 8) = 1;
        else
            *(int *)(p + i * 28 + 8) = 0;
    }
}
