/*
 * function: func_0220AFD8
 * address: 0x0220AFD8
 * packet: pkt_ov187_0220AFD8
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220B02C 0x0220B02C thumb ov187
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0220B02C(void *);
int func_0220AFD8(void *a,int *state,int b,void *p) { switch(*state) { case 0: *state=1; break; case 1: if(func_0220B02C(p)) *state=2; break; case 2: return 1; } return 0; }
