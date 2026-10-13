/*
 * function: FIELD_BUILDMODEL_UpdateSeasonState
 * address:  0x0218BCF4
 * packet:   pkt_ov021_0218BCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 *   gBuildModelSeasonAnimSlot     0x021D3D50  data  a4
 */

typedef struct {
    int cur;
    int prev;
    int changed;
    unsigned char val;
    unsigned char id;
} S;

extern unsigned char gBuildModelSeasonAnimSlot[];
typedef unsigned int   u32;
u32 TIMEZONE_GetNowTimeZone(u32 row);

void FIELD_BUILDMODEL_UpdateSeasonState(S *p)
{
    p->prev = p->cur;
    p->cur = TIMEZONE_GetNowTimeZone(p->id);
    p->changed = p->cur != p->prev;
    p->val = gBuildModelSeasonAnimSlot[p->cur];
}
