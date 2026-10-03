/*
 * function: func_021C4AC4
 * address: 0x021C4AC4
 * packet: pkt_ov127_021C4AC4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
struct pair { u16 a,b; };
struct pair func_021C4AC4(char *p) { return *(struct pair *)(p+4); }
