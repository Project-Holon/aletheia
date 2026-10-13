/*
 * unit:     no
 * function: CLACT_SetAnimFrame
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
 *   CLACT_GetAnimCtrl  0x0204D410  arm
 *   CLACT_AddAnimFrame  0x0204D3C4  arm
 *
 * Set the +0x10 field of the record CLACT_GetAnimCtrl resolves for this object,
 * then re-run the object through the CLACT_AddAnimFrame dispatcher with a zero
 * second argument.  Both callees are themselves index-dispatch thunks
 * (`ldr r3,[r0]; ldr r2,[table, r3 lsl 2]; blx r2`), so this function is
 * the C-visible half of a virtual pair.
 *
 * The object pointer is kept in r5 across the first call rather than
 * recomputed, which is what forces the four-register push: r4 holds the
 * incoming second argument over the same call.
 *
 * This is the missing witness for src/pending/CLACT_SetActorAnimFrame.c, whose only
 * unresolved site is the ABS32 pool word naming 0x0204D3A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetAnimFrame.c \
 *       --func CLACT_SetAnimFrame --addr 0x0204D3A0 --cc 1.1p1 --arm
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

extern struct Rec *CLACT_GetAnimCtrl(struct Obj *o);
extern void *CLACT_AddAnimFrame(struct Obj *o, u32 arg);

void CLACT_SetAnimFrame(struct Obj *o, u32 value)
{
    CLACT_GetAnimCtrl(o)->unk_10 = value;
    CLACT_AddAnimFrame(o, 0);
}
