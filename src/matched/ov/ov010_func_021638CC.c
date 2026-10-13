/*
 * function: FLDMMDL_MOVE_HitCheckMove
 * address:  0x021638CC
 * packet:   pkt_ov010_021638CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects five placement-test failures into a bit mask: 1 from
 * FLDMMDL_MOVE_HitCheckMoveLimit, 2 from FLDMMDL_MOVE_HitCheckAttr (the cell-centre position by
 * value), 8 when the ground-height probe FLDMMDL_MOVE_GetMapHeight fails or lands
 * 0x14000 or more from the object's height, 4 from FLDMMDL_MOVE_HitCheckOtherObjects, 0x10
 * from the ov021 test at 0x0218DC04.
 *
 * x and y are s16 register parameters (their spill homes are stored at
 * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16
 * z is copied into a fresh spill slot, while this spelling keeps the
 * incoming slot as its home and reloads it with ldrsh after the calls.
 *
 * symbols:
 *   FLDMMDL_MOVE_HitCheckMoveLimit  0x02163C9C  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckAttr  0x02163D04  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckOtherObjects  0x02163BAC  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetG3dMapper  0x0216D52C  thumb  ov010
 *   FIELD_G3D_MAPPER_IsOutsideGrid  0x0218DC04  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Obj {
    u32 f00;
    fx32 f04;           /* 0x04 */
} Obj;

extern int FLDMMDL_MOVE_HitCheckMoveLimit(int a, int b, int c);
extern int FLDMMDL_MOVE_HitCheckAttr(void *m, u32 kind, VecFx32 pos);
extern int FLDMMDL_MOVE_GetMapHeight(void *m, VecFx32 *pos, fx32 *y);
extern int FLDMMDL_MOVE_HitCheckOtherObjects(int a, int b, int c, int d);
extern void *FLDMMDL_GetMmdlSys(void *m);
extern u32 FLDMMDL_SysGetG3dMapper(void *p);
struct Grid;
extern int FIELD_G3D_MAPPER_IsOutsideGrid(struct Grid *g, struct VecFx32 *pos);

u32 FLDMMDL_MOVE_HitCheckMove(void *m, Obj *o, s16 x, s16 y, int z, u16 kind)
{
    u32 flags = 0;
    VecFx32 pos;
    fx32 h;

    pos.x = (x << 16) + 0x8000;
    pos.y = o->f04;
    pos.z = (*(s16 *)&z << 16) + 0x8000;
    if (FLDMMDL_MOVE_HitCheckMoveLimit((int)m, x, *(s16 *)&z) == 1)
        flags |= 1;
    if (FLDMMDL_MOVE_HitCheckAttr(m, kind, pos) == 1)
        flags |= 2;
    if (FLDMMDL_MOVE_GetMapHeight(m, &pos, &h) == 1) {
        fx32 d = o->f04 - h;
        if (d < 0)
            d = -d;
        if (d >= 0x14000)
            flags |= 8;
        y = (h >> 4) / 0x1000;
    } else {
        flags |= 8;
    }
    if (FLDMMDL_MOVE_HitCheckOtherObjects((int)m, x, y, *(s16 *)&z) == 1)
        flags |= 4;
    if (FIELD_G3D_MAPPER_IsOutsideGrid((struct Grid *)FLDMMDL_SysGetG3dMapper(FLDMMDL_GetMmdlSys(m)), &pos) == 1)
        flags |= 0x10;
    return flags;
}
