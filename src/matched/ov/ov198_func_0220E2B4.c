/*
 * function: B_PLIST_DRAW_Init
 * address: 0x0220E2B4
 * packet: pkt_ov198_0220E2B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0220E2F6 alignment padding.
 * symbols:
 *   B_PLIST_DRAW_ClearIds 0x0220E2F8 thumb ov198
 *   B_PLIST_DRAW_RegisterRowCharacters 0x0220E340 thumb ov198
 *   B_PLIST_DRAW_RegisterIconSet1 0x0220E3F0 thumb ov198
 *   B_PLIST_DRAW_RegisterIconSet3 0x0220E518 thumb ov198
 *   B_PLIST_DRAW_RegisterIconSet2 0x0220E460 thumb ov198
 *   B_PLIST_DRAW_RegisterIconSet4 0x0220E584 thumb ov198
 *   B_PLIST_DRAW_RegisterIconSet5 0x0220E5FC thumb ov198
 *   B_PLIST_DRAW_CreateActors 0x0220E6E0 thumb ov198
 *   B_PLIST_MAIN_CreateToolActors 0x0220F1F4 thumb ov198
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
extern void B_PLIST_DRAW_ClearIds(char *);
typedef unsigned char  u8;
extern void B_PLIST_DRAW_RegisterRowCharacters(u8 *p);
extern void B_PLIST_DRAW_RegisterIconSet1(char *);
extern void B_PLIST_DRAW_RegisterIconSet3(char *);
extern void B_PLIST_DRAW_RegisterIconSet2(char *);
extern void B_PLIST_DRAW_RegisterIconSet4(char *);
extern void B_PLIST_DRAW_RegisterIconSet5(char *);
extern void B_PLIST_DRAW_CreateActors(char *);
extern void B_PLIST_MAIN_CreateToolActors(u8 *p);
typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void B_PLIST_DRAW_Init(char *p)
{
    B_PLIST_DRAW_ClearIds(p);
    B_PLIST_DRAW_RegisterRowCharacters((u8 *)p);
    B_PLIST_DRAW_RegisterIconSet1(p);
    B_PLIST_DRAW_RegisterIconSet3(p);
    B_PLIST_DRAW_RegisterIconSet2(p);
    B_PLIST_DRAW_RegisterIconSet4(p);
    B_PLIST_DRAW_RegisterIconSet5(p);
    B_PLIST_DRAW_CreateActors(p);
    B_PLIST_MAIN_CreateToolActors((u8 *)p);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
