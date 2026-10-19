/*
 * function: WIFIBATTLEMATCH_NET_CompStepMainMenu
 * address: 0x021D7BE4
 * packet: pkt_ov175_021D7BE4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback 0x021D9A1C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult 0x021D9A30 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepMainMenu 0x021D7BE4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepMatchmake 0x021D7E18 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepConfirmQuit 0x021D8E30 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepWithdrawEntry 0x021D9344 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit 0x021D8EC8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupCompStatusWindow 0x021D965C thumb ov175
 *   WIFIBATTLEMATCH_NET_DrawCompStatusWindow 0x021D97E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsCompStatusWindowReady 0x021D97B8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupCompChoiceMenu 0x021D98E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollCompChoiceMenu 0x021D9A08 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu 0x021D99F4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CopyCompBox 0x021D9A50 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepPostPartyData 0x021D95B0 thumb ov175
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00013.h"
#include "../include/Obj24233.h"
typedef unsigned long u32;
struct Obj;
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *,void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepMatchmake(u32 sys, int *state, struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_CompStepConfirmQuit(u32 sys, int *state, char *ctx);
extern void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepPostPartyData(u32 sys, int *state, char *ctx);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct Obj *),WIFIBATTLEMATCH_NET_DrawCompStatusWindow(char *,u32);
extern u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(char *);
extern void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *p, int mode);
extern void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *);
extern void WIFIBATTLEMATCH_NET_CopyCompBox(char *,char *);
extern int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *);
void WIFIBATTLEMATCH_NET_CompStepMainMenu(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00013 *)p)->f104;
    int v;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:if(((struct Obj00013 *)p)->f1C==0) {
            WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct Obj *)p);WIFIBATTLEMATCH_NET_DrawCompStatusWindow(p,0);*state=2;
        } else *state=3;
        break;
    case 2:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(p)) *state=3;break;
    case 3:func_02040588(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,74,1);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);*state=16;break;
    case 4:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,3);*state=5;break;
    case 5:v=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p);
        if(v!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p);
            switch(v) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepConfirmQuit);break;
    case 7:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepWithdrawEntry);*state=8;break;
    case 8:v=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=9;
        else if(v==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 9:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 10:WIFIBATTLEMATCH_NET_CopyCompBox(*(char * *)&((struct Obj24233 *)q)->f14,p);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,24,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,11);*state=16;break;
    case 11:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepPostPartyData);*state=12;break;
    case 12:v=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);
        if(v==0) *state=13;
        else if(v==1) *state=13;
        else if(v==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMainMenu);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 13:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMatchmake);break;
    case 14:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,120,1);
        *state=16;WIFIBATTLEMATCH_UTIL_SetRequest(sys,15);break;
    case 15:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 16:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct Obj00013 *)p)->f2C)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}
