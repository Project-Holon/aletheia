/*
 * function: FIELDMAP_Create
 * address:  0x02188030
 * packet:   pkt_ov021_02188030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   ZONEDATA_CreateAreaData  0x0201407C  thumb
 *   FIELDMAP_GetCtrlFuncs  0x02189BA8  thumb  ov021
 *   sFieldMapSourceName     0x021DD9C0  data  a4
 */
#include "../include/Obj03102.h"

typedef unsigned short u16;

extern int sFieldMapSourceName;

void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, u16 tag);
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
unsigned char *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
typedef unsigned int   u32;
u32 ZONEDATA_GetAreaId(u32 id);
int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
int ZONEDATA_CreateAreaData(int a, int b, int c);
int FIELDMAP_GetCtrlFuncs(int x);

void *FIELDMAP_Create(int a, int b)
{
    char *p = (char *)func_02030734(b, 0x154, 1, (const char *)(&sFieldMapSourceName), 0x209);

    ((struct Obj03102 *)p)->f0 = b;
    ((struct Obj03102 *)p)->fC0 = 0;
    ((struct Obj03102 *)p)->f4 = a;
    ((struct Obj03102 *)p)->f8 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    ((struct Obj03102 *)p)->fD0 = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a));
    {
        int r7 = ZONEDATA_GetAreaId(((struct Obj03102 *)p)->fD0);
        ((struct Obj03102 *)p)->fC = ZONEDATA_CreateAreaData(b, r7, COMM_PLAYER_SUPPORT_GetInfoCode((void *)a));
    }
    ((struct Obj03102 *)p)->f108 = FIELDMAP_GetCtrlFuncs(((struct Obj03102 *)p)->fD0);
    return p;
}
