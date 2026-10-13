/*
 * function: MONOLITH_TOOL_LIST_Main
 * address: 0x021B9070
 * packet: pkt_ov071_021B9070
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 * symbols:
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0201F184 0x0201F184 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF08 0x0200BF08 thumb
 *   GAME_DATA_GetExitMode 0x02012B58 thumb
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   INTRUDE_COMM_GetWorkIfRunning 0x02158344 thumb ov010
 *   INTRUDE_COMM_SendPairMessage 0x02174660 thumb ov011
 *   func_021B6C7C 0x021B6C7C thumb ov071
 *   MONOLITH_TOOL_UpdateMarker 0x021B9BD8 thumb ov071
 *   MONOLITH_TOOL_UpdateBackButton 0x021B9BAC thumb ov071
 *   MONOLITH_TOOL_LIST_ShowMessage 0x021B9798 thumb ov071
 *   MONOLITH_TOOL_LIST_IsMessageDone 0x021B98B4 thumb ov071
 *   MONOLITH_TOOL_LIST_HideMessage 0x021B98C4 thumb ov071
 *   MONOLITH_TOOL_SetCursor 0x021B9F2C thumb ov071
 *   MONOLITH_TOOL_StartBlink 0x021B7108 thumb ov071
 *   MONOLITH_TOOL_ProcessListInput 0x021B9C7C thumb ov071
 *   MONOLITH_TOOL_ClearPrevHighlight 0x021BA004 thumb ov071
 *   MONOLITH_TOOL_ScrollBy 0x021BA0CC thumb ov071
 *   MONOLITH_TOOL_UpdateBgScroll 0x021BA11C thumb ov071
 *   MONOLITH_TOOL_UpdateRows 0x021BA140 thumb ov071
 *   MONOLITH_TOOL_ApplyCursorChange 0x021BA01C thumb ov071
 *   func_021B6B58 0x021B6B58 thumb ov071
 *   func_021B6C74 0x021B6C74 thumb ov071
 *   func_021B7194 0x021B7194 thumb ov071
 *   func_021B7204 0x021B7204 thumb ov071
 *   func_021B71FC 0x021B71FC thumb ov071
 *   func_021B6C30 0x021B6C30 thumb ov071
 *   func_021B6B98 0x021B6B98 thumb ov071
 *   MONOLITH_TOOL_LIST_ShowFormattedMessage 0x021B9818 thumb ov071
 *   MONOLITH_TOOL_IsBlinking 0x021B7114 thumb ov071
 *   MONOLITH_TOOL_UpdateScrollArrows 0x021B9C30 thumb ov071
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_02034714 0x02034714 arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 */
#include "../include/Obj13181.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { FALSE, TRUE } Bool;
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void func_021B6C7C(int *p, int idx);
extern void MONOLITH_TOOL_UpdateMarker(char *p);
extern void MONOLITH_TOOL_UpdateBackButton(void *p, int a);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef signed int     s32;
typedef unsigned short u16;
struct Big;
struct BigObj;
struct PrintSys;
struct WordSet;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void MONOLITH_TOOL_LIST_ShowMessage(char *a, char *b, u32 c);
extern int MONOLITH_TOOL_LIST_IsMessageDone(u8 *a, u8 *b);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetCont(void);
extern void MONOLITH_TOOL_LIST_HideMessage(char *a);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int MONOLITH_TOOL_SetCursor(u8 *p, int i, int v);
extern int TOUCHPANEL_HitTrg(const void *);
extern void MONOLITH_TOOL_StartBlink(void *);
extern void func_020355D8(u8 v);
extern void MONOLITH_TOOL_ProcessListInput(void *,void *);
extern void MONOLITH_TOOL_ClearPrevHighlight(char *p);
extern int MONOLITH_TOOL_ScrollBy(u8 *p, int d);
extern void MONOLITH_TOOL_UpdateBgScroll(char *p);
extern void MONOLITH_TOOL_UpdateRows(u8 *p);
extern void MONOLITH_TOOL_ApplyCursorChange(void *a, u8 *p);
extern void func_021B6B58(void **p, int v);
extern u8 func_021B6C74(void *,int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_021B7194(int *p, void *arg1, u32 heap);
extern int func_021B7204(int a, int b, void *p, int *q);
extern void func_021B71FC(void *p);
extern void func_021B6C30(int *p, int flag, int index);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern int INTRUDE_COMM_SendPairMessage(int,...);
extern void MONOLITH_TOOL_LIST_ShowFormattedMessage(char *a, char *b, u32 c);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
struct Rec1B0;
extern void func_0200BF08(struct Rec1B0 *p, u32 v);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern void GAME_COMM_PushPairMessage(u32,u32,u32);
extern int MONOLITH_TOOL_IsBlinking(void *);
extern void MONOLITH_TOOL_UpdateScrollArrows(u8 *);
extern const u32 d_021BAAFC[];
extern const u32 d_021BABFC[];
#define W(k) (*(u32 *)(o+(k)))
#define C(k) (*(u32 *)(c+(k)))
#define CP(k) ((u8 *)C(k))
int MONOLITH_TOOL_LIST_Main(int unused,int *state,u8 *c,u8 *o)
{
    u32 initial,handle,mask,save;
    int active,result,off;
    unsigned short flip;
    initial=INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)*(u32 *)CP(0)));
    func_021B6C7C((int *)c,1); func_021B6C7C((int *)c,3);
    MONOLITH_TOOL_UpdateMarker((char *)o); MONOLITH_TOOL_UpdateBackButton(CP(4),(u32)o);
    handle=*(u32 *)(CP(4)+8);
    if (o[0x28c]!=0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)handle,(void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x288))))==0) {
        BMP_WIN_TransferChars((struct Descriptor *)W(0x288)); o[0x28c]=0;
    }
    if (c[0x2e]==1 && *state==4) return 1;
    switch (*state) {
    case 0: *state=1; break;
    case 1: MONOLITH_TOOL_LIST_ShowMessage((char *)o,(char *)CP(4),0x25); ++*state; break;
    case 2:
        if (MONOLITH_TOOL_LIST_IsMessageDone(CP(4),o)==1 && (TOUCHPANEL_GetTrg()!=0 || (KEY_GetTrg()&3))) {
            MONOLITH_TOOL_LIST_HideMessage((char *)o); GFL_USE_PlaySeDefaultVolume(0x547);
            if (TOUCHPANEL_GetTrg()==0) MONOLITH_TOOL_SetCursor(o,1,0);
            else MONOLITH_TOOL_SetCursor(o,0xffff,0);
            ++*state;
        } break;
    case 3:
        if (TOUCHPANEL_GetCont()==0 && !(KEY_GetCont()&3)) *state=4;
        break;
    case 4:
        mask=KEY_GetTrg(); active=TOUCHPANEL_HitTrg(d_021BAAFC);
        if (active==0 || (mask&2)) {
            MONOLITH_TOOL_StartBlink(o+0x298);
            if (active==0) func_020355D8(TRUE);
            else func_020355D8(FALSE);
            GFL_USE_PlaySeDefaultVolume(0x551); *state=17; break;
        }
        MONOLITH_TOOL_ProcessListInput(c,o); MONOLITH_TOOL_ClearPrevHighlight((char *)o);
        off=0x2e0;
        if (MONOLITH_TOOL_ScrollBy(o,W(off)+W(off+4))==1) {
            MONOLITH_TOOL_UpdateBgScroll((char *)o); MONOLITH_TOOL_UpdateRows(o); W(off+16)=1;
        }
        MONOLITH_TOOL_ApplyCursorChange(c,o);
        if (W(0x2f4)==0xffff) { CP(8)[1]=0x30; }
        else {
            CP(8)[1]=*(u32 *)(o+(W(0x2f4)<<2)+0xec);
            CP(8)[2]=*(u32 *)(o+(W(0x2f4)<<2)+0x1b4);
            if (*(u32 *)(o+(W(0x2f4)<<2)+0x1b4)==0) {
                func_021B6B58((void **)(o+8),1); goto selected;
            }
        }
        func_021B6B58((void **)(o+8),0);
selected:
        if (W(0x300)!=0xffff) { GFL_USE_PlaySeDefaultVolume(0x54c); *state=5; }
        break;
    case 5:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            MONOLITH_TOOL_LIST_ShowMessage((char *)o,(char *)CP(4),0x20); ++*state;
        } break;
    case 6:
        if (MONOLITH_TOOL_LIST_IsMessageDone(CP(4),o)==1) {
            if (W(0x310)!=0) func_02034714((const char *)d_021BABFC,0,(const char *)d_021BABFC);
            W(0x310)=(u32)func_021B7194((int *)CP(4),(void *)W(0x30c),0x61); ++*state;
        } break;
    case 7:
        if (func_021B7204(C(4),4,(void *)W(0x310),&result)==1) {
            func_021B71FC((void *)W(0x310)); W(0x310)=0; MONOLITH_TOOL_LIST_HideMessage((char *)o);
            if (result==1) *state=8;
            else { W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3); *state=4; }
        } break;
    case 8:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_0201F184((struct WordSet *)(*(u32 *)(CP(4)+0x10)),0,*(u32 *)(o+(W(0x300)<<2)+0xec));
            MONOLITH_TOOL_LIST_ShowFormattedMessage((char *)o,(char *)CP(4),0x23); *state=9;
        } break;
    case 9:
        if (initial==0) goto write10;
        if (INTRUDE_COMM_SendPairMessage(CP(0)[0x3c])==1) { *state=10; break; }
        break;
