/*
 * function: APP_TASKMENU_WIN_Delete
 * address:  0x02028148
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_TASKMENU_WIN_Delete.c \\
 *       --func APP_TASKMENU_WIN_Delete --addr 0x02028148 --thumb --cc 1.1p1
 *
 * symbols:
 *   APP_TASKMENU_WIN_Free  0x02028164  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 */
#include "../include/Obj15778.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void APP_TASKMENU_WIN_Free(u8 *p);

void APP_TASKMENU_WIN_Delete(u8 *p)
{
    BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj15778 *)p)->f0));
    APP_TASKMENU_WIN_Free(p);
}
