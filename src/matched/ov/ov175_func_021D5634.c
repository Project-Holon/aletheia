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
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupSprite 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsSpriteAnimDone 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepJ 0x021D56D4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepH 0x021D5560 thumb ov175
 */
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(unsigned);
extern void func_021E8AB4(unsigned,unsigned);
extern void func_021E8738(int *,int,int,int);
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
        func_021E8738((int *)p[9],p[4],0x27,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupSprite((u32 *)p,0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch(result) {
            case 0: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)p[12]); func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepJ); break;
            case 1: func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepH); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
