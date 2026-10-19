/*
 * function: UNION_SUBDISP_FreeFrameBgChar
 * address: 0x021F0420
 * packet: pkt_ov031_021F0420
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 */
#include "../include/Obj20404.h"
typedef unsigned int u32;
extern void BG_SYS_FreeTileRun(u32, u32, u32);
void UNION_SUBDISP_FreeFrameBgChar(char *p)
{
    BG_SYS_FreeTileRun(5, ((struct Obj20404 *)p)->f4, 128);
}
