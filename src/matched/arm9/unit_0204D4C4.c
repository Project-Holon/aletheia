/*
 * unit:     yes
 * function: sub_0204D4C4
 * address:  0x0204D4C4
 * packet:   pkt_0204D3C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_020A7F3C  0x020A7F3C  data
 *   sub_020643C4   0x020643C4  arm
 *
 * A dispatch thunk and the first two of the three handlers its table row
 * names, 60 bytes end to end.  Each handler steps the pointer past the
 * object's 0xc-byte header and tail-calls into the G2D layer; a tail call
 * is always a pool word and a `bx`, never a displacement branch, because
 * every function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The handlers save
 * nothing, so disasm.py gives them no labels; they are folded in here
 * rather than left as this thunk's `EXACT*` tail.
 *
 * The thunk forwards two arguments, not one: it allocates r3 then r2 for
 * the table load, leaving r1 alone, where the one-argument form in
 * src/matched/unit_0204D410.c allocates r2 then r1
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * The third handler, sub_0204D500 at 0x0204D500, is deliberately left out
 * of the range: its tail-call target 0x02064B68 is named only by its own
 * pool word, so including it caps the whole unit at MATCH.  It is parked
 * byte-correct in src/pending/sub_0204D500.c, and it graduates when
 * 0x02064B68 does (docs/notes/sub_02064B68.c.txt).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D4C4.c \
 *       --addr 0x0204D4C4 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void (*DispatchFn)(struct Obj *o, u32 arg);

extern DispatchFn const gUnk_020A7F3C[];

struct MultiCellAnim;
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);

void sub_0204D4C4(struct Obj *o, u32 arg)
{
    gUnk_020A7F3C[o->type](o, arg);
}

void sub_0204D4E0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
}

void sub_0204D4F0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
}

