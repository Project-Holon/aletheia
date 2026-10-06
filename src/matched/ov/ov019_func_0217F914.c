/*
 * function: func_0217F914
 * address: 0x0217F914
 * packet: pkt_ov019_0217F914
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217FD04 0x0217FD04 thumb ov019
 *   func_0217FACC 0x0217FACC thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void func_0217FD04(struct E *p);
extern void func_0217FACC(u32 *p);
void func_0217F914(char *p) { if(p) { func_0217FD04((struct E *)(p+0x20)); func_0217FACC((u32 *)p); } }
