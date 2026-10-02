/*
 * function: func_021E36C8
 * address:  0x021E36C8
 * packet:   pkt_ov093_021E36C8
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
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B40(void *p);

void func_021E36C8(int u, void *a, int b, int *p)
{
    if (b == func_021D775C(3))
        *p = (func_021D5B40(func_021C7CF4(a, b)) != 0) ? 1 : 0;
}
