/*
 * function: INTRUDE_SUBDISP_UpdateTouch
 * address:  0x0217EC7C
 * packet:   pkt_ov018_0217EC7C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   INTRUDE_SUBDISP_IsAlone  0x0217F284  thumb  ov018
 *   INTRUDE_SUBDISP_SetTouchRect  0x0217EC44  thumb  ov018
 *   INTRUDE_SUBDISP_IsInTouchRect  0x0217EC5C  thumb  ov018
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   BMP_OAM_GetEnabled  0x020257C4  thumb
 *   d_02176AA0     0x02176AA0  data  a4
 *
 * blocker:  byte-correct; the two THM_CALLs to ZONEDATA_IsZoneInTableDFC0 (arm9) have no
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           ZONEDATA_IsZoneGroup118To120's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int ZONEDATA_IsZoneInTable(int a0, const int *a1, int a2);
 *             int ZONEDATA_IsZoneInTableDFC0(int a0)
 *             { return ZONEDATA_IsZoneInTable(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int lo : 20;
    unsigned int id : 10;
    unsigned int hi : 2;
} Mon;

typedef struct {
    int l, t, r, b;
} Rect;

typedef struct {
    u16 id;
    u8 pad02[0x1A];
} QEnt;

typedef struct {
    u8 pad00[0xA0];
    QEnt e[3];
} Q;

typedef struct {
    int f00;
    u8 pad04[0x8C - 0x04];
    int f8C[3];
    u8 pad98[0xC4 - 0x98];
    int fC4;
    u8 padC8[0xD8 - 0xC8];
    u8 fD8;
    u8 fD9;
    u8 padDA[0x106 - 0xDA];
    u8 f106;
    u8 f107;
    u8 pad108[0x110 - 0x108];
    u16 f110;
    u8 f112;
    u8 f113;
    u8 pad114[0x168 - 0x114];
    u8 f168;
    u8 f169;
} Obj;

struct Actor;
struct BigObj;
struct Ctx;
struct Obj;
struct PtS;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int FIELD_SUBSCREEN_GetPanelResult(u32 a);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern Mon *INTRUDE_FIELD_FindZonePos(int a0);
extern int INTRUDE_SUBDISP_IsAlone(u8 *p);
extern void INTRUDE_SUBDISP_SetTouchRect(int x, int y, int w, int h, Rect *r);
extern int INTRUDE_SUBDISP_IsInTouchRect(u32 x, u32 y, Rect *r);
extern int ZONEDATA_IsZoneInTableDFC0(int a0);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 ZONEDATA_IsEntralink(u32 id);
extern int BMP_OAM_GetEnabled(const int *p);
extern const Ent d_02176AA0[];

void INTRUDE_SUBDISP_UpdateTouch(Q *q, Obj *p, int id)
{
    Rect rect;
    u32 tx;
    u32 ty;
    s16 pt[2];
    int x;
    int sel;
    int h;
    int i;
    int w;
    int a;
    const Ent *e;
    Mon *m;

    x = FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap((const struct Ctx *)p->f00));
    GAMESYSTEM_GetGameComm((const struct Ctx *)p->f00);
    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p->f00);
    if (p->f112 != 0 || p->f106 == 1 || !TOUCHPANEL_GetPointTrg(&tx, &ty) || FIELD_SUBSCREEN_GetPanelResult(x) != 0) {
        return;
    }
    sel = GAME_DATA_GetOwnNetId((const struct BigObj *)h);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(p->fD9 & (1 << i))) {
            continue;
        }
        w = p->f8C[i];
        if (CLACT_GetActorDrawEnable((struct Obj *)w) != 1) {
            continue;
        }
        CLACT_GetActorSurfacePos((struct Actor *)w, (struct PtS *)pt, 0);
        if (tx - 12 > pt[0] || tx + 12 < pt[0]) {
            continue;
        }
        if (ty - 12 > pt[1] || ty + 12 < pt[1]) {
            continue;
        }
        if (q == 0) {
            continue;
        }
        if (INTRUDE_FIELD_FindZonePos(q->e[i].id) == 0) {
            continue;
        }
        p->f169 = i;
        return;
    }
    if (INTRUDE_SUBDISP_IsAlone((u8 *)p) == 1) {
        return;
    }
    if (p->fD8 != GAME_DATA_GetOwnNetId((const struct BigObj *)h)) {
        for (i = 0; i < 8; i++) {
            e = &d_02176AA0[i];
            INTRUDE_SUBDISP_SetTouchRect(e->x, e->y, 0x10, 0x10, &rect);
            if (INTRUDE_SUBDISP_IsInTouchRect(tx, ty, &rect) != 1) {
                continue;
            }
            a = e->a;
            if (id == a || id == e->b || (ZONEDATA_IsZoneInTableDFC0(id) == 1 && ZONEDATA_IsZoneInTableDFC0(a) == 1)) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                return;
            }
            if (i == 7) {
                p->f106 = 1;
                p->f107 = 0;
            } else {
                m = INTRUDE_FIELD_FindZonePos(a);
                if (m == 0) {
                    continue;
                }
                p->f110 = m->id;
                p->f112 = 1;
            }
            p->f113 = i;
            return;
        }
    }
    if (p->fD8 != GAME_DATA_GetOwnNetId((const struct BigObj *)h)) {
        INTRUDE_SUBDISP_SetTouchRect(0x80, 0x5C, 0x10, 0x10, &rect);
        if (INTRUDE_SUBDISP_IsInTouchRect(tx, ty, &rect) == 1) {
            if (ZONEDATA_IsEntralink(id) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                return;
            }
            p->f110 = 0x117;
            p->f112 = 1;
            p->f113 = 8;
            return;
        }
    }
    if (p->f168 == 0 && BMP_OAM_GetEnabled((const int *)p->fC4) == 1) {
        INTRUDE_SUBDISP_SetTouchRect(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (INTRUDE_SUBDISP_IsInTouchRect(tx, ty, &rect) == 1) {
            p->f168 = 1;
        }
    }
}
