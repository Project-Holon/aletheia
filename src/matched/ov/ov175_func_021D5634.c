/*
 * function: func_021D5634
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
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D56D4 0x021D56D4 thumb ov175
 *   func_021D5560 0x021D5560 thumb ov175
 */
extern void func_021E8AA0(unsigned,void *);
extern int func_021E8844(unsigned);
extern void func_021E8AB8(unsigned);
extern void func_021E8AB4(unsigned,unsigned);
extern void func_021E8738(int *,int,int,int);
extern void func_021D6550(char *,int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
extern void func_021DA36C(void *);
extern void func_021D56D4(void);
extern void func_021D5560(void);
void func_021D5634(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x27,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((char *)p,0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021DA36C((void *)p[12]); func_021E8AA0(sys,func_021D56D4); break;
            case 1: func_021E8AA0(sys,func_021D5560); break;
            }
        }
        break;
    case 3: if(func_021E8844(p[9])) func_021E8AB8(sys); break;
    }
}
