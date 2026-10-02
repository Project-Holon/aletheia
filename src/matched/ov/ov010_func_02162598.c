/*
 * function: func_02162598
 * address: 0x02162598
 * packet: pkt_ov010_02162598
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02162E00 0x02162E00 thumb ov010
 */
typedef unsigned short u16;
struct Box; struct Q;
extern int func_02162E00(struct Box *, struct Q *);
int func_02162598(char *p, struct Q *q) { int i; char *r; i=0; r=*(char **)(p+0x24); for(;i<*(u16 *)(p+0x16);i++,r+=20) { if(func_02162E00((struct Box *)r,q)) return i; } return 0xffff; }
