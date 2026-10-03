/*
 * function: func_021B7D90
 * address: 0x021B7D90
 * packet: pkt_ov105_021B7D90
 * region: ov105
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
struct U16Vec; struct Descriptor; extern void func_02045808(struct U16Vec *); extern void func_020452E8(struct Descriptor *); extern void func_02082BCC(void *,unsigned char,unsigned int);
void func_021B7D90(unsigned char *p) { func_02045808(*(struct U16Vec **)(p+12)); func_020452E8(*(struct Descriptor **)p); func_02082BCC(p,0,20); }
