/*
 * function: IRC_RHYTHM_GetTouchTap
 * address: 0x021B884C
 * packet: pkt_ov104_021B884C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
int IRC_RHYTHM_GetTouchTap(u32 *p) { u32 x,y; if(TOUCHPANEL_GetPointTrg(&x,&y)) { if(x<=256 && y<=168) { p[0]=x; p[1]=y; return 1; } } return 0; }
