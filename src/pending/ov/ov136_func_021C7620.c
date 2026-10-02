/*
 * function: func_021C7620
 * address:  0x021C7620
 * packet:   pkt_ov136_021C7620
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-02: DIFF. Layout matches. Original computes the bit test into r1 and keeps
 *   r0 = p for the call; ours uses r0 as the test temp and rebuilds r0 from r4.
 *   Tried: ternary both ways, if/else on a local, u8 param, struct pointer param.
 *
 * symbols:
 *   func_021C630C 0x021C630C thumb
 *   func_021C71A8 0x021C71A8 thumb
 */

typedef unsigned char u8;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern void func_021C630C(u8 *, int);
extern int func_021C71A8(u8 *, int, int);
void func_021C7620(u8 *p)
{
    func_021C630C(p, ((struct Bf7 *)(p + 0x21))->w == 0 ? 3 : 4);
    func_021C71A8(p, 1, 0x1A);
}
