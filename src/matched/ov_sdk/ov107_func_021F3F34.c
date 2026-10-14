/*
 * function: MB_AddGameInfo
 * address:  0x021F3F34
 * packet:   pkt_ov107_021F3F34
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_AddGameInfo (libmb.TWL.HYB.a mb_gameinfo.o)
 *
 * symbols:
 *   g_021F6EF4     0x021F6EF4  data
 */

#include "../include/G_SUnlock.h"

typedef struct MBGameInfo {
    unsigned char pad[0x4BC];
    struct MBGameInfo *next;
} MBGameInfo;

extern struct SUnlock g_021F6EF4;

void MB_AddGameInfo(MBGameInfo *newGameInfop)
{
    MBGameInfo *gInfop;

    gInfop = g_021F6EF4.list;
    if (gInfop == 0) {
        g_021F6EF4.list = newGameInfop;
    } else {
        while (gInfop->next != 0)
            gInfop = gInfop->next;
        gInfop->next = newGameInfop;
    }
    newGameInfop->next = 0;
}
