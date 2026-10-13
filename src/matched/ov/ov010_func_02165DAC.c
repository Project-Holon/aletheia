/*
 * function: GAME_BEACON_ACCESSOR_GetDetailsType
 * address: 0x02165DAC
 * packet: pkt_ov010_02165DAC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
#include "../include/Obj19003.h"
unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj19003 *)p)->f48;
    if(a>=6) a=5;
    return a;
}
