/*
 * function: UN_SELECT_SceneStepMessageIdle
 * address:  0x021BA208
 * packet:   pkt_021BA208
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UN_SELECT_UpdateMessage  0x021B9C00  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26047.h"

extern int UN_SELECT_UpdateMessage(char *p);

int UN_SELECT_SceneStepMessageIdle(void *unused, char *p)
{
    return UN_SELECT_UpdateMessage((char *)(((struct Obj26047 *)p)->f28)) != 0;
}
