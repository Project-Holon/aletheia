/*
 * function: MBi_InitSendFixedBeacon
 * address:  0x021F40F4
 * packet:   pkt_ov107_021F40F4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_InitSendFixedBeacon (libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * symbols:
 *   g_021F6EF4  0x021F6EF4  data
 */

#include "../include/G_SUnlock.h"

extern struct SUnlock g_021F6EF4;

void MBi_InitSendFixedBeacon(void)
{
    if (((unsigned char *)&g_021F6EF4)[0x24] != 2)
        return;
    if (*(unsigned char *)(*(char **)(((unsigned char *)&g_021F6EF4) + 0x1C) + 0x4B2) == 0) {
        ((unsigned char *)&g_021F6EF4)[0x28] = 9;
        *(void **)(((unsigned char *)&g_021F6EF4) + 0x20) = *(char **)(((unsigned char *)&g_021F6EF4) + 0x1C);
    } else {
        ((unsigned char *)&g_021F6EF4)[0x28] = 4;
        *(void **)(((unsigned char *)&g_021F6EF4) + 0x20) = *(char **)(((unsigned char *)&g_021F6EF4) + 0x1C) + 0x220;
    }
    ((unsigned char *)&g_021F6EF4)[0x24] = 3;
}
