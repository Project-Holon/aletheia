/*
 * function: PMS_INPUT_HitCategoryCell
 * address: 0x021BE800
 * packet: pkt_ov110_021BE800
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsInputCategoryCellTemplate 0x021C39B0 data a1
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 */
typedef unsigned char u8;
typedef struct { u8 b[8]; } Box;
extern const Box gPmsInputCategoryCellTemplate;
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned int   u32;
struct Ctx;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
int PMS_INPUT_HitCategoryCell(u8 *a0) {
 int x,y;
 Box box=gPmsInputCategoryCellTemplate;
 int i,j;
 if(!TOUCHPANEL_GetTrg()) return -1;
 TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
 for(i=0;i<4;i++) {
  box.b[0]=24*i+56; box.b[1]=box.b[0]+16;
  for(j=0;j<3;j++) { box.b[2]=80*j+12; box.b[3]=box.b[2]+72; if(TOUCHPANEL_HitPoint((struct Ctx *)(&box),x,y)!=-1) return j+3*i; }
 }
 return -1;
}
