/*
 * function: WIFIBATTLEMATCH_NET_TaskStepC
 * address: 0x021D4730
 * packet: pkt_ov175_021D4730
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
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_CreateHttpRap 0x021DC738 thumb ov175
 *   WIFIBATTLEMATCH_NET_HttpRapProcess 0x021DC77C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetRapPair 0x021DC8A0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepB 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteBoxAndWait 0x021D63DC thumb ov175
 *   WIFIBATTLEMATCH_NET_SetWaitCallback 0x021D6788 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepQ 0x021D61F0 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetWaitResult 0x021D679C thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupB 0x021D61CC thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepD 0x021D495C thumb ov175
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009448Obj *func_02009448(void *);
extern u8 func_020092EC(const struct Sub02009210Obj *);
extern void MI_CpuFill8(void *, int, int);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32, u32);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void WIFIBATTLEMATCH_NET_CreateHttpRap(char *, unsigned);
extern int WIFIBATTLEMATCH_NET_HttpRapProcess(u8 *p);
extern void WIFIBATTLEMATCH_NET_GetRapPair(char *, void *);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepB(u32 sys, int *state, u32 *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *);
extern void WIFIBATTLEMATCH_NET_SetWaitCallback(char *, void *);
extern void WIFIBATTLEMATCH_NET_TaskStepQ(u32 sys, int *state, char *p);
extern u32 WIFIBATTLEMATCH_NET_GetWaitResult(char *);
extern void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepD(u32 sys, int *state, u32 *p);
void WIFIBATTLEMATCH_NET_TaskStepC(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    u32 result;
    switch (*state) {
    case 0:
        if (func_020092EC((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl((struct Big *)*(u32 *)ctx[2])))) *state = 1;
        else *state = 6;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 41, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 24, 2); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 3); break;
    case 3: MI_CpuFill8((void *)ctx[12], 0, 8); WIFIBATTLEMATCH_NET_CreateHttpRap((char *)p[12], 87); *state = 4; break;
    case 4:
        switch (WIFIBATTLEMATCH_NET_HttpRapProcess((u8 *)p[12])) {
        case 0: break;
        case 1: WIFIBATTLEMATCH_NET_GetRapPair((char *)p[12], (void *)((u32 *)p[16])[12]); *state = 5; break;
        case 3: MI_CpuFill8((void *)((u32 *)p[16])[12], 0, 8); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 2:
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB); break;
            }
            break;
        }
        break;
    case 5: if (((u8 *)ctx[12])[6]) *state = 9; else *state = 6; break;
    case 6: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 55, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 9:
        WIFIBATTLEMATCH_NET_SetWaitCallback((char *)p, WIFIBATTLEMATCH_NET_TaskStepQ); *state = 10;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
        case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 10:
        result = WIFIBATTLEMATCH_NET_GetWaitResult((char *)p);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (result != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            }
        }
        break;
    case 11: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 120, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 12: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 13: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepD); break;
    case 14: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
