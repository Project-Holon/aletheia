/*
 * function: func_021D2CE8
 * address:  0x021D2CE8
 * packet:   pkt_ov021_021D2CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: logic right.  The original has three separate `return v` exits
 * and keeps i in r1 / the table in r3; ours merges the found-path returns into
 * one exit.  Tried if/else, ternary and inverted tests.
 *
 * symbols:
 *   d_021DD718     0x021DD718  data  ov021  a4
 *   func_020056EC  0x020056EC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012EBC  0x02012EBC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02012EBC(void *p);
extern void *func_0200C0F0(void *p);
extern int func_0200C234(void *p);
extern u32 func_020056EC(u32 v);
extern u32 d_021DD718[];

u32 func_021D2CE8(void *a, u32 v)
{
    void *h = func_0200C0F0(func_02012EBC(a));
    int i;

    for (i = 0; i < 8; i++) {
        if (v == d_021DD718[i]) {
            return func_0200C234(h) ? v : func_020056EC(0xc) + 0x5a;
        }
    }
    return v;
}
