/*
 * function: PMS_INPUT_HitInitialCell
 * address: 0x021BE8B4
 * packet: pkt_ov110_021BE8B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsInputInitialCellTemplate 0x021C38F8 data a1
 *   PMSI_SEARCH_GetKeyCount 0x021BB1F4 thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
typedef unsigned char u8;
typedef struct { u8 b[8]; } Box;
extern const Box gPmsInputInitialCellTemplate;
extern int PMSI_SEARCH_GetKeyCount(void);
extern void PMSI_SEARCH_GetKeyPosition(unsigned,int *,int *);
extern int TOUCHPANEL_HitTrg(const void *p);
int PMS_INPUT_HitInitialCell(u8 *a0) {
 Box box;
 int x,y;
 Box template;
 int i,count;
 count=PMSI_SEARCH_GetKeyCount();
 i=0;
 if(count>0) {
  template=gPmsInputInitialCellTemplate;
  do { box=template; PMSI_SEARCH_GetKeyPosition(i,&x,&y); box.b[0]=y+48; box.b[1]=y+64; box.b[2]=x+8; box.b[3]=x+24; if(TOUCHPANEL_HitTrg(&box)!=-1) return i; i++; } while(i<count);
 }
 return -1;
}
