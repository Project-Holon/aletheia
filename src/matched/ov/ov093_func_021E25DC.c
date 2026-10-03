/*
 * function: func_021E25DC
 * address:  0x021E25DC
 * packet:   pkt_ov093_021E25DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D76BC(int key, u32 val);

void func_021E25DC(int u, int a, int b, int *p)
{
    if (p[6] != 0)
        func_021D76BC(0x41, 1);
}
