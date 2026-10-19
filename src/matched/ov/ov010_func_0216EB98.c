/*
 * function: EVENT_BATTLE_ProcBattleTask
 * address:  0x0216EB98
 * packet:   pkt_ov010_0216EB98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    case 1's argument-less `bl FIELDMAP_GetEncEff` takes proc (the
 *           GAMESYSTEM_GetFieldMap result) as its hidden r0 argument: the matched
 *           ov021 definition is int FIELDMAP_GetEncEff(unsigned char *p). That
 *           keeps proc in r0 through the dispatch, the index in r1 and the
 *           r2 copy of proc for cases 2 and 10 (457 -> 2 bytes). The ov230
 *           probe calls resolve with the `ov230d` token, prototypes copied
 *           from the matched twin src/matched/arm9/GAMESYSTEM_ProcInit.c.
 * residue:  case 7 zeroes its spilled `ok` (sp+0xC) through r2 in the image
 *           (`movs r2,#0; str r2,[sp,#0xc]` at 0x0216ECCC), r0 in the compile.
 *           No change from ok as u32, u8, enum, function-scope, passed as the
 *           seed, or with start/end locals ahead of it; permuter 300 found
 *           nothing (baseline agrees, DIFF 2/612).
 * blocker:  even byte-correct this caps at MATCH: 0x0202E80C (arm9, Thumb,
 *           unlabelled: `ldr r1,[r0]; str r1,[r0,#8]; movs r1,#0; str
 *           r1,[r0]; bx lr`, verified C not filed: arm9 is the integrator's);
 *           0x0216EFDC (ov010 unlabelled tail-call leaf, not filed while an
 *           arm9 leaf blocks); ov093_id/ov092_id pooled ids passed to
 *           GAME_EVENT_CallProc, which is not in OVERLAY_ID_CONSUMERS;
 *           d_021EFDAC/d_021B9D94 (proc data of ov093/ov092) unwitnessed.
 * prototype conflicts (parked, matched callees not edited):
 *           EVENT_BATTLE_FreeBtlSetup (ov010 0x0216F054, src/matched/ov/EVENT_BATTLE_FreeBtlSetup.c)
 *           is defined int(int a0, int a1) but a1 is overwritten before any
 *           read (`ldr r1,[r0,#0x20]` at 0x0216F054); the three call sites
 *           here set only r0 (`adds r0, r5, #0; bl`). GAME_DATA_GetPmsWork (arm9,
 *           src/matched/arm9/GAME_DATA_GetPmsWork.c) is defined int(int p0..p3) and
 *           reads only p0; both sites here set only r0 (`ldr r0,[sp,#0x10];
 *           bl`). The C below declares both with one parameter.
 * runs:     4 iteration + checks (2 + 2 + 1) + permuter 300; one cleanup run.
 * checks:   1 every callee re-derived from its matched definition: FIELDMAP_GetEncEff takes the live proc in r0 (fixed), F054/2F20 definitions over-declare (conflict above); 2 twin GAMESYSTEM_ProcInit gives the ov230d probe tokens and prototypes (resolved 3 sites), u32 start local no change; 3 ok as u32 / enum no change; 4 u8 flag idiom (a-narrow-flag-local-is-spilled) no change, zero-register idioms read; 5 idioms re-listed, nothing new applies
 * note:     2026-10-05 wave P19 lane 6 recoup: byte-correct (612/612, 0 bytes off).
 *           Lever: case 7 writes ok in both arms (`if (probe == ~f) ok = 1; else ok = 0;`
 *           with `int ok;` uninitialised), which moves the spilled zero to r2 (was r0,
 *           2 bytes). Tried before it: six per-function pragmas (lifetimes 14 B, the rest
 *           2 B), function-scope ok, ok as the probe seed or a separate zero local, probe
 *           result in a local (3 B), ternary sum (258 B). Data words resolve with
 *           `data ov093` / `data ov092` tokens. Leaf witnesses filed:
 *           src/matched/arm9/COMM_PLAYER_SUPPORT_StashMode.c and src/matched/ov/ov010_func_0216EFDC.c (both
 *           EXACT c99 and c); the three unresolved call sites resolve once the integrator
 *           refreshes the manifest. Callee arity conflicts (matched definitions
 *           over-declare, callers pass less): EVENT_BATTLE_FreeBtlSetup and GAME_DATA_GetPmsWork.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask  0x02029B28  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   COMM_PLAYER_SUPPORT_Init  0x0202E79C  thumb
 *   COMM_PLAYER_SUPPORT_StashMode  0x0202E80C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020056A0  0x020056A0  thumb
 *   GAMESYSTEM_RandTwice  0x02011D34  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   FLD_BTL_INST_TOOL_AddBattleTally  0x02168D30  thumb  ov010
 *   EVENT_BATTLE_IsTaskResultSilent  0x0216EFDC  thumb  ov010
 *   EVENT_BATTLE_FinishBattleTask  0x0216EFF0  thumb  ov010
 *   EVENT_BATTLE_FreeBtlSetup  0x0216F054  thumb  ov010
 *   EVENT_BATTLE_CallAndInvert  0x0216E680  thumb  ov010
 *   EVENT_BATTLE_IntegrityProbeA  0x0216F064  thumb  ov010
 *   EVENT_BATTLE_IntegrityProbeB  0x0216F070  thumb  ov010
 *   EVENT_BATTLE_IntegrityDecoyC  0x0216F07C  thumb  ov010
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   func_021882DC  0x021882DC  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data  ov093
 *   d_021B9D94     0x021B9D94  data  ov092
 *   g_0214624C     0x0214624C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Info {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Info;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    Info *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Info *f10;          /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u8 pad20[4];
    void *f24;          /* 0x24 */
} Work;

extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;

struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct Record;
struct Result;
struct S0201235C;
struct Sub02014444Obj;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern int GAME_DATA_GetPmsWork(int p0);
extern void *GAME_DATA_GetListCursor(void *base);
extern u8 FIELD_STATUS_SwapSeasonDispFlag(struct Sub02014444Obj *o, u8 v);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *sys);
extern void *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(void *a, u16 b);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern void COMM_PLAYER_SUPPORT_Init(u8 *p);
extern void COMM_PLAYER_SUPPORT_StashMode(u32 *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void *func_020056A0(void (*callback)(void *, void *), void *work, u32 key);
extern void GAMESYSTEM_RandTwice(void);
extern void *SCRCMD_NETWORK_CreateCommProcEvent(void *sys);
extern void FLD_BTL_INST_TOOL_AddBattleTally(struct Record *r, struct Result *s);
extern int EVENT_BATTLE_IsTaskResultSilent(int *w);
extern void EVENT_BATTLE_FinishBattleTask(int *p, void *a);
extern int EVENT_BATTLE_FreeBtlSetup(int a0);
extern int EVENT_BATTLE_CallAndInvert(int a0);
extern int EVENT_BATTLE_IntegrityProbeA(int a0);
extern int EVENT_BATTLE_IntegrityProbeB(int a0);
extern int EVENT_BATTLE_IntegrityDecoyC(int a0);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 func_021882DC(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188390(void (*a)(void), void (*b)(void), u32 c);
extern void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int EVENT_BATTLE_ProcBattleTask(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *p04 = w->f04;
    void *proc = GAMESYSTEM_GetFieldMap(sys);
    u32 sum = 0x013A1AB5;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(sys, w->f08->f18));
        (*state)++;
        break;
    case 1:
        ENCEFF_Start((void *)FIELDMAP_GetEncEff(proc), (u32)evt, (int)w->f24);
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(evt, (void *)FIELD_STATUS_CreateFieldCloseEvent((int)sys, (int)proc));
        (*state)++;
        break;
    case 3:
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(p04), 1);
        COMM_PLAYER_SUPPORT_Init((u8 *)GAME_DATA_GetPmsWork((int)p04));
        GAME_EVENT_CallProc(evt, (u32)ov093_id, (u32)d_021EFDAC, (u32)w->f08);
        (*state)++;
        break;
    case 4:
        w->f10 = w->f08;
        w->f0c = p04;
        GAME_EVENT_CallProc(evt, (u32)ov092_id, (u32)d_021B9D94, (u32)&w->f0c);
        (*state)++;
        break;
    case 5:
        func_02034AC4((s32)ov230_id);
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(p04), 0);
        COMM_PLAYER_SUPPORT_StashMode((void *)GAME_DATA_GetPmsWork((int)p04));
        (*state)++;
        break;
    case 6: {
        int ok = 0;

        if (func_021882DC((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeA, 0) == ~(u32)EVENT_BATTLE_IntegrityProbeA)
            ok = 1;
        sum += ok ? 0 : 0x3D1;
        EVENT_BATTLE_FinishBattleTask((int *)w, p04);
        if (w->f1c != 0)
            FLD_BTL_INST_TOOL_AddBattleTally(*(void **)GAME_DATA_GetListCursor(p04), (struct Result *)w->f08);
        (*state)++;
        ok = 0;
        if (func_02188354((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeB, 0) == ~(u32)EVENT_BATTLE_IntegrityProbeB)
            ok = 1;
        sum += ok ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int ok;

        if (func_02188390((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityDecoyC, 0) == ~(u32)EVENT_BATTLE_IntegrityDecoyC)
            ok = 1;
        else
            ok = 0;
        sum += ok * 0x9D;
        if (w->f18 == 0 && EVENT_BATTLE_IsTaskResultSilent((int *)w) == 1)
            GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(sys, 0x1E));
        else
            GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(sys));
        func_02034A5C((s32)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (w->f18 == 0 && EVENT_BATTLE_IsTaskResultSilent((int *)w) == 1) {
            if (w->f14 == 1) {
                EVENT_BATTLE_FreeBtlSetup((int)w);
                return 1;
            }
            EVENT_BATTLE_FreeBtlSetup((int)w);
            GAME_EVENT_ChangeEvent(evt, SCRCMD_NETWORK_CreateCommProcEvent(sys));
            return 0;
        }
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(sys));
        (*state)++;
        break;
    case 9:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(sys));
        (*state)++;
        break;
    case 10:
        if (w->f14 == 0)
            GAME_EVENT_CallEvent(evt, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(sys, (int)proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        EVENT_BATTLE_FreeBtlSetup((int)w);
        return 1;
    }
    if (sum % 0x1933 != 0) {
        func_020056A0((void (*)(void *, void *))GAMESYSTEM_RandTwice, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}
