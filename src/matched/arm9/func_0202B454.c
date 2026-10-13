/*
 * function: ISS_DUNGEON_SYS_ResetTracks
 * address:  0x0202B454
 * packet:   pkt_0202B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15838.h"

void ISS_DUNGEON_SYS_ResetTracks(char *p)
{
    int i;
    ((struct Obj15838 *)p)->f1C = 0xffff;
    for (i = 0; i < 4; i++) {
        *(unsigned short *)(p + i * 2 + 0x20) = 0;
        *(unsigned short *)(p + i * 2 + 0x28) = 0x100;
        *(unsigned short *)(p + i * 2 + 0x30) = 0;
    }
}