write10:
        *state=10;
        break;
    case 10:
        if (MONOLITH_TOOL_LIST_IsMessageDone(CP(4),o)==1) { GFL_USE_FadeOutBgm(6); ++*state; }
        break;
    case 11:
        if (GFL_USE_IsBgmFading()==0) { GFL_USE_SetBgmPlayerParam((void *)1); GFL_USE_PushBgm(); ++*state; }
        break;
    case 12: GFL_USE_CancelChangeAndPlayBgm(0x531,0xffff); ++*state; break;
    case 13:
        if (GFL_USE_IsBgmPlaying()==0) { GFL_USE_PopBgm(); GFL_USE_SetBgmPlayerParam(0); GFL_USE_FadeInBgmFull(6); ++*state; }
        break;
    case 14: if (GFL_USE_IsBgmFading()==0) *state=15; break;
    case 15:
        if (TOUCHPANEL_GetTrg()!=0 || (KEY_GetTrg()&3)) {
            MONOLITH_TOOL_LIST_HideMessage((char *)o);
            func_0200BF08((struct Rec1B0 *)func_0200BE48(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)CP(0))))),*(u32 *)(o+(W(0x300)<<2)+0xec));
            save=GAMESYSTEM_GetGameComm((const struct Ctx *)*(u32 *)CP(0));
            handle=C(0);
            GAME_COMM_PushPairMessage(save,GAME_DATA_GetExitMode(GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj13181 *)handle)->f0))),((struct Obj13181 *)handle)->f3C);
            W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3);
            if (TOUCHPANEL_GetTrg()!=0) *state=16;
            else *state=17;
        } break;
    case 16: if (TOUCHPANEL_GetCont()==0) *state=17; break;
    case 17:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2 && MONOLITH_TOOL_IsBlinking(o+0x298)==0) {
            c[0x2c]=0; return 1;
        } break;
    }
    MONOLITH_TOOL_UpdateScrollArrows(o); return 0;
}
