/*
 * function: BTL_CALC_GetWeatherMoveRatio
 * address: 0x021D7C38
 * packet: pkt_ov093_021D7C38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned char u8;
u32 BTL_CALC_GetWeatherMoveRatio(int a,int b) { switch(a) { case 1: if(b==9) return 6144; if(b==10) return 2048; break; case 2: if(b==9) return 2048; if(b==10) return 6144; break; } return 4096; }
