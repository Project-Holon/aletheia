/*
 * function: TOWNMAP_MoveScroll
 * address: 0x021BB19C
 * packet: pkt_ov072_021BB19C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOWNMAP_ApplyScroll 0x021BB0E4 thumb ov072
 */
typedef unsigned int u32;
extern void TOWNMAP_ApplyScroll(void *,void *);
void TOWNMAP_MoveScroll(u32 *p,const u32 *v) { p[8]=v[0]+p[8]; p[9]+=v[1]; TOWNMAP_ApplyScroll(p,p+8); }
