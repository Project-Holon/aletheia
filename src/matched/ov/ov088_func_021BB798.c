/*
 * function: func_021BB798
 * address:  0x021BB798
 * packet:   pkt_ov088_021BB798
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020410D0  0x020410D0  arm
 *   func_0202CF84  0x0202CF84  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BD5EE     0x021BD5EE  data  ov088  a2
 */
#include "../include/Obj20819.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WinMgr;
extern u16 d_021BD5EE[];

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, void *a5, u8 a6,
                          u8 a7, u8 a8, u8 a9);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_02041B6C(u32);

void func_021BB798(char *p, u32 i, u32 arg)
{
    u8 v = arg;
    u16 x = *(u16 *)((char *)d_021BD5EE + i * 4);
    u32 h;
    func_020410D0(2, 3, v, 0x1a, x, *(void **)(p + i * 4 + 0xf8), 0, 0, 0x1a, x);
    h = func_0202CF84(((struct Obj20819 *)p)->f118, i);
    func_020410D0(1, 3, v, 0x1a, x, (void *)h, 0, 0, 0x1a, x);
    func_02041B6C(1);
    func_02041B6C(2);
}
