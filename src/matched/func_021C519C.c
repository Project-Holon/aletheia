/*
 * function: func_021C519C
 * address:  0x021C519C
 * packet:   pkt_021C519C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C519C   0x021C519C  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   func_021CE668   0x021CE668  arm  ov016
 *   func_021CE6F0   0x021CE6F0  arm  ov016
 *   dat_021DA58C   0x021DA58C  data
 *   dat_021DA574   0x021DA574  data
 *   dat_021DB438   0x021DB438  data
 *   dat_0207ECF0   0x0207ECF0  data
 *   dat_021DE5D8   0x021DE5D8  data
 *
 * Copy a 0x19-byte and a 0x16-byte NCL resource path into two stack buffers
 * (the first copy is odd-sized, so it ends with a trailing byte), load one
 * tilemap through func_021BD1D4, publish both buffers through
 * func_021BD170/func_021D4B68 into the record held by 0x021DE5D8+4, poke
 * func_021CE668/func_021CE6F0 on it, then set the low two bits of the
 * 0x04001008 pair, 0x04000008 and the 0x0400000A triple.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C519C.c \
 *       --func func_021C519C --addr 0x021C519C --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { char s[0x19]; } T25;
typedef struct { char s[0x17]; } T23;
typedef struct { char s[0x16]; } T22;
typedef struct { char s[0x15]; } T21;

extern void func_021BD1D4(int, int);
extern int func_021BD170(void *);
extern int func_021D4B68(int, int, int);

extern T25 dat_021DA58C;
extern T22 dat_021DA574;
extern unsigned char dat_021DB438[];
extern unsigned char dat_0207ECF0[];
extern unsigned char dat_021DE5D8[];

void func_021C519C(void)
{
    T25 buf2;
    T22 buf;
    u16 *p;

    buf2 = dat_021DA58C;
    buf = dat_021DA574;
    func_021BD1D4((int)dat_021DB438, (int)dat_0207ECF0);

    (*(int **)(dat_021DE5D8 + 4))[1] = func_021D4B68(func_021BD170(&buf2), 0, 4);
    func_021CE668((*(int **)(dat_021DE5D8 + 4))[1]);
    func_021CE6F0();
    (*(int **)(dat_021DE5D8 + 4))[2] = func_021D4B68(func_021BD170(&buf), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 2;
    p[1] = (p[1] & ~3) | 3;
    p[2] = (p[2] & ~3) | 2;
}
