/*
 * unit:     yes
 * function: func_02028B18
 * address:  0x02028B18
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c: hand an already claimed slot to a new owner
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * func_02028B18 is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * symbols:
 *   func_020062BC  0x020062BC  thumb
 *   func_021D21C0  0x021D21C0  thumb ov021
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028B18.c --addr 0x02028B18 --thumb
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

extern int func_021D21C0(u32 id);
extern u32 func_021D21E0(u32 id);
extern int func_02006148(u32 a0);
extern void func_020061E4(u32 id);
extern void func_020061F0(u32 id, u32 who);
extern void func_020062BC(int i, u32 level);

void func_02028B18(struct SoundSys2 *s, u32 id, u32 who)
{
    s32 i;

    if (func_021D21C0(id) != 0) {
        for (i = 0; i < 2; i++) {
            if (s->slot[i] == id) {
                func_020062BC(i + 1, who);
                s->owner[i] = who;
                return;
            }
        }
    }
}
