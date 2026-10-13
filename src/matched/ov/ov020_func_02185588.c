/*
 * function: EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset
 * address:  0x02185588
 * packet:   pkt_ov020_02185588
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD9r lane42): EXACT. Two source facts closed the last 18 bytes:
 *   (1) id is a u16 parameter, and ZONEDATA_SetDirectLocation takes a u16 id (its matched definition in
 *       src/matched/arm9/ZONEDATA_SetDirectLocation.c). This fixed the asrs/ldr order at the 02014184 call.
 *   (2) the e->lo bitfield is read into its own block local (`int lo = e->lo; r = lo - getter;`),
 *       the same shape as sibling 02185140 (`r2 = r5 - GAME_DATA_GetExitMode(r4)`). This fixed the
 *       owner/r colour swap (owner r4, r r5).
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   ZONEDATA_DirToExitDir  0x020142A4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   EVENT_MAPCHANGE_FadeDelayedEvent  0x0218466C  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;

typedef struct E { char pad[0x86]; u16 lo : 3; u16 hi : 13; } E;

typedef struct V3 { u32 x, y, z; } V3;

struct Desc;
struct Obj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 ZONEDATA_IsZone117(u32 id);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern void EVENT_MAPCHANGE_InitWork(void **o, void *p);
extern u32 ZONEDATA_DirToExitDir(u32 idx);
extern void ZONEDATA_SetDirectLocation(void *r, u16 id, s16 count, u32 a, u32 b, u32 c);
extern int EVENT_MAPCHANGE_FadeDelayedEvent(int ctx, int *state, u8 *p);

void *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(void *owner, u16 id, const V3 *pos)
{
    V3 v = *pos;
    void *ctx = GAMESYSTEM_GetGameData((const struct Ctx *)owner);
    void *node = func_020122C0(owner, 0, (void *)EVENT_MAPCHANGE_FadeDelayedEvent, 0x9C);
    char *x = func_020124E8((struct Obj *)node);
    int r = 0;

    if (ZONEDATA_IsZone117(id) == 1) {
        E *e = (E *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)owner));
        if (e != 0) {
            int lo = e->lo;
            r = lo - GAME_DATA_GetExitMode(ctx);
            if (r < 0)
                r += *(u8 *)((char *)e + 0x902);
        }
        v.x += (u32)r << 22;
    }
    EVENT_MAPCHANGE_InitWork((void **)x, owner);
    ZONEDATA_SetDirectLocation(x + 0x10, id, (s16)ZONEDATA_DirToExitDir(0), v.x, v.y, v.z);
    *(u32 *)(x + 0x2C) = 0;
    *(u32 *)(x + 0x40) = 0;
    return node;
}
