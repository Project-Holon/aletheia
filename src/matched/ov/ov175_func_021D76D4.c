/*
 * function: WIFIBATTLEMATCH_NET_CompStepRegisterParty
 * address: 0x021D76D4
 * packet: pkt_ov175_021D76D4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_SetupCompStatusWindow 0x021D965C thumb
 *   WIFIBATTLEMATCH_NET_DrawCompStatusWindow 0x021D97E4 thumb
 *   WIFIBATTLEMATCH_NET_SetupCompPartyWindow 0x021D9874 thumb
 *   WIFIBATTLEMATCH_NET_IsCompStatusWindowReady 0x021D97B8 thumb
 *   WIFIBATTLEMATCH_NET_IsCompPartyWindowReady 0x021D98CC thumb
 *   WIFIBATTLEMATCH_NET_SetupCompChoiceMenu 0x021D98E4 thumb
 *   WIFIBATTLEMATCH_NET_PollCompChoiceMenu 0x021D9A08 thumb
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu 0x021D99F4 thumb
 *   WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle 0x021D98D8 thumb
 *   WIFIBATTLEMATCH_NET_DeleteCompPartyWindow 0x021D98B8 thumb
 *   WIFIBATTLEMATCH_NET_CopyCompBox 0x021D9A50 thumb
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   WIFIBATTLEMATCH_NET_SetupPostData 0x021DCB58 thumb
 *   WIFIBATTLEMATCH_NET_HttpRapPost 0x021DCC28 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   WIFIBATTLEMATCH_NET_SetupGdbUpload 0x021DBC04 thumb
 *   WIFIBATTLEMATCH_NET_GdbUpdateRecord 0x021DBDAC thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_NET_GetGsProfileId 0x021DD020 thumb
 *   WIFIBATTLEMATCH_NET_SetupHttpRap 0x021DC8B4 thumb
 *   WIFIBATTLEMATCH_NET_HttpRapSend 0x021DC908 thumb
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb
 *   WIFIBATTLEMATCH_NET_CompStepMainMenu 0x021D7BE4 thumb
 *   WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit 0x021D8EC8 thumb
 */
