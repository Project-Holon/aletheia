/*
 * function: NAMEIN_GRAPHIC_CallbackGridAction
 * address: 0x021F47B4
 * packet: pkt_ov194_021F47B4
 * region: ov194
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_GetGridAction 0x021F32D8 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridIndex 0x021F32FC thumb ov194
 *   NAMEIN_GRAPHIC_IsIconAnimDone 0x021F4390 thumb ov194
 *   NAMEIN_GRAPHIC_PrintPokeMsg 0x021F3DE0 thumb ov194
 *   NAMEIN_GRAPHIC_PrintMonMsg 0x021F3E18 thumb ov194
 *   NAMEIN_GRAPHIC_PrintMsg 0x021F3D70 thumb ov194
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 *   NAMEIN_GRAPHIC_AppendCandidate 0x021F21BC thumb ov194
 *   NAMEIN_GRAPHIC_ApplyConversion 0x021F21FC thumb ov194
 *   NAMEIN_GRAPHIC_RevertChar 0x021F22AC thumb ov194
 *   NAMEIN_GRAPHIC_Backspace 0x021F2150 thumb ov194
 *   NAMEIN_GRAPHIC_ClearSecondary 0x021F233C thumb ov194
 *   NAMEIN_GRAPHIC_CommitSecondary 0x021F235C thumb ov194
 *   NAMEIN_GRAPHIC_GetSecondaryLength 0x021F23F8 thumb ov194
 *   NAMEIN_GRAPHIC_IsNameValid 0x021F45A8 thumb ov194
 *   PROF_WORD_FindMatch 0x021F5370 thumb ov194
 *   PROF_WORD_CheckDigitCount 0x021F54CC thumb ov194
 *   NAMEIN_GRAPHIC_CommitName 0x021F4524 thumb ov194
 *   NAMEIN_GRAPHIC_PrintNameStream 0x021F3EF0 thumb ov194
 *   NAMEIN_GRAPHIC_SetCallback 0x021F462C thumb ov194
 *   NAMEIN_GRAPHIC_CallbackWaitPrint 0x021F46F4 thumb ov194
 *   NAMEIN_GRAPHIC_CallbackFadeOut 0x021F46B4 thumb ov194
 *   NAMEIN_GRAPHIC_GetNameForAction 0x021F4480 thumb ov194
 *   NAMEIN_GRAPHIC_ClearPrimary 0x021F2394 thumb ov194
 *   NAMEIN_GRAPHIC_AppendString 0x021F23B8 thumb ov194
 *   NAMEIN_GRAPHIC_UpdateGrid 0x021F31F4 thumb ov194
 *   NAMEIN_GRAPHIC_RefreshInputField 0x021F1FB4 thumb ov194
 *   NAMEIN_GRAPHIC_UpdateIconTouch 0x021F42E8 thumb ov194
 *   NAMEIN_GRAPHIC_IsMsgDrawDone 0x021F3E78 thumb ov194
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01287.h"
#include "../include/Obj01577.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int NAMEIN_GRAPHIC_GetGridAction(char *,u16 *);
extern unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p);
extern u16 NAMEIN_GRAPHIC_GetGridIndex(char *);
extern u32 KEY_GetTrg(void);
extern void NAMEIN_GRAPHIC_PrintPokeMsg(char *,int,u32,u32,u16);
extern void NAMEIN_GRAPHIC_PrintMonMsg(char *,int,void *),NAMEIN_GRAPHIC_PrintMsg(char *,int);
extern int NAMEIN_GRAPHIC_AppendChar(char *,u16);
extern int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, unsigned short b);
extern int NAMEIN_GRAPHIC_ApplyConversion(unsigned char *a, int b);
extern int NAMEIN_GRAPHIC_RevertChar(char *);
extern int NAMEIN_GRAPHIC_Backspace(unsigned char *p);
extern void NAMEIN_GRAPHIC_ClearSecondary(char *);
extern void NAMEIN_GRAPHIC_CommitSecondary(char *);
extern void NAMEIN_GRAPHIC_ClearPrimary(unsigned char *p);
extern void NAMEIN_GRAPHIC_AppendString(char *p, const u16 *q);
typedef unsigned char  u8;
struct U16Vec;
extern u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);
extern int NAMEIN_GRAPHIC_IsNameValid(int);
extern int PROF_WORD_FindMatch(const u32 *cache, const void *input, u16 heap);
extern int PROF_WORD_CheckDigitCount(void *,int,int);
extern int NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b);
extern void NAMEIN_GRAPHIC_CommitName(char *),NAMEIN_GRAPHIC_PrintNameStream(char *,char *,int *,u32),NAMEIN_GRAPHIC_SetCallback(unsigned char *,u32);
extern void NAMEIN_GRAPHIC_CallbackWaitPrint(unsigned char *a, int *state, char *p);
extern void NAMEIN_GRAPHIC_CallbackFadeOut(unsigned char *p, int *state);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void NAMEIN_GRAPHIC_UpdateGrid(char *,char *);
extern int NAMEIN_GRAPHIC_RefreshInputField(u8 *p);
extern void NAMEIN_GRAPHIC_UpdateIconTouch(char *);
extern int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p);
static inline int invert(char *p,int v) { int r=1; if(NAMEIN_GRAPHIC_ApplyConversion((unsigned char *)p,v)==0) r=0; return r; }
void NAMEIN_GRAPHIC_CallbackGridAction(unsigned char *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=NAMEIN_GRAPHIC_GetGridAction(p+0xfc,&selected);
    u16 value=NAMEIN_GRAPHIC_GetGridIndex(p+0xfc);
    if(((struct Obj01287 *)p)->f2C8==1) {
        if(action!=0 || NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(p+0x264))!=0 || (KEY_GetTrg()&~1u)!=0) {
            int *q=*(int * *)&((struct Obj01287 *)p)->f2C4;
            if(q[0]==1) {
                if(q[2]==0) NAMEIN_GRAPHIC_PrintPokeMsg(p+0x230,q[0],((struct Obj01577 *)q)->f4,((struct Obj01577 *)q)->f6,30);
                else NAMEIN_GRAPHIC_PrintMonMsg(p+0x230,q[0],(void *)q[2]);
            } else NAMEIN_GRAPHIC_PrintMsg(p+0x230,q[0]);
            ((struct Obj01287 *)p)->f2C8=0;
        }
    }
    switch(action) {
    case 1: if(NAMEIN_GRAPHIC_AppendChar(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 2: if(NAMEIN_GRAPHIC_AppendCandidate((unsigned char *)(p+0x68),selected,value)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 3: if(invert(p+0x68,0)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 4: if(invert(p+0x68,1)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 10: if(NAMEIN_GRAPHIC_RevertChar(p+0x68)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 5: if(NAMEIN_GRAPHIC_Backspace((unsigned char *)(p+0x68))) GFL_USE_PlaySeDefaultVolume(0x553); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 6: NAMEIN_GRAPHIC_ClearSecondary(p+0x68); break;
    case 11: NAMEIN_GRAPHIC_CommitSecondary(p+0x68); break;
    case 7: if(NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)((int)(p+0x68)))==0) {
        if(NAMEIN_GRAPHIC_IsNameValid((int)p)==0) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(p+0x230,8);((struct Obj01287 *)p)->f2C8=1;}
        else {
            if(PROF_WORD_FindMatch(*(u32 * *)&((struct Obj01287 *)p)->f2CC,p+0x68,30)) GFL_USE_PlaySeDefaultVolume(0x557);
            else if(PROF_WORD_CheckDigitCount(p+0x68,((struct Obj01287 *)p)->f86,30)) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(p+0x230,9);((struct Obj01287 *)p)->f2C8=1;}
            else {
                int *q;
                GFL_USE_PlaySeDefaultVolume(0x54d);NAMEIN_GRAPHIC_CommitName(p);q=*(int * *)&((struct Obj01287 *)p)->f2C4;
                if(q[0]==1 && q[3]!=0) {NAMEIN_GRAPHIC_PrintNameStream(p+0x254,p+0x230,q,30);NAMEIN_GRAPHIC_SetCallback(owner,(u32)NAMEIN_GRAPHIC_CallbackWaitPrint);}
                else NAMEIN_GRAPHIC_SetCallback(owner,(u32)NAMEIN_GRAPHIC_CallbackFadeOut);
            }
        }
    } else {NAMEIN_GRAPHIC_CommitSecondary(p+0x68);GFL_USE_PlaySeDefaultVolume(0x54d);} break;
    case 0: if(NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(p+0x264))) {
        int text=NAMEIN_GRAPHIC_GetNameForAction((u8 *)p,**(int * *)&((struct Obj01287 *)p)->f2C4,30);
        NAMEIN_GRAPHIC_ClearPrimary((unsigned char *)(p+0x68));
        if(text) {NAMEIN_GRAPHIC_AppendString(p+0x68,STRBUF_GetChars((struct U16Vec *)text));STRBUF_Delete((struct U16Vec *)text);}
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } break;
    case 9: NAMEIN_GRAPHIC_CommitSecondary(p+0x68);if(NAMEIN_GRAPHIC_AppendChar(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557);break;
    default: break;
    }
    NAMEIN_GRAPHIC_UpdateGrid(p+0xfc,p+0x68);
    NAMEIN_GRAPHIC_RefreshInputField((u8 *)(p+0x68));
    NAMEIN_GRAPHIC_UpdateIconTouch(p+0x264);
    NAMEIN_GRAPHIC_IsMsgDrawDone((u8 *)(p+0x230));
}
