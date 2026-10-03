/*
 * function: func_021B7890
 * address: 0x021B7890
 * packet: pkt_ov106_021B7890
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78D0 0x021B78D0 thumb ov106
 */
extern void func_02082BCC(void *,unsigned char,unsigned int); extern void func_021B78D0(unsigned char *,unsigned int);
void func_021B7890(unsigned char *p,unsigned int a,unsigned int b) { func_02082BCC(p,0,16); *(unsigned int *)(p+12)=a; func_021B78D0(p,b); }
