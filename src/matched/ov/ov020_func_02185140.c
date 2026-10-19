/*
 * function: EVENT_MAPCHANGE_CreateIntrudeWarpEvent
 * address:  0x02185140
 * packet:   pkt_ov020_02185140
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  byte-correct (212/212). The bl at +00BA to 0x02014184 has no
 *           witness: an unlabelled arm9 Thumb leaf (printed as .word data
 *           after ZONEDATA_InitLocation), the integrator's to file. Evidence class: label /
 *           sole-ref/code. Verified C for the leaf, per
 *           ov020_func_021852F0.c:
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void ZONEDATA_SetDirectLocation(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetWarpLocation  0x020128E4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   INTRUDE_UpdatePlaySeconds  0x0200BFA4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   ZONEDATA_DirToExitDir  0x020142A4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   EVENT_MAPCHANGE_GetCurrentLocation  0x021852F0  thumb  ov020
 *   EVENT_MAPCHANGE_CreateIntrudeSessionEvent  0x02185BFC  thumb  ov020
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb  ov011
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned long long u64;

typedef struct { int f0; int f4; int f8; } S3;
typedef struct { int f[7]; } S7;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Ctx;
struct Rec1C;
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void GAME_DATA_SetWarpLocation(struct BigObj *p, const struct Rec1C *src);
void *GAME_DATA_GetSaveControl(struct Big *p);
u16 *INTRUDE_GetFromSave(void *sys);
int GAME_DATA_GetPlayTime(int p0);
unsigned long long INTRUDE_UpdatePlaySeconds(u8 *p, void *q, u32 mode);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
u32 ZONEDATA_DirToExitDir(u32 idx);
void ZONEDATA_SetDirectLocation(S7 *out, int b, s16 c, int d, int e, int f);
void EVENT_MAPCHANGE_GetCurrentLocation(void *dst, int x);
void *EVENT_MAPCHANGE_CreateIntrudeSessionEvent(void *p, int a1, S7 *a2, int a3, int a4);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_COMM_HasUnlockFlags(void *p);
u8 INTRUDE_COMM_GetRequesterNetId(u8 *p, u8 *q);

void *EVENT_MAPCHANGE_CreateIntrudeWarpEvent(void *a, int b, S3 *c, int d)
{
    int h;
    void *r4;
    S3 t;
    S7 w;
    S7 out;
    int r6;
    int r5;
    int r2;
    void *q;
    u8 *r7;

    h = (int)GAMESYSTEM_GetFieldMap(a);
    r4 = GAMESYSTEM_GetGameData(a);
    t = *c;
    r6 = 0;
    EVENT_MAPCHANGE_GetCurrentLocation(&w, h);
    GAME_DATA_SetWarpLocation(r4, (const struct Rec1C *)(&w));
    q = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(r4));
    INTRUDE_UpdatePlaySeconds(q, (void *)GAME_DATA_GetPlayTime((int)r4), 0);
    r7 = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(a));
    if (r7 == 0 || INTRUDE_COMM_HasUnlockFlags(r4) == 0) {
        r5 = 0;
        r2 = 0;
    } else {
        r5 = INTRUDE_COMM_GetRequesterNetId(r7, r7 + 0x1AC);
        r2 = r5 - GAME_DATA_GetOwnNetId(r4);
        if (r2 < 0)
            r2 += r7[0x902];
        r6 = 0x10000;
    }
    t.f0 += r6 + (r2 << 22);
    ZONEDATA_SetDirectLocation(&out, b, ZONEDATA_DirToExitDir(0), t.f0, t.f4, t.f8);
    return EVENT_MAPCHANGE_CreateIntrudeSessionEvent(a, h, &out, d, r5);
}
