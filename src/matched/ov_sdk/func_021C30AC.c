/*
 * function: func_021C30AC
 * address:  0x021C30AC
 * packet:   pkt_021C30AC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Advances the flag byte g_021DE5A8.f0 and dispatches the indexed record.
 *
 * symbols:
 *   func_0207C994  0x0207C994  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021BD4C8  0x021BD4C8  arm
 *   g_021DE5A8     0x021DE5A8  data
 *   d_021DA4D0     0x021DA4D0  data
 *   d_021DA4D2     0x021DA4D2  data
 *   d_021DA4D4     0x021DA4D4  data
 *   d_021DA4D6     0x021DA4D6  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct G {
    u8 f0;
};

extern int  func_0207C994(int a, int b);
extern void func_021CFFAC(unsigned int v);
extern void func_021BD4C8(int a, int b, int c, int d);
extern struct G g_021DE5A8;
extern u16 d_021DA4D0[][4];
extern u16 d_021DA4D2[][4];
extern u16 d_021DA4D4[][4];
extern u16 d_021DA4D6[][4];

void func_021C30AC(int a)
{
    u8 i;

    if (a == 1)
        g_021DE5A8.f0 = (u8)func_0207C994(g_021DE5A8.f0 + 2, 3);
    else
        g_021DE5A8.f0 = (u8)func_0207C994(g_021DE5A8.f0 + 1, 3);
    func_021CFFAC(8);
    i = g_021DE5A8.f0;
    func_021BD4C8(d_021DA4D0[i][0], d_021DA4D4[i][0],
                  d_021DA4D2[i][0], d_021DA4D6[i][0]);
}
