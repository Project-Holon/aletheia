/*
 * function: WIFICLUBACTOR_FindCursorStartTile
 * address:  0x021BA0F8
 * packet:   pkt_ov099_021BA0F8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: declaration order j, n2, i, n1 (stack slots and r4/r5 follow it).
 *
 * symbols:
 *   WF2DMAP_MAP_GetWidth  0x021C47F8  thumb  ov127
 *   WF2DMAP_MAP_GetHeight  0x021C47FC  thumb  ov127
 *   WF2DMAP_MAP_GetCellValue  0x021C4864  thumb  ov127
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef struct {
    char pad00[0x588];
    void *f588;
} W;

extern u16 WF2DMAP_MAP_GetWidth(u16 *p);
extern u16 WF2DMAP_MAP_GetHeight(u16 *p);
extern u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y);

void WIFICLUBACTOR_FindCursorStartTile(W *w, u16 *out)
{
    u32 j;
    u32 n2;
    u32 i;
    u32 n1;

    n1 = WF2DMAP_MAP_GetWidth(w->f588);
    n2 = WF2DMAP_MAP_GetHeight(w->f588);
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            if (WF2DMAP_MAP_GetCellValue(w->f588, i, j) == 0xf) {
                out[0] = i * 16;
                out[1] = j * 16;
                return;
            }
        }
    }
}
