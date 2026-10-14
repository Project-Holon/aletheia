/*
 * function: GURU2_MAIN_TeardownAll
 * address: 0x021DF83C
 * packet: pkt_ov137_021DF83C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_HidePlanes 0x021DFA14 thumb ov137
 *   GURU2_MAIN_FreeActorResources 0x021DFFC8 thumb ov137
 *   GURU2_MAIN_DeleteWindows 0x021E00D4 thumb ov137
 *   GURU2_MAIN_ExitBg 0x021DFE40 thumb ov137
 *   GURU2_MAIN_DeletePaletteAnim 0x021DFEFC thumb ov137
 *   GURU2_MAIN_DeleteCamera 0x021E04B4 thumb ov137
 */
extern void GURU2_MAIN_HidePlanes(char *);
typedef unsigned char  u8;
extern void GURU2_MAIN_FreeActorResources(u8 *p);
extern void GURU2_MAIN_DeleteWindows(u8 *p);
extern void GURU2_MAIN_ExitBg(char *);
extern void GURU2_MAIN_DeletePaletteAnim(char *);
extern void GURU2_MAIN_DeleteCamera(u8 *p);
void GURU2_MAIN_TeardownAll(char *p){GURU2_MAIN_HidePlanes(p);GURU2_MAIN_FreeActorResources((u8 *)p);GURU2_MAIN_DeleteWindows((u8 *)p);GURU2_MAIN_ExitBg(p);GURU2_MAIN_DeletePaletteAnim(p);GURU2_MAIN_DeleteCamera((u8 *)p);}
