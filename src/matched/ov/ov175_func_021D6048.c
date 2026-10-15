/*
 * function: WIFIBATTLEMATCH_NET_TaskStepO
 * address: 0x021D6048
 * packet: pkt_ov175_021D6048
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
 *   WIFIBATTLEMATCH_NET_TaskStepL 0x021D5908 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepP 0x021D60E0 thumb ov175
 */
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(unsigned);
extern void func_021E8AB4(unsigned,unsigned);
extern void func_021E8738(int *,int,int,int);
extern void WIFIBATTLEMATCH_NET_SetupSprite(unsigned int *p, int mode);
extern int WIFIBATTLEMATCH_NET_IsSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *);
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_NET_TaskStepL(unsigned sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_TaskStepP(u32 sys, int *state, u32 *p);
void WIFIBATTLEMATCH_NET_TaskStepO(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x26,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupSprite((unsigned int *)p,0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch(result) {
            case 0: func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepL); break;
            case 1: func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepP); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
