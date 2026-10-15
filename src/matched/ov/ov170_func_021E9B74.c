/*
 * function: BOX2_SEQ_StatePmVoiceOpenD
 * address: 0x021E9B74
 * packet: pkt_ov170_021E9B74
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_StopRightBar 0x021EA770 thumb
 *   func_02026124 0x02026124 thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_MAIN_SceneMoveCursor 0x021E072C thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorActor 0x021ED594 thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_StopLeftBar 0x021EA75C thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   data_021EF918 0x021EF918 data a1
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb
 *   func_0202136C 0x0202136C thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb
 *   func_02007F1C 0x02007F1C thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 */
struct WinMgr;
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_SEQ_StopLeftBar(int p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_ShowWindowB(char *);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_DrawFrameList(unsigned char *,const void *,unsigned);
extern const unsigned char data_021EF918[];
extern void BOX2_UI_PutListFrames(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintPrompt(unsigned char *,int,int,int);
extern unsigned func_0202136C(unsigned short);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *,int,int,int);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
extern void BOX2_SEQ_StopRightBar(int p);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void BOX2_SEQ_SwapSlotActors(char *,unsigned);
extern void BOX2_MAIN_SceneMoveCursor(unsigned char *);
extern void BOX2_SEQ_SetSlotDimB(char **p, int i);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
int BOX2_SEQ_StatePmVoiceOpenD(unsigned char *p)
{
    switch(p[0x13]) {
    case 0:
        BOX2_SEQ_DrawFrameList(p,data_021EF918,4);
        BOX2_UI_PutListFrames(*(struct WinMgr **)(WORK+0x74)); BOX2_SEQ_PrintPrompt(p,p[0x16],1,0x18);
        BOX2_UI_MoveCursor((char **)p,0xd,0x25); BOX2_SEQ_RefreshCursorSlot((char *)p); return 0x23;
    case 1:
        BOX2_SEQ_DrawFrameList(p,data_021EF918,4);
        BOX2_UI_PutListFrames(*(struct WinMgr **)(WORK+0x74)); BOX2_SEQ_PrintPrompt(p,p[0x16],1,0x18);
        BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(WORK,0);
        BOX2_UI_MoveCursor((char **)p,0xe,0xa); BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_RefreshCursorSlot((char *)p); return 0x27;
    case 4:
        BOX2_SEQ_StopRightBar((int)p); BOX2_UI_MoveCursor((char **)p,6,p[0x16]);
        func_02026124(*(void **)(WORK+0x70),0x27);
        p[0x16]=0xff; return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((int)p);
        if(p[0x16]<0x1e && p[0x14]!=p[0x17])
            BOX2_SEQ_ShowSlotIcon(p,p[0x17],p[0x16],*(unsigned char *)(WORK+0x3df6));
        else BOX2_SEQ_SwapSlotActors(WORK,p[0x16]);
        BOX2_MAIN_SceneMoveCursor(p); BOX2_SEQ_SetSlotDimB((char **)p,0x24);
        BOX2_UI_MoveCursor((char **)p,6,p[0x1d]); func_02026124(*(void **)(WORK+0x70),0x27);
        BOX2_SEQ_MoveCursorActor((char *)p,0x24); return 0x20;
    }
    return 0;
}
