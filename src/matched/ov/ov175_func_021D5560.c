/*
 * function: WIFIBATTLEMATCH_NET_TaskStepH
 * address: 0x021D5560
 * packet: pkt_ov175_021D5560
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupChoiceMenu 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_PollChoiceMenu 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteChoiceMenu 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepD 0x021D495C thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepI 0x021D5634 thumb ov175
 */
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned, unsigned);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_NET_SetupChoiceMenu(u32 *, int);
extern int WIFIBATTLEMATCH_NET_PollChoiceMenu(char *);
extern void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(char *);
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepD(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepI(unsigned, int *, int *);
void WIFIBATTLEMATCH_NET_TaskStepH(unsigned sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12], 0, (void *)1)) {
        case 0: case 1: case 4: *state = 1; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9], p[4], 0x26, 1);
        *state = 4;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)p, 0);
        *state = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)p);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)p);
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepD); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepI); break;
            }
        }
        break;
    case 4:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}
