/*
 * function: B_PLIST_MAIN_FinishSwap
 * address: 0x02211810
 * packet: pkt_ov198_02211810
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_UpdateSwapFrames 0x02211420 thumb ov198
 *   B_PLIST_MAIN_HasSwappable 0x0221189C thumb ov198
 *   B_PLIST_ANM_UpdateSelectedTile 0x0220BBF0 thumb ov198
 *   B_PLIST_DRAW_PrintHeader9 0x0220C67C thumb ov198
 *   B_PLIST_DRAW_ShowSubWindow 0x0220E27C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_PLIST_MAIN_UpdateSwapFrames(u8 *);
extern int B_PLIST_MAIN_HasSwappable(u8 *);
extern void B_PLIST_ANM_UpdateSelectedTile(u8 *);
extern void B_PLIST_DRAW_PrintHeader9(char *p);
extern void B_PLIST_DRAW_ShowSubWindow(u8 *p);
int B_PLIST_MAIN_FinishSwap(u8 *p)
{
    if (B_PLIST_MAIN_UpdateSwapFrames(p) == 0) {
        if (B_PLIST_MAIN_HasSwappable(p) == 0) return 31;
        B_PLIST_ANM_UpdateSelectedTile(p);
        B_PLIST_DRAW_PrintHeader9((char *)p);
        B_PLIST_DRAW_ShowSubWindow(p);
        return 3;
    }
    return 9;
}
