/*
 * function: func_021D8F84
 * address:  0x021D8F84
 * packet:   pkt_ov093_021D8F84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D8E00  0x021D8E00  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D8E7C  0x021D8E7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D8E00(int a, int b);
extern int func_021D775C(int key);
extern int func_021D70A8(void *a);
extern void func_021D8E7C(int u, int a, int b, u8 c, u8 d);

void func_021D8F84(int u, int a, int b, int *p)
{
    int t;

    if (*p != 0 && func_021D8E00(a, b) != 0) {
        if (b == func_021D775C(2)) {
            t = func_021D775C(0x10);
            if (t != func_021D70A8((void *)u))
                func_021D8E7C(u, a, b, 0, 0);
        }
    }
}
