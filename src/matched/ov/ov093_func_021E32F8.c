/*
 * function: func_021E32F8
 * address:  0x021E32F8
 * packet:   pkt_ov093_021E32F8
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
 *   func_02018820  0x02018820  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021D5844(void *m);
extern u32 func_02018820(void *p);
extern int func_021D76BC(int key, u32 val);

void func_021E32F8(int u, void *a, int b)
{
    if (b == func_021D775C(3))
        func_021D76BC(0x30, func_02018820(func_021D5844(func_021C7CF4(a, b))));
}
