/*
 * function: WIFIBATTLEMATCH_NET_CompStepI
 * address: 0x021D8CF0
 * packet: pkt_ov175_021D8CF0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: the two-value tail dispatch is a switch; if (v==1 || v==2) folds into a range and compiles 316/320 bytes.
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
 *   WIFIBATTLEMATCH_NET_CompStepF 0x021D7E18 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepJ 0x021D8E30 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepN 0x021D9344 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepK 0x021D8EC8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupCompChoiceMenu 0x021D98E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollCompChoiceMenu 0x021D9A08 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu 0x021D99F4 thumb ov175
 *   func_02040588 0x02040588 arm
 *   GAME_DATA_SaveStart  0x02012DAC  thumb  arm9
 *   WIFIBATTLEMATCH_NET_CompStepM  0x021D9090  thumb
 *   WIFIBATTLEMATCH_NET_GetSetCompStat  0x021D9D50  thumb
 */
#include "../include/Obj00013.h"
typedef unsigned long u32;
typedef unsigned char  u8;
struct Obj;
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern int GAME_DATA_SaveStart(int a0);
extern int WIFIBATTLEMATCH_NET_GetSetCompStat(char *,u32 *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *,void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *);
extern void WIFIBATTLEMATCH_NET_CompStepK(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepM(u32 sys, int *state, char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *p, int mode);
extern void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *);
extern int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *);
extern void WIFIBATTLEMATCH_NET_CompStepF(u32 sys, int *state, struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_CompStepJ(u32 sys, int *state, char *ctx);
extern void WIFIBATTLEMATCH_NET_CompStepN(u32 sys, int *state, char *p);
void WIFIBATTLEMATCH_NET_CompStepI(u32 sys,int *state,char *p)
{
    int v;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,(void *)1)) {
        case 0:case 1:case 4:*state=1;break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:func_02040588(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,92,1);
        *state=7;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,4);*state=3;break;
    case 3:v=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p);
        if(v!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p);
            switch(v) {
            case 0:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepF);break;
            case 1:*state=4;break;
            case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepJ);break;
            }
        }break;
    case 4:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepN);*state=5;break;
    case 5:v=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=6;
        v=WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj00013 *)p)->f34,0,0);
        switch(v) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }
        break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepK);break;
    case 7:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct Obj00013 *)p)->f2C)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}
