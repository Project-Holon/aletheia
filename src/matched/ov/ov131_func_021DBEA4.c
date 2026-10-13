/*
 * function: P_STA_OAM_GetCellResMode
 * address: 0x021DBEA4
 * packet: pkt_ov131_021DBEA4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware register read at 021DBEB4
 * symbols:
 *   func_0204AF28 0x0204AF28 arm
 */
#include "../include/Obj23174.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
int P_STA_OAM_GetCellResMode(u8 *p, int screen, u32 owner)
{
    int mode;
    u32 bits;
    bits = *(volatile u32 *)(screen == 0 ? 0x04000000 : 0x04001000) & 0x00300010;
    switch (bits) {
    case 0x00200010: mode = 0; break;
    case 0x00100010: mode = 1; break;
    case 0x10: mode = 2; break;
    default: mode = 0; break;
    }
    if (*(int *)(p + 8 + mode * 4) != -1) return mode;
    *(int *)(p + 8 + mode * 4) = func_0204AF28((void *)owner, 0x4d, 0x80, ((struct Obj23174 *)p)->f4);
    return mode;
}
