/*
 * function: WIFIBATTLEMATCH_NET_TaskStepI
 * address: 0x021D5634
 * packet: pkt_ov175_021D5634
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupSprite 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsSpriteAnimDone 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepJ 0x021D56D4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepH 0x021D5560 thumb ov175
 */
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned,unsigned);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *,int,int,int);
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_NET_SetupSprite(u32 *p, int mode);
extern int WIFIBATTLEMATCH_NET_IsSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(void *);
extern void WIFIBATTLEMATCH_NET_TaskStepJ(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskStepH(unsigned sys, int *state, int *p);
void WIFIBATTLEMATCH_NET_TaskStepI(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9],p[4],0x27,1);
        state[0]=3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupSprite((u32 *)p,0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch(result) {
            case 0: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)p[12]); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepJ); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepH); break;
            }
        }
        break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
