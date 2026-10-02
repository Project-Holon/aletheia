/*
 * function: func_021F0DE0
 * address: 0x021F0DE0
 * packet: pkt_ov032_021F0DE0
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
typedef struct { short x,y; } Pair;
extern void func_0204B404(void *, const Pair *, unsigned);
void func_021F0DE0(void *p, short x, short y) { Pair d; d.x=x; d.y=y; func_0204B404(p,&d,0); }
