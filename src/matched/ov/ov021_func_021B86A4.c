/*
 * function: func_021B86A4
 * address:  0x021B86A4
 * packet:   pkt_ov021_021B86A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Scores three neighbouring cells (row from func_021B87D8, then one
 * func_021B8514 lookup per direction) against the start cell q.
 * q is read through a const pointer: with a plain `u32 *q` the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * func_021B8514 calls (8 bytes).  Declaration order of row/best1 sets their
 * stack slots (best1 at sp+0xc, row at sp+0x10).
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

u32 *func_021B87D8(u8 *t, u32 idx);
u32 *func_021B8514(u32 *row, int dir, u8 *t, u16 *r, int flag);
int func_021B93D4(int dir);
int func_021B9434(int dir);
int func_021B9404(int dir);
int func_021B9278(const u32 *p, u32 b, u8 *t);
int func_021B9280(const u32 *p, int a, int b, u8 *t);
int func_021B8674(u8 *p, u32 *q, u32 v);

void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6)
{
    u32 *row;
    int best1;
    u32 *res1;
    u32 *res2;
    u32 *res3;
    int best2;
    int m;
    int r;

    best1 = 0;
    row = func_021B87D8(t, q[0]);
    res1 = func_021B8514(row, func_021B93D4(q[2]), t, a5, 1);
    res2 = func_021B8514(row, func_021B9434(q[2]), t, a5, 1);
    res3 = func_021B8514(row, func_021B9404(q[2]), t, a5, 1);
    best2 = func_021B9280(q, 0, func_021B9278(q, a6, t), t);
    if (res1) {
        m = func_021B9278(res1, a6, t);
        r = func_021B9280(res1, m, m, t);
        if (r > best2)
            best2 = r;
    }
    if (res2) {
        m = func_021B9278(res2, a6, t);
        if (func_021B8674(t, res2, (u32)row))
            r = func_021B9280(res2, 0, m, t);
        else
            r = func_021B9280(res2, m, m, t);
        if (r > best1)
            best1 = r;
    }
    if (res3) {
        m = func_021B9278(res3, a6, t);
        if (func_021B8674(t, res3, (u32)row))
            r = func_021B9280(res3, 0, m, t);
        else
            r = func_021B9280(res3, m, m, t);
        if (r > best1)
            best1 = r;
    }
    *out1 = best1;
    *out2 = best2;
}
