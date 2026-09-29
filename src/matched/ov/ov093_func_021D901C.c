/*
 * function: func_021D901C
 * address:  0x021D901C
 * packet:   pkt_ov093_021D901C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D8E00  0x021D8E00  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D8E00(int a, int b);
extern int func_021C8288(int a);
extern int func_021D775C(int key);
extern int func_021B9A24(int a, int b);
extern void func_021D7704(int a, int b);

void func_021D901C(int u, int a, int b)
{
    u8 k;

    if (func_021D8E00(a, b) != 0 && func_021C8288(a) == 1) {
        k = func_021D775C(4);
        if (func_021B9A24(b, k) != 0) {
            if (func_021D775C(0x1a) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}
