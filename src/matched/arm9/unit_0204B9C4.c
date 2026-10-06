/*
 * unit:     yes
 * function: func_0204B9C4
 * address:  0x0204B9C4
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204D410  0x0204D410  arm
 *   func_0204D768  0x0204D768  arm
 *   func_0204D7C4  0x0204D7C4  arm
 *
 * Three functions, 0x0204B9C4 / 0x0204BA00 / 0x0204BA10.  Only the first is
 * labelled: the other two save no lr, so `disasm.py` never named them and the
 * extent walk from 0x0204B9C4 runs straight through both
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into this unit because that is the only way they get a manifest
 * entry at all; neither can ever be attested by the `label` class.
 *
 * func_0204B9C4 stores a 4-bit field into the actor's +0x60 word and then
 * pushes the same value into the animation record.  The field is a bitfield,
 * not a mask-and-shift: `lsl #0x1c` followed by `orr ..., lsr #1` is the
 * compiler's insert sequence for width 4 at bit offset 27, where an explicit
 * `(v & 0xf) << 27` would have produced an `and` and a single shift
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The zero arm clears two fields and the non-zero arm writes one, which is
 * what makes the compiler predicate all three stores off the single `cmp r4,
 * #0` instead of branching.
 *
 * func_0204BA00 and func_0204BA10 are tail-call thunks that only re-base the
 * actor pointer onto its +0x68 sub-object.  Each is a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B9C4.c \
 *       --addr 0x0204B9C4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Anim {
    u8  pad_00[8];
    u32 unk_08;   /* 0x08 */
    u8  pad_0c[0x0c];
    u32 unk_18;   /* 0x18 */
};

struct Ctl {
    u8 pad_00[4];
};

struct Actor {
    u8         pad_00[0x60];
    u32        pad_60_lo : 27;
    u32        mode      : 4;    /* 0x60, bits 27..30 */
    u32        pad_60_hi : 1;
    u8         pad_64[4];
    struct Ctl ctl;              /* 0x68 */
};

struct Obj;
struct Rec;
extern struct Rec *func_0204D410(struct Obj *o);
struct Cmd;
extern void         func_0204D768(struct Ctl *c, const struct Cmd *cmd);
extern void         func_0204D7C4(struct Ctl *c);

void func_0204B9C4(struct Actor *a, u32 v)
{
    struct Anim *an;

    a->mode = v;

    an = (struct Anim *)func_0204D410((struct Obj *)(&a->ctl));
    if (v == 0) {
        an->unk_08 = 0;
        an->unk_18 = 0;
    } else {
        an->unk_18 = v;
    }
}

void func_0204BA00(struct Actor *a, const struct Cmd *cmd)
{
    func_0204D768(&a->ctl, cmd);
}

void func_0204BA10(struct Actor *a)
{
    func_0204D7C4(&a->ctl);
}
