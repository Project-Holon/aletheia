/*
 * function: UNION_CHARA_GetGroupCategory
 * address: 0x0217F858
 * packet: pkt_ov019_0217F858
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned int u32;
int UNION_CHARA_GetGroupCategory(int a) { if(a>=4 && a<=23) return 1; switch(a) { case 3:return 4; case 24:return 2; case 25:return 5; case 26:return 3; default:return 0; } }
