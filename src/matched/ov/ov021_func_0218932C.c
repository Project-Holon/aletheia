/*
 * function: FIELDMAP_CheckPlayerMoved
 * address:  0x0218932C
 * packet:   pkt_ov021_0218932C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   ZONEDATA_GetLocationVec  0x020141E0  thumb
 *   ZONEDATA_SetLocationVec  0x020141F0  thumb
 */
#include "../include/Obj19496.h"

typedef struct Vec { int x, y, z; } Vec;

struct Ctx;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Rec020141E0;
struct Rec020141F0;
struct Rec44;
struct Vec020141E0;
struct Vec020141F0;
struct Vec12;
extern struct Vec12 *GAME_DATA_GetPlayerPosition(struct Rec44 *p);
extern void ZONEDATA_GetLocationVec(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern void ZONEDATA_SetLocationVec(struct Rec020141F0 *p, const struct Vec020141F0 *v);

int FIELDMAP_CheckPlayerMoved(char *p)
{
    Vec v;
    char *q;
    Vec *pos;

    q = p + 0xd4;
    pos = (Vec *)GAME_DATA_GetPlayerPosition(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(((struct Obj19496 *)p)->f4)));
    ZONEDATA_GetLocationVec((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (pos->x != v.x || pos->z != v.z) {
        ZONEDATA_SetLocationVec((struct Rec020141F0 *)q, (const struct Vec020141F0 *)pos);
        return 1;
    }
    return 0;
}
