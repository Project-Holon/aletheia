/*
 * file:     iss_switch.c
 * unit:     yes
 * function: ISS_SWITCH_Alloc, ISS_SWITCH_Free, ISS_SWITCH_Init, ISS_SWITCH_SetParam, ISS_SWITCH_CountUpFade, ISS_SWITCH_IsFadeEnd, ISS_SWITCH_Update, ISS_SWITCH_UpdateOn, ISS_SWITCH_UpdateOff, ISS_SWITCH_UpdateFadeIn, ISS_SWITCH_UpdateFadeOut, ISS_SWITCH_StartFadeIn, ISS_SWITCH_StartFadeOut, ISS_SWITCH_SetOnState, ISS_SWITCH_SetOffState, ISS_SWITCH_GetState, ISS_SWITCH_SetState, ISS_SWITCH_GetVolume, ISS_SWITCH_ApplyVolume, ISS_SWITCH_IsOnState, ISS_SWITCH_IsOffState, ISS_SWITCH_GetSubscreenMode, ISS_SWITCH_IsSeasonMatch, ISS_SWITCH_ApplySubscreenMode, ISS_SWITCH_RefreshSubscreenMode, ISS_SWITCH_CheckAreaOwner, ISS_SWITCH_CheckSpecialPower, ISS_SWITCH_CheckBirthday
 * address:  0x0202C590
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   IssSwitchFileName      0x020A7780  data
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMusicalWork  0x0201297C  thumb
 *   MOVE_POKEMON_FindEntryByZone  0x0215E6A8  thumb
 *   CALENDER_GetWeatherThunk  0x021647E8  thumb  ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   MOVE_POKEMON_IsAnyEntryActive  0x0215E6F8  thumb ov010
 *   GAME_DATA_GetSubscreenMode  0x02012994  thumb
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   ZONEDATA_IsRawZone176Or17A   0x02014044  thumb
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   APP_ENV_GetOwnerColorAndBirthMonth   0x0202EB60  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock  0x0202E888  thumb
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"
#include "iss_switch_shared_types.h"

struct Ctx;

struct Pair {
    u16 a;
    u16 b;
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);

extern void *ICA_ANIME_GetField1C(const struct Ctx *p);

extern u32 GAME_DATA_GetMusicalWork(const struct BigObj *p);

extern u32 MOVE_POKEMON_FindEntryByZone(void *a, u16 b);

extern u32 CALENDER_GetWeatherThunk(void *arg, unsigned int b);

extern u32 ZONEDATA_GetWeatherId(u32 id);

extern void GAME_DATA_SetSubscreenMode(struct BigObj *p, u8 v);

extern int MOVE_POKEMON_IsAnyEntryActive(int a0);

extern u8 GAME_DATA_GetSubscreenMode(const struct BigObj *p);

extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);

extern u32 ICA_ANIME_GetField24(const struct Ctx *p);

extern int ZONEDATA_IsZoneGroup118To13C(u32 key);

extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

extern s32 INTRUDE_COMM_GetAreaOwnerVersion(u32 a);

extern u32 GPOWER_GetSpecialPowerId(void);

extern u32 ZONEDATA_IsRawZone176Or17A(u32 id);

extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);

extern void APP_ENV_GetOwnerColorAndBirthMonth(u8 *out1, u8 *out2);

void *ISS_SWITCH_Alloc(u32 heapId);

u32 ISS_SWITCH_Free(void *sw);

void ISS_SWITCH_Init(struct IssSwitch *sw);

u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits);

void ISS_SWITCH_CountUpFade(struct IssSwitch *sw);

u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw);

void ISS_SWITCH_Update(void *sw);

void ISS_SWITCH_UpdateOn(void *sw);

void ISS_SWITCH_UpdateOff(void *sw);

u32 ISS_SWITCH_UpdateFadeIn(void *sw);

u32 ISS_SWITCH_UpdateFadeOut(void *sw);

u32 ISS_SWITCH_StartFadeIn(void *sw);

u32 ISS_SWITCH_StartFadeOut(void *sw);

u32 ISS_SWITCH_SetOnState(void *sw);

u32 ISS_SWITCH_SetOffState(void *sw);

u32 ISS_SWITCH_GetState(struct IssSwitch *sw);

struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state);

s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw);

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume);

u32 ISS_SWITCH_IsOnState(void *sw);

u32 ISS_SWITCH_IsOffState(void *sw);

u32 ISS_SWITCH_GetSubscreenMode(void *a0, u32 a1);

int ISS_SWITCH_IsSeasonMatch(int a0);

void ISS_SWITCH_ApplySubscreenMode(struct Ctx *p, u32 a1);

void ISS_SWITCH_RefreshSubscreenMode(u8 *a0, int a1);

s32 ISS_SWITCH_CheckAreaOwner(void *a0, u32 a1, u32 a2);

s32 ISS_SWITCH_CheckSpecialPower(void *a0, u32 a1, u32 a2);

u32 ISS_SWITCH_CheckBirthday(void *a, void *b, u32 c);

extern char IssSwitchFileName[];

extern struct Pair gTbl_0209FFF4[];

void *ISS_SWITCH_Alloc(u32 heapId)
{
    return func_02030734(heapId, 0xc, 0, IssSwitchFileName, 0x115);
}

/*
 * An unlabelled leaf sitting inside sub_0202C590's own literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a
 * pool-word-and-bx tail call into the ARM SDK function ENV_SetResourceSet
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md
 * covers the shape, though this is a genuine tail call rather than a
 * linker veneer). Reached only through sub_0202C548's own
 * pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5AC.c \
 *       --func ISS_SWITCH_Free --addr 0x0202C5AC --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_Free(void *sw)
{
    return func_020307B0(sw);
}

void ISS_SWITCH_Init(struct IssSwitch *sw)
{
    sw->state = 1;
    sw->fadeCount = 0;
    sw->fadeFrames = 0;
    sw->trackBits = 0;
}

/*
 * An unlabelled leaf, six bytes padded to eight, sitting between
 * sub_0202C5B4's trailing padding and ISS_SWITCH_CountUpFade's label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a plain
 * two-field setter with no prologue at all, reached only through
 * sub_0202C550's pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5C4.c \
 *       --func ISS_SWITCH_SetParam --addr 0x0202C5C4 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits)
{
    sw->fadeFrames = fadeFrames;
    sw->trackBits = trackBits;
}

void ISS_SWITCH_CountUpFade(struct IssSwitch *sw)
{
    sw->fadeCount = sw->fadeCount + 1;
    if (sw->fadeFrames < sw->fadeCount) {
        sw->fadeCount = sw->fadeFrames;
    }
}

u32 ISS_SWITCH_IsFadeEnd(struct IssSwitch *sw)
{
    if (sw->fadeFrames > sw->fadeCount) {
        return 0;
    }
    return 1;
}

void ISS_SWITCH_Update(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        ISS_SWITCH_UpdateOn(sw);
        break;
    case 1:
        ISS_SWITCH_UpdateOff(sw);
        break;
    case 2:
        ISS_SWITCH_UpdateFadeIn(sw);
        break;
    case 3:
        ISS_SWITCH_UpdateFadeOut(sw);
        break;
    }
}

void ISS_SWITCH_UpdateOn(void *sw)
{
}

void ISS_SWITCH_UpdateOff(void *sw)
{
}

u32 ISS_SWITCH_UpdateFadeIn(void *sw)
{
    ISS_SWITCH_CountUpFade(sw);
    if (ISS_SWITCH_IsFadeEnd(sw) == 1) {
        ISS_SWITCH_SetState(sw, 0);
    }
}

u32 ISS_SWITCH_UpdateFadeOut(void *sw)
{
    ISS_SWITCH_CountUpFade(sw);
    if (ISS_SWITCH_IsFadeEnd(sw) == 1) {
        ISS_SWITCH_SetState(sw, 1);
    }
}

u32 ISS_SWITCH_StartFadeIn(void *sw)
{
    if (ISS_SWITCH_IsOnState(sw) != 1) {
        ISS_SWITCH_SetState(sw, 2);
    }
}

u32 ISS_SWITCH_StartFadeOut(void *sw)
{
    if (ISS_SWITCH_IsOffState(sw) != 1) {
        ISS_SWITCH_SetState(sw, 3);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through sub_0202C570 and sub_0202C578's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between ISS_SWITCH_StartFadeOut's last instruction and
 * sub_0202C6B8's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */
