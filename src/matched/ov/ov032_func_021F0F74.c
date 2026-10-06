/*
 * function: func_021F0F74
 * address:  0x021F0F74
 * packet:   pkt_ov032_021F0F74
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0F74  0x021F0F74  thumb
 *   func_02165CE8  0x02165CE8  thumb  ov010
 *   func_0204A9D0  0x0204A9D0  arm
 *   func_020215BC  0x020215BC  thumb
 *   d_021F3541     0x021F3541  data  ov032  a1
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct PalAnmSlot;
struct S;
struct Sub0204A9D0;
extern u8 func_02165CE8(struct S *p);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u8 d_021F3541[];

void func_021F0F74(char *p, u8 *q, void *r)
{
    int x;

    x = func_02165CE8((struct S *)r);
    func_0204A9D0(*(int *)(((struct Obj00007 *)p)->f158 + q[0] * 4), (struct Sub0204A9D0 *)(*(int *)(p + x * 8 + 0x338)));
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC),
                  (const void *)(*(int *)&((struct Obj00007 *)p)->f3BC + ((d_021F3541[x] & 0xf) << 5)), 3,
                  (u16)((q[0] + 9) << 4), 0x20);
}
