/*
 * function: FIELD_SOUND_SYSTEM_IsSoundIdPlayable
 * address:  0x02028CB0
 * packet:   pkt_02028BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  02028C30 label
 * blocker:  02028C50 label
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_IsKnownSoundId  0x02028C30  thumb
 *   FIELD_SOUND_SYSTEM_IsSoundRecordChainValid  0x02028C50  thumb
 */

typedef unsigned int u32;

extern int FIELD_SOUND_SYSTEM_IsKnownSoundId(u32 v);
extern u32 FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(int index);

int FIELD_SOUND_SYSTEM_IsSoundIdPlayable(u32 v)
{
    if (FIELD_SOUND_SYSTEM_IsKnownSoundId(v) == 0) {
        return 0;
    }
    if (FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(v) != 0) {
        return 1;
    }
    return 0;
}
