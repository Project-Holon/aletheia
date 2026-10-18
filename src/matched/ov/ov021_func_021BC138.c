/*
 * function: FLDEFF_REFLECT_UpdateActor
 * address:  0x021BC138
 * packet:   pkt_ov021_021BC138
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witnesses: arm9 leaves BILLBOARD_ACT_GetBoard, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled,
 * BILLBOARD_ACT_GetEntryElemId, BILLBOARD_GetElemCell filed in src/matched/arm9 (wave A1).
 *
 * The u16 `slot` local is what truncates BILLBOARD_ACT_GetEntryFlags's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 *
 * symbols:
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   BILLBOARD_ACT_GetEntryFlags  0x020507D0  arm
 *   BILLBOARD_ACT_SetEntryFlags  0x020507A0  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDEFF_REFLECT_GetZoneHeightOffset  0x021BC340  thumb  ov021
 *   FLDEFF_REFLECT_GetZoneRotateOffset  0x021BC338  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   BILLBOARD_ACT_GetEntryElemId  0x020508C4  arm
 *   BILLBOARD_GetElemId  0x0204F5E4  arm
 *   BILLBOARD_SetElemId  0x0204F604  arm
 *   BILLBOARD_GetElemCell  0x0204F654  arm
 *   BILLBOARD_SetElemCell  0x0204F66C  arm
 *   BILLBOARD_SetElemScale  0x0204F684  arm
 *   BILLBOARD_SetElemFlipT  0x0204F794  arm
 *   BILLBOARD_GetElemFlipS  0x0204F748  arm
 *   BILLBOARD_SetElemFlipS  0x0204F764  arm
 *   gReflectMdlSizeOffsetZ     0x021D9B40  data  a4
 *   gReflectTypeOffsetY     0x021D9B58  data  a4
 *   gReflectMdlSizeOffsetY     0x021D9B4C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            fx32;

typedef struct { fx32 x, y, z; } Vec;

typedef struct {
    u8 pad0[7];
    u8 f7;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 padC[0x14 - 0xC];
    u32 *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Param;

extern const fx32 gReflectMdlSizeOffsetZ[];
extern const fx32 gReflectTypeOffsetY[];
extern const fx32 gReflectMdlSizeOffsetY[];

struct Manager0204F684;
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int BILLBOARD_ACT_GetEntryFlags(u32 a, u16 b);
extern int BILLBOARD_ACT_SetEntryFlags(void *p, int idx, u32 x);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
struct Trip;
extern void *FLDMMDL_GetObjCodeParam(void *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
extern void FLDMMDL_GetDrawOffset(u8 *p, u8 *q);
extern int FLDMMDL_MOVE_GetMapHeight(u32 a, Vec *v, int *y);
extern void FLDMMDL_GetDrawOffsetOutside(u8 *p, u8 *q);
extern u32 FLDMMDL_GetNowAttr(void *p);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FLDEFF_REFLECT_GetZoneHeightOffset(int a, int b);
extern int FLDEFF_REFLECT_GetZoneRotateOffset(u32 a);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void G3D_CAMERA_GetCamTarget(u32 cam, Vec *out);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern u32 BILLBOARD_ACT_GetEntryElemId(u32 a, u16 b);
extern void BILLBOARD_GetElemId(u8 *a0, u32 i, u16 *out);
extern void BILLBOARD_SetElemId(void *p, u32 idx, u16 *src);
extern void BILLBOARD_GetElemCell(u32 h, u32 i, s16 *v);
extern void BILLBOARD_SetElemCell(int p0, int p1, int p2);
extern void BILLBOARD_SetElemScale(struct Manager0204F684 *mgr, int idx, const s16 *p12, const s16 *p14);
extern void BILLBOARD_SetElemFlipT(void *p, u32 idx, u32 *val);
extern u32 BILLBOARD_GetElemFlipS(u8 *a0, int i);
extern void BILLBOARD_SetElemFlipS(void *p, u32 idx, u32 *val);

void FLDEFF_REFLECT_UpdateActor(u16 id, Param *p)
{
    Vec v;
    Vec w;
    Vec u;
    int y;
    u32 flag;
    s16 rot[4];
    u16 kind;
    u32 h2;
    u32 h;
    int idx;
    u32 obj;
    Info *info;
    u32 i1;
    u32 i2;
    u16 slot;

    h2 = p->f24;
    h = BILLBOARD_ACT_GetBoard((u32 *)h2);
    idx = FLDMMDL_CallDrawGetProc((void *)p->f1C, 0);
    if (id == 0xFFFF) {
        return;
    }
    kind = FIELDMAP_GetZoneId((u8 *)FIELD_EFFECT_GetFieldMap((u8 *)(*p->f14)));
    slot = BILLBOARD_ACT_GetEntryFlags(h2, idx);
    BILLBOARD_ACT_SetEntryFlags((void *)h2, id, slot);
    BILLBOARD_ACT_SetEntryEnabled((void *)h2, id, 0);
    obj = p->f1C;
    info = FLDMMDL_GetObjCodeParam((void *)obj);
    FLDMMDL_GetPos((const struct Actor *)obj, (struct VecFx32 *)&v);
    v.z += gReflectMdlSizeOffsetZ[info->f7];
    FLDMMDL_GetDrawOffset((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.z -= w.z;
    if (FLDMMDL_MOVE_GetMapHeight(obj, &v, &y) == 1) {
        v.y = y;
    }
    v.y += gReflectTypeOffsetY[p->f18];
    FLDMMDL_GetDrawOffsetOutside((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.y -= w.y;
    v.z -= w.z;
    v.y += gReflectMdlSizeOffsetY[info->f7];
    if (info->f7 == 2) {
        if (MAP_ATTR_GetFlags(FLDMMDL_GetNowAttr((void *)obj)) & 0x40) {
            v.y -= 0x3800;
        } else {
            v.y -= 0x8000;
        }
    }
    v.y += FLDEFF_REFLECT_GetZoneHeightOffset(kind, info->f7);
    G3D_CAMERA_GetCamTarget(FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)FIELD_EFFECT_GetFieldMap((u8 *)(*p->f14)))), &u);
    v.x += (v.x / 4096 - u.x / 4096) * 298;
    BILLBOARD_SetElemPos((u8 *)h, id, (struct Trip *)(&v));
    flag = 1;
    i1 = BILLBOARD_ACT_GetEntryElemId(h2, idx);
    i2 = BILLBOARD_ACT_GetEntryElemId(h2, id);
    rot[3] = p->f8;
    rot[2] = p->f4;
    rot[2] += (s16)FLDEFF_REFLECT_GetZoneRotateOffset(kind);
    rot[1] = 0;
    rot[0] = 0;
    BILLBOARD_GetElemId((u8 *)h, i1, (u16 *)(&rot[1]));
    BILLBOARD_SetElemId((void *)h, i2, (u16 *)(&rot[1]));
    BILLBOARD_GetElemCell(h, i1, &rot[0]);
    BILLBOARD_SetElemCell(h, i2, (int)(&rot[0]));
    BILLBOARD_SetElemScale((struct Manager0204F684 *)h, i2, &rot[3], &rot[2]);
    BILLBOARD_SetElemFlipT((void *)h, i2, &flag);
    flag = BILLBOARD_GetElemFlipS((u8 *)h, i1);
    BILLBOARD_SetElemFlipS((void *)h, i2, &flag);
}
