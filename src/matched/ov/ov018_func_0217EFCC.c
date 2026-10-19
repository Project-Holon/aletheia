/*
 * function: INTRUDE_SUBDISP_InitTownState
 * address: 0x0217EFCC
 * packet: pkt_ov018_0217EFCC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetOwnNetId 0x02012B58 thumb
 *   INTRUDE_SUBDISP_UpdateTownState 0x0217F008 thumb ov018
 */
#include "../include/Obj00399.h"
typedef unsigned char u8;
typedef struct { u8 a, b, c, d; int e, f; } State;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern void INTRUDE_SUBDISP_UpdateTownState(char *, char *);
void INTRUDE_SUBDISP_InitTownState(char *p, char *q)
{
    State *s;
    void *h;
    s = (State *)(p + 0xd8);
    h = GAMESYSTEM_GetGameData(((struct Obj00399 *)p)->f0);
    if (q == 0) {
        s->a = GAME_DATA_GetOwnNetId(h);
        s->b = 1 << s->a;
        s->c = 1;
        s->d = 0;
        s->e = 0;
        s->f = 0;
    } else {
        INTRUDE_SUBDISP_UpdateTownState(p, q);
    }
}
