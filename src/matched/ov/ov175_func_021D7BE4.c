/*
 * function: WIFIBATTLEMATCH_NET_CompStepE
 * address: 0x021D7BE4
 * packet: pkt_ov175_021D7BE4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback 0x021D9A1C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult 0x021D9A30 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepE 0x021D7BE4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepF 0x021D7E18 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepJ 0x021D8E30 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepN 0x021D9344 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepK 0x021D8EC8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupCompRecord 0x021D965C thumb ov175
 *   WIFIBATTLEMATCH_NET_StartTradeIconAnim 0x021D97E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsTradeIconReady 0x021D97B8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupRegSprite 0x021D98E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone 0x021D9A08 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompSprite 0x021D99F4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CopyCompBox 0x021D9A50 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepO 0x021D95B0 thumb ov175
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00013.h"
#include "../include/Obj24233.h"
typedef unsigned long u32;
struct Obj;
typedef unsigned char  u8;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32);
extern int func_021E8844(const int *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *,void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepF(u32 sys, int *state, struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_CompStepJ(u32 sys, int *state, char *ctx);
extern void WIFIBATTLEMATCH_NET_CompStepN(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepK(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepO(u32 sys, int *state, char *ctx);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void WIFIBATTLEMATCH_NET_SetupCompRecord(struct Obj *),WIFIBATTLEMATCH_NET_StartTradeIconAnim(char *,u32);
extern u32 WIFIBATTLEMATCH_NET_IsTradeIconReady(char *);
extern void WIFIBATTLEMATCH_NET_SetupRegSprite(u32 *p, int mode);
extern void WIFIBATTLEMATCH_NET_DeleteCompSprite(char *);
extern void WIFIBATTLEMATCH_NET_CopyCompBox(char *,char *);
extern int WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(char *);
void WIFIBATTLEMATCH_NET_CompStepE(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00013 *)p)->f104;
    int v;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:if(((struct Obj00013 *)p)->f1C==0) {
            WIFIBATTLEMATCH_NET_SetupCompRecord((struct Obj *)p);WIFIBATTLEMATCH_NET_StartTradeIconAnim(p,0);*state=2;
        } else *state=3;
        break;
    case 2:if(WIFIBATTLEMATCH_NET_IsTradeIconReady(p)) *state=3;break;
    case 3:func_02040588(0,1);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,74,1);
        func_021E8AB4(sys,4);*state=16;break;
    case 4:WIFIBATTLEMATCH_NET_SetupRegSprite((u32 *)p,3);*state=5;break;
    case 5:v=WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(p);
        if(v!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompSprite(p);
            switch(v) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepJ);break;
    case 7:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepN);*state=8;break;
    case 8:v=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=9;
        else if(v==3) func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:case 2:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 9:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepK);break;
    case 10:WIFIBATTLEMATCH_NET_CopyCompBox(*(char * *)&((struct Obj24233 *)q)->f14,p);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,24,2);
        func_021E8AB4(sys,11);*state=16;break;
    case 11:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepO);*state=12;break;
    case 12:v=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);
        if(v==0) *state=13;
        else if(v==1) *state=13;
        else if(v==3) func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepE);break;
        case 2:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 13:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepF);break;
    case 14:func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,120,1);
        *state=16;func_021E8AB4(sys,15);break;
    case 15:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepK);break;
    case 16:if(func_021E8844((const int *)(((struct Obj00013 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}
