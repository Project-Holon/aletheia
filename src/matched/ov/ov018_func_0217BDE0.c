/*
 * function: INTRUDE_FIELD_TryStartOfferEvent
 * address:  0x0217BDE0
 * packet:   pkt_ov018_0217BDE0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_IsSessionFinished  0x02175BBC  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   EVENT_COMM_COMMON_CreateOfferEvent  0x02182124  thumb  ov018
 *   gIntrudeOfferZoneIds     0x021DB810  data   ov021  a2
 *   gIntrudeOfferTilePositions     0x021DB834  data   ov021  a2
 */
#include "../include/Obj12483.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { u32 f : 4; u32 g : 28; } Fw;
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { s16 x, y, z, w; } Ent;

extern u16 gIntrudeOfferZoneIds[];
extern Ent gIntrudeOfferTilePositions[];

extern int INTRUDE_COMM_IsSessionAccepted(u8 *);
extern int INTRUDE_COMM_IsSessionFinished(u8 *);
extern u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *);
extern int INTRUDE_COMM_GetJoinStatus(char *p, u8 *q);
struct Ctx;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_GetGridNowPos(void *, Vec3s *);
extern int EVENT_COMM_COMMON_CreateOfferEvent(int, u8 *, u8 *);

int INTRUDE_FIELD_TryStartOfferEvent(int a, u8 *b, int c)
{
    u8 *e;
    int n;
    int idx;
    Vec3s v;

    if (INTRUDE_COMM_IsSessionAccepted(b + 0x1AC) != 1)
        goto fail;
    if (INTRUDE_COMM_IsSessionFinished(b + 0x1AC) != 0)
        goto fail;
    e = INTRUDE_COMM_GetActiveSessionRequest(b + 0x1AC);
    if (e == 0)
        goto fail;
    if (((Fw *)(e + 4))->f != 4)
        goto fail;
    if (((Fh *)(b + 0x86))->f != e[0x28])
        goto fail;
    if (INTRUDE_COMM_GetJoinStatus((char *)b, b + 0x1AC) != 0)
        goto fail;
    n = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a));
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl((void *)c), &v);
    idx = ((struct Obj12483 *)e)->f14;
    if (n != gIntrudeOfferZoneIds[idx])
        goto fail;
    if (v.x != gIntrudeOfferTilePositions[idx].x)
        goto fail;
    if (v.y != gIntrudeOfferTilePositions[idx].y)
        goto fail;
    if (v.z != gIntrudeOfferTilePositions[idx].z)
        goto fail;
    return EVENT_COMM_COMMON_CreateOfferEvent(a, b, e);
fail:
    return 0;
}
