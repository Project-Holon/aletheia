/*
 * function: func_0217F928
 * address: 0x0217F928
 * packet: pkt_ov019_0217F928
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217FD38 0x0217FD38 thumb ov019
 *   func_0217FAF0 0x0217FAF0 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void func_0217FD38(struct E *p);
extern void func_0217FAF0(u32 *p);
void func_0217F928(char *p) { if(p) { func_0217FD38((struct E *)(p+0x20)); func_0217FAF0((u32 *)p); } }
