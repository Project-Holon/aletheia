/*
 * function: UNION_CHARA_IsUnionObjId
 * address: 0x0217AF38
 * packet: pkt_ov019_0217AF38
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

typedef unsigned short u16;
int UNION_CHARA_IsUnionObjId(u16 a) { unsigned int v; v = (unsigned char)a; if ((u16)v >= 0x20) return 1; else return 0; }
