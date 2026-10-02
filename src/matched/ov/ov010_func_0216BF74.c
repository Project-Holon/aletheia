/*
 * function: func_0216BF74
 * address: 0x0216BF74
 * packet: pkt_ov010_0216BF74
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   func_0200C38C 0x0200C38C thumb
 *   d_02172508 0x02172508 data a4
 */
typedef unsigned int u32;
extern u32 func_02008530(void *);
extern void func_0200C38C(void *, int, u32);
extern const u32 d_02172508[];
void func_0216BF74(void *a, int i, void *b) {
    if(i<8) func_0200C38C(a,i,func_02008530(b)^*(const u32 *)((u32)d_02172508+(u32)i*4));
}
