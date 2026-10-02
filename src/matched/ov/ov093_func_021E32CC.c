/*
 * function: func_021E32CC
 * address:  0x021E32CC
 * packet:   pkt_ov093_021E32CC
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
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02018790  0x02018790  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u32 func_021D5844(void *m);
extern u16 func_02018790(u32 v);
extern int func_021D76BC(int a, int b);

void func_021E32CC(int u, void *a, int b)
{
    if (b == func_021D775C(2))
        func_021D76BC(0x16, func_02018790(func_021D5844(func_021C7CF4(a, b))));
}
