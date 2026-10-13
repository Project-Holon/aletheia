/*
 * function: UNION_EFF_Draw
 * address: 0x0217F928
 * packet: pkt_ov019_0217F928
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_EFF_DrawIconGroup 0x0217FD38 thumb ov019
 *   UNION_EFF_DrawAnimGroup 0x0217FAF0 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void UNION_EFF_DrawIconGroup(struct E *p);
extern void UNION_EFF_DrawAnimGroup(u32 *p);
void UNION_EFF_Draw(char *p) { if(p) { UNION_EFF_DrawIconGroup((struct E *)(p+0x20)); UNION_EFF_DrawAnimGroup((u32 *)p); } }
