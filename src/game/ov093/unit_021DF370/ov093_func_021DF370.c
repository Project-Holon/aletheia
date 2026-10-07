/*
 * function: func_021DF370
 * address:  0x021DF370
 * packet:   pkt_ov093_021DF370
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern int func_021DD008(int);
extern void func_021D7704(int, int);
void func_021DF370(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D7704(0x35, func_021DD008(a));
}
