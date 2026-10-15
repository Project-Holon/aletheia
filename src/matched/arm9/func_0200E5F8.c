/*
 * function: BATTLE_EXAMINATION_GetTrainerSlot
 * address:  0x0200E5F8
 * packet:   pkt_0200E5F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf: element idx of a five-entry array of 0x120 byte
 * records, the base itself when idx is out of range. Filed as the relocation
 * witness for ov021 TRIAL_HOUSE_LoadDeliveredTrainer (wave A1).
 */

typedef unsigned int u32;

char *BATTLE_EXAMINATION_GetTrainerSlot(char *p, u32 idx)
{
    if (idx < 5) {
        p += idx * 0x120;
    }
    return p;
}
