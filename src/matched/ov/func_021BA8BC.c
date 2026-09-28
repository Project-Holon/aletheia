/*
 * function: func_021BA8BC
 * address:  0x021BA8BC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   sub_020452E8  0x020452E8  arm
 *
 * Null-guarded two-step release; always answers 0.  The `adds r4, r0, #0`
 * before the `beq` is the compare, not a copy.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

extern void func_0201F7A8(void *p, int v);
extern void sub_020452E8(void *p);

int func_021BA8BC(void *p)
{
    if (p != 0) {
        func_0201F7A8(p, 0);
        sub_020452E8(p);
    }

    return 0;
}
