/*
 * function: func_021BB204
 * address: 0x021BB204
 * packet: pkt_ov072_021BB204
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_02045808(void *p);
extern void func_020452E8(void *p);
extern void func_02082BCC(void *p,int v,int n);
void func_021BB204(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x14); }
