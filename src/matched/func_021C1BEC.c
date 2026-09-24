/*
 * function: func_021C1BEC
 * address:  0x021C1BEC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2090  0x021C2090  thumb  ov099
 *
 * When the flag at +0x8EF is clear and the selector at +0x8F1 is 1, runs
 * func_021C2090 on the block and clears the selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021C2090(void *p);

void func_021C1BEC(u8 *p)
{
    if (p[0x8EF] != 0) {
        return;
    }

    if (p[0x8F1] != 1) {
        return;
    }

    func_021C2090(p);
    p[0x8F1] = 0;
}
