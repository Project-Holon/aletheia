/*
 * function: func_021D54E8
 * address: 0x021D54E8
 * packet: pkt_ov175_021D54E8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D5560 0x021D5560 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 */
extern unsigned func_021D9F04(unsigned,int,int);
extern void func_021E8AA0(unsigned,void *);
extern int func_021E8844(unsigned);
extern void func_021E8AB8(unsigned);
typedef unsigned char  u8;
extern void func_021D5560(unsigned sys, int *state, int *p);
extern void func_021D61A4(void *obj, int unused, u8 *p);
void func_021D54E8(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0:
        switch(func_021D9F04(p[12],0,1)) {
        case 0: state[0]=1; break;
        case 1: case 4: func_021E8AA0(sys,func_021D5560); break;
        case 2: func_021E8AA0(sys,func_021D61A4); break;
        case 3: break;
        }
        break;
    case 1: func_021E8AA0(sys,func_021D5560); break;
    case 2: if(func_021E8844(p[9])) func_021E8AB8(sys); break;
    }
}
