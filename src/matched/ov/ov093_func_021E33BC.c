/*
 * function: func_021E33BC
 * address:  0x021E33BC
 * packet:   pkt_ov093_021E33BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B40(void *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D76BC(int key, u32 val);

void func_021E33BC(int u, void *a, int b)
{
    if (b == func_021D775C(3))
        func_021D76BC(0x30, func_021D805C((void *)((u16)func_021D5B40(func_021C7CF4(a, b))), 0xb));
}
