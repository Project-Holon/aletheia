/*
 * function: func_021BBAF8
 * address:  0x021BBAF8
 * packet:   pkt_ov091_021BBAF8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BBC04  0x021BBC04  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 *   func_02027778  0x02027778  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Req {
    u32 heap;
    u8 v;
    u8 *p;
    u32 one;
    u8 c[4];
} Req;

extern void func_021BBC04(u8 *a, u8 *b, int *items);
extern void func_020355D8(u32 a);
extern int func_02027778(Req *r, u32 b);

void func_021BBAF8(u8 *a, u8 *b, int *items)
{
    Req r;

    func_021BBC04(a, b, items);
    r.heap = *(u16 *)a;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x18;
    r.c[2] = 0xd;
    r.c[3] = 3;
    func_020355D8(*(u32 *)(a + 8));
    *(int *)(b + 0x74) = func_02027778(&r, *(u32 *)(a + 0x254));
}
