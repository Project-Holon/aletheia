/*
 * function: func_021B9634
 * address:  0x021B9634
 * packet:   pkt_ov093_021B9634
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_0201AA18(void *a);
extern void *func_0201AB28(void *a, int i);
extern int func_02017E1C(void *a, int b, int c);

int func_021B9634(void *a)
{
    int i;
    void *e;

    for (i = func_0201AA18(a) - 1; i >= 0; i--) {
        e = func_0201AB28(a, i);
        if (func_02017E1C(e, 0x4c, 0) == 0 && func_02017E1C(e, 0xa0, 0) != 0)
            return i;
    }
    return -1;
}
