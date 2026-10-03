/*
 * function: func_021F463C
 * address: 0x021F463C
 * packet: pkt_ov194_021F463C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3304 0x021F3304 thumb ov194
 *   func_021F22E8 0x021F22E8 thumb ov194
 *   func_021F3E78 0x021F3E78 thumb ov194
 *   func_021F462C 0x021F462C thumb ov194
 *   func_021F4674 0x021F4674 thumb ov194
 */
extern int func_021F3304(char *),func_021F22E8(unsigned char *),func_021F3E78(unsigned char *);
extern void func_021F462C(unsigned char *,unsigned),func_021F4674(unsigned char *,int *);
void func_021F463C(unsigned char *p,int *unused,unsigned char *q){int v;v=func_021F3304((char *)(q+252));v|=func_021F22E8(q+104);if(func_021F3E78(q+560)|v)func_021F462C(p,(unsigned)func_021F4674);}
