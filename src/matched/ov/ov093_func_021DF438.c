/*
 * function: func_021DF438
 * address:  0x021DF438
 * packet:   pkt_ov093_021DF438
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
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned short u16;
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int key, int m);

void func_021DF438(int self, int a, int b)
{
    u8 v;

    if (b != func_021D775C(3))
        return;
    if (func_021D5444(func_021C7CF4((int *)a, b)) != 0x1e7)
        return;
    v = func_021D775C(0x16);
    if (v == 0xf || v == 7)
        func_021D7704(0x31, 0x1333);
}
