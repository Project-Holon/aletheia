/*
 * function: func_021DC2A0
 * address:  0x021DC2A0
 * packet:   pkt_021DC2A0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *
 * Sibling of func_021DC240 on the +0x148 block: take-and-clear, and when
 *     it was live, feed the object's +0x218 port block, the caller's argument
 *     and the literal 4 to 0x02082D44.
 */

typedef unsigned long u32;

extern void func_02082D44(char *dst, u32 arg, u32 n);

u32 func_021DC2A0(char *obj, u32 arg)
{
    u32 v = *(u32 *)(obj + 0x148);

    if (v != 0) {
        *(u32 *)(obj + 0x148) = 0;
        func_02082D44(obj + 0x218, arg, 4);
    }
    return v;
}

