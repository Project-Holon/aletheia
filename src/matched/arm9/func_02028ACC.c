/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_ClaimSlotWithOwner
 * address:  0x02028ACC
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c: the same claim with an owner id supplied by the caller
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * FIELD_SOUND_SYSTEM_TransferSlot is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * symbols:
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 *   SCRCMD_FindRegisteredEntry  0x021D21C0  thumb ov021
 *   SCRCMD_IsRegisteredEntryEnabled  0x021D21E0  thumb ov021
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/FIELD_SOUND_SYSTEM_ClaimSlotWithOwner.c --addr 0x02028ACC --thumb
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

extern int SCRCMD_FindRegisteredEntry(u32 id);
extern int SCRCMD_IsRegisteredEntryEnabled(u32 id);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GFL_USE_PlaySeWithVolume(u32 id, u32 who);
extern void GFL_USE_SetSeSlotVolume(int i, u32 level);

void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(struct SoundSys2 *s, u32 id, u32 who)
{
    u32 n;

    if (SCRCMD_FindRegisteredEntry(id) == 0) {
        GFL_USE_PlaySeDefaultVolume(id);
        return;
    }
    if (SCRCMD_IsRegisteredEntryEnabled(id) != 0) {
        n = GFL_USE_GetSeSlot(id) - 1;
        s->slot[n] = id;
        s->owner[n] = who;
    }
    if (s->unkB4 == 0) {
        GFL_USE_PlaySeWithVolume(id, who);
    }
}
