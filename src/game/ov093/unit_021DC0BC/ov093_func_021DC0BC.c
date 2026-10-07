/*
 * function: func_021DC0BC
 * address:  0x021DC0BC
 * packet:   pkt_ov093_021DC0BC
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 d);
extern void func_021D7704(int a, int b);

void func_021DC0BC(int u, int a, int b)
{
    void *m;
    u32 n;
    if (b == func_021D775C(3)) {
        m = func_021C7CF4((int *)a, b);
        n = func_021D59B4(m, 0xd);
        if (n <= func_021D7B60(m, 2)) {
            func_021D7704(0x35, 2 << 10);
        }
    }
}
