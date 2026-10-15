/*
 * function: BOX2_SEQ_StateZoomMenu
 * address: 0x021E83C0
 * packet: pkt_ov170_021E83C0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return r0 from BOX2_SEQ_GetActorDrawEnable and BOX2_SEQ_ResetEntryB is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb ov170
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb ov170
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   BOX2_UI_HideWindowA 0x021EF680 thumb ov170
 *   BOX2_SEQ_ResetEntryB 0x021EA858 thumb ov170
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb ov170
 *   BOX2_UI_HideWindowB 0x021EF69C thumb ov170
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb ov170
 *   BOX2_UI_CloseListPack 0x021EF534 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_PrintIndexedMessage 0x021EBC28 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   d_021EF908 0x021EF908 data a4
 */
typedef unsigned char u8;
struct WinMgr;
typedef struct { unsigned short a; unsigned short b; } Ent;
typedef struct { u8 pad[0x1c]; u8 lo : 4; u8 hi : 4; } Flags;
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);
extern void BOX2_SEQ_SetSlotDim(char **, int);
extern void BOX2_SEQ_ShowWindowObject(char *, int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *, int, int);
extern int BOX2_MAIN_IsWindowMoving(char *);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
extern void BOX2_UI_HideWindowA(char *);
extern int BOX2_SEQ_ResetEntryB(char *, int);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_HideWindowB(char *);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
extern void BOX2_SEQ_DrawFrameList(char *, Ent *, unsigned);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotActors(char *, int, int);
extern void BOX2_SEQ_PrintIndexedMessage(u8 *, int, int);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_SEQ_SetCursorFrame(char *, int);
extern Ent d_021EF908[];
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
#define M (*(struct WinMgr **)(W + 0x74))
int BOX2_SEQ_StateZoomMenu(char *p)
{
    switch (S) {
    case 0:
        S++;
        BOX2_SEQ_SetActorDrawEnable(W, 4, 0);
        BOX2_SEQ_SetWindow9((unsigned char *)p, 14, 0);
        BOX2_UI_ToggleSlotPair(W, 0);
        if (BOX2_UI_IsListOpen(M) == 1) {
            if (BOX2_SEQ_GetActorDrawEnable(W, 10) == 1)
                BOX2_SEQ_SetActorDrawEnable(W, 10, 0);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject(W, 24);
            BOX2_MAIN_RefreshCursorBox(p);
            BOX2_UI_OpenListPack(M);
            return BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_IsWindowMoving, 0x5d);
        } else if (BOX2_UI_IsInfoBarOpen(M) == 1) {
            BOX2_UI_SetMiniIconVisible(p, 0, 0);
            BOX2_UI_HideWindowA(W);
            return BOX2_SEQ_ResetEntryB(p, 0x5d);
        } else if (BOX2_UI_IsTopBarOpen(M) == 1) {
            BOX2_UI_HideWindowB(W);
            BOX2_UI_OpenBar(M);
            return BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_IsWindowBusy, 0x5d);
        } else {
            BOX2_UI_HideWindowA(W);
        }
    case 1:
        BOX2_SEQ_DrawFrameList(p, d_021EF908, 4);
        BOX2_UI_CloseListPack(M);
        S++;
        return BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_IsWindowMoving, 0x5d);
    case 2:
        S = 0;
        BOX2_SEQ_SetSlotActors(p, 1, 1);
        BOX2_SEQ_PrintIndexedMessage((u8 *)p, 0, 24);
        BOX2_UI_MoveCursor((char **)p, 10, 0);
        ((Flags *)p)->lo = 0;
        BOX2_SEQ_SetCursorFrame(p, 6);
        return 0x5e;
    }
    return 0x5d;
}
