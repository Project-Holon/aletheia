/*
 * function: FIELD_EVENT_CHECK_CheckPosEventForDir
 * address:  0x0218A784
 * packet:   pkt_ov021_0218A784
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unless the tile attribute under the object's position blocks it
 * (MAP_ATTR_IsNoInteract), asks ov010 EVENTDATA_SYSTEM_GetPosEventScriptId for a message id and shows it
 * through SCRIPT_SYS_CreateScriptEventSimple; returns 0 otherwise.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsNoInteract  0x021AB188  thumb
 *   EVENTDATA_SYSTEM_GetPosEventScriptId  0x02162928  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx784 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
};

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
struct Desc;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsNoInteract(u16 id);
extern u16 EVENTDATA_SYSTEM_GetPosEventScriptId(void *p, void *q, int key, int mode);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int FIELD_EVENT_CHECK_CheckPosEventForDir(struct Ctx784 *c, int a)
{
    void *x = GAMESYSTEM_GetFieldMap(c->f4);
    void *y = (void *)GAME_DATA_GetEventWork(c->f8);
    u32 pos[3];
    u32 msg;

    FIELD_PLAYER_GetPos(c->f18, (struct VecFx32 *)pos);
    if (MAP_ATTR_IsNoInteract(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(x), pos))) == 1)
        return 0;
    msg = EVENTDATA_SYSTEM_GetPosEventScriptId(c->fC, y, (int)pos, a);
    if (msg != 0xFFFF)
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)c->f4, msg, 0, c->f0);
    return 0;
}
