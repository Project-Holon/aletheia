/*
 * function: INTRUDE_FIELD_Update
 * address:  0x0217AE20
 * packet:   pkt_ov018_0217AE20
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   INTRUDE_FIELD_UpdateCommState  0x0217B968  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMaps  0x0217BBD8  thumb  ov018
 *   INTRUDE_FIELD_IsListedZone  0x0217C11C  thumb  ov018
 *   INTRUDE_FIELD_UpdateAreaIndex  0x0217BAB4  thumb  ov018
 *   INTRUDE_COMM_UpdatePlayerObjects  0x02175004  thumb  ov011
 *   INTRUDE_COMM_GetPlayerObjCode  0x02175598  thumb  ov011
 *   COMM_PLAYER_Update  0x02167590  thumb  ov010
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   COMM_PLAYER_Add  0x021675D0  thumb  ov010
 *   COMM_PLAYER_SetPackage  0x02167848  thumb  ov010
 *   COMM_PLAYER_SetEffect  0x021679C4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct SaveBlock;
struct Sub24;
struct Rec44;

typedef struct {
    int f0;
    u8 pad4[0x12];
    u16 lo : 9;
    u16 mode : 6;
    u16 hi : 1;
    u16 f18;
    u16 pad1a;
} Rec;

typedef struct {
    u8 a : 2;
    u8 state : 2;
    u8 rest : 4;
} Flags;

typedef struct {
    u8 pad0[8];
    int f8;
    u8 padc[0x78];
    u16 f84;
    u8 pad86[6];
    Rec recs[3];
    u8 padE0[0x81B];
    u8 f8fb;
    u8 pad8fc;
    u8 f8fd;
    u8 pad8fe[6];
    Flags f904;
    u8 pad905[0xB];
    u8 f910;
} Obj;

extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Work;
extern u32 GAME_COMM_GetWork(void *obj);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern u32 GAME_COMM_GetKind(void *obj);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_IsEntralink(u32 id);
extern u32 func_0200FB24(void);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern void INTRUDE_FIELD_UpdateCommState(int a0, void *a1, void *a2, void *a3);
extern void INTRUDE_FIELD_AddAreaMaps(u8 *a, int b, u8 *c);
extern int INTRUDE_FIELD_IsListedZone(u32 value);
extern void INTRUDE_FIELD_UpdateAreaIndex(int a0, void *a1, void *a2, u8 *p);
extern void INTRUDE_COMM_UpdatePlayerObjects(u8 *p);
extern u16 INTRUDE_COMM_GetPlayerObjCode(u8 *o, u32 id);
extern void COMM_PLAYER_Update(void *a, struct Work *w);
extern int COMM_PLAYER_CheckOccupy(void *p, int i);
struct Src;
extern void COMM_PLAYER_Add(struct Work *w, int idx, int a2, struct Src *src);
extern void COMM_PLAYER_SetPackage(char *a0, int a1, char *a2);
extern int COMM_PLAYER_SetEffect(struct Work *w, int i);

void INTRUDE_FIELD_Update(u8 *a0, int a1, int a2)
{
    int h;
    Obj *p;
    void *ctx;
    int skip;
    int i;
    int r;

    h = GAMESYSTEM_GetGameComm((const struct Ctx *)a1);
    p = (Obj *)GAME_COMM_GetWork((void *)h);
    ctx = GAMESYSTEM_GetGameData((const struct Ctx *)a1);
    if (GAME_DATA_IsSaving(ctx) == 1)
        return;
    INTRUDE_FIELD_UpdateCommState((int)a0, (void *)a1, (void *)h, (void *)a2);
    if (GAME_COMM_GetKind((void *)h) != 2 || p == 0)
        return;
    h = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(ctx));
    if (p->f910 == 0 && ZONEDATA_IsEntralink(h) == 1)
        p->f910 = 1;
    INTRUDE_FIELD_AddAreaMaps(a0, a1, (u8 *)p);
    if (p->f8fd != 7 || func_0200FB24() != 0)
        return;
    if (GAME_DATA_GetIntrudeCount(ctx) == 0) {
        if (p->f904.state == 0) {
            if (INTRUDE_FIELD_IsListedZone(p->f84) == 1)
                p->f904.state = 1;
            else
                p->f904.state = 2;
        }
        if (p->f904.state == 2)
            return;
    }
    skip = GAME_DATA_GetOwnNetId(ctx);
    INTRUDE_COMM_UpdatePlayerObjects((u8 *)p);
    COMM_PLAYER_Update((void *)a1, (struct Work *)p->f8);
    for (i = 0; i < 3; i++) {
        if (i == skip || !(p->f8fb & (1 << i)))
            continue;
        if (COMM_PLAYER_CheckOccupy((void *)p->f8, i) == 0) {
            GAME_DATA_GetMyStatusPlayer(ctx, i);
            r = INTRUDE_COMM_GetPlayerObjCode((u8 *)(&p->recs[i]), (u32)GAME_DATA_GetMyStatusPlayer(ctx, i));
            if (p->recs[i].f18 != 0 || GAME_DATA_GetIntrudeCount(ctx) != 0)
                COMM_PLAYER_Add((struct Work *)p->f8, i, r, (struct Src *)(&p->recs[i]));
        } else {
            COMM_PLAYER_SetPackage((char *)p->f8, i, (char *)(&p->recs[i]));
            if (p->recs[i].f0 == 0) {
                if ((u16)(p->recs[i].mode + 0xFFFE) <= 1)
                    COMM_PLAYER_SetEffect((struct Work *)p->f8, i);
            }
        }
    }
    INTRUDE_FIELD_UpdateAreaIndex((int)a0, (void *)a1, (void *)a2, (u8 *)p);
}
