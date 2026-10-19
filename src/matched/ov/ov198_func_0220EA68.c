/*
 * function: B_PLIST_DRAW_LayoutActors
 * address: 0x0220EA68
 * packet: pkt_ov198_0220EA68
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   B_PLIST_DRAW_LayoutPartyListPage 0x0220EAF0 thumb ov198
 *   B_PLIST_DRAW_LayoutMonMenuPage 0x0220EBCC thumb ov198
 *   B_PLIST_DRAW_LayoutSummaryPage 0x0220EC2C thumb ov198
 *   B_PLIST_DRAW_LayoutMoveListPage 0x0220ECCC thumb ov198
 *   B_PLIST_DRAW_LayoutMoveDetailPage 0x0220ED54 thumb ov198
 *   B_PLIST_DRAW_LayoutMoveListForItemPage 0x0220EFD8 thumb ov198
 *   B_PLIST_DRAW_LayoutMoveListWithNewMovePage 0x0220EE44 thumb ov198
 *   B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage 0x0220EECC thumb ov198
 */
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void B_PLIST_DRAW_LayoutPartyListPage(void *);
extern void B_PLIST_DRAW_LayoutMonMenuPage(void *);
typedef unsigned char  u8;
extern void B_PLIST_DRAW_LayoutSummaryPage(u8 *p);
extern void B_PLIST_DRAW_LayoutMoveListPage(u8 *p);
extern void B_PLIST_DRAW_LayoutMoveDetailPage(u8 *p);
extern void B_PLIST_DRAW_LayoutMoveListForItemPage(u8 *p);
extern void B_PLIST_DRAW_LayoutMoveListWithNewMovePage(u8 *p);
extern void B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage(u8 *p);
void B_PLIST_DRAW_LayoutActors(char *p,unsigned mode)
{
    unsigned i;
    for(i=0;i<41;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x1ebc),0);
    switch(mode){
    case 0: case 8: B_PLIST_DRAW_LayoutPartyListPage(p);return;
    case 1: B_PLIST_DRAW_LayoutMonMenuPage(p);return;
    case 2: B_PLIST_DRAW_LayoutSummaryPage((u8 *)p);return;
    case 3: B_PLIST_DRAW_LayoutMoveListPage((u8 *)p);return;
    case 4: B_PLIST_DRAW_LayoutMoveDetailPage((u8 *)p);return;
    case 5: B_PLIST_DRAW_LayoutMoveListForItemPage((u8 *)p);return;
    case 6: B_PLIST_DRAW_LayoutMoveListWithNewMovePage((u8 *)p);return;
    case 7: B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage((u8 *)p);return;
    }
}
