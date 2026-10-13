/*
 * function: EVENT_MAPCHANGE_DetachedTailEvent
 * address:  0x02184504
 * packet:   pkt_ov020_02184504
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 */
#include "../include/Obj04972.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
struct Evt;
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(int a, int b);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);

int EVENT_MAPCHANGE_DetachedTailEvent(int a, int *state, u8 *p)
{
    int r;
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04972 *)p)->f0;
    z = ((struct Obj04972 *)p)->f8;
    y = ((struct Obj04972 *)p)->f4;
    v = GAME_DATA_GetBgmInfo((const struct BigObj *)y);

    switch (*state) {
    case 0:
        r = (int)EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 1:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(v, y, ((struct Obj04972 *)p)->f14, (u8)((struct Obj04972 *)p)->f4A);
        FIELD_SOUND_SYSTEM_PostFadeIn(v, y);
        (*state)++;
        break;
    case 2:
        r = (int)EVENT_MAPCHANGE_CreateChangeFieldEvent(p, ((struct Obj04972 *)p)->f30);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
