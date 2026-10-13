/*
 * function: OPTION_MENU_StateKeepSaved
 * address: 0x021BB4A4
 * packet: pkt_ov068_021BB4A4
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OPTION_MENU_WriteSettings 0x021BAFA8 thumb ov068
 *   OPTION_MENU_ApplySoundMode 0x021BACF4 thumb ov068
 *   OPTION_MENU_SetRunnerCallback 0x021BB138 thumb ov068
 *   OPTION_MENU_StateFadeOut 0x021BB188 thumb ov068
 */
#include "../include/Obj20655.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void OPTION_MENU_WriteSettings(u8 *p);
extern void OPTION_MENU_ApplySoundMode(u8 *p,u32 a,u32 b);
extern void OPTION_MENU_SetRunnerCallback(void *p,int v);
extern void OPTION_MENU_StateFadeOut(void *p,u32 *state);
void OPTION_MENU_StateKeepSaved(void *a,u32 b,u8 *p) { OPTION_MENU_WriteSettings(p+0x248); OPTION_MENU_ApplySoundMode(p+0x148,((struct Obj20655 *)p)->f24B,1); OPTION_MENU_SetRunnerCallback(a,(int)OPTION_MENU_StateFadeOut); }
