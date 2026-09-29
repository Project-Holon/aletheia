/*
 * function: func_021E1434
 * address:  0x021E1434
 * packet:   pkt_ov093_021E1434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, u8 b);
extern int func_021D5BDC(void *p, u32 n);
extern void func_021D7704(int key, s32 m);

void func_021E1434(int a, void *p, int id)
{
    int k;
    if (id == func_021D775C(3)) {
        k = 4;
        if (func_021D5BDC(func_021C7CF4(p, func_021D775C(4)), 4)) {
            func_021D7704(0x35, k << 11);
        }
    }
}
