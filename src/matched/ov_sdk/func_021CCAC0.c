/*
 * function: func_021CCAC0
 * address:  0x021CCAC0
 * packet:   pkt_021CCAC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CCAC0   0x021CCAC0  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   dat_021DA800   0x021DA800  data
 *   dat_021DB778   0x021DB778  data
 *   dat_0207F0B8   0x0207F0B8  data
 *   dat_021DB790   0x021DB790  data
 *   dat_0207E3D0   0x0207E3D0  data
 *   dat_021DB7A8   0x021DB7A8  data
 *   dat_0207EB78   0x0207EB78  data
 *   dat_021DE614   0x021DE614  data
 *
 * Copy a 0x16-byte NCL resource path from the static table into a stack
 * buffer, load three tilemaps through func_021BD1D4, publish the buffer
 * through func_021BD170/func_021D4B68 into the 0x021DE614 record, then set
 * the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CCAC0.c \
 *       --func func_021CCAC0 --addr 0x021CCAC0 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T22;

extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *func_021BD170(unsigned char *name);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_021D603C(int lcd, int plane);

extern T22 dat_021DA800;
extern unsigned char dat_021DB778[];
extern unsigned char dat_0207F0B8[];
extern unsigned char dat_021DB790[];
extern unsigned char dat_0207E3D0[];
extern unsigned char dat_021DB7A8[];
extern unsigned char dat_0207EB78[];
extern unsigned char dat_021DE614[];

void func_021CCAC0(void)
{
    T22 buf;
    u16 *p;

    buf = dat_021DA800;
    func_021BD1D4((char *)((int)dat_021DB778), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB790), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB7A8), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));
    ((int *)dat_021DE614)[1] = (int)func_021D4B68((char *)((int)func_021BD170((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
