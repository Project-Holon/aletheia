/*
 * function: STARTMENU_TitleDemoUpdateParts
 * address:  0x021B9928
 * packet:   pkt_ov088_021B9928
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STARTMENU_CaptureRunTasks  0x021B99E0  thumb  ov088
 *   STARTMENU_LogoUpdate  0x021B9BD4  thumb  ov088
 *   STARTMENU_Demo3dUpdate  0x021B9DD0  thumb  ov088
 *   STARTMENU_SpritesUpdate  0x021B9F68  thumb  ov088
 */
#include "../include/Obj07719.h"

extern void STARTMENU_CaptureRunTasks(void *, unsigned short);
extern void STARTMENU_LogoUpdate(void *, unsigned short);
extern void STARTMENU_Demo3dUpdate(void *, unsigned short);
extern void STARTMENU_SpritesUpdate(void *, unsigned short);

void STARTMENU_TitleDemoUpdateParts(unsigned char *p)
{
    STARTMENU_CaptureRunTasks(p + 0x08, ((struct Obj07719 *)p)->f2);
    STARTMENU_LogoUpdate(p + 0x14, ((struct Obj07719 *)p)->f2);
    STARTMENU_Demo3dUpdate(p + 0x40, ((struct Obj07719 *)p)->f2);
    STARTMENU_SpritesUpdate(p + 0x54, ((struct Obj07719 *)p)->f2);
}
