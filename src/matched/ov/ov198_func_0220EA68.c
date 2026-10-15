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
 *   B_PLIST_DRAW_LayoutMode0 0x0220EAF0 thumb ov198
 *   B_PLIST_DRAW_LayoutMode1 0x0220EBCC thumb ov198
 *   B_PLIST_DRAW_LayoutMode2 0x0220EC2C thumb ov198
 *   B_PLIST_DRAW_LayoutMode3 0x0220ECCC thumb ov198
 *   B_PLIST_DRAW_LayoutMode4 0x0220ED54 thumb ov198
 *   B_PLIST_DRAW_LayoutMode5 0x0220EFD8 thumb ov198
 *   B_PLIST_DRAW_LayoutMode6 0x0220EE44 thumb ov198
 *   B_PLIST_DRAW_LayoutMode7 0x0220EECC thumb ov198
 */
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void B_PLIST_DRAW_LayoutMode0(void *);
extern void B_PLIST_DRAW_LayoutMode1(void *);
typedef unsigned char  u8;
extern void B_PLIST_DRAW_LayoutMode2(u8 *p);
extern void B_PLIST_DRAW_LayoutMode3(u8 *p);
extern void B_PLIST_DRAW_LayoutMode4(u8 *p);
extern void B_PLIST_DRAW_LayoutMode5(u8 *p);
extern void B_PLIST_DRAW_LayoutMode6(u8 *p);
extern void B_PLIST_DRAW_LayoutMode7(u8 *p);
void B_PLIST_DRAW_LayoutActors(char *p,unsigned mode)
{
    unsigned i;
    for(i=0;i<41;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x1ebc),0);
    switch(mode){
    case 0: case 8: B_PLIST_DRAW_LayoutMode0(p);return;
    case 1: B_PLIST_DRAW_LayoutMode1(p);return;
    case 2: B_PLIST_DRAW_LayoutMode2((u8 *)p);return;
    case 3: B_PLIST_DRAW_LayoutMode3((u8 *)p);return;
    case 4: B_PLIST_DRAW_LayoutMode4((u8 *)p);return;
    case 5: B_PLIST_DRAW_LayoutMode5((u8 *)p);return;
    case 6: B_PLIST_DRAW_LayoutMode6((u8 *)p);return;
    case 7: B_PLIST_DRAW_LayoutMode7((u8 *)p);return;
    }
}
