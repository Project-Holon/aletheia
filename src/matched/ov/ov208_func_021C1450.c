/*
 * function: ZUKAN_DETAIL_AREA_HandleTownTouchInput
 * address:  0x021C1450
 * packet:   pkt_ov208_021C1450
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 *   ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown 0x021C0CCC thumb ov208
 *   ZUKAN_DETAIL_AREA_FindTownAtPoint 0x021C0D5C thumb ov208
 *   ZUKAN_DETAIL_AREA_FindNearestTown 0x021C1068 thumb ov208
 *   ZUKAN_DETAIL_AREA_DrawTownName 0x021C1D30 thumb ov208
 *   ZUKAN_DETAIL_AREA_UpdateTerrainIcons 0x021C2238 thumb ov208
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   BUTTON_MAN_ScaleVec 0x020520A4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Vec { int x, y, z; };
struct PtS { s16 x, y; };

extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
struct Actor;
struct Obj;
struct Vec2;
struct Vec3;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern u16 TOWNMAP_GRH_GetTownInfoValue(char *, int, int);
extern void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, u8 *p, int key);
extern u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused, char *p, int unused2, u8 x, u8 y);
extern u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, char *p, int key, u8 x, u8 y);
extern void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key);
extern void VEC_Subtract(struct Vec *a, struct Vec *b, struct Vec *out);
extern int VEC_Mag(struct Vec *v);
extern void VEC_Normalize(struct Vec *src, struct Vec *dst);
extern void BUTTON_MAN_ScaleVec(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

#define W(o) (*(u32 *)(p + (o)))
#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))

static inline void set3(struct Vec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, u8 *p, int key)
{
    u32 tx, ty;
    struct { struct PtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (W(0x90) == 0)
        return;
    if (func_020355C4() == 0) {
        if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
            func_020355D8(1);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
        }
    } else if (KEY_GetTrg()) {
        func_020355D8(0);
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        return;
    }
    if (func_020355C4() == 0) {
        old = p[0x79];
        moved = 0;
        found = 0;
        near = 0;
        {
        struct Vec v = {0, 0, 0};
        struct Vec d = {0, 0, 0};
        struct Vec a;
        struct Vec b;
        CLACT_GetActorSurfacePos((struct Actor *)W(0xcc), &pt.c, 0);
        keys = KEY_GetCont();
        if ((keys & 0x10) || (keys & 0x20) || (keys & 0x40) || (keys & 0x80)) {
            moved = 1;
            if (keys & 0x10)
                v.x += 0x1000;
            if (keys & 0x20)
                v.x -= 0x1000;
            if (keys & 0x40)
                v.y -= 0x1000;
            if (keys & 0x80)
                v.y += 0x1000;
        }
        idx = ZUKAN_DETAIL_AREA_FindNearestTown(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = TOWNMAP_GRH_GetTownInfoValue(*(char **)(p + 0x3c8), idx, 4);
            pt.t.y = TOWNMAP_GRH_GetTownInfoValue(*(char **)(p + 0x3c8), idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            VEC_Subtract(&a, &b, &d);
            if (VEC_Mag(&d) < 0x1BB6)
                near = 1;
            if (VEC_Mag(&d) > 0x1000) {
                VEC_Normalize(&d, &d);
                BUTTON_MAN_ScaleVec((const struct Vec3 *)(&d), 0x1000, (struct Vec3 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            VEC_Normalize(&v, &v);
            dx = d.x + v.x * 3;
            dy = d.y + v.y * 3;
            if (dx > 0 && dx < 0x1000)
                dx = 0x1000;
            else if (dx > -0x1000 && dx < 0)
                dx = -0x1000;
            if (dy > 0 && dy < 0x1000)
                dy = 0x1000;
            else if (dy > -0x1000 && dy < 0)
                dy = -0x1000;
            pt.c.x = pt.c.x + (s16)(dx >> 12);
            pt.c.y = pt.c.y + (s16)(dy >> 12);
        }
        pt.c.x = pt.c.x > 0xf8 ? 0xf8 : (pt.c.x < 0 ? 0 : pt.c.x);
        pt.c.y = pt.c.y > 0xa8 ? 0xa8 : (pt.c.y < 8 ? 8 : pt.c.y);
        CLACT_AddActorSurfacePos((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt.c), 0);
        p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p[0x79] != old) {
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            if (p[0x79] != 0xff)
                GFL_USE_PlaySeDefaultVolume(0x548);
        }
        }
    } else if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
        p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, (u8)tx, (u8)ty);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        if (p[0x79] != 0xff)
            GFL_USE_PlaySeDefaultVolume(0x54C);
    }
}
