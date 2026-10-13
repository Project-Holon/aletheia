/*
 * function: POKELIST_RefreshCursor
 * address:  0x021B8418
 * packet:   pkt_ov091_021B8418
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 *
 * symbols:
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   POKELIST_HasBackButton  0x021B9AB4  thumb  ov091
 *   PLIST_MENU_ButtonWinSetActive  0x021BBE5C  thumb  ov091
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern int POKELIST_IsItemMode(u32 p);
extern int POKELIST_HasBackButton(u8 *p);
extern void PLIST_MENU_ButtonWinSetActive(int h, int f);
extern void POKELIST_MoveCursorToPlate(u8 *p, int v);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

#define W(o) (*(int *)(p + (o)))

void POKELIST_RefreshCursor(u8 *p)
{
    W(0x2c) = *(int *)(W(0x280) + 0x3c);
    p[0xe] = 0;
    W(0x3c) = 0x17;
    if (POKELIST_IsItemMode((u32)p) == 1) {
        PLIST_MENU_ButtonWinSetActive(W(0x108), 0);
        PLIST_MENU_ButtonWinSetActive(W(0x10c), 0);
    }
    if (W(8) == 0) {
        if (W(0x2c) <= 5) {
            POKELIST_MoveCursorToPlate(p, W(0x2c));
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
        } else {
            PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        if (W(0x2c) <= 5) {
            if (p[0xc] == 3) {
                PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            }
        } else {
            PLIST_MENU_ButtonWinSetActive(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 0);
        }
    }
    func_0204B3DC((struct Obj *)W(0x1e4), W(0x14));
    if (POKELIST_IsItemMode((u32)p) == 1 || POKELIST_HasBackButton(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
}
