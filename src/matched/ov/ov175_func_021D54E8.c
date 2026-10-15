/*
 * function: WIFIBATTLEMATCH_NET_TaskStepG
 * address: 0x021D54E8
 * packet: pkt_ov175_021D54E8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepH 0x021D5560 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 */
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *ctx, void *a, void *b);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_NET_TaskStepH(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
void WIFIBATTLEMATCH_NET_TaskStepG(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)p[12],0,(void *)1)) {
        case 0: state[0]=1; break;
        case 1: case 4: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepH); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepH); break;
    case 2: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
