/*
 * function: WIFIBATTLEMATCH_NET_TaskStepN
 * address: 0x021D6000
 * packet: pkt_ov175_021D6000
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepO 0x021D6048 thumb ov175
 */
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(unsigned);
extern void WIFIBATTLEMATCH_NET_TaskStepO(unsigned,int *,int *);
void WIFIBATTLEMATCH_NET_TaskStepN(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepO); break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
