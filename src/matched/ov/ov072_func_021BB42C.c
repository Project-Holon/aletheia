/*
 * function: func_021BB42C
 * address: 0x021BB42C
 * packet: pkt_ov072_021BB42C
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
struct Descriptor;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *p,int v,int n);
void func_021BB42C(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x10); }