u32 ISS_SWITCH_SetOnState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 0);
}

u32 ISS_SWITCH_SetOffState(void *sw)
{
    return (u32)ISS_SWITCH_SetState(sw, 1);
}

u32 ISS_SWITCH_GetState(struct IssSwitch *sw)
{
    return sw->state;
}

struct IssSwitch *ISS_SWITCH_SetState(struct IssSwitch *sw, u32 state)
{
    sw->state = state;
    sw->fadeCount = 0;
    return sw;
}

s32 ISS_SWITCH_GetVolume(struct IssSwitch *sw)
{
    s32 volume;

    switch (ISS_SWITCH_GetState((struct IssSwitch *)sw)) {
    case 0:
        return 0x7F;
    case 1:
        return 0;
    case 2:
        volume = sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    case 3:
        volume = 0x7F - sw->fadeCount * 0x7F / sw->fadeFrames;
        break;
    }
    return volume;
}

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume)
{
    GFL_USE_SetBgmTrackVolume(sw->trackBits, maxVolume * ISS_SWITCH_GetVolume(sw) / 0x7F);
}

u32 ISS_SWITCH_IsOnState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}

u32 ISS_SWITCH_IsOffState(void *sw)
{
    switch (ISS_SWITCH_GetState(sw)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}

/*
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/CALENDER_GetWeatherThunk.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */
u32 ISS_SWITCH_GetSubscreenMode(void *a0, u32 a1)
{
    u32 ctx = (u32)ICA_ANIME_GetField1C(a0);
    u32 saved = GAME_DATA_GetMusicalWork((const struct BigObj *)ctx);
    u32 r;

    r = MOVE_POKEMON_FindEntryByZone((void *)ctx, (u16)a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = ISS_SWITCH_CheckAreaOwner(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = ISS_SWITCH_CheckSpecialPower(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = ISS_SWITCH_CheckBirthday(a0, (void *)ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (ISS_SWITCH_IsSeasonMatch(ctx) != 0) {
        return (u8)CALENDER_GetWeatherThunk((void *)saved, (u16)a1);
    }
    return (u8)ZONEDATA_GetWeatherId((u16)a1);
}

int ISS_SWITCH_IsSeasonMatch(int a0){ int t0, t1; t0 = GAME_DATA_GetSeason(a0); t1 = COMM_PLAYER_SUPPORT_GetSeasonFromClock((int)t0); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 1; } else {  return 0; } }

void ISS_SWITCH_ApplySubscreenMode(struct Ctx *p, u32 a1)
{
    struct BigObj *obj = ICA_ANIME_GetField1C(p);
    u32 r = ISS_SWITCH_GetSubscreenMode(p, a1);

    GAME_DATA_SetSubscreenMode(obj, (u8)r);
}

/*
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to MOVE_POKEMON_IsAnyEntryActive in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `MOVE_POKEMON_FindEntryByZone(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 */
void ISS_SWITCH_RefreshSubscreenMode(u8 *a0, int a1)
{
    u32 v;
    u16 r;

    v = MOVE_POKEMON_FindEntryByZone(a0, (u16)a1);
    r = (u16)(u32)GAME_DATA_GetSubscreenMode((const struct BigObj *)a0);
    if (v != 0xffff) {
        GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (MOVE_POKEMON_IsAnyEntryActive((int)a0) != 1) {
        return;
    }
    GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)ZONEDATA_GetWeatherId((u16)a1));
}

/*
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */
s32 ISS_SWITCH_CheckAreaOwner(void *a0, u32 a1, u32 a2)
{
    u32 r6;
    u32 r4;
    u32 i;

    r6 = GAME_DATA_GetEventWork((const struct BigObj *)a1);
    r4 = ICA_ANIME_GetField24(a0);
    if (ZONEDATA_IsZoneGroup118To13C((u16)a2) == 0 || r4 == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (a2 == gTbl_0209FFF4[i].a) {
            if (ZONEDATA_CheckEventFlag((void *)r6, gTbl_0209FFF4[i].b) == 0) {
                if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xd;
                return 0xe;
            }
            if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}

s32 ISS_SWITCH_CheckSpecialPower(void *a0, u32 a1, u32 a2)
{
    u32 r = GAME_DATA_GetEventWork((const struct BigObj *)a1);

    if (a2 == 0x151) {
        if (ZONEDATA_CheckEventFlag((void *)r, 0x96f) != 0) {
            if (GPOWER_GetSpecialPowerId() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}

u32 ISS_SWITCH_CheckBirthday(void *a, void *b, u32 c)
{
    u8 buf[2];
    struct RtcDate date;

    if (!ZONEDATA_IsRawZone176Or17A((u16)c)) {
        goto fail;
    }
    GF_STANDARD_SetField00_F4E4(&date);
    APP_ENV_GetOwnerColorAndBirthMonth(&buf[1], &buf[0]);
    if (date.month != buf[1]) {
        goto fail;
    }
    if (date.day != buf[0]) {
        goto fail;
    }
    return 0;

fail:
    return 0xFFFF;
}
