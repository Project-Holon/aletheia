/*
 * function: func_021BA7F8
 * address: 0x021BA7F8
 * packet: pkt_ov072_021BA7F8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02166C7C 0x02166C7C thumb ov010
 *   func_021BA774 0x021BA774 thumb ov072
 * call: r1 forwards the second entry parameter unchanged to ov010's callee.
 */
typedef unsigned int u32;
extern u32 func_02166C7C(void *a, u32 b);
extern int func_021BA774(char *p, int i);
void *func_021BA7F8(char *p, u32 b) { u32 i; u32 v; void *q; v=func_02166C7C(*(void **)p,b); for(i=0;i<*(u32 *)(p+12);i++) { q=(void *)(*(u32 *)(p+8)+i*0x44); if(v==func_021BA774(q,0)) return q; } return 0; }
