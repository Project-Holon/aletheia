/*
 * function: func_021BE6B4
 * address: 0x021BE6B4
 * packet: pkt_ov204_021BE6B4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 */
#include "../include/Obj14612.h"
extern void func_021BD368(unsigned char *);
extern int func_021BD380(unsigned char *);
int func_021BE6B4(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BD368(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(func_021BD380(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}
