/*
 * function: func_021C8C88
 * address:  0x021C8C88
 * packet:   pkt_ov016_021C8C88
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * State tick for the object published at 0x021DE5EC+8: bail out while the
 * pending-action word at +0x38 is set, decrement the +0x41 delay, then
 * dispatch on func_021CE998() through an 8-entry table.  State 2/3 recompute
 * the 0x021DE5EC+4 halfword as (func_021CE984() * 0x91) / 55; states 4 and 6
 * arm/complete the callback at 0x021C9D78 / 0x021C9E3C with the 0x78-height
 * func_021D7680; states 5/7 clear the +0x46 flag.  Addresses are Black-image
 * addresses.
 *
 * blocker: the two `bl 0x021CE984` sites cap at MATCH.  0x021CE984 is a real
 * ARM leaf (ldr pool; ldr; ldrb [r0,#0x1a]; bx lr, the sibling of the traced
 * func_021CE998 at 0x021CE998) but ov016 never traced a label at it -- it
 * emits those four instructions as a `.word` run (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), so label /
 * sole-ref/code cannot fire.  It must not be named `func_021CE984` either:
 * ov021 overlaps the address with a thumb `func_021CE984` label, so any
 * arm-declared symbol there is refused as an ISA conflict.  The only
 * image-wide referrers are the call sites inside this range, so no outside
 * witness exists.  Everything else is byte-correct; the two call sites are
 * wildcarded, hence MATCH not EXACT.
 * symbols:
 *   dat_021DE5EC  0x021DE5EC  data
 *   func_021BD5A8 0x021BD5A8  arm  ov016
 *   func_021CE998 0x021CE998  arm  ov016
 *   func_021C91F4 0x021C91F4  arm  ov016
 *   func_021CFFAC 0x021CFFAC  arm  ov016
 *   func_021CA030 0x021CA030  arm  ov016
 *   func_021D7680 0x021D7680  arm  ov016
 *   func_021C9D78 0x021C9D78  arm  ov016
 *   func_021C9E3C 0x021C9E3C  arm  ov016
 *   func_0207C994 0x0207C994  arm
 */

typedef struct Sub021C8C88 {
    char _38[0x38];
    int f38;
    char _3c[0x41 - 0x3c];
    unsigned char f41;
    char _42[0x45 - 0x42];
    unsigned char f45;
    unsigned char f46;
} Sub021C8C88;

typedef struct Base021C8C88 {
    char _0[4];
    unsigned short f4;
    char _6[2];
    Sub021C8C88 *o8;
} Base021C8C88;

extern Base021C8C88 dat_021DE5EC;

extern int func_021CE998(void);
extern int sub_ce984(void);
extern void func_021BD5A8(void);
extern void func_021C91F4(void);
extern void func_021CFFAC(int);
extern int func_0207C994(unsigned short, int);
extern void func_021CA030(void);
extern int func_021D7680(int, void *, int, int);
extern void func_021C9D78(void);
extern void func_021C9E3C(void);

void func_021C8C88(void)
{
    if (dat_021DE5EC.o8->f38 != 0)
        return;
    if (dat_021DE5EC.o8->f41 != 0)
        dat_021DE5EC.o8->f41--;

    switch (func_021CE998()) {
    case 1:
        dat_021DE5EC.o8->f45 = 1;
        return;
    case 2:
        if (dat_021DE5EC.o8->f41 != 0)
            return;
        func_021BD5A8();
        dat_021DE5EC.f4 = sub_ce984() * 0x91 / 55;
        func_021C91F4();
        dat_021DE5EC.o8->f41 = 4;
        return;
    case 3: {
        int v;

        dat_021DE5EC.o8->f45 = 0;
        dat_021DE5EC.f4 = sub_ce984() * 0x91 / 55;
        func_021CFFAC(0x13);
        func_021C91F4();
        v = func_0207C994(dat_021DE5EC.f4, 0x1d);
        if (v == 0) {
            func_021CA030();
            return;
        }
        if (v < 0x10) {
            dat_021DE5EC.o8->f38 = func_021D7680(0, (void *)func_021C9D78, 0, 0x78);
            return;
        }
        dat_021DE5EC.o8->f38 = func_021D7680(0, (void *)func_021C9E3C, 0, 0x78);
        return;
    }
    case 4:
        if (dat_021DE5EC.f4 == 0) {
            if (dat_021DE5EC.o8->f46 != 0)
                return;
            func_021CFFAC(9);
            dat_021DE5EC.o8->f46 = 1;
            return;
        }
        func_021CFFAC(0x13);
        dat_021DE5EC.o8->f38 = func_021D7680(0, (void *)func_021C9D78, 0, 0x78);
        return;
    case 6:
        if (dat_021DE5EC.f4 == 0x91) {
            if (dat_021DE5EC.o8->f46 != 0)
                return;
            func_021CFFAC(9);
            dat_021DE5EC.o8->f46 = 1;
            return;
        }
        func_021CFFAC(0x13);
        dat_021DE5EC.o8->f38 = func_021D7680(0, (void *)func_021C9E3C, 0, 0x78);
        return;
    case 5:
    case 7:
        dat_021DE5EC.o8->f46 = 0;
        return;
    }
    return;
}
