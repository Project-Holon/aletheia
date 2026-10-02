/*
 * function: func_021BC17C
 * address: 0x021BC17C
 * packet: pkt_ov091_021BC17C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BBE74 0x021BBE74 thumb ov091
 *   func_02020FE4 0x02020FE4 thumb
 */
extern int func_021BBE74(int);
extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
int func_021BC17C(unsigned short *p,int id) { switch(func_021BBE74(id)) { case 26:return 1; case 27:return 1; case 28: if(func_02020FE4((void *)id,39,*p)) return 1; break; } return 0; }
