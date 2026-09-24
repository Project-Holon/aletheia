/*
 * function: func_021C047C
 * address:  0x021C047C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *
 * Ages the counter at +0x1E0 and, when it underflows, hands the halfword at
 * +0x246 to func_021C18C8 with mode 2 and stamps selector 0x9E.  The image
 * branches on the subs flags themselves (bpl), so the condition is the
 * decremented value, written as a prefix -- on the dereference.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021C18C8(char *p, int a, int b);

int func_021C047C(char *p, int v)
{
    if (--*(s32 *)(p + 0x1E0) < 0) {
        func_021C18C8(p, 2, *(u16 *)(p + 0x246));
        *(u32 *)(p + 0x1CC) = 0x9E;
    }

    return v;
}
