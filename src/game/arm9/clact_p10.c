/*
 * file:     clact_p10.c
 * unit:     yes
 * function: sub_0204D410, sub_0204D444
 * address:  0x0204D410
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 */
struct Rec;
struct Node;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void *(*DispatchFn)(struct Obj *o);

struct Rec *sub_0204D410(struct Obj *o);
void *sub_0204D42C(struct Obj *o);
void *sub_0204D434(struct Obj *o);
void *sub_0204D43C(struct Obj *o);
struct Node *sub_0204D444(struct Obj *o);
void *sub_0204D460(struct Obj *o);
void *sub_0204D468(struct Obj *o);
void *sub_0204D470(struct Obj *o);
extern DispatchFn const gUnk_020A1394[][3];


/*
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


/*
 * The same shape as src/matched/unit_0204D410.c one row over: the thunk
 * dispatches on the object's kind through row 1 of the handler table at
 * 0x020A1394, and the three row-1 handlers are again the +0xc pointer
 * adjustment.  Three unlabelled leaves folded into the unit with the thunk.
 *
 * The base is attested `literal` by the pool word at 0x0204D490, outside
 * this range; see src/matched/func_0204D324.c for the row map.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D444.c \
 *       --addr 0x0204D444 --arm
 */
struct Node *sub_0204D444(struct Obj *o)
{
    return gUnk_020A1394[1][o->type](o);
}


void *sub_0204D460(struct Obj *o)
{
    return &o->unk_0c;
}


void *sub_0204D468(struct Obj *o)
{
    return &o->unk_0c;
}


void *sub_0204D470(struct Obj *o)
{
    return &o->unk_0c;
}
