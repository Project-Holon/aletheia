/*
 * function: PMS_INPUT_HitBrowseTopButtons
 * address: 0x021BE7B8
 * packet: pkt_ov110_021BE7B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsInputBrowseTopButtonHits 0x021C392C data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
#include "../include/Obj22380.h"
typedef unsigned char u8;
extern const u8 gPmsInputBrowseTopButtonHits[];
extern int TOUCHPANEL_HitTrg(const void *);
int PMS_INPUT_HitBrowseTopButtons(u8 *p) {
 int n=TOUCHPANEL_HitTrg(gPmsInputBrowseTopButtonHits);
 if(n==-1) return 0;
 switch(n) {
 case 0: return 1;
 case 1: if(((struct Obj22380 *)p)->f3C==0) return 2; break;
 }
 return 0;
}
