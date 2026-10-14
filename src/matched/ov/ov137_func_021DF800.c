/*
 * function: GURU2_MAIN_SetupAll
 * address: 0x021DF800
 * packet: pkt_ov137_021DF800
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_SetupVram 0x021DF984 thumb ov137
 *   GURU2_MAIN_Setup3dSystem 0x021DFAD8 thumb ov137
 *   GURU2_MAIN_SetupBg 0x021DFB60 thumb ov137
 *   GURU2_MAIN_CreatePaletteAnim 0x021DFEC4 thumb ov137
 *   GURU2_MAIN_InitActorSystem 0x021DFF44 thumb ov137
 *   GURU2_MAIN_LoadBgPalette 0x021DFC74 thumb ov137
 *   GURU2_MAIN_CreateWindows 0x021DFFF8 thumb ov137
 *   GURU2_MAIN_LoadActorResources 0x021DFF70 thumb ov137
 *   GURU2_MAIN_ShowPlanes 0x021DF998 thumb ov137
 */
extern void GURU2_MAIN_SetupVram(char *);
typedef unsigned char  u8;
extern void GURU2_MAIN_Setup3dSystem(u8 *p);
extern void GURU2_MAIN_SetupBg(char *);
extern void GURU2_MAIN_CreatePaletteAnim(char *);
extern void GURU2_MAIN_InitActorSystem(u8 *p);
extern void GURU2_MAIN_LoadBgPalette(char *);
extern void GURU2_MAIN_CreateWindows(u8 *p);
extern void GURU2_MAIN_LoadActorResources(u8 *p);
extern void GURU2_MAIN_ShowPlanes(char *);
void GURU2_MAIN_SetupAll(char *p){GURU2_MAIN_SetupVram(p);GURU2_MAIN_Setup3dSystem((u8 *)p);GURU2_MAIN_SetupBg(p);GURU2_MAIN_CreatePaletteAnim(p);GURU2_MAIN_InitActorSystem((u8 *)p);GURU2_MAIN_LoadBgPalette(p);GURU2_MAIN_CreateWindows((u8 *)p);GURU2_MAIN_LoadActorResources((u8 *)p);GURU2_MAIN_ShowPlanes(p);}
