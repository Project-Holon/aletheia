/*
 * function: WIFICLUB_CreateTrainerActor
 * address:  0x021BB374
 * packet:   pkt_ov099_021BB374
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWifiClubTrainerSpritePos     0x021C37D4  data   ov099  a2
 *   WIFICLUB_DeleteTrainerActor  0x021BB42C  thumb  ov099
 *   func_02009864  0x02009864  thumb
 *   func_02025C88  0x02025C88  thumb
 *   POKEGRA_OpenTrainerHandle  0x0202DA04  thumb
 *   POKEGRA_RegisterTrainerCgr  0x0202DA48  thumb
 *   POKEGRA_RegisterTrainerPalette  0x0202DA18  thumb
 *   POKEGRA_RegisterTrainerCellAnim  0x0202DA6C  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 */
#include "../include/Obj00008.h"

typedef unsigned short u16;

typedef struct {
    u16 v[4];
} T4;

extern const T4 gWifiClubTrainerSpritePos;
extern void WIFICLUB_DeleteTrainerActor(void *p);
typedef unsigned int   u32;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern u32 func_02025C88(u32 x);
extern int POKEGRA_OpenTrainerHandle(int a0);
extern void *POKEGRA_RegisterTrainerCgr(void *a, int b, int c, u16 d);
typedef signed int     s32;
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern void ARC_TOOL_DeleteHandle(void *o);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

void WIFICLUB_CreateTrainerActor(char *p, int a, int b)
{
    T4 t;
    int r;
    void *o;

    t = gWifiClubTrainerSpritePos;
    if (((struct Obj00008 *)p)->f180 != 0)
        WIFICLUB_DeleteTrainerActor(p);
    r = func_02009864(((struct Obj00008 *)p)->f4, a, 8);
    r = func_02025C88(r);
    o = (void *)POKEGRA_OpenTrainerHandle((u16)b);
    ((struct Obj00008 *)p)->f184 = POKEGRA_RegisterTrainerCgr(o, r, 1, b);
    ((struct Obj00008 *)p)->f188 = (void *)POKEGRA_RegisterTrainerPalette((u32)o, r, 1, 0, b);
    ((struct Obj00008 *)p)->f18C = (void *)POKEGRA_RegisterTrainerCellAnim(r, 2, 1, b);
    ARC_TOOL_DeleteHandle(o);
    ((struct Obj00008 *)p)->f180 = CLACT_CreateActor(((struct Obj00008 *)p)->f110, (unsigned int)((struct Obj00008 *)p)->f184, (unsigned int)((struct Obj00008 *)p)->f188, (unsigned int)((struct Obj00008 *)p)->f18C, &t, 1, b);
}
