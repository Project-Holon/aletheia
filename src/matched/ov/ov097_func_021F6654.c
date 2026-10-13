/*
 * function: VS_MULTI_LIST_StateTeardown
 * address: 0x021F6654
 * packet: pkt_ov097_021F6654
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VS_MULTI_LIST_DeleteVBlankTask 0x021F69FC thumb ov097
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   VS_MULTI_LIST_DeleteBgFrames 0x021F75E0 thumb ov097
 *   VS_MULTI_LIST_ExitIcons 0x021F6F3C thumb ov097
 *   VS_MULTI_LIST_DeleteWindows 0x021F6B1C thumb ov097
 *   VS_MULTI_LIST_DeleteTextResources 0x021F69C0 thumb ov097
 *   VS_MULTI_LIST_ExitBgs 0x021F68E0 thumb ov097
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void VS_MULTI_LIST_DeleteVBlankTask(u8 *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void VS_MULTI_LIST_DeleteBgFrames(int *);
extern void VS_MULTI_LIST_ExitIcons(char *p);
extern void VS_MULTI_LIST_DeleteWindows(u8 *);
extern void VS_MULTI_LIST_DeleteTextResources(u8 *);
extern void VS_MULTI_LIST_ExitBgs(void);
int VS_MULTI_LIST_StateTeardown(u8 *p) { VS_MULTI_LIST_DeleteVBlankTask(p); BG_SYS_SetMainPlaneVisible(0x17,0); VS_MULTI_LIST_DeleteBgFrames((int *)p); VS_MULTI_LIST_ExitIcons((char *)p); VS_MULTI_LIST_DeleteWindows(p); VS_MULTI_LIST_DeleteTextResources(p); VS_MULTI_LIST_ExitBgs(); return 5; }
