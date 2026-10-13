/*
 * function: FIELD_EVENT_CHECK_CheckPosEventCenterTile
 * address:  0x0218A8BC
 * packet:   pkt_ov021_0218A8BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or FIELD_PLAYER_GetFormCode allows it.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsNoInteract  0x021AB188  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight  0x0216282C  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
    u32 f1C;
    char pad20[0x04];
    u16 f24;
    u16 f26;
    char pad28[0x04];
    u32 f2C;
};

struct BgEvent {
    u16 msg;
    char pad02[0x06];
    u16 f8;
    struct {
        u16 x;
        u16 z;
        u16 w;
        u16 h;
    } rect;
};

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *id, struct VecFx32 *out);
struct BigObj;
struct Desc;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsNoInteract(u16 id);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Rec;
extern struct Rec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(struct Ctx *c, void *a, int *key, int mode);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetAcmdCode(u8 *p);

int FIELD_EVENT_CHECK_CheckPosEventCenterTile(struct FieldCtx *p)
{
    void *obj = GAMESYSTEM_GetFieldMap(p->f4);
    void *id = FIELDMAP_GetFieldPlayer(obj);
    int pos[3];
    struct BgEvent *e;
    int a;
    u16 b;
    u32 cx;
    u16 *r;
    u32 cz;

    FIELD_PLAYER_GetPos(id, (struct VecFx32 *)pos);
    if (MAP_ATTR_IsNoInteract(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(obj), pos))) != 1)
        return 0;
    e = (struct BgEvent *)EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(p->fC, (void *)GAME_DATA_GetEventWork(p->f8), pos, 9);
    if (e == 0)
        return 0;
    if (e->f8 != 0)
        return 0;
    r = (u16 *)&e->rect;
    cz = r[1] + ((u32)r[3] >> 1);
    cx = e->rect.x + ((u32)r[2] >> 1);
    if (cx == (pos[0] >> 12) / 16 && cz == (pos[2] >> 12) / 16)
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)p->f4, e->msg, 0, p->f0);
    a = FIELD_PLAYER_GetFormCode(id);
    b = FLDMMDL_GetAcmdCode(FIELD_PLAYER_GetMmdl(id));
    if (a != 0 || b == 0x58 || b == 0x59 || b == 0x5A || b == 0x5B || (u16)(b + 0xFF5D) <= 3)   /* b - 0xA3 */
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)p->f4, e->msg, 0, p->f0);
    return 0;
}
