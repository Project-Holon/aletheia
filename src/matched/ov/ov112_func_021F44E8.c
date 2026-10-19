/*
 * function: MUSICAL_SHOT_INFO_IsFinished
 * address: 0x021F44E8
 * packet: pkt_ov112_021F44E8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int MUSICAL_SHOT_INFO_IsFinished(u32 *p) { if(p[1]==7) return 1; return 0; }
