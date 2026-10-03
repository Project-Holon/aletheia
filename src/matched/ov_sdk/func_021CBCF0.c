/*
 * function: func_021CBCF0
 * address:  0x021CBCF0
 * packet:   pkt_021CBCF0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CBCF0   0x021CBCF0  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   func_021D603C   0x021D603C  arm  ov016
 *   dat_021DA7BC   0x021DA7BC  data
 *   dat_021DB708   0x021DB708  data
 *   dat_0207E51C   0x0207E51C  data
 *   dat_021DB71C   0x021DB71C  data
 *   dat_0207F0B8   0x0207F0B8  data
 *   dat_021DB734   0x021DB734  data
 *   dat_0207E3D0   0x0207E3D0  data
 *   dat_021DB74C   0x021DB74C  data
 *   dat_0207EB78   0x0207EB78  data
 *   dat_021DE60C   0x021DE60C  data
 *
 * Copy a 0x16-byte NCL resource path into a stack buffer, load four
 * tilemaps through func_021BD1D4, publish the buffer through
 * func_021BD170/func_021D4B68 into the record held by 0x021DE60C+4, poke
 * func_021D603C, then set the low two bits of the 0x04001008 and
 * 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CBCF0.c \
 *       --func func_021CBCF0 --addr 0x021CBCF0 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T22;

extern void func_021BD1D4(int, int);
extern int func_021BD170(void *);
extern int func_021D4B68(int, int, int);
extern void func_021D603C(int lcd, int plane);

extern T22 dat_021DA7BC;
extern unsigned char dat_021DB708[];
extern unsigned char dat_0207E51C[];
extern unsigned char dat_021DB71C[];
extern unsigned char dat_0207F0B8[];
extern unsigned char dat_021DB734[];
extern unsigned char dat_0207E3D0[];
extern unsigned char dat_021DB74C[];
extern unsigned char dat_0207EB78[];
extern unsigned char dat_021DE60C[];

void func_021CBCF0(void)
{
    T22 buf;
    u16 *p;
    int r;

    buf = dat_021DA7BC;
    func_021BD1D4((int)dat_021DB708, (int)dat_0207E51C);
    func_021BD1D4((int)dat_021DB71C, (int)dat_0207F0B8);
    func_021BD1D4((int)dat_021DB734, (int)dat_0207E3D0);
    func_021BD1D4((int)dat_021DB74C, (int)dat_0207EB78);

    r = func_021D4B68(func_021BD170(&buf), 0, 4);
    *(int *)(*(int *)(dat_021DE60C + 4)) = r;
    func_021D603C(1, 0x10);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
