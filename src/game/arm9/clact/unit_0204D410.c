/*
 * unit:     yes
 * function: sub_0204D410
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
 *   gUnk_020A1394  0x020A1394  data
 *   sub_0204D410   0x0204D410  arm
 *   sub_0204D42C   0x0204D42C  arm
 *   sub_0204D434   0x0204D434  arm
 *   sub_0204D43C   0x0204D43C  arm
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
 * sub_0204D3A0 write through it directly.
 *
 * This file was parked at MATCH* while 0x020A13E8 was read as a table
 * object of its own, which left the ABS32 without a witness.  It is row 7
 * of the one eight-by-three array based at 0x020A1394; see
 * src/matched/func_0204D324.c for the row map and the reasoning.  The base
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

extern DispatchFn const gUnk_020A1394[][3];

struct Rec;

struct Rec *sub_0204D410(struct Obj *o)
{
    return gUnk_020A1394[7][o->type](o);
}

void *sub_0204D42C(struct Obj *o)
{
    return &o->unk_0c;
}

void *sub_0204D434(struct Obj *o)
{
    return &o->unk_0c;
}

void *sub_0204D43C(struct Obj *o)
{
    return &o->unk_0c;
}
