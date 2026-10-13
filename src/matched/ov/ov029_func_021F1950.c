/*
 * function: C_GEAR_CreateHudActors
 * address:  0x021F1950
 * packet:   pkt_ov029_021F1950
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 *   C_GEAR_SetPaintModeIcon  0x021F1910  thumb  ov029
 *   C_GEAR_UpdateClock  0x021F1F80  thumb  ov029
 *   C_GEAR_UpdateTileMarkers  0x021F20AC  thumb  ov029
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 */
#include "../include/Obj00811.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern int OS_IsRunOnTwl(void);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void C_GEAR_SetPaintModeIcon(char *p, int on);
extern void C_GEAR_UpdateClock(char *p);
extern void C_GEAR_UpdateTileMarkers(char *p);
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];

void C_GEAR_CreateHudActors(char *p)
{
    int i;
    int j;
    S13Rec s;
    int *q;

    BG_SYS_SetSubPlaneVisible(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        s.x = d_021F3531[i];
        s.y = d_021F353C[i];
        s.z = d_021F3526[i];
        if (s.z == 6 && OS_IsRunOnTwl()) {
            s.z = 7;
        }
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x4b] = (int)CLACT_CreateActor((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x4b], 0);
        CLACT_SetActorVisible((struct Actor *)q[0x4b], 0);
    }
    C_GEAR_SetPaintModeIcon(p, 0);
    for (j = 0; j < 3; j++) {
        s.x = 8;
        s.y = 8;
        s.z = d_021F3548[j];
        s.a = 0;
        s.b = 2;
        q = (int *)(p + j * 4);
        q[0x56] = (int)CLACT_CreateActor((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x56], 0);
        CLACT_SetActorVisible((struct Actor *)q[0x56], 0);
    }
    C_GEAR_UpdateClock(p);
    C_GEAR_UpdateTileMarkers(p);
}
