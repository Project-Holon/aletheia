/*
 * function: FIELD_PLAYER_GRID_EVENT_CreateJumpTask
 * address:  0x021C1228
 * packet:   pkt_ov021_021C1228
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFileFieldPlayerGridEvent     0x021DE3AC  data  ov021  a4
 *   FIELD_PLAYER_GetFieldMap  0x021A3068  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_PLAYER_GetGrid  0x021A36E0  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   FIELD_PLAYER_GRID_EVENT_RunStateTable  0x021C1988  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03610.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u8 gFileFieldPlayerGridEvent;
extern u32 FIELD_PLAYER_GetFieldMap(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELD_PLAYER_GetGrid(u8 *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern void FLDMMDL_MOVE_GetMapHeight(void *a, Vec3 *v, int *out);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern void func_02030DA8(u32, void (*)(), u8 *, u32);
extern void FIELD_PLAYER_GRID_EVENT_RunStateTable(void *a, u16 *s);

void FIELD_PLAYER_GRID_EVENT_CreateJumpTask(u32 a, u16 b, u32 c, u32 d)
{
    u8 *r;
    void *r7;
    Vec3 va;
    Vec3 vb;
    int out;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x4c, 1, (const char *)&gFileFieldPlayerGridEvent, 0x2b3);
    ((struct Obj03610 *)r)->f4 = b;
    ((struct Obj03610 *)r)->f3C = a;
    ((struct Obj03610 *)r)->f40 = FIELD_PLAYER_GetFieldMap((u8 *)a);
    r7 = FIELD_PLAYER_GetMmdl((void *)a);
    FLDMMDL_GetPos(r7, (struct VecFx32 *)&va);
    vb = va;
    FLDMMDL_MOVE_AddDirVector(((struct Obj03610 *)r)->f4, (int *)(&vb), 0x20000);
    FLDMMDL_MOVE_GetMapHeight(r7, &vb, &out);
    if (out > va.y)
        ((struct Obj03610 *)r)->f0 = 1;
    ((struct Obj03610 *)r)->f44 = FIELD_PLAYER_GetGrid((u8 *)(((struct Obj03610 *)r)->f3C));
    func_02030DA8(FIELDMAP_GetTcblSys((u8 *)(((struct Obj03610 *)r)->f40)), FIELD_PLAYER_GRID_EVENT_RunStateTable, r, 0);
}
