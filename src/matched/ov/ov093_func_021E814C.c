/*
 * function: func_021E814C
 * address:  0x021E814C
 * packet:   pkt_ov093_021E814C
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
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, u8 b);
extern int func_021D5814(void *a, int b);
extern int func_021D76BC(int key, u32 val);

void func_021E814C(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_021D5814(func_021C7CF4(b, func_021D775C(4)), 2) != 0)
            func_021D76BC(0x40, 1);
    }
}
