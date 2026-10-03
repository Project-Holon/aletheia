/*
 * function: func_021DD928
 * address: 0x021DD928
 * packet: pkt_ov137_021DD928
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 */
extern void func_021DD924(void *);
int func_021DD928(char *p,int state) {*(int *)(p+280)=2;func_021DD924(p);return state;}
