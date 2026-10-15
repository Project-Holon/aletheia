/*
 * function: COMM_PLAYER_UpdateMyPackage
 * address:  0x0216786C
 * packet:   pkt_ov010_0216786C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
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

typedef struct Where {
    VecFx32 pos;        /* 0x00 */
    u16 zone;           /* 0x0C */
    u8 dir : 4;         /* 0x0E */
    u8 flag : 1;
} Where;

typedef struct Report {
    u32 flag;           /* 0x00 */
    VecFx32 pos;        /* 0x04 */
    u16 zone;           /* 0x10 */
    u8 dir;             /* 0x12 */
} Report;

typedef struct Work {
    void *sys;          /* 0x00 */
    u8 pad04[0x78 - 0x04];
    Where last;         /* 0x78 */
    u8 pad88[0x8F - 0x88];
    u8 f8f;             /* 0x8F */
} Work;

struct BigObj;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u8 FIELD_STATUS_GetSeasonDispFlag(struct Sub02014444Obj *o);
extern u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_IsReady(void *proc);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FIELD_PLAYER_GetFormSlot(u8 *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern VecFx32 *GAME_DATA_GetPlayerPosition(void *pl);
extern u16 GAME_DATA_GetPlayerDirectionType(void *pl);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

int COMM_PLAYER_UpdateMyPackage(Work *w, Report *out)
{
    VecFx32 pos;
    void *a;
    void *pl;
    void *ctx;
    Where *last;
    void *q;
    u32 flag;
    u32 dir;
    u16 zone;

    ctx = GAMESYSTEM_GetGameData(w->sys);
    last = &w->last;
    flag = 0;
    if (w->f8f == 1)
        return 0;
    pl = GAME_DATA_GetMyPlayerWork(ctx);
    dir = GAME_DATA_GetPlayerObjectCode(pl);
    if (FIELD_STATUS_GetSeasonDispFlag(GAME_DATA_GetMoveModelSys(ctx)) == 2) {
        zone = last->zone;
        pos = last->pos;
        flag = 1;
        dir = last->dir;
    } else if (GAMESYSTEM_IsFieldMapExist(w->sys) == 1 && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(w->sys)) == 1) {
        q = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(w->sys));
        a = FIELD_PLAYER_GetMmdl(q);
        if (FIELD_PLAYER_GetFormSlot(q) == 4)
            FIELD_PLAYER_GetPos(q, &pos);
        else
            FLDMMDL_ACMD_GetDrawPos(a, (s32 *)(&pos));
        zone = FIELD_PLAYER_GetDirDisp(q);
    } else {
        pos = *GAME_DATA_GetPlayerPosition(pl);
        zone = GAME_DATA_GetPlayerDirectionType(pl);
    }
    out->zone = zone;
    out->pos = pos;
    out->flag = flag;
    out->dir = dir;
    if (zone != last->zone || dir != last->dir || flag != last->flag
        || GF_STANDARD_CompareBytes((const u8 *)(&pos), (const u8 *)last, sizeof(VecFx32)) != 0) {
        last->zone = zone;
        last->pos = pos;
        last->dir = dir;
        last->flag = flag;
        return 1;
    }
    return 0;
}
