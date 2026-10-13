/*
 * function: FIELDMAP_CheckZoneBoundary
 * address:  0x02189370
 * packet:   pkt_ov021_02189370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   ZONEDATA_GetLocationVec  0x020141E0  thumb
 *   MAP_MATRIX_IsInRangeByPos  0x02159C48  thumb  ov010
 *   MAP_MATRIX_GetZoneIdByPos  0x02159BD4  thumb  ov010
 */
#include "../include/Obj05698.h"
#include "../include/Obj19497.h"

typedef struct Vec { int x, y, z; } Vec;

typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
struct Rec020141E0;
struct Vec020141E0;
extern void ZONEDATA_GetLocationVec(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern int MAP_MATRIX_IsInRangeByPos(int a0, int a1, int a2);
extern int MAP_MATRIX_GetZoneIdByPos(int a0, int a1, int a2);

u32 FIELDMAP_CheckZoneBoundary(char *p)
{
    Vec v;
    char *q;
    void *m;
    int r;

    q = p + 0xd4;
    m = (void *)GAME_DATA_GetFieldWork(((struct Obj19497 *)p)->f8);
    ZONEDATA_GetLocationVec((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (MAP_MATRIX_IsInRangeByPos((int)m, v.x, v.z) == 1) {
        r = MAP_MATRIX_GetZoneIdByPos((int)m, v.x, v.z);
        if (r != 0xFFFF && r != ((struct Obj05698 *)q)->f4)
            return 1;
    }
    return 0;
}
