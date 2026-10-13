/*
 * function: FIELD_SUBSCREEN_AnimTask
 * address:  0x021D29A8
 * packet:   pkt_ov021_021D29A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   FIELD_SUBSCREEN_ClearPanelResult  0x021A0FA8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
extern int FIELD_SUBSCREEN_GetPanelResult(u32 link);
extern void FIELD_SUBSCREEN_ClearPanelResult(int *p);

u32 FIELD_SUBSCREEN_AnimTask(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        FIELD_SUBSCREEN_RequestMode(p[1], 9);
        st[0]++;
        break;
    case 1:
        if (FIELD_SUBSCREEN_GetPanelResult(p[1]) == 14) {
            FIELD_SUBSCREEN_ClearPanelResult((int *)p[1]);
            st[0]++;
        }
        break;
    case 2:
        FIELD_SUBSCREEN_RequestMode(p[1], 0);
        return 1;
    }
    return 0;
}
