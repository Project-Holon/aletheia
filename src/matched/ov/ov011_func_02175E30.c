/*
 * function: func_02175E30
 * address:  0x02175E30
 * packet:   pkt_ov011_02175E30
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020127B8  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8 v : 6;
} Bf6;

typedef struct {
    u32 w0;
    u32 slot : 4;
} Rec;

extern u8 *func_020127B8(void *a);
extern int func_02012950(void *a, int i);
extern u32 func_02008530(int a);
extern int func_021584F4(u32 a, u32 b);

void func_02175E30(void *a, u8 *b, Rec *c)
{
    u8 *d;
    u32 v;
    int r;
    int t;

    d = func_020127B8(a);
    t = func_02012950(a, ((u8 *)c)[0x34]);
    v = ((Bf6 *)(b + ((u8 *)c)[0x34] * 0x1c + 0xa7))->v;
    r = func_021584F4((u8)v, func_02008530(t));
    if (r == 0x14) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 1;
    } else if (r == 0x15) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 2;
    }
}
