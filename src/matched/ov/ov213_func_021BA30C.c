/*
 * function: func_021BA30C
 * address: 0x021BA30C
 * packet: pkt_ov213_021BA30C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA14C 0x021BA14C thumb ov213
 *   func_021B9E80 0x021B9E80 thumb ov213
 *   func_021BA2E0 0x021BA2E0 thumb ov213
 */
extern void func_021BA14C(char *,unsigned),func_021BA2E0(char *);extern int func_021B9E80(unsigned);
void func_021BA30C(char *p,unsigned limit){func_021BA14C(p+32,limit);if(func_021B9E80(*(unsigned char *)(p+16)))func_021BA2E0(p);(*(unsigned *)(p+80))++;}
