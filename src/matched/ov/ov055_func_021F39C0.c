/*
 * function: CROWD_Init
 * address:  0x021F39C0
 * packet:   pkt_ov055_021F39C0
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_CLOCK_GetTimeZone  0x021690B4  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   CROWD_LoadConfig  0x021F3E84  thumb  ov055
 *   CROWD_CreatePerson  0x021F3C2C  thumb  ov055
 *   CROWD_SpawnInitialPeople  0x021F405C  thumb  ov055
 *   CROWD_InitChatter  0x021F43D8  thumb  ov055
 *   FIELDMAP_SetZoneEffectWork  0x02189A68  thumb  ov021
 */
#include "../include/Obj09846.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
struct O;
struct T;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int FIELD_CLOCK_GetTimeZone(int);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void CROWD_LoadConfig(char *, int, int, int);
extern void CROWD_CreatePerson(struct O *o, int a, int b, const struct T *s, int i);
struct S;
extern void CROWD_SpawnInitialPeople(struct S *p, char *q, int k);
extern void CROWD_InitChatter(char *, int, char *, int, int);
extern void FIELDMAP_SetZoneEffectWork(char *a, int b);

void CROWD_Init(int a, int b, char *c)
{
    int i;
    int t4, t0, t1, t2, t3;

    t0 = FIELDMAP_GetMsgBg((u8 *)b);
    t1 = (int)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)b));
    ((struct Obj09846 *)c)->f0 = FIELDMAP_GetFieldPlayer((void *)b);
    ((struct Obj09846 *)c)->f4 = FIELDMAP_GetMmdlSys((void *)b);
    t2 = FIELDMAP_GetZoneId((u8 *)b);
    t3 = FIELD_CLOCK_GetTimeZone(t1);
    t4 = FIELDMAP_GetHeapId((u8 *)b);
    CROWD_LoadConfig(c + 0x308, t3, t2, t4);
    for (i = 0; i < 0x20; i++)
        CROWD_CreatePerson((struct O *)(c + 8 + i * 0x18), (int)(((struct Obj09846 *)c)->f4), t2, (const struct T *)(c + 0x308), i);
    CROWD_SpawnInitialPeople((struct S *)(c + 0x308), c, t3);
    CROWD_InitChatter(c + 0x348, t0, c + 0x308, t3, t4);
    FIELDMAP_SetZoneEffectWork((char *)b, (int)c);
}
