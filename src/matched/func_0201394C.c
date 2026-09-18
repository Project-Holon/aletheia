/*
 * function: func_0201394C
 * address:  0x0201394C
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202A3FC  0x0202A3FC  thumb
 *
 * zonedata.c.  A one-shot state step: only while the state word is 1 does it
 * advance to 2 and choose a pair of halfword bounds, keyed off a value read
 * through the object's +0x4c pointer.  The 0x470/0x480 pair is built by
 * `movs`+`lsls` (Thumb has no wide immediate), the 0x46b/0x47d pair comes
 * from the literal pool because 0x46b does not fit a Thumb immediate - both
 * spellings are a plain `u16` store of a constant.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201394C.c \
 *       --func func_0201394C --addr 0x0201394C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ZoneData {
    u32 f0;             /* +0x00 */
    u8  pad04[0x14];
    u16 f18;            /* +0x18 */
    u16 f1a;            /* +0x1A */
    u8  pad1c[0x30];
    u8 *f4c;            /* +0x4C */
};

extern u32 func_0202A3FC(u32 v);

void func_0201394C(struct ZoneData *o)
{
    if (o->f0 == 1) {
        o->f0 = 2;
        if (func_0202A3FC(*(u32 *)(o->f4c + 4)) != 0xb) {
            o->f18 = 0x46b;
            o->f1a = 0x47d;
        } else {
            o->f18 = 0x470;
            o->f1a = 0x480;
        }
    }
}
