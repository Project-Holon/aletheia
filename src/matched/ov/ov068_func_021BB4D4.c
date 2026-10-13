/*
 * function: OPTION_MENU_StateApply
 * address: 0x021BB4D4
 * packet: pkt_ov068_021BB4D4
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OPTION_MENU_GetListSettings 0x021BA9E0 thumb ov068
 *   OPTION_MENU_WriteSettings 0x021BAFA8 thumb ov068
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   OPTION_MENU_SetRunnerCallback 0x021BB138 thumb ov068
 *   OPTION_MENU_StateFadeOut 0x021BB188 thumb ov068
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a,b,c; } Blk;
extern void OPTION_MENU_GetListSettings(u8 *p,Blk *out);
extern void OPTION_MENU_WriteSettings(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void OPTION_MENU_SetRunnerCallback(void *p,int v);
extern void OPTION_MENU_StateFadeOut(void *p,u32 *state);
void OPTION_MENU_StateApply(void *a,u32 b,u8 *p) { Blk t; OPTION_MENU_GetListSettings(p+0x148,&t); OPTION_MENU_WriteSettings((u8 *)&t); GFL_USE_PlaySeDefaultVolume(0x558); OPTION_MENU_SetRunnerCallback(a,(int)OPTION_MENU_StateFadeOut); }
