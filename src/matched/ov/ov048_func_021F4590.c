/*
 * function: GIMMICK_OBJ_ELBOARD_CollectTableHighlights
 * address:  0x021F4590
 * packet:   pkt_ov048_021F4590
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The one-trip outer loop survives only because its int counter is compared
 * against an unsigned (sizeof) bound: `i < 1` or an unsigned counter is
 * folded away as a single pass. Tables: gElboardPlaceTable = {0x0071} (u16),
 * gElboardPlaceKinds = {6,7,8} (u8). FIELDMAP_GetZoneWeatherId returns int (its own file); the
 * u8 local is what emits the lsls/lsrs #24.
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_ClearHighlights  0x021F44B8  thumb  ov048
 *   FIELDMAP_GetZoneWeatherId  0x02188C70  thumb  ov021
 *   gElboardPlaceTable     0x021F4E5C  data  a2
 *   gElboardPlaceKinds     0x021F4E5E  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void GIMMICK_OBJ_ELBOARD_ClearHighlights(u8 *);
extern int FIELDMAP_GetZoneWeatherId(int *p, int b);
extern u16 gElboardPlaceTable[1];
extern u8 gElboardPlaceKinds[3];

void GIMMICK_OBJ_ELBOARD_CollectTableHighlights(int *p, u8 *out)
{
    int i, j, n;

    GIMMICK_OBJ_ELBOARD_ClearHighlights(out);
    n = 0;
    for (i = 0; i < sizeof(gElboardPlaceTable) / sizeof(gElboardPlaceTable[0]); i++) {
        u16 v = gElboardPlaceTable[i];
        u8 r = FIELDMAP_GetZoneWeatherId((int *)p[1], v);

        for (j = 0; j < sizeof(gElboardPlaceKinds); j++) {
            if (r == gElboardPlaceKinds[j]) {
                if (n >= 4)
                    break;
                ((u16 *)out)[n] = v;
                out[8 + n] = r;
                n++;
            }
        }
    }
}
