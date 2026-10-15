/*
 * function: STARTMENU_HideMessageWindow
 * address:  0x021BBF98
 * packet:   pkt_ov088_021BBF98
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub after STARTMENU_StartMessage (function_starts seed);
 * called by STARTMENU_StateConnectPrompt.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 */
#include "../include/Obj20822.h"

typedef unsigned int u32;

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

void STARTMENU_HideMessageWindow(char *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj20822 *)p)->fE8, 1);
}
