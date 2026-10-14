/*
 * function: DENDOU_VIEW_InitActors
 * address: 0x021DDFE8
 * packet: pkt_ov171_021DDFE8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_InitClactSystem 0x021DE114 thumb ov171
 *   DENDOU_VIEW_LoadButtonResources 0x021DE144 thumb ov171
 *   DENDOU_VIEW_CreateButtonActors 0x021DE2D4 thumb ov171
 *   DENDOU_VIEW_InitPageCounterOam 0x021DE80C thumb ov171
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void DENDOU_VIEW_InitClactSystem(u8 *);
extern void DENDOU_VIEW_LoadButtonResources(char *);
extern void DENDOU_VIEW_CreateButtonActors(char *);
extern void DENDOU_VIEW_InitPageCounterOam(char *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
void DENDOU_VIEW_InitActors(u8 *p)
{
    DENDOU_VIEW_InitClactSystem(p);
    DENDOU_VIEW_LoadButtonResources((char *)p);
    DENDOU_VIEW_CreateButtonActors((char *)p);
    DENDOU_VIEW_InitPageCounterOam((char *)p);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
}
