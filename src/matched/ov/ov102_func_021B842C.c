/*
 * function: IRC_COMPATIBLE_MENU_UpdateScene
 * address: 0x021B842C
 * packet: pkt_ov102_021B842C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_MENU_UpdateTextQueue 0x021B7CB0 thumb ov102
 *   IRC_COMPATIBLE_MENU_UpdateWindow 0x021B7DC4 thumb ov102
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   IRC_COMPATIBLE_MENU_DrawSprites 0x021B78E4 thumb ov102
 */
#include "../include/Obj22163.h"
extern void IRC_COMPATIBLE_MENU_UpdateTextQueue(unsigned char *); extern int IRC_COMPATIBLE_MENU_UpdateWindow(unsigned char *,unsigned char *); extern void IRC_APPBAR_Update(int); extern void IRC_COMPATIBLE_MENU_DrawSprites(void *);
void IRC_COMPATIBLE_MENU_UpdateScene(unsigned char *p) { IRC_COMPATIBLE_MENU_UpdateTextQueue(p+0x9c); IRC_COMPATIBLE_MENU_UpdateWindow(p+0xac,p+0x9c); IRC_COMPATIBLE_MENU_UpdateWindow(p+0x46c,p+0x9c); IRC_APPBAR_Update(((struct Obj22163 *)p)->f468); IRC_COMPATIBLE_MENU_DrawSprites(p); }
