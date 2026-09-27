/*
 * function: func_021B86A4
 * address:  0x021B86A4
 * packet:   pkt_021B86A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * near miss: compiles 264 vs 280.  All 17 relocation sites resolve and the
 * call order is right.  Original keeps q in r4 and t in r5 and fits in the
 * 0x1c frame with only r4-r7 saved; 1.1p1 swaps (t->r4, q->r5), spills one
 * more value and pushes r3 (frame 0x20).  best1 leaks into a register instead
 * of the original's [sp+0xc] stack slot.
 *
 * symbols:
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B8514  0x021B8514  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B9434  0x021B9434  thumb
 *   func_021B9404  0x021B9404  thumb
 *   func_021B9278  0x021B9278  thumb
 *   func_021B9280  0x021B9280  thumb
 *   func_021B8674  0x021B8674  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B93D4(int dir);
int func_021B9434(int dir);
int func_021B9404(int dir);
int func_021B9278(u32 a, u32 b, u32 c);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B8674(u8 *p, u32 *q, u32 v);

void func_021B86A4(u8 *t, u32 *q, u32 *out1, u32 *out2, u32 a5, u32 a6)
{
    u8 *row = func_021B87D8(t, *q);
    u8 *res1 = func_021B8514(row, func_021B93D4(q[2]), t, (u16 *)a5, 1);
    u8 *res2 = func_021B8514(row, func_021B9434(q[2]), t, (u16 *)a5, 1);
    u8 *res3 = func_021B8514(row, func_021B9404(q[2]), t, (u16 *)a5, 1);
    int best2 = func_021B9280((u8 *)q, 0,
                              func_021B9278((u32)q, a6, (u32)t), (u8 *)t);
    int best1 = 0;

    if (res1) {
        u32 m = func_021B9278((u32)res1, a6, (u32)t);
        int r = func_021B9280(res1, m, m, (u8 *)t);
        if (r > best2)
            best2 = r;
    }
    if (res2) {
        u32 m = func_021B9278((u32)res2, a6, (u32)t);
        int r = func_021B9280(res2, func_021B8674(t, (u32 *)res2, (u32)row) ? 0 : m,
                              m, (u8 *)t);
        if (r > best1)
            best1 = r;
    }
    if (res3) {
        u32 m = func_021B9278((u32)res3, a6, (u32)t);
        int r = func_021B9280(res3, func_021B8674(t, (u32 *)res3, (u32)row) ? 0 : m,
                              m, (u8 *)t);
        if (r > best1)
            best1 = r;
    }
    *out1 = best1;
    *out2 = best2;
}

