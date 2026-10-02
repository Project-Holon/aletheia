/*
 * function: func_021E2FB0
 * address:  0x021E2FB0
 * packet:   pkt_ov093_021E2FB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C8288(void *p);
extern int func_021D76BC(int a, int b);

void func_021E2FB0(int u, void *a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021C8288(a) != 0)
            func_021D76BC(0x30, func_021D775C(0x30) * 2);
    }
}
