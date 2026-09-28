/*
 * function: func_021C57E4
 * address:  0x021C57E4
 * packet:   pkt_ov016_021C57E4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * State tick sibling of func_021C8C88 for the object published at
 * 0x021DE5D8+4: dispatch on func_021CE998(), drive the +0x55/+0x57/+0x58
 * flags and recompute the 0x021DE5D8+2 halfword as
 * func_0207C958(func_021CE984() * o->f40, o->f53).  States 4 and 6 arm the
 * func_021C60EC / func_021C61A4 callback through func_021D7680(..., 0x78).
 * Addresses are Black-image addresses.
 *
 * blocker: the two `bl 0x021CE984` sites cap at MATCH, exactly as in
 * src/pending/ov016_func_021C8C88.c: 0x021CE984 is a real ARM leaf that
 * ov016 never traced a label at (`func_021CE998` at 0x021CE998 is its
 * traced sibling), so label / sole-ref/code cannot fire; naming it
 * `func_021CE984` is refused because ov021 overlaps the address with a
 * thumb label; and every referrer is inside this range.  Everything else is
 * byte-correct, the two call sites are wildcarded.
 * symbols:
 *   dat_021DE5D8  0x021DE5D8  data
 *   func_021BD5A8 0x021BD5A8  arm  ov016
 *   func_021CE998 0x021CE998  arm  ov016
 *   func_021BCB9C 0x021BCB9C  arm  ov016
 *   func_021BCB84 0x021BCB84  arm  ov016
 *   func_021C5D9C 0x021C5D9C  arm  ov016
 *   func_021CFFAC 0x021CFFAC  arm  ov016
 *   func_021C628C 0x021C628C  arm  ov016
 *   func_021D7680 0x021D7680  arm  ov016
 *   func_021C60EC 0x021C60EC  arm  ov016
 *   func_021C61A4 0x021C61A4  arm  ov016
 *   func_0207C958 0x0207C958  arm
 *   func_0207C994 0x0207C994  arm
 */

typedef struct Sub021C57E4 {
    char _38[0x38];
    int f38;
    char _3c[0x40 - 0x3c];
    unsigned short f40;
    char _42[0x51 - 0x42];
    unsigned char f51;
    char _52[0x53 - 0x52];
    unsigned char f53;
    char _54[0x55 - 0x54];
    unsigned char f55;
    char _56[0x57 - 0x56];
    unsigned char f57;
    unsigned char f58;
} Sub021C57E4;

typedef struct Base021C57E4 {
    char _0[2];
    unsigned short f2;
    Sub021C57E4 *o4;
} Base021C57E4;

extern Base021C57E4 dat_021DE5D8;

extern int func_021CE998(void);
extern int sub_ce984(void);
extern void func_021BD5A8(void);
extern void func_021BCB9C(void);
extern void func_021BCB84(void);
extern void func_021C5D9C(void);
extern void func_021CFFAC(int);
extern int func_0207C958(unsigned int, unsigned int);
extern int func_0207C994(unsigned short, int);
extern void func_021C628C(void);
extern int func_021D7680(int, void *, int, int);
extern void func_021C60EC(void);
extern void func_021C61A4(void);

void func_021C57E4(void)
{
    if (dat_021DE5D8.o4->f38 != 0)
        return;
    if (dat_021DE5D8.o4->f55 != 0)
        dat_021DE5D8.o4->f55--;

    switch (func_021CE998()) {
    case 1:
        dat_021DE5D8.o4->f57 = 1;
        func_021BCB9C();
        return;
    case 2:
        if (dat_021DE5D8.o4->f55 != 0)
            return;
        func_021BD5A8();
        dat_021DE5D8.f2 = func_0207C958(
            sub_ce984() * dat_021DE5D8.o4->f40, dat_021DE5D8.o4->f53);
        func_021C5D9C();
        dat_021DE5D8.o4->f55 = 4;
        return;
    case 3: {
        int v;

        dat_021DE5D8.o4->f57 = 0;
        func_021BCB84();
        dat_021DE5D8.f2 = func_0207C958(
            sub_ce984() * dat_021DE5D8.o4->f40, dat_021DE5D8.o4->f53);
        func_021CFFAC(0x13);
        func_021C5D9C();
        v = func_0207C994(dat_021DE5D8.f2, 0x1c);
        if (v == 0) {
            func_021C628C();
            return;
        }
        if (v < 0xe) {
            dat_021DE5D8.o4->f38 = func_021D7680(0, (void *)func_021C60EC, 0, 0x78);
            return;
        }
        dat_021DE5D8.o4->f38 = func_021D7680(0, (void *)func_021C61A4, 0, 0x78);
        return;
    }
    case 4:
        if (dat_021DE5D8.f2 == 0) {
            if (dat_021DE5D8.o4->f58 != 0)
                return;
            func_021CFFAC(9);
            dat_021DE5D8.o4->f58 = 1;
            return;
        }
        func_021CFFAC(0x13);
        dat_021DE5D8.o4->f38 = func_021D7680(0, (void *)func_021C60EC, 0, 0x78);
        return;
    case 6:
        if (dat_021DE5D8.o4->f51 > 4
                && dat_021DE5D8.f2 != dat_021DE5D8.o4->f40)
            goto case6_else;
        if (dat_021DE5D8.o4->f58 != 0)
            return;
        func_021CFFAC(9);
        dat_021DE5D8.o4->f58 = 1;
        return;
    case6_else:
        func_021CFFAC(0x13);
        dat_021DE5D8.o4->f38 = func_021D7680(0, (void *)func_021C61A4, 0, 0x78);
        return;
    case 5:
    case 7:
        dat_021DE5D8.o4->f58 = 0;
        return;
    }
    return;
}
