/*
 * function: func_021C84BC
 * address:  0x021C84BC
 * packet:   pkt_021C84BC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_021C84BC   0x021C84BC  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   func_021CE668   0x021CE668  arm  ov016
 *   func_021CE6F0   0x021CE6F0  arm  ov016
 *   dat_021DA708   0x021DA708  data
 *   dat_021DA6D8   0x021DA6D8  data
 *   dat_021DA6F0   0x021DA6F0  data
 *   dat_021DB580   0x021DB580  data
 *   dat_0207E51C   0x0207E51C  data
 *   dat_021DB594   0x021DB594  data
 *   dat_0207F1E0   0x0207F1E0  data
 *   dat_021DB5AC   0x021DB5AC  data
 *   dat_0207F0B8   0x0207F0B8  data
 *   dat_0207E3D0   0x0207E3D0  data
 *   dat_021DB5C4   0x021DB5C4  data
 *   dat_0207ECF0   0x0207ECF0  data
 *   dat_021DE5EC   0x021DE5EC  data
 *
 * PARKED: 14 bytes differ and they are ALL in the last six instructions, which
 * is the only residue.  Everything from the three byte-pair prologue copies
 * (0x2b / 0x16 / 0, sizes 0x17, 0x15 and 0x16 -- the two odd copies end with
 * the trailing byte) through the five func_021BD1D4 calls, the three
 * func_021D4B68 publishes into the record at 0x021DE5EC+8, the masked
 * 0x0400000C write and the whole 0x04001008 / 0x04000008 / 0x0400000A /
 * 0x0400000C tail is byte for byte right, 508 bytes compiled = 508 listed.
 * The image puts the 0x04001008 constant in r1 and the published record
 * pointer in r2; the compiler takes r1 for the record pointer and r3 for the
 * constant, and consequently hoists the two derived addresses
 * (sub r2, r1, #0x1000 for 0x04000008 and sub r1, r4, #2 for 0x0400000A)
 * three instructions earlier.  The two `sub`s appear either way.
 * Re-spellings tried, each compiled, each identical: the store target as
 * `*(int *)((char *)(*(int **)(G + 8)) + 0x10)`, the value through a local
 * `int r` first, and `p = (u16 *)0x04001008;` hoisted above the publish (both
 * just before the first publish and just before the last).  This is the O39
 * note 2 register-naming class, not a semantic error.
 *
 * Copy three NCL resource paths (0x17, 0x15 and 0x16 bytes, both odd copies
 * ending with a trailing byte) into three stack buffers, poke the 0x0400000C
 * halfword register, load five tilemaps through func_021BD1D4 (one of them
 * from the second buffer), publish all three buffers through
 * func_021BD170/func_021D4B68 into the record held by 0x021DE5EC+8 and
 * repaint the 0x04001008/0x04000008/0x0400000A/0x0400000C register bits.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C84BC.c \
 *       --func func_021C84BC --addr 0x021C84BC --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;

typedef struct { char s[0x17]; } T23;
typedef struct { char s[0x15]; } T21;
typedef struct { char s[0x16]; } T22;

extern void func_021BD1D4(int, int);
extern int func_021BD170(void *);
extern int func_021D4B68(int, int, int);
extern void func_021CE668(int);
extern void func_021CE6F0(void);
extern T23 dat_021DA708;
extern T21 dat_021DA6D8;
extern T22 dat_021DA6F0;
extern unsigned char dat_021DB580[];
extern unsigned char dat_0207E51C[];
extern unsigned char dat_021DB594[];
extern unsigned char dat_0207F1E0[];
extern unsigned char dat_021DB5AC[];
extern unsigned char dat_0207F0B8[];
extern unsigned char dat_0207E3D0[];
extern unsigned char dat_021DB5C4[];
extern unsigned char dat_0207ECF0[];
extern unsigned char dat_021DE5EC[];

void func_021C84BC(void)
{
    T23 buf3;
    T21 buf2;
    T22 buf;
    u16 *p;

    buf3 = dat_021DA708;
    buf2 = dat_021DA6D8;
    buf = dat_021DA6F0;
    p = (u16 *)0x0400000C;
    p[0] = (p[0] & 0x43) | 0x218 | 0xc00;

    func_021BD1D4((int)dat_021DB580, (int)dat_0207E51C);
    func_021BD1D4((int)dat_021DB594, (int)dat_0207F1E0);
    func_021BD1D4((int)dat_021DB5AC, (int)dat_0207F0B8);
    func_021BD1D4((int)&buf2, (int)dat_0207E3D0);
    func_021BD1D4((int)dat_021DB5C4, (int)dat_0207ECF0);

    (*(int **)(dat_021DE5EC + 8))[2] = func_021D4B68(func_021BD170(&buf3), 0, 4);
    func_021CE668((*(int **)(dat_021DE5EC + 8))[2]);
    func_021CE6F0();
    (*(int **)(dat_021DE5EC + 8))[3] = func_021D4B68(func_021BD170(&buf2), 0, 4);
    (*(int **)(dat_021DE5EC + 8))[4] = func_021D4B68(func_021BD170(&buf), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)0x0400000C;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 2;
}
