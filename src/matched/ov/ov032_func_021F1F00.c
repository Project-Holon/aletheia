/*
 * function: func_021F1F00
 * address: 0x021F1F00
 * packet: pkt_ov032_021F1F00
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb ov032
 *   func_021F1F34 0x021F1F34 thumb ov032
 *   func_021F0DD8 0x021F0DD8 thumb ov032
 */
#include "../include/Obj13066.h"

typedef unsigned char u8;
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
extern void func_021F1F34(char *p, u8 *q, int *r);
extern void func_021F0DD8(unsigned int a);
void func_021F1F00(char *p, int a)
{
    u8 *q;
    u8 index;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&((struct Obj13066 *)p)->f3C, a + ((struct Obj13066 *)p)->f7C);
    q = func_021F0F44((u8 *)p, index);
    func_021F1F34(p, q, (int *)(p + 0xa8));
    func_021F0DD8(0x54c);
}
