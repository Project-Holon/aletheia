/*
 * function: INTRUDE_SUBDISP_IsAlone
 * address: 0x0217F284
 * packet: pkt_ov018_0217F284
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetOwnNetId 0x02012B58 thumb
 *   INTRUDE_COMM_HasUnlockFlags 0x02158590 thumb ov010
 */
#include "../include/Obj12494.h"
typedef unsigned char u8;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern int INTRUDE_COMM_HasUnlockFlags(void *);
int INTRUDE_SUBDISP_IsAlone(u8 *p)
{
    void *q = GAMESYSTEM_GetGameData(((struct Obj12494 *)p)->f0);
    if (((struct Obj12494 *)p)->fE4 == 0 && GAME_DATA_GetOwnNetId(q) == 0 && INTRUDE_COMM_HasUnlockFlags(q) == 0) return 1;
    return 0;
}
