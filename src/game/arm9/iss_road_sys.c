/*
 * file:     iss_road_sys.c
 * unit:     yes
 * function: ISS_ROAD_SYS_Create, ISS_ROAD_SYS_Delete, ISS_ROAD_SYS_Update, ISS_ROAD_SYS_Start, ISS_ROAD_SYS_Stop, ISS_ROAD_SYS_Activate, ISS_ROAD_SYS_Deactivate, ISS_ROAD_SYS_UpdateVolume, ISS_ROAD_SYS_HasPlayerMoved, ISS_ROAD_SYS_FadeIn, ISS_ROAD_SYS_FadeOut, ISS_ROAD_SYS_ApplyVolume
 * address:  0x0202B1AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_road_sys.c, iss_road_sys_tail.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ISS_ROAD_SYS_UpdateVolume  0x0202B230  thumb
 *   ISS_ROAD_SYS_ApplyVolume  0x0202B2BC  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 */
#include "iss_road_sys_shared_types.h"

struct PlayerWork;

#include "../types.h"

typedef struct PlayerPosition {
    u32 x, y, z;
} PlayerPosition;

/* Footstep-road sound state: volume rises while the player moves, falls when still. */
typedef struct IssRoadSys {
    u32 isActive;
    s32 volume;
    struct PlayerWork *player;
    PlayerPosition lastPosition;
} IssRoadSys;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);

extern u32 GFL_HEAP_Free(void *p);

extern void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road);

void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road);
struct Location;

IssRoadSys *ISS_ROAD_SYS_Create(struct Location *player, u32 heapId);

void ISS_ROAD_SYS_Delete(void *road);

void ISS_ROAD_SYS_Update(IssRoadSys *road);

void ISS_ROAD_SYS_Start(IssRoadSys *road);

void ISS_ROAD_SYS_Stop(IssRoadSys *road);

void ISS_ROAD_SYS_Activate(IssRoadSys *road);

void ISS_ROAD_SYS_Deactivate(IssRoadSys *road);

/*
 * Allocates a 0x18-byte road state with the allocator entry point, clears
 * its active flag and volume, stores the player at +8, and copies the
 * player's 12-byte position into +0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Create.c  *       --func ISS_ROAD_SYS_Create --addr 0x0202B1AC --thumb --cc 1.1p1
 */
IssRoadSys *ISS_ROAD_SYS_Create(struct Location *player, u32 heapId)
{
    IssRoadSys *road = (IssRoadSys *)GFL_HEAP_Alloc(heapId, 0x18, 0,
                                                   (const void *)0x020A7708, 0x4a);
    const PlayerPosition *position;

    road->isActive = 0;
    road->volume = 0;
    road->player = (struct PlayerWork *)player;

    position = (const PlayerPosition *)GAME_DATA_GetPlayerPosition((struct PlayerWork *)player);
    road->lastPosition = *position;
    return road;
}

void ISS_ROAD_SYS_Delete(void *road)
{
    GFL_HEAP_Free(road);
}

/*
 * A bare tail-call thunk to ISS_ROAD_SYS_UpdateVolume.
 *
 * Closed by the `matched` class: 0x0202B230 was filed as an EXACT entry in this wave.
 */
void ISS_ROAD_SYS_Update(IssRoadSys *road)
{
    ISS_ROAD_SYS_UpdateVolume(road);
}

/*
 * A bare tail-call thunk to ISS_ROAD_SYS_Activate.
 */
void ISS_ROAD_SYS_Start(IssRoadSys *road)
{
    ISS_ROAD_SYS_Activate(road);
}

void ISS_ROAD_SYS_Stop(IssRoadSys *road)
{
    ISS_ROAD_SYS_Deactivate(road);
}

/*
 * When the road sound is idle, marks it active, clears its volume and
 * applies the volume through ISS_ROAD_SYS_ApplyVolume.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Activate.c  *       --func ISS_ROAD_SYS_Activate --addr 0x0202B20C --thumb --cc 1.1p1
 */
void ISS_ROAD_SYS_Activate(IssRoadSys *road)
{
    if (road->isActive == 0) {
        road->isActive = 1;
        road->volume = 0;
        ISS_ROAD_SYS_ApplyVolume(road);
    }
}

/*
 * Clears the active flag when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Deactivate.c  *       --func ISS_ROAD_SYS_Deactivate --addr 0x0202B224 --thumb --cc 1.1p1
 */
void ISS_ROAD_SYS_Deactivate(IssRoadSys *road)
{
    if (road->isActive != 0) {
        road->isActive = 0;
    }
}

extern PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);

extern void GFL_USE_SetBgmTrackVolume(u32 a, u32 b);

void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road);

u32 ISS_ROAD_SYS_HasPlayerMoved(IssRoadSys *road);

void ISS_ROAD_SYS_FadeIn(IssRoadSys *road);

void ISS_ROAD_SYS_FadeOut(IssRoadSys *road);

/*
 * Road sound update. When the road sound is active, raises the volume if the
 * player moved since the last call, otherwise lowers it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_UpdateVolume.c \
 *       --func ISS_ROAD_SYS_UpdateVolume --addr 0x0202B230 --thumb --cc 1.1p1
 */
void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road)
{
    if (road->isActive == 0) {
        return;
    }
    if (ISS_ROAD_SYS_HasPlayerMoved(road) != 0) {
        ISS_ROAD_SYS_FadeIn(road);
    } else {
        ISS_ROAD_SYS_FadeOut(road);
    }
}

/*
 * Compares the 12-byte last position against the player's current position,
 * then stores the current position either way, and reports whether they
 * differed.
 *
 * The guard has to be written as a conjunction of equalities over subscripts:
 * `if (s[0] == d[0] && s[1] == d[1] && s[2] == d[2]) differ = 0; else differ = 1;`
 * Each test then branches *away* to the shared "1" block and the "0" block falls
 * through, which is the original shape (movs r3,#0; b over; movs r3,#1).  The
 * disjunction of inequalities is the same value but emits the last test with
 * the opposite polarity; the ternary spelling keeps the polarity but moves the
 * copy, and loses the match.
 */
u32 ISS_ROAD_SYS_HasPlayerMoved(IssRoadSys *road)
{
    u32 *position = (u32 *)GAME_DATA_GetPlayerPosition(road->player);
    int moved;

    if (position[0] == road->lastPosition.x && position[1] == road->lastPosition.y &&
        position[2] == road->lastPosition.z) {
        moved = 0;
    } else {
        moved = 1;
    }
    road->lastPosition = *(PlayerPosition *)position;
    return (u32)moved;
}

/*
 * Raises the signed volume by 8, saturating at 0x7f, and applies it.
 */
void ISS_ROAD_SYS_FadeIn(IssRoadSys *road)
{
    s32 volume = road->volume;

    if (volume < 0x7f) {
        volume += 8;
        if (volume > 0x7f) {
            volume = 0x7f;
        }
        road->volume = volume;
        ISS_ROAD_SYS_ApplyVolume(road);
    }
}

/*
 * Lowers the volume by 8, saturating at 0, and applies it.
 */
void ISS_ROAD_SYS_FadeOut(IssRoadSys *road)
{
    s32 volume = road->volume;

    if (volume > 0) {
        volume -= 8;
        if (volume < 0) {
            volume = 0;
        }
        road->volume = volume;
        ISS_ROAD_SYS_ApplyVolume(road);
    }
}

/*
 * Tail-calls GFL_USE_SetBgmTrackVolume(0x300, volume).
 */
void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road)
{
    GFL_USE_SetBgmTrackVolume(0x300, road->volume);
}
