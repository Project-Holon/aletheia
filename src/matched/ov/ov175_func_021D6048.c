/*
 * function: func_021D6048
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
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D5908 0x021D5908 thumb ov175
 *   func_021D60E0 0x021D60E0 thumb ov175
 */
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(unsigned);
extern void func_021E8AB4(unsigned,unsigned);
extern void func_021E8738(int *,int,int,int);
extern void func_021D6550(char *,int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
typedef unsigned int   u32;
extern void func_021D5908(unsigned sys, int *state, char *p);
extern void func_021D60E0(u32 sys, int *state, u32 *p);
void func_021D6048(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x26,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((char *)p,0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021E8AA0((int *)sys,(int)func_021D5908); break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D60E0); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
