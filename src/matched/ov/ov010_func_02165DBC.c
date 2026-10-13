/*
 * function: GAME_BEACON_ACCESSOR_GetDetailsTrainerNo
 * address: 0x02165DBC
 * packet: pkt_ov010_02165DBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
#include "../include/Obj07306.h"
unsigned short GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 2: case 3: case 4:
        if(b==0 || b>=616) b=1;
        return b;
    default: return 1;
    }
}
