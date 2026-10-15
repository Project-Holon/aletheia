/*
 * function: BOX2_UI_GetBackButtonPoint
 * address: 0x021EF1FC
 * packet: pkt_ov170_021EF1FC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   d_021F0024 0x021F0024 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int TOUCHPANEL_HitCont(const void*);
extern unsigned TOUCHPANEL_GetPointCont(unsigned*,unsigned*);
extern const u8 d_021F0024[];
int BOX2_UI_GetBackButtonPoint(unsigned*a,unsigned*b){if(TOUCHPANEL_HitCont(d_021F0024)!=-1){TOUCHPANEL_GetPointCont(a,b);return 1;}return 0;}
