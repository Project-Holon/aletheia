/*
 * function: func_021B95F8
 * address: 0x021B95F8
 * packet: pkt_ov181_021B95F8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA318 0x021BA318 thumb ov181
 *   func_021B9C80 0x021B9C80 thumb ov181
 *   func_021B9F40 0x021B9F40 thumb ov181
 *   d_021BAB70 0x021BAB70 data a4
 */
extern void func_021BA318(unsigned char *),func_021B9C80(char *),func_021B9F40(char *);
extern int (*const d_021BAB70[])(char *);
int func_021B95F8(char *p){func_021BA318((unsigned char *)p);*(unsigned *)(p+0x2e8)=d_021BAB70[*(unsigned *)(p+0x2e8)](p);if(*(unsigned *)(p+0x2e8)==5)return 0;func_021B9C80(p);func_021B9F40(p);return 1;}
