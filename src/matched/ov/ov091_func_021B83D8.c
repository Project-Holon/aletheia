/*
 * function: POKELIST_UpdateInputStage
 * address:  0x021B83D8
 * packet:   pkt_ov091_021B83D8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKELIST_UpdateCursorInput  0x021B8A8C  thumb  ov091
 *   POKELIST_UpdateSwapCommand  0x021B86D8  thumb  ov091
 *   POKELIST_UpdateHealShareCommand  0x021B8758  thumb  ov091
 *   POKELIST_HandleCommand  0x021B8508  thumb  ov091
 */

typedef unsigned char u8;

extern void POKELIST_UpdateCursorInput(u8 *p);
extern void POKELIST_UpdateSwapCommand(u8 *p);
extern void POKELIST_UpdateHealShareCommand(u8 *p);
extern void POKELIST_HandleCommand(u8 *p);

void POKELIST_UpdateInputStage(u8 *p)
{
    switch (p[0xe]) {
    case 0:
        p[0xe] = 1;
        p[0xf] = 4;
        break;
    case 1:
        POKELIST_UpdateCursorInput(p);
        break;
    case 2:
        if (p[0xc] == 3) {
            POKELIST_UpdateSwapCommand(p);
        } else if (p[0xc] == 4) {
            POKELIST_UpdateHealShareCommand(p);
        } else {
            POKELIST_HandleCommand(p);
        }
        break;
    }
}
