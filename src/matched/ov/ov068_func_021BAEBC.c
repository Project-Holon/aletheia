/*
 * function: OPTION_MENU_GetMessageBoxAnswer
 * address:  0x021BAEBC
 * packet:   pkt_ov068_021BAEBC
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (halfword getter) found while matching OPTION_MENU_StateDiscardPrompt.
 */
#include "../include/Obj20648.h"

typedef unsigned char  u8;
typedef unsigned short u16;

u16 OPTION_MENU_GetMessageBoxAnswer(u8 *p)
{
    return ((struct Obj20648 *)p)->f54;
}