#include "../include/Obj00013.h"
typedef unsigned int u32;
typedef struct { unsigned char a,b,c,d; u32 id; } Request;
typedef struct {char pad[0x48];u32 slots[6];} SlotView;
struct Obj;
extern void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_DrawCompStatusWindow(char *,unsigned);
extern void WIFIBATTLEMATCH_NET_SetupCompPartyWindow(char *);
extern unsigned WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(char *);
extern int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(char *);
extern void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *p, int mode);
extern int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *);
extern int WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(char *);
extern void WIFIBATTLEMATCH_NET_CopyCompBox(char *,char *);
typedef unsigned char  u8;
struct Obj;
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
extern int REGULATION_NoOp(unsigned);
typedef signed int     s32;
struct Big;
struct Rec1E;
struct RecBig;
struct Reg2;
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void WIFIBATTLEMATCH_NET_SetupPostData(char *,void *,int);
struct Record;
extern int WIFIBATTLEMATCH_NET_HttpRapPost(char *p, u8 *out);
extern u32 POKEPARTY_GetCount(void *p);
extern void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p, u32 mode, struct Record *src);
extern int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void *func_0200BAF4(int a0, int a1);
extern void BATTLE_BOX_SetLockFlags(struct Obj *p, u32 v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void REGULATION_BuildParty(int,int);
extern u32 func_020307B0(void *p);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(unsigned char *);
extern void MI_CpuFill8(void *,int,unsigned);
extern unsigned WIFIBATTLEMATCH_NET_GetGsProfileId(char *);
extern void WIFIBATTLEMATCH_NET_SetupHttpRap(char *,void *,unsigned);
extern int WIFIBATTLEMATCH_NET_HttpRapSend(char *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned,unsigned);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepMainMenu(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(u32 sys, int *state, char *p);
#define W(k) (*(u32 *)(p+(k)))
void WIFIBATTLEMATCH_NET_CompStepRegisterParty(u32 sys,int *state,char *p)
{
    u32 *ctx=(u32 *)W(0x104);
    int r,i,n,empty;
    char *rec;
    void *box;
    u32 saved,tmp,out;
    Request request;
    switch(*state) {
    case 0: WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct Obj *)p); WIFIBATTLEMATCH_NET_DrawCompStatusWindow(p,2); WIFIBATTLEMATCH_NET_SetupCompPartyWindow(p); *state=1; break;
    case 1: r=1; r &= WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(p); r &= WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(p); if(r) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x41,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); *state=30; break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,2); *state=4; break;
    case 4: r=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p); if(r!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p); switch(r) {case 0:*state=12;break;case 1:*state=5;break;}} break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x44,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); *state=30; break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,0); *state=7; break;
    case 7: r=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p); if(r!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p); switch(r) {case 0:*state=8;break;case 1:*state=2;break;}} break;
    case 8: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x45,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); *state=30; break;
    case 9: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)p,0); *state=10; break;
    case 10: r=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(p); if(r!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p); switch(r) {case 0:*state=11;break;case 1:*state=2;break;}} break;
    case 11: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(p)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(p); *state=29;} break;
    case 12:
        rec=(char *)ctx[5]; WIFIBATTLEMATCH_NET_CopyCompBox(rec,p);
        if(POKEPARTY_GetBattleReadyCount(rec+0xd4)==0) *state=14;
        else {out=0; if(POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(W(0x108)),rec+0xd4,&out)==0) *state=15; else *state=13;}
        break;
    case 13: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x49,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 14: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x61,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 15: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(p)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(p); *state=16;} break;
    case 16: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x46,2); WIFIBATTLEMATCH_UTIL_SetRequest(sys,17); *state=30; break;
    case 17:
        WIFIBATTLEMATCH_NET_SetupPostData((char *)W(0x34),(void *)(ctx[5]+0xd4),1);
        MI_CpuFill8(p+0x44,0,0x9c); *state=18; break;
    case 18:
        r=WIFIBATTLEMATCH_NET_HttpRapPost((char *)W(0x34),(u8 *)(p+0x44));
        if(r==1) {
            n=POKEPARTY_GetCount((void *)(ctx[5]+0xd4)); empty=0;
            for(i=0;i<n;i++) if(((SlotView *)p)->slots[i]==0) empty++;
            if(((struct Obj00013 *)p)->f44==0 && empty==n) *state=20; else *state=19;
        } else if(r==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 19: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x47,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 20: if(*(u32 *)ctx[8]==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)W(0x34),0,(void *)(ctx[5]+0xd4));*state=21;} break;
    case 21:
        r=WIFIBATTLEMATCH_NET_GdbUpdateRecord((char *)W(0x34));
        if(r==1) {*(u32 *)((u32 *)W(0x104))[8]=0x708; *state=22;}
        if(r!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 22:
        saved=(u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2])); box=BATTLE_BOX_GetFromSave((void *)saved);
        tmp=(u32)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave((void *)saved),0);
        saved=(u32)func_0200BAF4((int)box,0x8056); BATTLE_BOX_SetLockFlags(box,1);
        REGULATION_Card_SetValue((struct Reg2 *)W(0x108),10,2); REGULATION_BuildParty(tmp,saved); func_020307B0((void *)saved);
        *state=23; break;
    case 23: GAME_DATA_SaveStart(*(u32 *)ctx[2]); *state=24; break;
    case 24: r=GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2]); if(r==2) *state=25; else if(r==3) *state=29; break;
    case 25:
        MI_CpuFill8(&request,0,8); request.b=2; request.id=WIFIBATTLEMATCH_NET_GetGsProfileId((char *)W(0x34));
        ((unsigned char *)((u32 *)W(0x104))[12])[5]=2;
        WIFIBATTLEMATCH_NET_SetupHttpRap((char *)W(0x34),&request,87); *state=26; break;
    case 26:
        r=WIFIBATTLEMATCH_NET_HttpRapSend((char *)W(0x34)); if(r==1) *state=27; else if(r==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;} break;
    case 27: WIFIBATTLEMATCH_NET_DrawCompStatusWindow(p,0); WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x48,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,28); *state=30; break;
    case 28: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMainMenu); break;
    case 29: ctx[1]=0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 30: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)W(0x2c))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
