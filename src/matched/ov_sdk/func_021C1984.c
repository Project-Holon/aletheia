/*
 * function: func_021C1984
 * address:  0x021C1984
 * packet:   pkt_021C1984
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Settles the panel and dispatches the record indexed by dat_021DE59C[0].
 *
 * symbols:
 *   func_021C1A04  0x021C1A04  arm
 *   func_021BD674  0x021BD674  arm
 *   func_021BD060  0x021BD060  arm
 *   func_021D0AB0  0x021D0AB0  arm
 *   func_021BD4C8  0x021BD4C8  arm
 *   func_021C0E40  0x021C0E40  arm
 *   dat_021DE59C   0x021DE59C  data
 *   d_021DA488     0x021DA488  data
 *   d_021DA48A     0x021DA48A  data
 *   d_021DA48C     0x021DA48C  data
 *   d_021DA48E     0x021DA48E  data
 *   func_021C1AE8  0x021C1AE8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_021C1A04(void);
extern void func_021BD674(int x);
extern void func_021BD060(int a, int b, int c);
extern void func_021D0AB0(int x);
extern void func_021BD4C8(int a, int b, int c, int d);
extern void func_021C0E40(unsigned int v);
extern u8   dat_021DE59C[];
extern u16  d_021DA488[][4];
extern u16  d_021DA48A[][4];
extern u16  d_021DA48C[][4];
extern u16  d_021DA48E[][4];
extern void func_021C1AE8(void);

void func_021C1984(void)
{
    u8 i;

    func_021C1A04();
    func_021BD674(0);
    func_021BD060(0x2e, -1, 0);
    func_021D0AB0(4);
    i = dat_021DE59C[0];
    func_021BD4C8(d_021DA488[i][0], d_021DA48C[i][0],
                  d_021DA48A[i][0], d_021DA48E[i][0]);
    func_021C0E40((unsigned int)func_021C1AE8);
}
