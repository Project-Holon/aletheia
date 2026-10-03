/*
 * function: func_021BE328
 * address: 0x021BE328
 * packet: pkt_ov204_021BE328
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 */
extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
int func_021BE328(char *p,int *state,int *q){switch(*state){case 0:func_0204E720(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(func_0204E804()==0)return 1;break;}return 0;}
