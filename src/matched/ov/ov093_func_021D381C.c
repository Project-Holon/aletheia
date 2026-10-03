/*
 * function: func_021D381C
 * address:  0x021D381C
 * packet:   pkt_ov093_021D381C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern void func_021D5EA8(u8 *p, int i, u8 n);

int func_021D381C(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5EA8(m, 1, c[1]);
    func_021D5EA8(m, 2, c[2]);
    func_021D5EA8(m, 3, c[3]);
    func_021D5EA8(m, 4, c[4]);
    func_021D5EA8(m, 5, c[5]);
    func_021D5EA8(m, 6, c[6]);
    func_021D5EA8(m, 7, c[7]);
    return 1;
}
