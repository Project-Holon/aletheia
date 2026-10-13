/*
 * unit:     yes
 * function: CLACT_GetAnimCtrl
 * address:  0x0204D410
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactAnimFuncTable  0x020A1394  data
 *   CLACT_GetAnimCtrl   0x0204D410  arm
 *   CLACT_GetCellAnimCtrl   0x0204D42C  arm
 *   CLACT_GetMultiCellAnimCtrl   0x0204D434  arm
 *   CLACT_GetVramAnimCtrl   0x0204D43C  arm
 *
 * One index-dispatch thunk plus the three handlers it dispatches to, 52
 * bytes end to end with no padding.  The object's first word is a small
 * kind index, and row 7 of the handler table at 0x020A1394 holds the three
 * implementations, which are all the same pointer adjustment to +0xc.
 * They save nothing, so disasm.py gives them no labels and they used to be
 * this function's `EXACT*` tail; as a unit they are four real entries.
 *
 * The register pair the load uses names the arity: this one allocates r2
 * then r1, leaving r1 free, so the thunk forwards only r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * `blx` plus `push {r3, lr}` rather than a tail `bx` is the ordinary
 * non-tail form: the result is returned unchanged, which is what lets
 * CLACT_SetAnimFrame write through it directly.
 *
 * This file was parked at MATCH* while 0x020A13E8 was read as a table
 * object of its own, which left the ABS32 without a witness.  It is row 7
 * of the one eight-by-three array based at 0x020A1394; see
 * src/matched/CLACT_SetAnimSeq.c for the row map and the reasoning.  The base
 * is attested `literal` by the pool word at 0x0204D490, outside this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D410.c \
 *       --addr 0x0204D410 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void *(*DispatchFn)(struct Obj *o);

extern DispatchFn const g_ClactAnimFuncTable[][3];

struct Rec;

struct Rec *CLACT_GetAnimCtrl(struct Obj *o)
{
    return g_ClactAnimFuncTable[7][o->type](o);
}

void *CLACT_GetCellAnimCtrl(struct Obj *o)
{
    return &o->unk_0c;
}

void *CLACT_GetMultiCellAnimCtrl(struct Obj *o)
{
    return &o->unk_0c;
}

void *CLACT_GetVramAnimCtrl(struct Obj *o)
{
    return &o->unk_0c;
}
