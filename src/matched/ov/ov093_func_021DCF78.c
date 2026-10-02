/*
 * function: func_021DCF78
 * address: 0x021DCF78
 * packet: pkt_ov093_021DCF78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCEC4 0x021DCEC4 thumb ov093
 *   func_021D70BC 0x021D70BC thumb ov093
 *   func_021D70DC 0x021D70DC thumb ov093
 */
extern void *func_021DCEC4(void *,unsigned int);
extern void func_021D70BC(void *);
extern void func_021D70DC(void *,int,int);
void *func_021DCF78(void *p,unsigned int k) { void *q; if(k) { q=func_021DCEC4(p,k); if(q) { func_021D70BC(q); func_021D70DC(q,6,1); return q; } } return 0; }
