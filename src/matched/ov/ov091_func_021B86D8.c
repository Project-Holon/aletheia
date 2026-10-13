/*
 * function: POKELIST_UpdateSwapCommand
 * address:  0x021B86D8
 * packet:   pkt_ov091_021B86D8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   POKELIST_StartSwapAnimation  0x021B9968  thumb  ov091
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   POKELIST_SetupModeScreen  0x021B7B98  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void POKELIST_StartSwapAnimation(u8 *p);
extern void POKELIST_MoveCursorToPlate(u8 *p, int v);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void POKELIST_SetupModeScreen(u8 *p);
extern void func_020061E4(u32 id);

#define W(o) (*(int *)(p + (o)))

void POKELIST_UpdateSwapCommand(u8 *p)
{
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (p[0xf] == 3 && W(0x2c) == W(0x30)) {
        p[0xf] = 1;
    }
    if (p[0xf] != 1) {
        if (p[0xf] == 3) {
            POKELIST_StartSwapAnimation(p);
        }
    } else {
        W(0x38) = 0;
        p[0xc] = 2;
        POKELIST_MoveCursorToPlate(p, W(0x2c));
        PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        W(0x30) = 9;
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        POKELIST_SetupModeScreen(p);
        func_020061E4(0x551);
    }
}
