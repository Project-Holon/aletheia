/*
 * function: func_021C2A3C
 * address:  0x021C2A3C
 * packet:   pkt_021C2A3C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2B00  0x021C2B00  arm
 *   func_021BD674  0x021BD674  arm
 *   func_021D0AB0  0x021D0AB0  arm
 *   func_021BD060  0x021BD060  arm
 *   func_021D5368  0x021D5368  arm
 *   func_021BD4C8  0x021BD4C8  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5A8     0x021DE5A8  data
 *   d_021DA4D0     0x021DA4D0  data
 *   d_021DA4D2     0x021DA4D2  data
 *   d_021DA4D4     0x021DA4D4  data
 *   d_021DA4D6     0x021DA4D6  data
 *   func_021C2C94  0x021C2C94  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G {
    u8  f0;
    u8  f1;
    u8  pad02[6];
    int f8;
};

extern void func_021C2B00(void);
extern void func_021BD674(int x);
extern void func_021D0AB0(int x);
extern void func_021BD060(int a, int b, int c);
extern int  func_021D5368(int a, int b);
extern void func_021BD4C8(int a, int b, int c, int d);
extern void func_021C0E40(unsigned int v);
extern struct G g_021DE5A8;
extern u16 d_021DA4D0[][4];
extern u16 d_021DA4D2[][4];
extern u16 d_021DA4D4[][4];
extern u16 d_021DA4D6[][4];
extern void func_021C2C94(void);

void func_021C2A3C(void)
{
    int q;
    u8 i;

    g_021DE5A8.f1 = 0;
    func_021C2B00();
    func_021BD674(0x10);
    func_021D0AB0(3);
    func_021BD060(0x39, -1, 0);
    g_021DE5A8.f8 = func_021D5368(0, 0x5b);
    q = g_021DE5A8.f8;
    *(u32 *)q = (*(u32 *)q & 0xFE00FF00) | 0x84 | 0xE00000;
    q = g_021DE5A8.f8;
    *(u16 *)(q + 4) = (*(u16 *)(q + 4) & ~0xC00) | 0xC00;
    i = g_021DE5A8.f0;
    func_021BD4C8(d_021DA4D0[i][0], d_021DA4D4[i][0],
                  d_021DA4D2[i][0], d_021DA4D6[i][0]);
    func_021C0E40((unsigned int)func_021C2C94);
}
