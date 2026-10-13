/*
 * function: MOVE_POKEMON_InitSkillInfo
 * address:  0x0215E840
 * packet:   pkt_ov010_0215E840
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fill the 0x14-byte Info for the field: id, the ov021 handles, and the
 * flags word from the object kind, the map tests and the save flags.
 * One lever: the u16 for FIELD_GetPlayerAreaZoneId is declared before x (stack order).
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FIELD_PLAYER_SearchFrontMmdl  0x021A3250  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb  ov021
 *   FIELD_PLAYER_CheckEncountAttr  0x021A3504  thumb  ov021
 *   FIELD_PLAYER_CheckSurfEntryAttr  0x021A3524  thumb  ov021
 *   FIELD_PLAYER_GetNowGridPos  0x021A35FC  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_IsMovedPosObjCode  0x0216E5FC  thumb  ov010
 *   FLDMMDL_CheckMovedPosAtMapPos  0x0216E5B0  thumb  ov010
 *   MOVE_POKEMON_IsInSkillArea  0x0215F118  thumb  ov010
 *   ZONEDATA_IsFlyEnabled  0x02013C40  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   ZONEDATA_IsRawZoneF6  0x0201400C  thumb
 *   ZONEDATA_IsRawZoneF7  0x02014018  thumb
 *   ZONEDATA_IsNormalFieldZone  0x02013E04  thumb
 *   func_02012B70  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

typedef struct Info {
    u16 id;             /* 0x00 */
    u16 flags;          /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    void *obj;          /* 0x0C */
    void *field;        /* 0x10 */
} Info;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct Actor;
struct BigObj;
struct Sub02014444Obj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern void *FIELD_PLAYER_SearchFrontMmdl(void *q);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u32 FIELD_PLAYER_GetFrontAttribute(u32 *a, u32 b);
extern int FIELD_PLAYER_CheckEncountAttr(u8 *a, int b, int c);
extern int FIELD_PLAYER_CheckSurfEntryAttr(u8 *a, int b, int c);
extern void FIELD_PLAYER_GetNowGridPos(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u16 FLDMMDL_GetObjCode(void *obj);
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern int FLDMMDL_IsMovedPosObjCode(u16 kind);
extern int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos);
extern int MOVE_POKEMON_IsInSkillArea(const Area *a, u16 x, u16 z, u32 flag, void *field);
extern u32 ZONEDATA_IsFlyEnabled(u32 id);
extern u32 ZONEDATA_IsWeatherEnabled(u32 id);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012B38(const struct BigObj *p);
extern u16 FIELD_STATUS_GetMapEffectMask(struct Sub02014444Obj *o);
extern int FIELD_GetPlayerAreaZoneId(void *field, u16 *out);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
extern u32 ZONEDATA_IsRawZoneF6(u32 id);
extern u32 ZONEDATA_IsRawZoneF7(u32 id);
extern u32 ZONEDATA_IsNormalFieldZone(u32 id);
extern int func_02012B70(const struct BigObj *p);

extern const Area d_021711EC;
extern const Area d_021711F4;

void MOVE_POKEMON_InitSkillInfo(void *field, Info *out)
{
    VecFx32 pos;
    u16 v;
    u16 x;
    u16 y;
    u16 z;
    void *q;
    void *obj;
    void *map;
    u16 kind;
    u32 a;
    u32 b;
    u32 c;

    MI_CpuFill8(out, 0, sizeof(Info));
    out->id = FIELDMAP_GetZoneId(field);
    out->f08 = (u32)FIELDMAP_GetGameSystem(field);
    out->field = field;
    q = FIELDMAP_GetFieldPlayer(field);
    out->f04 = FIELD_PLAYER_GetFormCode(q);
    obj = FIELD_PLAYER_SearchFrontMmdl(q);
    out->obj = obj;
    if (obj != 0) {
        kind = FLDMMDL_GetObjCode(obj);
        map = FIELDMAP_GetMmdlSys(field);
        FLDMMDL_GetPos(obj, &pos);
        if (FLDMMDL_IsMovedPosObjCode(kind) && FLDMMDL_CheckMovedPosAtMapPos(map, &pos) == 0)
            out->flags |= 8;
        if (kind == 0x6C)
            out->flags |= 1;
    }
    a = FIELD_PLAYER_GetDirDisp(q);
    b = FIELD_PLAYER_GetNowAttribute(q);
    c = FIELD_PLAYER_GetFrontAttribute(q, a);
    if (FIELD_PLAYER_CheckEncountAttr((u8 *)q, b, c) == 1)
        out->flags |= 2;
    if (FIELD_PLAYER_CheckSurfEntryAttr((u8 *)q, b, c) == 1)
        out->flags |= 4;
    if (ZONEDATA_IsFlyEnabled(out->id) == 1) {
        out->flags |= 0x10;
        out->flags |= 0x40;
    }
    if (ZONEDATA_IsWeatherEnabled(out->id) == 1)
        out->flags |= 0x80;
    if (FIELD_STATUS_GetMapEffectMask(func_02012B38(func_020120F4((const struct Ctx *)out->f08))) & 1)
        out->flags |= 0x20;
    if (FIELD_GetPlayerAreaZoneId(field, &v) == 1)
        out->flags |= 0x400;
    if (ZONEDATA_IsZoneInTableDFB8(out->id)) {
        FIELD_PLAYER_GetNowGridPos(FIELDMAP_GetFieldPlayer(out->field), &x, &y, &z);
        if (ZONEDATA_IsRawZoneF6(out->id) && MOVE_POKEMON_IsInSkillArea(&d_021711EC, x, z, 0x113, field))
            out->flags |= 0x20;
        if (ZONEDATA_IsRawZoneF7(out->id) && MOVE_POKEMON_IsInSkillArea(&d_021711F4, x, z, 0x112, field))
            out->flags |= 8;
    }
    if (ZONEDATA_IsNormalFieldZone(out->id) == 0) {
        out->flags = 0;
    } else {
        out->flags |= 0x100;
        out->flags |= 0x200;
    }
    if (func_02012B70(func_020120F4((const struct Ctx *)out->f08)) == 1)
        out->flags = 0;
}
