/*
 * function: func_021B6C54
 * address: 0x021B6C54
 * packet: pkt_ov071_021B6C54
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_02082BCC(void *, int, int);
void func_021B6C54(char *p) { int i; for(i=0;i<4;i++) func_02082BCC(p+12+i*8,0,8); }
