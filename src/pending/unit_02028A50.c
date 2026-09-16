/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * address:  0x02028A50
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 * function: func_02028A50, func_02028A58, func_02028A64, func_02028A70
 *
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters func_02028794 takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * func_02028A50 is why this file exists as its own unit: it is the only caller
 * of func_02028D2C reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * symbols:
 *   func_02028794  0x02028794  thumb
 *   func_02028D2C  0x02028D2C  thumb
 *   func_02029F54  0x02029F54  thumb
 *   func_02029F60  0x02029F60  thumb
 *
 * Why it is capped: all four pool words are the only reference in the image to
 * their target.  func_02028D2C (pkt_02028B50), func_02029F54 and func_02029F60
 * (the packet at 0x02029D44) are reached from nowhere else at all, and
 * func_02028794 is reached only from src/matched/unit_0202878C.c, where it is
 * an interior function and therefore has no manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  A pool word is
 * not a branch, so the `label` class sees nothing, and no cut helps: every one
 * of the four functions here carries exactly one such word.  Three of the four
 * targets are outside pkt_0202878C, so closing this needs another packet's
 * work, not a better source shape here.  It caps src/pending/unit_020298E0.c
 * with it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Fader;

struct SoundSys {
    u8            unk00[0xA4];
    struct Fader *fader;
    void         *ringtone;
};

extern void func_02028D2C(void *sys, void *res);
extern void func_02028794(struct Fader *s, u8 level, u16 frames);
extern void func_02029F54(void *p);
extern void func_02029F60(void *p);

void func_02028A50(void *sys, void *res)
{
    func_02028D2C(sys, res);
}

void func_02028A58(struct SoundSys *sys, u8 level, u16 frames)
{
    func_02028794(sys->fader, level, frames);
}

void func_02028A64(struct SoundSys *sys)
{
    func_02029F54(sys->ringtone);
}

void func_02028A70(struct SoundSys *sys)
{
    func_02029F60(sys->ringtone);
}
