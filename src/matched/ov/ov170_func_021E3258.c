/*
 * function: BOX2_SEQ_StateSummaryClose
 * address: 0x021E3258
 * packet: pkt_ov170_021E3258
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ResetEntryB 0x021EA858 thumb ov170
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb ov170
 *   BOX2_UI_CloseBar 0x021EF36C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 */
typedef unsigned char u8;
struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **,int);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_MAIN_ResetBoxView(char *);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ResetEntryB(char *p, int a);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
extern void BOX2_UI_MoveCursor(char **,int,int);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_SetWindow9(u8 *,int,int);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_UI_ShowWindowB(char *);
#define W(p) (*(char **)((p)+0x2C))
int BOX2_SEQ_StateSummaryClose(u8 *p)
{
    unsigned n;
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p,0);
        BOX2_UI_SetMiniIconVisible((char *)p,0,0);
        BOX2_UI_DeleteSlotObjects((char *)p,0,0,1);
        if(CURSOR_MOVE_GetCurrent(*(void **)(W(p)+0x70))>=30) BOX2_MAIN_ResetBoxView((char *)p);
        (*(int *)(W(p)+0xA194))++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_ResetEntryB((char *)p,22);
    case 1:
        if(p[0x1B]==1) {
            BOX2_UI_PutBottomBarClosed(*(struct WinMgr **)(W(p)+0x74));
            BOX2_UI_CloseBar(*(struct WinMgr **)(W(p)+0x74));
            (*(int *)(W(p)+0xA194))++;
            return BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_IsWindowBusy,22);
        }
        n=CURSOR_MOVE_GetCurrent(*(void **)(W(p)+0x70));
        if(n>=30) n=0;
        BOX2_UI_MoveCursor((char **)p,3,n);
        BOX2_SEQ_SetCursorFrame((char *)p,6);
        BOX2_SEQ_SetWindow9(p,14,1);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p,n);
        *(int *)(W(p)+0xA194)=0;
        return 17;
    case 2:
        BOX2_UI_ShowWindowB(W(p));
        *(int *)(W(p)+0xA194)=0;
        return 33;
    }
    return 22;
}
