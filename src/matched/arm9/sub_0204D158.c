/*
 * unit:     no
 * function: sub_0204D158
 * address:  0x0204D158
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206428C  0x0206428C  arm
 *
 * Copy the source's two handles into the object's +4/+8 pair, then bind the
 * record at +0xc to them.
 *
 * The +4 field is read back from memory for sub_0206428C's third argument
 * rather than reused out of r2: the intervening call to sub_020627D8 could
 * alias it, so the cached load does not survive
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, the case
 * without the `const`).
 *
 * sub_020627D8 is called here with an explicit zero in r1, where
 * src/matched/sub_0204D340.c leaves r1 untouched: the two call sites
 * disagree about the arity, and the zero is written out only because this
 * one needs it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D158.c \
 *       --func sub_0204D158 --addr 0x0204D158 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8 unk_00[1];
};

struct Src {
    u8    pad_00[0xc];
    void *unk_0c;
    void *unk_10;
};

struct Obj {
    u8         pad_00[4];
    void      *unk_04;
    void      *unk_08;
    struct Rec unk_0c;
};

struct AnimBank;
struct AnimSequence;
extern struct AnimSequence *sub_020627D8(struct AnimBank *bank, u32 idx);
extern void sub_0206428C(char *self, int a1, char *c);

void sub_0204D158(struct Obj *o, const struct Src *s)
{
    o->unk_04 = s->unk_0c;
    o->unk_08 = s->unk_10;
    sub_0206428C((char *)(&o->unk_0c), (int)sub_020627D8(o->unk_08, 0), o->unk_04);
}
