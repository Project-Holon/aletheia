/*
 * unit:     no
 * function: sub_0204CAE4
 * address:  0x0204CAE4
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02082BCC  0x02082BCC  arm
 *   sub_02063790  0x02063790  arm
 *   sub_020637D4  0x020637D4  arm
 *
 * The constructor for the 0xe4-byte object this packet operates on: wipe
 * it, initialise the two embedded sub-objects at +0x1c and +0x40, set the
 * three 0x1000 scale fields, and fix up the flag word at +0x60.
 *
 * The flag word is one load and one store for three separate bitfield
 * assignments, which is the whole reason this function is worth reading:
 * the 4-bit field at bit 8 is a read-modify-write (`lsl #20; lsr #28; orr
 * #1; lsl #28; ... lsr #20` around a `bic #0xf00`), while the two fields
 * being set to zero collapse into plain `bic`s of their masks.  Only the
 * field whose new value depends on its old one pays for the extract and
 * reinsert.
 *
 * 0x1000 is materialised once into r4 and reused for all three stores; the
 * compiler spreads those stores across the two calls rather than keeping
 * them together, so their position in the listing is not their position in
 * the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CAE4.c \
 *       --func sub_0204CAE4 --addr 0x0204CAE4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8  pad_00[0x14];
    u32 unk_14;
    u32 unk_18;
    u8  unk_1c[0x24];
    u8  unk_40[0x14];
    u32 unk_54;
    u8  pad_58[8];
    u32 flag_lo   : 8;
    u32 mode      : 4;
    u32 flag_mid  : 6;
    u32 kind      : 2;
    u32 flag_hi   : 11;
    u32 done      : 1;
    u8  pad_64[0x80];
};

extern void sub_02082BCC(void *dst, int value, u32 len);
extern void sub_02063790(u32 *p);
extern void sub_020637D4(u32 *p);

void sub_0204CAE4(struct Obj *o)
{
    sub_02082BCC(o, 0, 0xe4);
    o->unk_54 = 0x1000;
    sub_02063790((u32 *)o->unk_1c);
    sub_020637D4((u32 *)o->unk_40);
    o->unk_14 = 0x1000;
    o->unk_18 = 0x1000;
    o->mode |= 1;
    o->done = 0;
    o->kind = 0;
}
