/*
 * function: INTRUDE_SUBDISP_UpdateMyPlayerActor
 * address:  0x0217E3D0
 * packet:   pkt_ov018_0217E3D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   INTRUDE_SUBDISP_SetTownCursor  0x0217F118  thumb  ov018
 *   d_021836A4     0x021836A4  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int id : 10;
    unsigned int rest : 22;
    u8 pad04[0x0A - 0x04];
    u8 x;
    u8 y;
} Mon;

typedef struct {
    Mon *mon;
    u16 id;
    u16 pad06;
} Slot;

typedef struct {
    int f00;
    u8 pad04[0x98 - 0x04];
    int f98;
    u8 pad9C[0xEC - 0x9C];
    Slot slots[1];
} Obj;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsZone117(u32 id);
extern Mon *INTRUDE_FIELD_FindZonePos(int a0);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a0, unsigned int a1);
extern void INTRUDE_SUBDISP_SetTownCursor(Obj *p, int a1);
extern const s8 d_021836A4[][2];
extern const Ent d_02176AA0[];

void INTRUDE_SUBDISP_UpdateMyPlayerActor(Obj *p, int a1, u16 id)
{
    s16 pos[2];
    int sel;
    int idx;
    Mon *m;
    int i;
    int v;
    int h;

    idx = GAME_DATA_GetExitMode(GAMESYSTEM_GetGameData((const struct Ctx *)p->f00));
    sel = 0xFF;
    if (ZONEDATA_IsZone117(id) == 1) {
        pos[0] = d_021836A4[idx][0] + 0x80;
        pos[1] = d_021836A4[idx][1] + 0x4C;
        sel = 8;
        p->slots[idx].mon = 0;
    } else {
        if (id != p->slots[idx].id) {
            m = INTRUDE_FIELD_FindZonePos(id);
        } else {
            m = p->slots[idx].mon;
        }
        p->slots[idx].mon = m;
        p->slots[idx].id = id;
        if (m != 0) {
            pos[0] = m->x + d_021836A4[idx][0];
            pos[1] = m->y + d_021836A4[idx][1];
            v = m->id;
            for (i = 0; i < 8; i++) {
                if (v == d_02176AA0[i].a || v == d_02176AA0[i].b) {
                    sel = i;
                    break;
                }
            }
        } else {
            pos[0] = 0xE8;
            pos[1] = idx * 0x18 + 0x50;
            sel = 0xFF;
            p->slots[idx].mon = 0;
        }
    }
    h = p->f98;
    CLACT_AddActorSurfacePos((struct Obj *)h, (const struct Vec2 *)pos, 0);
    CLACT_SetActorDrawEnable((struct Obj *)h, 1);
    INTRUDE_SUBDISP_SetTownCursor(p, sel);
    p->slots[idx].id = id;
}
