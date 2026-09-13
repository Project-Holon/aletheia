/*
 * function: sub_0200F824
 * address:  0x0200F824
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F824.c \
 *       --func sub_0200F824 --addr 0x0200F824 --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  func_0203CD98(void);
extern void func_0203CF5C(void);
extern void func_0208459C(u32 a, u32 b);

void sub_0200F824(void)
{
    if (func_0203CD98() == 1) {
        func_0203CF5C();
        func_0208459C(1, 1);
    }
}
