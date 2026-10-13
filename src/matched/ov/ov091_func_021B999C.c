/*
 * function: POKELIST_FinishSwap
 * address:  0x021B999C
 * packet:   pkt_ov091_021B999C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   POKELIST_SetupModeScreen  0x021B7B98  thumb  ov091
 */

typedef unsigned char u8;

extern void POKELIST_MoveCursorToPlate(u8 *p, int v);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void POKELIST_SetupModeScreen(u8 *p);

#define W(o) (*(int *)(p + (o)))

void POKELIST_FinishSwap(u8 *p)
{
    W(0x38) = 0;
    p[0xc] = 2;
    POKELIST_MoveCursorToPlate(p, W(0x2c));
    PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x30) = 9;
    *(int *)(W(0x280) + 0x3c) = W(0x2c);
    POKELIST_SetupModeScreen(p);
}
