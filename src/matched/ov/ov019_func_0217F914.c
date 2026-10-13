/*
 * function: UNION_EFF_Main
 * address: 0x0217F914
 * packet: pkt_ov019_0217F914
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_EFF_UpdateIconGroup 0x0217FD04 thumb ov019
 *   UNION_EFF_UpdateAnimGroup 0x0217FACC thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void UNION_EFF_UpdateIconGroup(struct E *p);
extern void UNION_EFF_UpdateAnimGroup(u32 *p);
void UNION_EFF_Main(char *p) { if(p) { UNION_EFF_UpdateIconGroup((struct E *)(p+0x20)); UNION_EFF_UpdateAnimGroup((u32 *)p); } }
