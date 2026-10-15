/*
 * function: WF2DMAP_OBJ_GetDestPos
 * address: 0x021C4AD0
 * packet: pkt_ov127_021C4AD0
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
struct pair { u16 a,b; };
struct pair WF2DMAP_OBJ_GetDestPos(char *p) { return *(struct pair *)(p+8); }
