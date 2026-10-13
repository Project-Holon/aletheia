/*
 * function: func_02028148
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
 *   python tools/match.py one --src src/matched/func_02028148.c \\
 *       --func func_02028148 --addr 0x02028148 --thumb --cc 1.1p1
 *
 * symbols:
 *   APP_TASKMENU_WIN_Free  0x02028164  thumb
 */
#include "../include/Obj15778.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void APP_TASKMENU_WIN_Free(u8 *p);

void func_02028148(u8 *p)
{
    func_020456F8((struct Descriptor *)(((struct Obj15778 *)p)->f0));
    APP_TASKMENU_WIN_Free(p);
}
