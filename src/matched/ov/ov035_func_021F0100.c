/*
 * function: C_GEAR_POWER_ONOFF_ExitBgs
 * address:  0x021F0100
 * packet:   pkt_ov035_021F0100
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_ExitBgs 0x021F0100 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf  0x020403F4 arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj20480.h"

typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);

void C_GEAR_POWER_ONOFF_ExitBgs(char *p)
{
    unsigned int v = ((struct Obj20480 *)p)->f10;
    BG_SYS_FreeTileRun(6, (unsigned short)v, (unsigned short)(v >> 16));
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}
