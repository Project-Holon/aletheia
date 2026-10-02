/*
 * function: func_0216BF9C
 * address: 0x0216BF9C
 * packet: pkt_ov010_0216BF9C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: named second call-result local preserves the original comparison registers.
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   func_0200C39C 0x0200C39C thumb
 *   d_02172508 0x02172508 data a4
 */
typedef unsigned int u32;
extern u32 func_02008530(void *);
extern u32 func_0200C39C(void *, int);
extern const u32 d_02172508[];
int func_0216BF9C(void *a, int i, void *b) {
    u32 v; u32 x;
    if(i>=8) return 0;
    v=func_02008530(b);
    x=func_0200C39C(a,i);
    if((x^v)==*(const u32 *)((u32)d_02172508+(u32)i*4)) return 1;
    return 0;
}
