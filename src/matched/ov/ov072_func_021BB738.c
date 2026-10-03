/*
 * function: func_021BB738
 * address: 0x021BB738
 * packet: pkt_ov072_021BB738
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BBAB4 0x021BBAB4 thumb ov072
 *   func_021BB968 0x021BB968 thumb ov072
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BBAB4(u32 *);
extern void func_021BB968(void *);
extern void func_020307B0(void *);
void func_021BB738(u32 *p) { func_02030EAC((void *)p[10]); func_021BBAB4(p+1); func_021BB968(p); func_020307B0(p); }
