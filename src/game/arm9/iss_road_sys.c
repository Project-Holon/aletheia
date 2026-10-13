/*
 * file:     iss_road_sys.c
 * unit:     yes
 * function: ISS_ROAD_SYS_Create, ISS_ROAD_SYS_Delete, ISS_ROAD_SYS_Update, ISS_ROAD_SYS_Start, ISS_ROAD_SYS_Stop, ISS_ROAD_SYS_Activate, ISS_ROAD_SYS_Deactivate
 * address:  0x0202B1AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   ISS_ROAD_SYS_UpdateVolume  0x0202B230  thumb
 *   ISS_ROAD_SYS_ApplyVolume  0x0202B2BC  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 */

struct PlayerWork;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct PlayerPosition {
    u32 x, y, z;
} PlayerPosition;

/* Footstep-road sound state: volume rises while the player moves, falls when still. */
typedef struct IssRoadSys {
    u32 isActive;
    u32 volume;
    struct PlayerWork *player;
    PlayerPosition lastPosition;
} IssRoadSys;

typedef unsigned short u16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);
extern u32 func_020307B0(void *p);
extern void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road);
extern void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road);
IssRoadSys *ISS_ROAD_SYS_Create(u32 player, u32 heapId);
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
IssRoadSys *ISS_ROAD_SYS_Create(u32 player, u32 heapId)
{
    IssRoadSys *road = (IssRoadSys *)func_02030734(heapId, 0x18, 0,
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
    func_020307B0(road);
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
