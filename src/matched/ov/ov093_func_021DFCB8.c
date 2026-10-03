/*
 * function: func_021DFCB8
 * address:  0x021DFCB8
 * packet:   pkt_ov093_021DFCB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */

extern int func_021D775C(int key);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D76BC(int key, u32 val);
extern u32 func_021C7EC4(u8 *p);

void func_021DFCB8(int a, void *b, int c)
{
    if (func_021C7EC4(b) == 0 && c == func_021D775C(4))
        func_021D76BC(75, 1);
}
