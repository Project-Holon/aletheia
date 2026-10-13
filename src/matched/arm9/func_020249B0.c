/*
 * function: PMS_WORD_IsSameGroup
 * address:  0x020249B0
 * packet:   pkt_020249B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf: true when a == b, or when the first of 13 halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 SCRCMD_CheckPmsWordPair (wave A1).
 *
 * symbols:
 *   g_pmsWordSimilarGroups  0x0209F7C8  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Group {
    const u16 *list;
    int count;
} Group;

extern const Group g_pmsWordSimilarGroups[13];

int PMS_WORD_IsSameGroup(u32 a, u16 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 13; i++) {
        for (j = 0; j < g_pmsWordSimilarGroups[i].count; j++) {
            if (a == g_pmsWordSimilarGroups[i].list[j]) {
                for (k = 0; k < g_pmsWordSimilarGroups[i].count; k++) {
                    if (b == g_pmsWordSimilarGroups[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
