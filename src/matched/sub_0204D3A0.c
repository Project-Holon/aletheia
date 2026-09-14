/*
 * unit:     no
 * function: sub_0204D3A0
 * address:  0x0204D3A0
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204D410  0x0204D410  arm
 *   sub_0204D3C4  0x0204D3C4  arm
 *
 * Set the +0x10 field of the record sub_0204D410 resolves for this object,
 * then re-run the object through the sub_0204D3C4 dispatcher with a zero
 * second argument.  Both callees are themselves index-dispatch thunks
 * (`ldr r3,[r0]; ldr r2,[table, r3 lsl 2]; blx r2`), so this function is
 * the C-visible half of a virtual pair.
 *
 * The object pointer is kept in r5 across the first call rather than
 * recomputed, which is what forces the four-register push: r4 holds the
 * incoming second argument over the same call.
 *
 * This is the missing witness for src/pending/sub_0204B8C4.c, whose only
 * unresolved site is the ABS32 pool word naming 0x0204D3A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D3A0.c \
 *       --func sub_0204D3A0 --addr 0x0204D3A0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8   pad_00[0x10];
    u32  unk_10;
};

struct Obj {
    u8 unk_00[1];
};

extern struct Rec *sub_0204D410(struct Obj *o);
extern void        sub_0204D3C4(struct Obj *o, u32 arg);

void sub_0204D3A0(struct Obj *o, u32 value)
{
    sub_0204D410(o)->unk_10 = value;
    sub_0204D3C4(o, 0);
}
