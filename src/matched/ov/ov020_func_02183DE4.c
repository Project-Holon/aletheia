/*
 * function: EVENT_MAPCHANGE_ContinueEvent
 * address:  0x02183DE4
 * packet:   pkt_ov020_02183DE4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct at 376 of 376 bytes.  Four wildcarded call sites, all of
 * them unlabelled tail-call leaves with no witness outside this range.
 * Each leaf's C below was verified EXACT with `match.py one` in a scratch
 * file; none is filed, because the arm9 one belongs to the integrator:
 *   +0xD4  FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx (arm9, the integrator's): ldr r3,=FIELD_SOUND_SYSTEM_GetFieldBgmForZone+1; bx r3
 *          int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(int a, int b, int c)
 *          { return FIELD_SOUND_SYSTEM_GetFieldBgmForZone(a, b, c); }
 *   +0x96  func_02164474 (ov010): void f(int a, int b) { MOVE_POKEMON_MoveActiveEntries(a, b); }
 *   +0xB6  FLDMMDL_SysLoadObjCodeParamCache (ov010): void f(u8 *p, int n)
 *          { ARC_TOOL_ReadMember(*(int *)(p + 0x44), 0x3a, n); }   (02048F4C arm)
 *   +0xBC  FLDMMDL_ClearObjCodeParamCache (ov010): void f(u8 *p)
 *          { MI_CpuFill8(*(int *)(p + 0x44), 0, 0x310); }  (02082BCC arm)
 * Filing the three ov010 leaves (region hint ov010: ov009 overlaps them)
 * and the arm9 leaf makes this file EXACT unchanged.  This is the callback
 * EVENT_MAPCHANGE_CreateContinueEvent registers through func_020122C0.
 *
 * 2026-10-04 (wD2 lane 02): the last blocker, the ov010 leaf func_02164474, is now filed as
 * src/matched/ov/ov010_func_02164474.c (EXACT); the other three leaves were already filed. The tool still reports
 * it unresolved because the manifest is stale. Expected EXACT after the integrator's manifest refresh.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_SetContinueFlag  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   EVENT_MAPCHANGE_DeleteAllMmdlOfSystem  0x02185B70  thumb  ov020
 *   EVENT_MAPCHANGE_UpdateFieldStateForZone  0x02185A68  thumb  ov020
 *   EVENT_MAPCHANGE_StartSeasonEffect  0x0218601C  thumb  ov020
 *   EVENT_MAPCHANGE_ApplyLocation  0x021857C0  thumb  ov020
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   ZONEDATA_GetMapSubType  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   FLDMMDL_SysLoadObjCodeParamCache  0x0216E29C  thumb  ov010
 *   FLDMMDL_ClearObjCodeParamCache  0x0216CCCC  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldOpenNoNotifyEvent  0x020145FC  thumb
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct Rec1C;
struct Sub02014444Obj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012B38(const struct BigObj *p);
extern void FIELD_STATUS_SetContinueFlag(struct Sub02014444Obj *o, u8 v);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(void *p);
extern void EVENT_MAPCHANGE_UpdateFieldStateForZone(void *a, int b);
extern void EVENT_MAPCHANGE_StartSeasonEffect(int a);
extern void EVENT_MAPCHANGE_ApplyLocation(void *a, int b);
extern void GAME_BEACON_SetZone(u32 a0, u32 a1);
extern void FIELD_CLOCK_Update(int a);
extern void func_02164474(int a, int b);
extern void func_0202C860(u8 *a0, int a1);
extern u8 ZONEDATA_GetMapSubType(u32 id);
extern u32 func_02012964(const struct BigObj *p);
extern void FLDMMDL_SysLoadObjCodeParamCache(struct Obj *o, int v);
extern void FLDMMDL_ClearObjCodeParamCache(struct Obj *o);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldOpenNoNotifyEvent(int a);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern void *func_0201210C(const struct Ctx *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(int a, int b, int c, int d, int e, int f, int g);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_ShowForZone(void *p, int v);

int EVENT_MAPCHANGE_ContinueEvent(int ctx, int *state, u8 *p)
{
    int a;
    int s;
    int m;
    u8 *q;
    int n;
    int t;

    a = *(int *)(p + 0);
    s = (int)func_020120F4((const struct Ctx *)a);
    m = func_0201296C((const struct BigObj *)s);

    switch (*state) {
    case 0:
        FIELD_STATUS_SetContinueFlag(func_02012B38((const struct BigObj *)s), 1);
        if (*(int *)(p + 0xc) != 0) {
            q = (u8 *)func_02012894((const struct BigObj *)s);
            *(s16 *)(p + 8) = *(s16 *)(q + 4);
            EVENT_MAPCHANGE_DeleteAllMmdlOfSystem((void *)a);
            EVENT_MAPCHANGE_UpdateFieldStateForZone((void *)a, *(u16 *)(p + 8));
            EVENT_MAPCHANGE_StartSeasonEffect(s);
            EVENT_MAPCHANGE_ApplyLocation((void *)a, (int)q);
            GAME_BEACON_SetZone(*(u16 *)(q + 4), s);
        } else {
            EVENT_MAPCHANGE_UpdateFieldStateForZone((void *)a, *(u16 *)(p + 8));
            EVENT_MAPCHANGE_StartSeasonEffect(s);
            FIELD_CLOCK_Update(s);
            func_02164474(s, *(u16 *)(p + 8));
            func_0202C860((u8 *)s, *(u16 *)(p + 8));
            n = ZONEDATA_GetMapSubType(*(u16 *)(p + 8));
            t = func_02012964((const struct BigObj *)s);
            if (n < 16) {
                FLDMMDL_SysLoadObjCodeParamCache((struct Obj *)t, n);
            } else {
                FLDMMDL_ClearObjCodeParamCache((struct Obj *)t);
            }
        }
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)ctx, func_020298A0((void *)a, FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx((void *)s, *(u16 *)(p + 8), func_02012984((const struct BigObj *)s)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)FIELD_STATUS_CreateFieldOpenNoNotifyEvent(a));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0xc) != 0 && *((u16 *)ZONEDATA_GetEventWorkAddress(m, 0x4041)) != 0) {
            SCRIPT_SYS_CallScriptEvent((void *)ctx, 0x83b, 0, 0, 0x15);
        } else {
            n = func_02012984((const struct BigObj *)s);
            GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn(a, (int)func_0201210C((const struct Ctx *)a), 3, 0, 0, n, n));
        }
        (*state)++;
        break;
    case 4:
        t = (int)func_0201210C((const struct Ctx *)a);
        if (FIELDMAP_GetPlaceName((u8 *)t) != 0) {
            FIELD_PLACE_NAME_ShowForZone((void *)FIELDMAP_GetPlaceName((u8 *)t), *(u16 *)(p + 8));
        }
        return 1;
    }
    return 0;
}
