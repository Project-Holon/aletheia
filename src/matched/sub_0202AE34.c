/*
 * function: func_0202AE34
 * address:  0x0202AE34
 * packet:   pkt_0202AE08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_0202AE04  0x0202AE04  thumb
 *   sub_0202AE60  0x0202AE60  thumb
 */

typedef unsigned int u32;
typedef signed int   s32;

extern u32 sub_0202AE04(void *obj);
extern void sub_0202AE60(void *obj, u32 val);

int func_0202AE34(void *obj)
{
    s32 val = (s32)sub_0202AE04(obj) - 2;

    if (val <= 0) {
        val = 0;
    }

    if (val == (s32)sub_0202AE04(obj)) {
        return 0;
    }

    sub_0202AE60(obj, val);
    return 1;
}
