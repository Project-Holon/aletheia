/*
 * function: func_021BE3EC
 * address: 0x021BE3EC
 * packet: pkt_ov204_021BE3EC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_020062BC 0x020062BC thumb
 *   func_02006268 0x02006268 thumb
 */
extern void func_020061E4(unsigned),func_020062BC(int,unsigned),func_02006268(int,unsigned,unsigned,unsigned);
extern int func_02006148(unsigned);
int func_021BE3EC(char *p,int *state,unsigned *q){int i;func_020061E4(q[0]);i=func_02006148(q[0]);if(q[1])func_020062BC(i,q[1]);if(q[2])func_02006268(i,-1,-1,q[2]);return 1;}
