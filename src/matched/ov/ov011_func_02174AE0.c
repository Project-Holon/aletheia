/*
 * function: INTRUDE_COMM_UpdateSeasonState
 * address:  0x02174AE0
 * packet:   pkt_ov011_02174AE0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   INTRUDE_COMM_SetState  0x02174E14  thumb ov011
 */
#include "../include/Obj09347.h"

typedef unsigned int   u32;
struct BigObj;
u32 GAME_COMM_GetGameData(void *obj);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
struct Sub02014444Obj;
unsigned char FIELD_STATUS_GetSeasonDispFlag(struct Sub02014444Obj *o);
typedef unsigned char  u8;
void INTRUDE_COMM_SetState(u8 *p, int a);

void INTRUDE_COMM_UpdateSeasonState(unsigned char *p)
{
    int r;

    r = FIELD_STATUS_GetSeasonDispFlag((struct Sub02014444Obj *)GAME_DATA_GetMoveModelSys((const struct BigObj *)GAME_COMM_GetGameData((void *)(((struct Obj09347 *)p)->f4))));
    switch (r) {
    case 0:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 2) {
            INTRUDE_COMM_SetState(p, 0);
        }
        break;
    case 1:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 0) {
            INTRUDE_COMM_SetState(p, 2);
        }
        break;
    }
}
