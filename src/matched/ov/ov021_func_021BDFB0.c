/*
 * function: ENTRANCE_CAMERA_SetupLeaveByRecord
 * address:  0x021BDFB0
 * packet:   pkt_ov021_021BDFB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENTRANCE_CAMERA_SetupLeaveByRecord  0x021BDFB0  thumb
 *   ENTRANCE_CAMERA_GetCamera  0x021BE17C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   ENTRANCE_CAMERA_GetEntranceType  0x021BE194  thumb  ov021
 *   ENTRANCE_CAMERA_LoadRecord  0x021BE148  thumb  ov021
 *   ENTRANCE_CAMERA_AimsAtEntrance  0x021BE1B0  thumb  ov021
 *   FIELD_GROUND_ANIME_GetEntryPos  0x021A7B08  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 */
#include "../include/Obj00282.h"
#include "../include/Obj03139.h"
#include "../include/Obj09656.h"

typedef unsigned short u16;

struct V3 {
    int x;
    int y;
    int z;
};

struct Q {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    struct V3 f40;
};

extern unsigned int ENTRANCE_CAMERA_GetCamera(unsigned char *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned char  u8;
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
typedef unsigned int   u32;
extern int ENTRANCE_CAMERA_GetEntranceType(u32 a);
extern struct Q ENTRANCE_CAMERA_LoadRecord(int a);
extern int ENTRANCE_CAMERA_AimsAtEntrance(u32 a);
extern void FIELD_GROUND_ANIME_GetEntryPos(int a, struct V3 *b);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);
extern void FIELD_CAMERA_ANIME_Setup(int a);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(int a, void *b);

void ENTRANCE_CAMERA_SetupLeaveByRecord(char *a)
{
    char *r6 = a + 8;
    char *r4 = r6 + 0x24;
    struct Q q;
    void *r7;
    int t30;
    int x;
    int y;
    int z;

    ENTRANCE_CAMERA_GetCamera((unsigned char *)a);
    r7 = FIELDMAP_GetFieldPlayer((struct Obj00020 *)(*(unsigned char * *)&((struct Obj00282 *)a)->f0));
    FIELD_PLAYER_GetDirDisp(r7);
    q = ENTRANCE_CAMERA_LoadRecord(ENTRANCE_CAMERA_GetEntranceType((u32)a));
    ((struct Obj09656 *)r6)->f48 = q.f3c;
    ((struct Obj09656 *)r6)->f44 = q.f38;
    t30 = q.f30;
    ((struct Obj00282 *)a)->f68 = t30;
    *(int *)&((struct Obj00282 *)a)->f6C = q.f34;
    if (t30 == 0) {
        return;
    }
    if (ENTRANCE_CAMERA_AimsAtEntrance((u32)a) != 0) {
        FIELD_GROUND_ANIME_GetEntryPos(*(int *)&((struct Obj00282 *)a)->f0, &q.f40);
    } else {
        FIELD_PLAYER_GetPos(r7, (struct VecFx32 *)(&q.f40));
    }
    FIELD_CAMERA_ANIME_Setup(*(int *)&((struct Obj00282 *)a)->f54);
    FIELD_CAMERA_ANIME_GetCurrentParam(*(int *)&((struct Obj00282 *)a)->f4, r6 + 4);
    ((struct Obj09656 *)r6)->f0 = q.f2c;
    ((struct Obj03139 *)r4)->f0 = q.f4;
    ((struct Obj03139 *)r4)->f2 = q.f8;
    ((struct Obj03139 *)r4)->f4 = q.fc << 12;
    z = q.f28 << 12;
    y = q.f24 << 12;
    x = q.f20 << 12;
    ((struct Obj03139 *)r4)->f14 = x;
    ((struct Obj03139 *)r4)->f18 = y;
    ((struct Obj03139 *)r4)->f1C = z;
    if (q.f10 != 0) {
        z = q.f1c << 12;
        y = q.f18 << 12;
        x = q.f14 << 12;
        ((struct Obj03139 *)r4)->f8 = x;
        ((struct Obj03139 *)r4)->fC = y;
        ((struct Obj03139 *)r4)->f10 = z;
    } else {
        *(struct V3 *)(r4 + 8) = q.f40;
    }
}
