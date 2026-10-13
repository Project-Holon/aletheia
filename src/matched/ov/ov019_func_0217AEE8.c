/*
 * function: UNION_CHARA_IsChildObjId
 * address: 0x0217AEE8
 * packet: pkt_ov019_0217AEE8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

typedef unsigned short u16;
typedef enum { FALSE, TRUE } BOOL;
BOOL UNION_CHARA_IsChildObjId(u16 a) { if ((u16)((unsigned char)a - 0x20) == 0) return FALSE; else return TRUE; }
