/*
 * function: func_02013BDC
 * address:  0x02013BDC
 * packet:   pkt_02013BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02013AD0  0x02013AD0  thumb
 *
 * The only indexed accessor on the zone record: four u16 lanes at record
 * +0x0c, +0x0e, +0x10 and +0x12 selected by a second argument bounded to
 * 0..3, with 0 returned for anything else.  That is what makes those eight
 * bytes one array of four rather than four unrelated fields, and it is the
 * only place in the subsystem where a record field is read by index.
 *
 * The dispatch is the dense PC-relative halfword table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the four
 * displacements in the table at 0x02013BF8 are exactly the four `ldrh r4`
 * encodings, so all four case labels existed and none of them is empty.
 *
 * The zero default is initialised before the call to sub_02013AD0, not in a
 * default arm: `movs r4, #0` sits at +0x04, ahead of the `bl`, which is what
 * lets every arm share one `adds r0, r4, #0` exit instead of carrying its own
 * return (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013BDC.c \
 *       --func func_02013BDC --addr 0x02013BDC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ZoneRec {
    u8  pad00[0x0c - 0x00];
    u16 conn0c;
    u16 conn0e;
    u16 conn10;
    u16 conn12;
};

extern struct ZoneRec *sub_02013AD0(u32 id);

u32 func_02013BDC(u32 id, u32 which)
{
    u16 v = 0;
    struct ZoneRec *r = sub_02013AD0(id);

    switch (which) {
    case 0:
        v = r->conn0c;
        break;
    case 1:
        v = r->conn0e;
        break;
    case 2:
        v = r->conn10;
        break;
    case 3:
        v = r->conn12;
        break;
    }
    return v;
}
