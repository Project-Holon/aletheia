/*
 * function: WIFIBATTLEMATCH_NET_CompStepA
 * address: 0x021D6BF4
 * packet: pkt_ov175_021D6BF4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupTradeIconAndWait 0x021D97D0 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepB 0x021D6C54 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepG 0x021D8904 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepH 0x021D8BC4 thumb ov175
 */
#include "../include/Obj14328.h"
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(u32);
extern void WIFIBATTLEMATCH_NET_SetupTradeIconAndWait(char *);
extern void WIFIBATTLEMATCH_NET_CompStepB(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_CompStepG(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepH(int *a, int *state, char *ctx);
void WIFIBATTLEMATCH_NET_CompStepA(u32 sys,void *unused,char *p)
{
    switch (((u32 *)((struct Obj14328 *)p)->f104)[3]) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepB); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi(((struct Obj14328 *)p)->f34);
    case 1:
        WIFIBATTLEMATCH_NET_SetupTradeIconAndWait(p);
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepG);
        break;
    case 3: WIFIBATTLEMATCH_NET_SetupTradeIconAndWait(p); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepH); break;
    }
}
