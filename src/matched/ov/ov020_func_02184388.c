/*
 * function: EVENT_MAPCHANGE_EntranceEvent
 * address:  0x02184388
 * packet:   pkt_ov020_02184388
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_MAPCHANGE_CheckSeasonChange  0x0218403C  thumb  ov020
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   EVENT_MAPCHANGE_SetupExitEntranceParam  0x0218409C  thumb  ov020
 *   EVENT_ENTRANCE_IN_Create  0x021BD648  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_MAPCHANGE_SetupEnterEntranceParam  0x02184120  thumb  ov020
 *   EVENT_ENTRANCE_OUT_Create  0x021BD9BC  thumb  ov021
 */
#include "../include/Obj00082.h"

typedef unsigned char u8;

extern void EVENT_MAPCHANGE_CheckSeasonChange(u8 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern void EVENT_MAPCHANGE_SetupExitEntranceParam(u8 *p, int a);
extern int EVENT_ENTRANCE_IN_Create(u8 *p);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern void EVENT_MAPCHANGE_SetupEnterEntranceParam(u8 *p, int a);
typedef unsigned int   u32;
extern int EVENT_ENTRANCE_OUT_Create(u32 *p);

int EVENT_MAPCHANGE_EntranceEvent(int a, int *state, u8 *p)
{
    void *w = ((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(p);
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((u8 *)w));
        EVENT_MAPCHANGE_SetupExitEntranceParam(p, a);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_ENTRANCE_IN_Create(p + 0x4c));
        (*state)++;
        return 0x21;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)a, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 0));
        (*state)++;
        break;
    case 2:
        EVENT_MAPCHANGE_SetupEnterEntranceParam(p, a);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_ENTRANCE_OUT_Create((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
