/*
 * function: WIFICLUBACTOR_StartBlinkOnTile
 * address:  0x021B9B24
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_IsFacingEntrance  0x021B9BC4  thumb  ov099
 *   WIFICLUBACTOR_GetCursorTileBelowAttr  0x021B984C  thumb  ov099
 *   WIFICLUBACTOR_StartBlinkScript  0x021BA794  thumb  ov099
 *
 * Toggles bit (state - 3) of the block 0x574 bytes in when the entry test answers 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUBACTOR_IsFacingEntrance(void *p);
extern int WIFICLUBACTOR_GetCursorTileBelowAttr(void *p);
extern void WIFICLUBACTOR_StartBlinkScript(u8 *p, u8 b);

void WIFICLUBACTOR_StartBlinkOnTile(char *p)
{
    if (WIFICLUBACTOR_IsFacingEntrance(p) == 1) {
        s8 x = (s8)WIFICLUBACTOR_GetCursorTileBelowAttr(p);
        s8 y = x - 3;

        WIFICLUBACTOR_StartBlinkScript((u8 *)(p + 0x574), y);
    }
}
