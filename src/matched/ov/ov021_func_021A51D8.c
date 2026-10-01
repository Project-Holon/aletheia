/*
 * function: func_021A51D8
 * address:  0x021A51D8
 * packet:   pkt_ov021_021A51D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
void func_021A3964(u32 h, int s);

void func_021A51D8(u32 *p, int b, u8 *c)
{
    int a = (*(u32 *)(c + 0x10) == 1) ? 0x14 : 0x10;

    func_0216D410(b, func_02197E7C(*(u16 *)(c + 8), a));
    p[0] = 1;
    func_021A3964(p[3], 1);
}
