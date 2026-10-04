/*
 * function: func_021D458C
 * address: 0x021D458C
 * packet: pkt_ov175_021D458C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D4608 0x021D4608 thumb ov175
 *   func_021D51BC 0x021D51BC thumb ov175
 *   func_021D5E24 0x021D5E24 thumb ov175
 *   func_021D54E8 0x021D54E8 thumb ov175
 *   func_021D6000 0x021D6000 thumb ov175
 */
extern void func_021E8AA0(int *p, int v);
extern void func_021DA36C(void *);
typedef unsigned int   u32;
extern void func_021D4608(u32 sys, int *state, u32 *p);
extern void func_021D51BC(unsigned sys, int *state, char *p);
extern void func_021D5E24(unsigned sys, int *state, char *p);
extern void func_021D54E8(unsigned,int *,int *);
extern void func_021D6000(unsigned,int *,int *);
void func_021D458C(unsigned sys,int *state,int *p)
{
    int *q=(int *)p[16];
    switch(q[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D4608); break;
    case 2:
        func_021DA36C((void *)p[12]);
    case 1:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D51BC);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D5E24);
        break;
    case 3:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D54E8);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D6000);
        break;
    }
}
