/*
 * function: WIFIBATTLEMATCH_NET_TaskStepMainMenu
 * address: 0x021D4608
 * packet: pkt_ov175_021D4608
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupChoiceMenu 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollChoiceMenu 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteChoiceMenu 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer 0x021D57BC thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer 0x021D4730 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupB 0x021D61CC thumb ov175
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 */
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **, int);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32, u32);
extern void WIFIBATTLEMATCH_NET_SetupChoiceMenu(u32 *, int);
extern int WIFIBATTLEMATCH_NET_PollChoiceMenu(char *);
extern void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(char *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *p);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
void WIFIBATTLEMATCH_NET_TaskStepMainMenu(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0: WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)p[8], 0); *state = 1; break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 25, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_NET_SetupChoiceMenu(p, 1); *state = 3; break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)p);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)p);
            switch (result) {
            case 0: ctx[0] = 1; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer); break;
            case 1: ctx[0] = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer); break;
            case 2: ctx[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 30, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 5); break;
    case 5: WIFIBATTLEMATCH_NET_SetupChoiceMenu(p, 0); *state = 6; break;
    case 6:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)p);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)p);
            switch (result) {
            case 0: ctx[1] = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
