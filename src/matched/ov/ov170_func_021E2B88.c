/*
 * function: BOX2_SEQ_StateSummary
 * address: 0x021E2B88
 * packet: pkt_ov170_021E2B88
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ResetEntry 0x021EA83C thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_SEQ_SelectBoxSlot 0x021EA114 thumb ov170
 */
typedef unsigned char u8;
typedef struct { u8 lo:4; u8 hi:4; } Nib;
struct WinMgr;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_SEQ_SwapSlotActors(char *,unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **,int);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ResetEntry(char *p, int a);
extern void BOX2_UI_MoveCursor(char **,int,int);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***,unsigned short,int,unsigned,unsigned);
extern void BOX2_SEQ_SetWindow9(u8 *,int,int);
extern int BOX2_SEQ_SelectBoxSlot(char *p, int a);
#define W(p) (*(char **)((p)+0x2C))
#define LO(p) (((Nib *)((p)+0x1C))->lo)
int BOX2_SEQ_StateSummary(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        p[0x19]=p[0x14];
        if(LO(p)==1) {
            p[0x17]=255;
            p[0x16]=func_020260E0(*(void **)(W(p)+0x70));
            if(p[0x16]>=30) {
                p[0x16]=0;
                BOX2_MAIN_ChangeBoxFormPreserve((char *)p,p[0x16]);
            }
        } else {
            p[0x17]=p[0x14];
            BOX2_SEQ_ShowWindowObject(W(p),24);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            BOX2_UI_ShowWindowA(W(p));
            BOX2_SEQ_SwapSlotActors(W(p),p[0x16]);
        }
        BOX2_SEQ_SetCursorDraw((char **)p,0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(W(p)+0x74));
        (*(int *)(W(p)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_IsWindowMoving,20);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(W(p)+0xA194))++;
        return BOX2_SEQ_ResetEntry((char *)p,20);
    case 2:
        BOX2_UI_MoveCursor((char **)p,4,p[0x16]);
        BOX2_SEQ_SetCursorFrame((char *)p,6);
        BOX2_UI_DeleteSlotObjects((char *)p,0,1,0);
        *(int *)(W(p)+0xA168)=p[0x16];
        *(int *)(W(p)+0xA194)=0;
        if(LO(p)==1) {
            if(!BOX2_MAIN_GetPartyValueAt((void ***)p,p[0x16],p[0x14],0xA9,0))
                BOX2_UI_DeleteSlotObjects((char *)p,0,1,2);
            BOX2_SEQ_SetWindow9(p,13,1);
            return 21;
        }
        if(LO(p)==2) BOX2_SEQ_SetWindow9(p,13,1);
        else BOX2_SEQ_SetWindow9(p,14,1);
        return BOX2_SEQ_SelectBoxSlot((char *)p,p[0x16]);
    }
    return 20;
}
