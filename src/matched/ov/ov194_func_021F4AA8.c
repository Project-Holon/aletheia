/*
 * function: func_021F4AA8
 * address: 0x021F4AA8
 * packet: pkt_ov194_021F4AA8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 *   func_021F4634 0x021F4634 thumb ov194
 */
extern void func_021BD368(unsigned char *);extern int func_021BD380(unsigned char *);extern void func_021F4634(unsigned char *);
void func_021F4AA8(unsigned char *p,int *state,unsigned char *q){switch(*state){case 0:func_021BD368(*(unsigned char **)(*(unsigned char **)(q+708)+36));*state=1;break;case 1:if(func_021BD380(*(unsigned char **)(*(unsigned char **)(q+708)+36))==1)func_021F4634(p);break;}}
