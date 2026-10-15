/*
 * function: BOX2_UI_PickIconSlot
 * address: 0x021EEC6C
 * packet: pkt_ov170_021EEC6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb ov170
 *   BOX2_MAIN_SetSeqParam 0x021DC9B4 thumb ov170
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 */
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
extern void BOX2_UI_MoveCursorBetweenIcons(char *, int, int);
extern void BOX2_MAIN_SetSeqParam(char *p, int v);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
#define WORK(p) (*(char **)((p)+0x2c))
void BOX2_UI_PickIconSlot(char *p, int k, int v)
{
    if (k >= 1 && k <= 4) BOX2_UI_SetMiniIconVisible(p, k-1, 1);
    else BOX2_UI_SetMiniIconVisible(p, 0, 0);
    BOX2_UI_MoveCursorBetweenIcons(WORK(p), k, v);
    BOX2_MAIN_SetSeqParam(WORK(p), (int)BOX2_MAIN_SceneApplyScroll);
    *(int *)(WORK(p)+0xa168) = k;
}
