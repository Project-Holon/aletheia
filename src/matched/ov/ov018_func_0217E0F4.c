/*
 * function: INTRUDE_SUBDISP_UpdatePlayerTownActors
 * address:  0x0217E0F4
 * packet:   pkt_ov018_0217E0F4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   INTRUDE_SUBDISP_UpdateTownMarkPalette  0x0217E2E0  thumb  ov018
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_GetActorPaletteOffset  0x0204B714  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   d_021836A4     0x021836A4  data   a1
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef struct {
    void *ptr;
    u16 id;
} Slot;

typedef struct {
    void *f00;
    u8 pad04[0x80 - 0x04];
    void *f80[3];
    void *f8c[3];
    u8 pad98[0xa0 - 0x98];
    void *fa0[3];
    u8 padAC[0xd8 - 0xac];
    u8 fd8;
    u8 fd9;
    u8 padDA[0xec - 0xda];
    Slot fec[3];
} Work;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 lo : 3;
    u16 mid : 6;
    u16 hi : 6;
    u8 pad18[4];
} Ent;

typedef struct {
    u8 pad00[0x8c];
    Ent ent[3];
} Mon;

typedef struct {
    Pos p2;
    Pos p;
} Pair;

typedef unsigned int   u32;
struct Actor;
struct BigObj;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void INTRUDE_SUBDISP_UpdateTownMarkPalette(Work *);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern u32 ZONEDATA_IsZone117(u32 id);
extern u8 *INTRUDE_FIELD_FindZonePos(u16);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 CLACT_GetActorPaletteOffset(struct Obj *o);
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern const s8 d_021836A4[3][2];

void INTRUDE_SUBDISP_UpdatePlayerTownActors(Work *p, Mon *m)
{
    void *sys;
    int cur;
    int i;
    int k;
    void *a;
    Ent *e;
    u8 *prev;
    u16 previd;
    u8 *obj;
    void *b;
    Pair l;

    sys = GAMESYSTEM_GetGameData(p->f00);
    cur = p->fd8;
    INTRUDE_SUBDISP_UpdateTownMarkPalette(p);
    for (i = 0; i < 3; i++) {
        obj = 0;
        prev = p->fec[i].ptr;
        previd = p->fec[i].id;
        if (i != GAME_DATA_GetExitMode(sys)) {
            p->fec[i].ptr = 0;
            p->fec[i].id = 0x1ab;
        }
        a = p->f8c[i];
        b = p->fa0[i];
        if (i == GAME_DATA_GetExitMode(sys)) {
            CLACT_SetActorDrawEnable(a, 0);
            CLACT_SetActorDrawEnable(b, 0);
            continue;
        }
        if (m == 0) {
            CLACT_SetActorDrawEnable(a, 0);
            CLACT_SetActorDrawEnable(b, 0);
            continue;
        }
        if (p->fd9 & (1 << i)) {
            e = &m->ent[i];
        } else {
            CLACT_SetActorDrawEnable(a, 0);
            CLACT_SetActorDrawEnable(b, 0);
            continue;
        }
        if (e->hi == 2) {
            CLACT_SetActorAutoAnimSpeed(a, 0x2000);
        } else {
            CLACT_SetActorAutoAnimSpeed(a, 0x1000);
        }
        if (e->lo == cur) {
            if (ZONEDATA_IsZone117(e->f14) == 1) {
                l.p.x = d_021836A4[i][0] + 0x80;
                l.p.y = d_021836A4[i][1] + 0x4c;
                CLACT_SetActorDrawEnable(b, 0);
            } else {
                if (e->f14 != previd) {
                    obj = INTRUDE_FIELD_FindZonePos(e->f14);
                } else {
                    obj = prev;
                }
                if (obj != 0) {
                    l.p.x = obj[0xa] + d_021836A4[i][0];
                    l.p.y = obj[0xb] + d_021836A4[i][1];
                    CLACT_SetActorDrawEnable(b, 0);
                } else {
                    l.p.x = 0xe8;
                    l.p.y = i * 0x18 + 0x50;
                    l.p2 = l.p;
                    l.p2.x = 0xf0;
                    CLACT_AddActorSurfacePos(b, (const struct Vec2 *)(&l.p2), 0);
                    CLACT_SetActorDrawEnable(b, 1);
                }
            }
            CLACT_AddActorSurfacePos(a, (const struct Vec2 *)(&l.p), 0);
            p->fec[i].ptr = obj;
            p->fec[i].id = e->f14;
        } else {
            CLACT_SetActorDrawEnable(b, 0);
            for (k = 0; k < 3; k++) {
                if (CLACT_GetActorPaletteOffset(p->f80[k]) == i + 1) {
                    CLACT_GetActorSurfacePos(p->f80[k], (struct PtS *)&l.p, 0);
                    break;
                }
            }
            if (k == 3) {
                CLACT_SetActorDrawEnable(a, 0);
                continue;
            }
            l.p.x += d_021836A4[i][0];
            l.p.y += d_021836A4[i][1];
            CLACT_AddActorSurfacePos(a, (const struct Vec2 *)(&l.p), 0);
        }
        CLACT_SetActorDrawEnable(a, 1);
    }
}
