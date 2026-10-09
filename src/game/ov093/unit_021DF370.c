/*
 * file:     unit_021DF370.c
 * function: func_021DF370, func_021DF390, func_021DF39C
 * address:  0x021DF370
 * packet:   pkt_ov093_021DF370
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021E8878  0x021E8878  thumb  ov093
 *   d_021F15FC     0x021F15FC  data   ov093  a4
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


extern int d_021F15FC[];
int *func_021DF390(int *p);

int *func_021DF390(int *p)
{
    *p = 2;
    return d_021F15FC;
}


void func_021E8878(int a, int b, int c, int d);
void func_021DF39C(int a, int b, int c, int d);

void func_021DF39C(int a, int b, int c, int d)
{
    func_021E8878(a, b, c, d);
}
