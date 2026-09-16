/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * function: func_02028ACC
 * address:  0x02028ACC
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * field_sound_system.c: the same claim with an owner id supplied by the caller
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * func_02028B18 is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_020061F0  0x020061F0  thumb
 *   func_021D21C0  0x021D21C0  thumb
 *   func_021D21E0  0x021D21E0  thumb
 *
 * Why it is capped: the calls to func_021D21C0 (and func_021D21E0) are
 * branches from the ARM9 static module into an overlay-resident address.  All
 * three of src/pending/func_02028A7C.c, src/pending/func_02028ACC.c and
 * src/pending/func_02028B18.c branch to 0x021D21C0 and so ought to attest each
 * other, but the `label` class needs a `func_XXXXXXXX` that `disasm.py` traced
 * at the target, and no arm9 listing carries a label for an overlay address,
 * so the branches are not counted.  This is a tooling gap rather than a
 * missing witness: see the handoff's note that `match.py show` needs
 * `--region` for overlay addresses.  Nothing in the C is in doubt; every
 * concrete byte is right.
 *
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/func_02028ACC.c --addr 0x02028ACC --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct SoundSys2 {
    u16 unk00[0x56];
    u16 slot[2];
    u16 owner[2];
    u32 unkB4;
};

extern u32 func_021D21C0(u32 id);
extern u32 func_021D21E0(u32 id);
extern u32 func_02006148(u32 id);
extern void func_020061E4(u32 id);
extern void func_020061F0(u32 id, u32 who);
extern void func_020062BC(u32 slot, u32 who);

void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who)
{
    u32 n;

    if (func_021D21C0(id) == 0) {
        func_020061E4(id);
        return;
    }
    if (func_021D21E0(id) != 0) {
        n = func_02006148(id) - 1;
        s->slot[n] = id;
        s->owner[n] = who;
    }
    if (s->unkB4 == 0) {
        func_020061F0(id, who);
    }
}
