/*
 * function: EVENT_GAMECLEAR_InitHallOfFameParam
 * address:  0x0215F900
 * packet:   pkt_0215F900
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three arm9 size reads on the record's handle, cached at three fields.
 *
 * symbols:
 *   GAME_DATA_GetMyParty   0x02012934  thumb
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   GAME_DATA_GetPlayTime   0x02012FCC  thumb
 */
#include "../include/Obj04883.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int GAME_DATA_GetPlayTime(int p0);

void EVENT_GAMECLEAR_InitHallOfFameParam(void *a0)
{
    char *p = (char *)a0;

    ((struct Obj04883 *)p)->f1C = GAME_DATA_GetMyParty(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f20 = (int)GAME_DATA_GetMyStatus(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f24 = GAME_DATA_GetPlayTime((int)(((struct Obj04883 *)p)->f4));
}

