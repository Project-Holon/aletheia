/*
 * function: GAME_BEACON_ACCESSOR_GetDetailsMonsNo
 * address: 0x02165DF0
 * packet: pkt_ov010_02165DF0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
#include "../include/Obj07306.h"
unsigned short GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 0: case 1:
        if(b==0 || b>649) b=504;
        return b;
    default: return 504;
    }
}
