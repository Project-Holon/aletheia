/*
 * function: func_021D8CAC
 * address:  0x021D8CAC
 * packet:   pkt_ov093_021D8CAC
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
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern u32 func_021D7B60(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D7704(int a, int b);

void func_021D8CAC(int a, int b, int c)
{
    void *p;
    u32 lim;

    if (b == func_021D775C(3)) {
        p = func_021C7CF4(a, b);
        lim = func_021D7B60(p, 3);
        if (func_021D59B4(p, 13) <= lim) {
            if (c == func_021D775C(22))
                func_021D7704(0x35, 3 << 11);
        }
    }
}
