/*
 * function: FIELD_GROUND_ANIME_DeleteBuildModel
 * address:  0x021A8234
 * packet:   pkt_ov021_021A8234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb
 */

typedef struct {
    int pad[10];
    int f28;
} S;

extern void FIELD_BUILDMODEL_DeleteNode(int a);

void FIELD_GROUND_ANIME_DeleteBuildModel(S *s)
{
    if (s->f28 != 0) {
        FIELD_BUILDMODEL_DeleteNode(s->f28);
    }
}
