/*
 * function: WIFIBATTLEMATCH_NET_TaskStepA
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
 *   WIFIBATTLEMATCH_NET_TaskStepB 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepF 0x021D51BC thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepM 0x021D5E24 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepG 0x021D54E8 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepN 0x021D6000 thumb ov175
 */
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(void *);
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_NET_TaskStepB(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepF(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepM(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepG(unsigned,int *,int *);
extern void WIFIBATTLEMATCH_NET_TaskStepN(unsigned,int *,int *);
void WIFIBATTLEMATCH_NET_TaskStepA(unsigned sys,int *state,int *p)
{
    int *q=(int *)p[16];
    switch(q[3]) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepB); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)p[12]);
    case 1:
        if(q[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepF);
        else if(q[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepM);
        break;
    case 3:
        if(q[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepG);
        else if(q[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepN);
        break;
    }
}
