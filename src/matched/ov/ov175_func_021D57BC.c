/*
 * function: WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer
 * address: 0x021D57BC
 * packet: pkt_ov175_021D57BC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupBoxRecord 0x021D62A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsBoxReady 0x021D63B0 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetWaitCallback 0x021D6788 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollWaitResult 0x021D679C thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteBoxAndWait 0x021D63DC thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepPostPartyData 0x021D61F0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepMainMenu 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake 0x021D5908 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupB 0x021D61CC thumb ov175
 */
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void WIFIBATTLEMATCH_NET_SetupBoxRecord(u32 *p, u32 mode);
extern unsigned long WIFIBATTLEMATCH_NET_IsBoxReady(char *);
extern void WIFIBATTLEMATCH_NET_SetWaitCallback(char *, void *);
extern unsigned long WIFIBATTLEMATCH_NET_PollWaitResult(char *);
extern void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepMainMenu(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupB(void *, unsigned **, char *);
void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(unsigned sys, int *state, int *p)
{
    unsigned long r;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 26, 1);
        WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)p, 1);
        *state = 1;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsBoxReady((char *)p)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)p[9])) *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 24, 2);
        *state = 4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_SetWaitCallback((char *)p, WIFIBATTLEMATCH_NET_TaskStepPostPartyData);
        *state = 5;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
            break;
        }
        break;
    case 5:
        r = WIFIBATTLEMATCH_NET_PollWaitResult((char *)p);
        if (r == 0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake);
        else if (r == 1) *state = 6;
        else if (r == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (r != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)p);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 6:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 120, 1);
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)p[9])) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB);
        break;
    }
}
