/*
 * file:     unit_021DF974.c
 * function: func_021DF974, func_021DF9BC
 * address:  0x021DF974
 * packet:   pkt_ov093_021DF974
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F157C     0x021F157C  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned short u16;
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int key, int m);
extern int func_021DD008(int a);

void func_021DF974(int self, int a, int b)
{
    u8 v;

    if (b != func_021D775C(3))
        return;
    if (func_021D5444(func_021C7CF4((int *)a, b)) != 0x1e4)
        return;
    v = func_021D775C(0x16);
    if (v == 0xf || v == 10)
        func_021D7704(0x31, func_021DD008(self));
}


extern int d_021F157C[];
int *func_021DF9BC(int *p);

int *func_021DF9BC(int *p)
{
    *p = 1;
    return d_021F157C;
}
