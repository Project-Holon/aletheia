/*
 * function: func_021BB19C
 * address: 0x021BB19C
 * packet: pkt_ov072_021BB19C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB0E4 0x021BB0E4 thumb ov072
 */
typedef unsigned int u32;
extern void func_021BB0E4(void *,void *);
void func_021BB19C(u32 *p,const u32 *v) { p[8]=v[0]+p[8]; p[9]+=v[1]; func_021BB0E4(p,p+8); }
