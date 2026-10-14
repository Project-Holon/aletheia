/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_TransferSlot
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
 * FIELD_SOUND_SYSTEM_TransferSlot is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * symbols:
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *   FIELD_SOUND_SYSTEM_FindSlotSound  0x021D21C0  thumb ov021
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   FIELD_SOUND_SYSTEM_IsSlotSoundTracked  0x021D21E0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/FIELD_SOUND_SYSTEM_TransferSlot.c --addr 0x02028B18 --thumb
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

extern int FIELD_SOUND_SYSTEM_FindSlotSound(u32 id);
extern u32 FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 id);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GFL_USE_PlaySeWithVolume(u32 id, u32 who);
extern void GFL_USE_SetSeSlotVolume(int i, u32 level);

void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *s, u32 id, u32 who)
{
    s32 i;

    if (FIELD_SOUND_SYSTEM_FindSlotSound(id) != 0) {
        for (i = 0; i < 2; i++) {
            if (s->slot[i] == id) {
                GFL_USE_SetSeSlotVolume(i + 1, who);
                s->owner[i] = who;
                return;
            }
        }
    }
}
