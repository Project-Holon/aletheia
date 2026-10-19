/*
 * function: WIFIBATTLEMATCH_NET_CompStepFetchRapPair
 * address: 0x021D6C54
 * packet: pkt_ov175_021D6C54
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092EC 0x020092EC thumb
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_NET_CreateHttpRap 0x021DC738 thumb ov175
 *   WIFIBATTLEMATCH_NET_HttpRapProcess 0x021DC77C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetRapPair 0x021DC8A0 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompExit 0x021D905C thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_NET_ClearErrorFlags 0x021DA044 thumb ov175
 *   WIFIBATTLEMATCH_NET_StepGdbEnsureRecord 0x021DA054 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepReconcileEntryState 0x021D6DB8 thumb ov175
 */
typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void MI_CpuFill8(void *,int,u32);
extern void WIFIBATTLEMATCH_NET_CreateHttpRap(char *,unsigned);
extern int WIFIBATTLEMATCH_NET_HttpRapProcess(u8 *p);
extern void WIFIBATTLEMATCH_NET_GetRapPair(char *,void *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompExit(u32 sys);
extern void WIFIBATTLEMATCH_NET_CompStepReconcileEntryState(int *sys, int *state, char *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_NET_ClearErrorFlags(u8 *p);
extern int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(char *);
void WIFIBATTLEMATCH_NET_CompStepFetchRapPair(u32 sys,int *state,u32 *p)
{
    u32 *ctx=(u32 *)p[0x104/4];
    int r;
    switch(*state) {
    case 0:
        if(func_020092EC((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))))) *state=1;
        else *state=5;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[0x2c/4],p[5],0x36,2); *state=2; break;
    case 2: MI_CpuFill8((void *)ctx[0xc],0,8); WIFIBATTLEMATCH_NET_CreateHttpRap((char *)p[0x34/4],87); *state=3; break;
    case 3:
        r=WIFIBATTLEMATCH_NET_HttpRapProcess((u8 *)p[0x34/4]);
        if(r==1) { WIFIBATTLEMATCH_NET_GetRapPair((char *)p[0x34/4],(void *)((u32 *)p[0x104/4])[0xc]); *state=4; }
        else if(r==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        else if(r!=0) {
            r=WIFIBATTLEMATCH_NET_HandleNetError((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 4: if(*(unsigned char *)(ctx[0xc]+6)) *state=7; else *state=5; break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[0x2c/4],p[5],0x37,1); *state=6; break;
    case 6: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)p[0x2c/4])) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompExit); break;
    case 7: if(*(u32 *)ctx[8]==0) {WIFIBATTLEMATCH_NET_ClearErrorFlags((u8 *)p[0x34/4]); *state=8;} break;
    case 8:
        r=WIFIBATTLEMATCH_NET_StepGdbEnsureRecord((char *)p[0x34/4]);
        if(r==1) { *(u32 *)((u32 *)p[0x104/4])[8]=0x708; *state=9; }
        if(r!=0) {
            r=WIFIBATTLEMATCH_NET_HandleNetError((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 9: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepReconcileEntryState); break;
    }
}
