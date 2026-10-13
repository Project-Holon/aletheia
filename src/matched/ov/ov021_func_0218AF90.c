/*
 * function: FIELD_EVENT_CHECK_CheckFrontTileEvents
 * address:  0x0218AF90
 * packet:   pkt_ov021_0218AF90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EVENT_CHECK_GetFrontPos  0x0218AE48  thumb  ov021
 *   FIELD_GIMMICK_IsGimmickId  0x021BE288  thumb  ov021
 *   GIMMICK38_StartDoorEvent  0x021F3A88  thumb  ov038
 *   FIELD_GIMMICK_D06_CheckPushStone  0x021F38A4  thumb  ov051
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FIELD_EVENT_CHECK_FindPartyMemberWithMove  0x0218B630  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsWaterfall  0x021AB310  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   FIELD_EVENT_CHECK_FindGridConnectId  0x0218AE04  thumb  ov021
 *   GIMMICK39_CheckRideEvent  0x021F404C  thumb  ov039
 *   GIMMICK41_CreateLaunchEvent  0x021F37E0  thumb  ov041
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
};

typedef struct Vec { int x, y, z; } Vec;

struct Obj;
extern void FIELD_EVENT_CHECK_GetFrontPos(struct Obj *p, struct Vec *out);
extern int FIELD_GIMMICK_IsGimmickId(u8 *pos, int k);
struct Desc;
extern int GIMMICK38_StartDoorEvent(int a0, int a1, int a2);
extern int FIELD_GIMMICK_D06_CheckPushStone(int a, int b);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *p, u32 move);
extern u16 MAP_ATTR_GetTerrainId(u32 a);
extern int MAP_ATTR_IsWaterfall(u16 a);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int FLDMMDL_MOVE_GetMapHeight(void *m, Vec *pos, int *h);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern u32 FIELD_EVENT_CHECK_FindGridConnectId(u8 *p, void *arg);
extern int GIMMICK39_CheckRideEvent(void *a);
extern int GIMMICK41_CreateLaunchEvent(void *a);

int FIELD_EVENT_CHECK_CheckFrontTileEvents(struct FieldInput *p, void *a, u8 *pos)
{
    Vec v;
    Vec w;
    int h;
    u32 attr;
    void *m;

    FIELD_EVENT_CHECK_GetFrontPos((struct Obj *)p, &v);
    if (FIELD_GIMMICK_IsGimmickId(pos, 6))
        return GIMMICK38_StartDoorEvent((int)a, v.x / 0x10000, v.z / 0x10000);
    if (FIELD_GIMMICK_IsGimmickId(pos, 0x19) || FIELD_GIMMICK_IsGimmickId(pos, 0x1A) || FIELD_GIMMICK_IsGimmickId(pos, 0x1B))
        return FIELD_GIMMICK_D06_CheckPushStone((int)pos, p->f24);
    attr = MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(pos), &v);
    if ((MAP_ATTR_GetFlags(attr) & 1) == 0)
        return 0;
    if (FIELD_PLAYER_GetFormCode(p->f18) == 2 && FIELD_EVENT_CHECK_FindPartyMemberWithMove(p->f8, 0x7F) != 6
        && MAP_ATTR_IsWaterfall(MAP_ATTR_GetTerrainId(attr)) == 1) {
        w = v;
        m = FIELD_PLAYER_GetMmdl(p->f18);
        FLDMMDL_MOVE_AddDirVector(p->f24, (int *)(&w), 0x10000);
        if (FLDMMDL_MOVE_GetMapHeight(m, &w, &h) == 1 && v.y > h)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)p->sys, 0x271F, 0, p->f0);
    }
    if (FIELD_EVENT_CHECK_FindGridConnectId((u8 *)p, &v) == 0xFFFF) {
        if (FIELD_GIMMICK_IsGimmickId(pos, 2))
            return GIMMICK39_CheckRideEvent(a);
        if (FIELD_GIMMICK_IsGimmickId(pos, 5))
            return GIMMICK41_CreateLaunchEvent(a);
    }
    return 0;
}
