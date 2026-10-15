/*
 * function: BOX2_SEQ_StateSwapApply
 * address: 0x021E35D8
 * packet: pkt_ov170_021E35D8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ResetEntryB 0x021EA858 thumb ov170
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb ov170
 *   BOX2_UI_CloseBar 0x021EF36C thumb ov170
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_SelectSlot 0x021EE754 thumb ov170
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 */
typedef unsigned char u8;
struct WinMgr;
extern void BOX2_SEQ_SetActorDrawEnable(char *,int,int);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ResetEntryB(char *p, int a);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **,int);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
extern void BOX2_UI_MoveCursor(char **,int,int);
extern void BOX2_UI_SelectSlot(u8 *,unsigned);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_UI_ShowWindowB(char *);
#define W(p) (*(char **)((p)+0x2C))
int BOX2_SEQ_StateSwapApply(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(W(p),4,0);
        BOX2_UI_SetMiniIconVisible((char *)p,0,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(W(p)+0xA194))++;
        return BOX2_SEQ_ResetEntryB((char *)p,25);
    case 1:
        BOX2_UI_PutBottomBarClosed(*(struct WinMgr **)(W(p)+0x74));
        BOX2_UI_CloseBar(*(struct WinMgr **)(W(p)+0x74));
        if(p[0x18]==1) BOX2_SEQ_HidePartialSlots((char **)p,1);
        else BOX2_SEQ_HidePartialSlots((char **)p,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(W(p)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_IsWindowBusy,25);
    case 2:
        BOX2_UI_MoveCursor((char **)p,6,30);
        BOX2_UI_SelectSlot(p,30);
        if(p[0x18]==0) BOX2_MAIN_ChangeBoxFormPreserve((char *)p,30);
        BOX2_UI_ShowWindowB(W(p));
        *(int *)(W(p)+0xA168)=30;
        *(int *)(W(p)+0xA194)=0;
        return 32;
    }
    return 25;
}
