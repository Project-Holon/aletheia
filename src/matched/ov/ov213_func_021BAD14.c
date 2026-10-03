/*
 * function: func_021BAD14
 * address: 0x021BAD14
 * packet: pkt_ov213_021BAD14
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BB1F8 0x021BB1F8 data a4
 */
extern const unsigned d_021BB1F8[][11];
extern void func_020403F4(unsigned char),func_020450C8(void),func_0203F9B4(void),func_02082BCC(void *,unsigned,unsigned);
void func_021BAD14(void *p){unsigned i;for(i=0;i<6;i++)func_020403F4(d_021BB1F8[i][0]);func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
