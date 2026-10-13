/*
 * function: UNION_EFF_DeleteAnimGroupObjs
 * address: 0x0217FABC
 * packet: pkt_ov019_0217FABC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_EFF_DeleteAnimObj 0x0217FA54 thumb ov019
 */

typedef unsigned int u32;
extern void UNION_EFF_DeleteAnimObj(u32 *p);
void UNION_EFF_DeleteAnimGroupObjs(u32 *p) { if (p[3] != 0) UNION_EFF_DeleteAnimObj(p); }
