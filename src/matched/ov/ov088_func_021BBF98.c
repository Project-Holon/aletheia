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
 *   func_0201F7A8  0x0201F7A8  thumb
 */
#include "../include/Obj20822.h"

typedef unsigned int u32;

extern void func_0201F7A8(void *desc, u32 kind);

void STARTMENU_HideMessageWindow(char *p)
{
    func_0201F7A8(((struct Obj20822 *)p)->fE8, 1);
}
