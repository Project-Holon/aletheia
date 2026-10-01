/*
 * function: func_021D6000
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
 *   func_021D6048 0x021D6048 thumb ov175
 */
extern void func_021E8AA0(unsigned,void *);
extern int func_021E8844(unsigned);
extern void func_021E8AB8(unsigned);
extern void func_021D6048(unsigned,int *,int *);
void func_021D6000(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: func_021E8AA0(sys,func_021D6048); break;
    case 3: if(func_021E8844(p[9])) func_021E8AB8(sys); break;
    }
}
