/*
 * function: DOWSING_Update
 * address:  0x021F0174
 * packet:   pkt_ov033_021F0174
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INFOWIN_Update 0x02024ABC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   MAP_MATRIX_IsInRangeByPos 0x02159C48 thumb ov010
 *   MAP_MATRIX_GetZoneIdByPos 0x02159BD4 thumb ov010
 *   GAMESYSTEM_GetMyPlayerWork 0x020120F8 thumb
 *   GAME_DATA_GetPlayerPosition 0x02012AA0 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldWork 0x02012974 thumb
 *   func_02013E7C 0x02013E7C thumb
 *   ZONEDATA_IsZoneGroup118To13C 0x02013D74 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   func_020061E4 0x020061E4 thumb
 *   DOWSING_ResetSearch 0x021EFF40 thumb ov033
 *   DOWSING_IsTargetAvailable 0x021EFEEC thumb ov033
 *   DOWSING_FindNextTarget 0x021EFF48 thumb ov033
 *   DOWSING_UpdateCloseButton 0x021F0AC4 thumb ov033
 *   sDowsingLevelTable 0x021F0DC8 data ov033 a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pan : 7;
} Ent;

typedef struct {
    u32 kind;
    u32 a;
    u32 b;
} Rec;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
} Ev;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[0x60 - 0x0C];
    u8 *map;
    int f64;
    int f68;
    int f6C;
    Rec cur;
    Rec found;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
    u16 hA0;
    u16 padA2;
    int fA4;
    u32 fA8;
    u32 fAC;
    int fB0;
    u32 fB4;
    u32 fB8;
    u32 fBC;
    int fC0;
    u32 fC4;
    int fC8;
    int fCC;
    void *fD0;
} W;

extern const Ent sDowsingLevelTable[];
struct Ctx;
struct BigObj;
extern void INFOWIN_Update(void);
extern void *FIELDMAP_GetGameSystem(void *p);
struct Rec44;
struct Vec12;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
extern struct Vec12 *GAME_DATA_GetPlayerPosition(struct Rec44 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
extern int MAP_MATRIX_IsInRangeByPos(int a0, int a1, int a2);
extern int MAP_MATRIX_GetZoneIdByPos(int a0, int a1, int a2);
extern u32 func_02013E7C(u32 id);
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);
extern void DOWSING_ResetSearch(char *p);
extern int DOWSING_IsTargetAvailable(char *p, int *q);
extern int DOWSING_FindNextTarget(void *p, Rec *out, int mode);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void func_0200616C(void *arg, int i);
extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void func_020061E4(u32 se);
extern void DOWSING_UpdateCloseButton(W *p);

void DOWSING_Update(W *p, int on)
{
    Rec r[2];
    int snd;
    int changed;
    int x0;
    u32 map;
    void *obj;
    int gx, gy, gz;
    int zone;
    int flag;
    u32 n;
    int xmin, xmax, zmin, zmax;
    int best;
    u16 bestIdx;
    Ev *e;
    s16 *s;
    int x1, z1;
    Vec *pos;
    int go;
    int start;
    u16 i;
    int x, z;
    int dx, dz;
    u16 idx;
    u32 d;
    int h;
    int pan;
    int c68;
    u32 k;

    p->fB0 = on;
    if (on)
        p->fC0 = 1;
    else
        p->fC0 = 2;
    INFOWIN_Update();
    if (on == 0)
        return;
    p->f64 = p->f68;
    p->cur.kind = p->found.kind;
    if (p->cur.kind == 1)
        p->cur.a = p->found.a;
    else if (p->cur.kind == 2)
        p->cur.b = p->found.b;
    obj = FIELDMAP_GetGameSystem((void *)p->f08);
    pos = (Vec *)GAME_DATA_GetPlayerPosition((struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(obj));
    gx = (pos->x >> 4) / 4096;
    gy = (pos->y >> 4) / 4096;
    gz = (pos->z >> 4) / 4096;
    map = GAME_DATA_GetFieldWork(GAMESYSTEM_GetGameData(obj));
    zone = 0xFFFF;
    flag = 0;
    if (MAP_MATRIX_IsInRangeByPos((int)map, pos->x, pos->z) == 1) {
        zone = MAP_MATRIX_GetZoneIdByPos((int)map, pos->x, pos->z);
        flag = (int)func_02013E7C((u16)zone);
    }
    if (p->f94 == 0) {
        p->f94 = 1;
        go = 1;
    } else {
        go = 1;
    }
    if (go) {
        xmin = gx - 15;
        xmax = gx + 17;
        zmin = gz - 11;
        zmax = gz + 13;
        best = -1;
        r[0].kind = 0;
        if (p->fC8 != 0) {
            DOWSING_ResetSearch(p->fD0);
            p->fC8 = 0;
        }
        if (p->fCC != 0) {
            n = 0xFFFF;
            p->fCC = 0;
        } else {
            n = 11;
        }
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (p->cur.kind != 0) {
                    if (DOWSING_IsTargetAvailable(p->fD0, (int *)(&p->cur))) {
                        r[1].kind = p->cur.kind;
                        if (r[1].kind == 1)
                            r[1].a = p->cur.a;
                        else if (r[1].kind == 2)
                            r[1].b = p->cur.b;
                    } else {
                        p->fC8 = 1;
                        p->fCC = 1;
                        break;
                    }
                }
            } else {
                if ((p->fC8 = DOWSING_FindNextTarget(p->fD0, &r[1], 0) ? 0 : 1) != 0)
                    break;
            }
            if (zone == 0xFFFF)
                continue;
            if (r[1].kind == 1) {
                e = (Ev *)r[1].a;
                if (zone != e->h4) {
                    if (e->b2 == 0)
                        continue;
                    if (flag == 0)
                        continue;
                    if (ZONEDATA_IsZoneGroup118To13C(e->h4) != 0)
                        continue;
                }
                x = e->h6;
                z = e->h8;
            } else if (r[1].kind == 2) {
                s = (s16 *)r[1].b;
                if ((int)func_02013E7C((u16)s[3]) == 0)
                    continue;
                if (flag == 0)
                    continue;
                x = s[0];
                z = s[2];
            }
            if (xmin <= x && x < xmax && zmin <= z && z < zmax) {
                dz = z - gz;
                dx = x - gx;
                idx = (u16)(dx + 15 + (dz + 11) * 32);
                if (p->map[idx] == 9)
                    continue;
                d = dx * dx + dz * dz;
                if (d < (u32)best) {
                    bestIdx = idx;
                    best = d;
                    r[0].kind = r[1].kind;
                    if (r[1].kind == 1)
                        r[0].a = r[1].a;
                    else if (r[1].kind == 2)
                        r[0].b = r[1].b;
                }
            }
        }
        k = r[0].kind;
        p->found.kind = k;
        if (k != 0) {
            p->f68 = p->map[bestIdx];
            if (k == 1)
                p->found.a = r[0].a;
            else if (k == 2)
                p->found.b = r[0].b;
        } else {
            p->f68 = 9;
        }
    }
    snd = 1;
    if (p->f68 == 8) {
        start = 0;
        if (p->f9C == 0) {
            start = 1;
            p->f9C = 1;
        } else if (p->hA0 == 6) {
            if (GFL_USE_IsSeSlotBusy(p->f98) == 0)
                p->hA0--;
        } else if (p->hA0 == 0) {
            start = 1;
        } else {
            p->hA0--;
        }
        if (start) {
            p->f98 = GFL_USE_GetSeSlot(0x760);
            func_0200616C((void *)0x760, p->f98);
            GFL_USE_SetSeSlotParams(p->f98, -1, 0x180, -1);
            p->hA0 = 6;
            p->fA4 = 1;
        }
        snd = 0;
    } else {
        p->f9C = 0;
    }
    if (snd && (c68 = p->f68) != 8 && p->found.kind != 0) {
        changed = 0;
        if (p->cur.kind == 1) {
            e = (Ev *)p->cur.a;
            x0 = e->h6;
            z = e->h8;
        } else if (p->cur.kind == 2) {
            s = (s16 *)p->cur.b;
            x0 = s[0];
            z = s[2];
        } else {
            changed = 1;
            goto done;
        }
        if (p->found.kind == 1) {
            e = (Ev *)p->found.a;
            x1 = e->h6;
            z1 = e->h8;
        } else if (p->found.kind == 2) {
            s = (s16 *)p->found.b;
            x1 = s[0];
            z1 = s[2];
        }
        if ((x0 != x1 || z != z1) && p->f64 != c68)
            changed = 1;
    done:
        if (changed) {
            h = GFL_USE_GetSeSlot(0x760);
            pan = ((int)sDowsingLevelTable[p->f68].pan - 8) * 16;
            if (pan < -127)
                pan = -127;
            else if (pan > 127)
                pan = 127;
            func_0200616C((void *)0x760, h);
            GFL_USE_SetSeSlotParams(h, -1, -1, pan);
            snd = 0;
        }
    }
    if (snd && p->f64 != p->f68)
        func_020061E4(0x762);
    p->f88 = gx;
    p->f8C = gy;
    p->f90 = gz;
    DOWSING_UpdateCloseButton(p);
}
