/*
 * function: func_021CE0BC
 * address: 0x021CE0BC
 * packet: pkt_ov093_021CE0BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021CE08C(u8 *);
extern void func_021CE150(u8 *,void *);
int func_021CE0BC(u8 *p,void *q) { if(func_021CE08C(p)) { if(q) func_021CE150(p,q); return 1; } return 0; }
