/*
 * function: FIELDMAP_ChangeZone
 * address:  0x021893C0
 * packet:   pkt_ov021_021893C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   GFL_NET_SetDeviceModeIfRunning  0x0203D12C  arm
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   ZONEDATA_GetLocationVec  0x020141E0  thumb
 *   MAP_MATRIX_GetZoneIdByPos  0x02159BD4  thumb  ov010
 *   FLDMMDL_SysDeleteZoneChangeMmdl  0x0216DF1C  thumb  ov010
 *   EVENTDATA_SYSTEM_Clear  0x021623DC  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   EVENTDATA_SYSTEM_LoadEventData  0x0216242C  thumb  ov010
 *   FIELD_MAP_CHANGE_ApplyZoneHeader  0x021643AC  thumb  ov010
 *   FIELDMAP_ChangeZoneSound  0x02189518  thumb  ov021
 *   FIELDMAP_ChangeZoneFog  0x0218958C  thumb  ov021
 *   FIELDMAP_ChangeZoneWeather  0x02189560  thumb  ov021
 *   FIELDMAP_ChangeZoneCamera  0x021895D0  thumb  ov021
 *   FIELDMAP_SetPlayerZoneId  0x021895BC  thumb  ov021
 *   FIELDMAP_SetupSceneArea  0x02189684  thumb  ov021
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   MAP_REPLACE_SetArriveFlag  0x0215A014  thumb  ov010
 *   SCRIPT_SYS_RunZoneChangeScript  0x02158AE0  thumb  ov010
 *   FIELDMAP_AddZoneNpcs  0x021894E0  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_ClearHoldMode  0x0215874C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03104.h"
#include "../include/Obj05698.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x, y, z;
} Vec;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
extern void GFL_NET_SetDeviceModeIfRunning(int a);
extern void EFFECT_ENCOUNT_Reset(u8 *p);
struct Rec020141E0;
struct Vec020141E0;
extern void ZONEDATA_GetLocationVec(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern int MAP_MATRIX_GetZoneIdByPos(int a0, int a1, int a2);
extern void FLDMMDL_SysDeleteZoneChangeMmdl(u32 a);
extern void EVENTDATA_SYSTEM_Clear(char *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void EVENTDATA_SYSTEM_LoadEventData(void *a0, u16 a1, u8 a2);
extern void FIELD_MAP_CHANGE_ApplyZoneHeader(void *a, void *b);
extern void FIELDMAP_ChangeZoneSound(char *p, unsigned int idx);
extern void FIELDMAP_ChangeZoneFog(unsigned char *p, int id);
extern void FIELDMAP_ChangeZoneWeather(int *p, int b);
extern void FIELDMAP_ChangeZoneCamera(u8 *p, u32 v);
extern int FIELDMAP_SetPlayerZoneId(void *a, u32 b);
extern void FIELDMAP_SetupSceneArea(char *p, unsigned int id);
extern int GAMESYSTEM_IsEventActive(char *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern void GAME_BEACON_SetZone(u32 a0, u32 a1);
extern void MAP_REPLACE_SetArriveFlag(void *a, int b);
extern void SCRIPT_SYS_RunZoneChangeScript(void *a0, void *a1);
extern void FIELDMAP_AddZoneNpcs(int a, int b, int c, int d);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void INTRUDE_COMM_ClearHoldMode(void *a);

void FIELDMAP_ChangeZone(u8 *p)
{
    u8 *q = p + 0xD4;
    void *sys;
    u32 v;
    Vec pos;
    u32 s4;
    u32 s0;

    sys = GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj03104 *)p)->f4));
    s4 = GAME_DATA_GetEventData(sys);
    s0 = ((struct Obj03104 *)p)->f38;
    v = GAME_DATA_GetFieldWork((const struct BigObj *)(((struct Obj03104 *)p)->f8));
    GFL_NET_SetDeviceModeIfRunning(2);
    EFFECT_ENCOUNT_Reset((u8 *)(((struct Obj03104 *)p)->f90));
    ZONEDATA_GetLocationVec((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&pos));
    v = MAP_MATRIX_GetZoneIdByPos(v, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FLDMMDL_SysDeleteZoneChangeMmdl(s0);
    EVENTDATA_SYSTEM_Clear((char *)s4);
    EVENTDATA_SYSTEM_LoadEventData((void *)s4, v, GAME_DATA_GetSeason(sys));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    FIELD_MAP_CHANGE_ApplyZoneHeader(sys, p);
    FIELDMAP_ChangeZoneSound((char *)p, v);
    FIELDMAP_ChangeZoneFog(p, v);
    FIELDMAP_ChangeZoneWeather((int *)p, (u32)v);
    FIELDMAP_ChangeZoneCamera(p, v);
    FIELDMAP_SetPlayerZoneId(sys, v);
    FIELDMAP_SetupSceneArea((char *)p, v);
    if (((struct Obj03104 *)p)->f30 != 0 && GAMESYSTEM_IsEventActive((char *)((struct Obj03104 *)p)->f4) == 0)
        FIELD_PLACE_NAME_OnZoneChange((void *)(((struct Obj03104 *)p)->f30), v);
    ((struct Obj05698 *)q)->f4 = v;
    GAME_BEACON_SetZone((u16)v, (u32)sys);
    MAP_REPLACE_SetArriveFlag(sys, v);
    SCRIPT_SYS_RunZoneChangeScript((void *)(((struct Obj03104 *)p)->f4), (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELDMAP_AddZoneNpcs((int)sys, s0, s4, v);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    INTRUDE_COMM_ClearHoldMode((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)((struct Obj03104 *)p)->f4));
}
