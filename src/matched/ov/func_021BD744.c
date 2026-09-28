/*
 * function: func_021BD744
 * address:  0x021BD744
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *
 * Reads the state word at +0x135C: when it is 2 or 3 runs the 0x7D setup,
 * otherwise the 0x7C one; clears +0x135C and stamps selector 0x8E.  Returns
 * the second argument.  The call is duplicated into both arms in the source -
 * with a computed selector 1.1p1 shares the `movs r2,#0` into r6 and the frame
 * grows to {r4,r5,r6,lr}, which is the tell that the image had two calls.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BAAB8(char *p, int a, int b);

int func_021BD744(char *p, int v)
{
    u32 x = *(u32 *)(p + 0x135C);

    if (x - 2 <= 1) {
        func_021BAAB8(p, 0x7D, 0);
    } else {
        func_021BAAB8(p, 0x7C, 0);
    }

    *(u32 *)(p + 0x135C) = 0;
    *(u32 *)(p + 0x1CC) = 0x8E;
    return v;
}
