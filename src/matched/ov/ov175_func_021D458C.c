/*
 * function: WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState
 * address: 0x021D458C
 * packet: pkt_ov175_021D458C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepMainMenu 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave 0x021D51BC thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave 0x021D5E24 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError 0x021D54E8 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt 0x021D6000 thumb ov175
 */
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(void *);
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_NET_TaskStepMainMenu(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError(unsigned,int *,int *);
extern void WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt(unsigned,int *,int *);
void WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState(unsigned sys,int *state,int *p)
{
    int *q=(int *)p[16];
    switch(q[3]) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)p[12]);
    case 1:
        if(q[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave);
        else if(q[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave);
        break;
    case 3:
        if(q[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        else if(q[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt);
        break;
    }
}
