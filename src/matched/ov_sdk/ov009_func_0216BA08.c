/*
 * function: DWC_IsServerMyself
 * address:  0x0216BA08
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Whether this host is the match server.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   DWC_GetServerAID  0x0216B9B0  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern unsigned char DWC_GetServerAID(void);

int DWC_IsServerMyself(void)
{
    if (*(char **)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    if (DWC_GetServerAID() == 0xff) {
        return 0;
    }
    return *(unsigned char *)(*(char **)(((char *)&g_021AA878) + 4) + 0x366) == 2;
}
