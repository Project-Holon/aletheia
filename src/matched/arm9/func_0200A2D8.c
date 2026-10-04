/*
 * function: func_0200A2D8
 * address:  0x0200A2D8
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  021DFE00 - same shape as func_0200A2B8's blocker: ov228 labels it, no branch outside this range reaches it.  All 40 bytes right.
 * symbols:
 *   func_021DFE00    0x021DFE00  thumb
 */

typedef unsigned char u8;

extern int  func_0200A350(void);
extern int  func_021DFE00(void *p);
extern int func_02012DD0(u8 *p);

int func_0200A2D8(void *a0, int a1)
{
    if (func_0200A350() == 0) {
        if (func_021DFE00(*(void **)((u8 *)a0 + 8)) != 0)
            return 2;
        return 0;
    }
    return func_02012DD0((u8 *)a1);
}
