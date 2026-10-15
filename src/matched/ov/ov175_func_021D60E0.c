/*
 * function: WIFIBATTLEMATCH_NET_TaskStepP
 * address: 0x021D60E0
 * packet: pkt_ov175_021D60E0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupSprite 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsSpriteAnimDone 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepO 0x021D6048 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupB 0x021D61CC thumb ov175
 */
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void WIFIBATTLEMATCH_NET_SetupSprite(u32 *,int);
extern int WIFIBATTLEMATCH_NET_IsSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *obj);
extern void WIFIBATTLEMATCH_NET_TaskStepO(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *p);
void WIFIBATTLEMATCH_NET_TaskStepP(u32 sys,int *state,u32 *p)
{
    u32 *ctx=(u32 *)p[16];
    int result;
    switch(*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9],p[4],39,1); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,1); break;
    case 1: WIFIBATTLEMATCH_NET_SetupSprite(p,0); *state=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch(result) {
            case 0: ctx[1]=0; *state=3; break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepO); break;
            }
        }
        break;
    case 3: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)p[9],p[4],43,2); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,4); break;
    case 4: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 5: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)p[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}
