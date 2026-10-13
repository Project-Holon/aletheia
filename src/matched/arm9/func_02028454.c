/*
 * function: APP_TASKMENU_WIN_TransChar
 * address:  0x02028454
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_TASKMENU_WIN_TransChar.c \\
 *       --func APP_TASKMENU_WIN_TransChar --addr 0x02028454 --thumb --cc 1.1p1
 */
#include "../include/Obj11292.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 v);

void APP_TASKMENU_WIN_TransChar(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj11292 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11292 *)p)->f18));
}
