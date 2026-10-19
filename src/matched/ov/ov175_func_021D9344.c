/*
 * function: WIFIBATTLEMATCH_NET_CompStepWithdrawEntry
 * address: 0x021D9344
 * packet: pkt_ov175_021D9344
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupCompChoiceMenu 0x021D98E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu 0x021D99F4 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollCompChoiceMenu 0x021D9A08 thumb ov175
 *   WIFIBATTLEMATCH_NET_DrawCompStatusWindow 0x021D97E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetGsProfileId 0x021DD020 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupHttpRap 0x021DC8B4 thumb ov175
 *   WIFIBATTLEMATCH_NET_HttpRapSend 0x021DC908 thumb ov175
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00781.h"
#include "../include/Obj08278.h"
#include "../include/Obj24288.h"
#include "../include/Obj24292.h"
#include "../include/Obj24293.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct Big;
typedef struct { u8 a,b,c,d; u32 id; } Request;
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *,int,int,int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32),WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *,int),WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *),WIFIBATTLEMATCH_NET_DrawCompStatusWindow(char *,u32);
extern int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *);
extern u32 WIFIBATTLEMATCH_NET_GetGsProfileId(char *);
extern void WIFIBATTLEMATCH_NET_SetupHttpRap(char *,void *,unsigned);
extern int WIFIBATTLEMATCH_NET_HttpRapSend(char *);
extern void *GAME_DATA_GetSaveControl(struct Big *),*BATTLE_BOX_GetFromSave(void *);
typedef signed int     s32;
typedef unsigned short u16;
struct Obj;
struct Reg2;
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int),GAME_DATA_SaveMain(u8 *);
extern void MI_CpuFill8(void *,int,u32);
void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(u32 sys,int *state,char *p) {
    char *ctx=*(char * *)&((struct Obj00781 *)p)->f104;
    int r;
    Request request;
    switch(*state) {
    case 0:
        r=((struct Obj24288 *)(*(char * *)&((struct Obj08278 *)ctx)->f30))->f5;
        if((u8)(r+255)<=1) { ((struct Obj00781 *)p)->f40=1; *state=2; }
        else { ((struct Obj00781 *)p)->f40=2; *state=1; }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,82,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,15); break;
    case 2:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,83,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,5); *state=4; break;
    case 4:
        r=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p);
        if(r!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p); switch(r) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,84,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,5); *state=7; break;
    case 7:
        r=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p);
        if(r!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p); switch(r) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,40,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); break;
    case 9:
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(struct Big ** *)&((struct Obj08278 *)ctx)->f8)),1);
        REGULATION_Card_SetValue((struct Reg2 *)(((struct Obj00781 *)p)->f108),10,4);
        GAME_DATA_SaveStart(**(int * *)&((struct Obj08278 *)ctx)->f8); *state=10; break;
    case 10:
        r=GAME_DATA_SaveMain(**(u8 ** *)&((struct Obj08278 *)ctx)->f8);
        if(r==2) { ((struct Obj00781 *)p)->f40=0; *state=11; }
        else if(r==3) *state=15;
        break;
    case 11:
        WIFIBATTLEMATCH_NET_DrawCompStatusWindow(p,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,81,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,12); break;
    case 12:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,70,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,13); break;
    case 13:
        MI_CpuFill8(&request,0,8); request.b=4;
        request.id=WIFIBATTLEMATCH_NET_GetGsProfileId(*(char * *)&((struct Obj00781 *)p)->f34);
        ((struct Obj24293 *)(*(char * *)&((struct Obj24292 *)(*(char * *)&((struct Obj00781 *)p)->f104))->f30))->f5=4;
        WIFIBATTLEMATCH_NET_SetupHttpRap(*(char * *)&((struct Obj00781 *)p)->f34,&request,87); *state=14; break;
    case 14:
        r=WIFIBATTLEMATCH_NET_HttpRapSend(*(char * *)&((struct Obj00781 *)p)->f34);
        if(r==1) *state=15;
        else if(r==3) { ((struct Obj00781 *)p)->f40=3; *state=15; }
        break;
    case 15: WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
    case 16: if(WIFIBATTLEMATCH_UTIL_GetBusy(*(int * *)&((struct Obj00781 *)p)->f2C)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
