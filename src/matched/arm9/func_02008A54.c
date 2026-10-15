/*
 * function: TRCARD_SIGN_GetBadgeDate
 * address:  0x02008A54
 * packet:   pkt_02008A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * alias: record i of the id 0x21 save block's four-byte table at +0x604,
 * returned by value (see src/matched/unit_020089A8.c for the object layout).
 * The ov111 caller 0x021C7B20 receives it as a struct.  The byte-by-byte
 * assembly into r0, the 1, 0, 2, 3 load order and the 0x605 pool constant
 * are what the compiler emits for returning a byte-aligned 4-byte struct;
 * no hand-written shift/or expression reproduces its register allocation.
 * This sits between unit_020089A8.c and unit_02008A7C.c in one original
 * file; the three can be merged into one unit.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02008A54Rec {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
};

struct Sub02008A54Obj {
    u32 unk000[384];
    u32 unk600;
    struct Sub02008A54Rec unk604[8];
};

struct Sub02008A54Rec TRCARD_SIGN_GetBadgeDate(struct Sub02008A54Obj *obj, int i)
{
    return obj->unk604[i];
}
