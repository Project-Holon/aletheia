/*
 * function: BEACON_DETAIL_GRA_StateClose
 * address:  0x021BBF14
 * packet:   pkt_021BBF14
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_DETAIL_GRA_RefreshButtons  0x021BCCBC  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25767.h"

typedef unsigned char  u8;
extern void BEACON_DETAIL_GRA_RefreshButtons(u8 *p);

int BEACON_DETAIL_GRA_StateClose(char *p)
{
    if (((struct Obj25767 *)p)->fC != 0)
        return 3;
    BEACON_DETAIL_GRA_RefreshButtons((u8 *)p);
    return 2;
}
