/*
 * function: func_021DF51C
 * address:  0x021DF51C
 * packet:   pkt_ov093_021DF51C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D775C(int);
extern void *func_021C7CF4(int, int);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int, int);
void func_021DF51C(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D5444(func_021C7CF4(b, c)) == 0x19)
        func_021D7704(0x35, 2 << 12);
}
