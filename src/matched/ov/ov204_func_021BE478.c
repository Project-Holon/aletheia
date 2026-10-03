/*
 * function: func_021BE478
 * address: 0x021BE478
 * packet: pkt_ov204_021BE478
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF23C 0x021BF23C thumb ov204
 *   func_021BF2F4 0x021BF2F4 thumb ov204
 */
extern void func_021BF23C(char *,void *,int);
extern int func_021BF2F4(char *);
int func_021BE478(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BF23C(*(char **)(p+24),(void *)q[0],q[1]);(*state)++;break;case 1:if(func_021BF2F4(*(char **)(p+24)))return 1;break;}return 0;}
