/*
 * function: func_021C7620
 * address:  0x021C7620
 * packet:   pkt_ov136_021C7620
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * lever: call in each conditional arm keeps p live in r0 and bit test in r1;
 *   inline selector/ternary instead use r0 for test and rebuild p, DIFF17/38.
 * extent: 38 code bytes followed by two zero alignment bytes at021C7646;
 *   next function begins021C7648 outside this inferred40-byte extent.
 *
 * symbols:
 *   func_021C630C 0x021C630C thumb ov136
 *   func_021C71A8 0x021C71A8 thumb ov136
 */

typedef unsigned char u8;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern void func_021C630C(u8 *, unsigned int);
extern int func_021C71A8(char *, int, int);
static inline unsigned int choose(const struct Bf7 *flag)
{
    return flag->w==0 ? 3 : 4;
}
void func_021C7620(u8 *p)
{
    if(((const struct Bf7 *)(p+0x21))->w==0)
        func_021C630C(p,3);
    else
        func_021C630C(p,4);
    func_021C71A8((char *)p, 1, 0x1A);
}
