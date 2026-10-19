/*
 * file:     event_sweet_scent.c
 * unit:     yes
 * function: SWEET_SCENT_CreateEventNoPokemon, SWEET_SCENT_CreateEvent, SWEET_SCENT_EventMain, SWEET_SCENT_CheckWeatherClear, SWEET_SCENT_StartFade, SWEET_SCENT_FadeMain, SWEET_SCENT_FadeSetup, SWEET_SCENT_FadeCleanup
 * address:  0x021C6068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from field_g3dobj.c at 021C6068..021C63AB: the SWEET_SCENT_ field event (own prefix, own data gSweetScentFadeBgPos 0x021DAAB4). The __FILE__ anchor field_g3dobj.c (FIELD_G3DOBJ_Create 021C63FC) starts at 021C63AC, so the sweet scent code lies before the anchored file and is not part of it.
 *
 * symbols:
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_VREQ_SetMainBlendAlphaEv  0x021D3288  thumb  ov021
 *   FLD_VREQ_SetMainBlendAlpha  0x021D325C  thumb  ov021
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 *   gSweetScentFadeBgPos     0x021DAAB4  data  a2
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 */
#include "field_g3dobj_shared_types.h"
#include "event_sweet_scent_shared_types.h"

/* Sweet Scent field move (021C6068..021C6368)                          */
#define SWEET_SCENT_NO_POKEMON 6   /* party slots 0..5 are real; 6 and above mean no Pokemon */

/* Event work of the move (0x14 bytes). */
typedef struct SweetScentWork {
    u8 partyIdx;                           /* party slot of the user, 0xFF from the item */
    u8 pad01[3];
    void *gameSys;
    void *gameData;
    void *fieldMap;
    void *fieldPlayer;
} SweetScentWork;

/* Work of the screen fade task (8 bytes). */
typedef struct SweetScentFade {
    u8 bgLayer;
    u8 level;                              /* 0..8, fade strength */
    u8 interval;                           /* frames per level */
    u8 timer;
    void *vreq;                            /* VRAM request object of the field */
} SweetScentFade;

typedef struct BgPoint {
    u16 x;
    u16 y;
} BgPoint;

extern void *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
struct GameEvent;

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern void MI_CpuFill8(void *p, int v, int n);
struct FieldMap;
struct FieldPlayer;

extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
struct GameSystem;
struct GameData;

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern void FIELD_PLAYER_StartFormChange(struct FieldPlayer *player, u32 mask);

extern int FIELD_PLAYER_StepFormChange(struct FieldPlayer *player);
struct Mmdl;

extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);

extern void FLDMMDL_SetAcmd(struct Mmdl *mmdl, u16 code);

extern int FLDMMDL_EndAcmd(struct Mmdl *mmdl);
struct Fld3dCi;

extern struct Fld3dCi *FIELDMAP_GetFld3dCi(struct FieldMap *fieldMap);

extern void *FLD3D_CI_StartPartyMemberSequence(void *gameSystem, struct Fld3dCi *ci, s32 partyPos);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
struct FieldEncount;

extern struct FieldEncount *FIELDMAP_GetEncount(struct FieldMap *fieldMap);

extern s32 FIELD_ENCOUNT_CheckWildEncount(struct FieldEncount *encount, s32 triggerMode);

extern void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
struct MmdlSys;

extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern void FLDMMDL_SysResumeMove(struct MmdlSys *sys);
struct WeatherSys;

extern struct WeatherSys *FIELDMAP_GetWeather(struct FieldMap *fieldMap);

extern u16 WEATHER_GetWeatherId(struct WeatherSys *sys);
struct FldVReq;

extern struct FldVReq *FIELDMAP_GetVReq(struct FieldMap *fieldMap);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void FLD_VREQ_SetMainBlendAlphaEv(struct FldVReq *vreq, s32 ev1, s32 ev2);

extern void FLD_VREQ_SetMainBlendAlpha(struct FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);

extern void FLD_VREQ_SetBgVisible(struct FldVReq *vreq, s32 frame, u8 visible);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);

extern void BG_SYS_PushTile(u32 index);

extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);

extern const BgPoint gSweetScentFadeBgPos;

void *SWEET_SCENT_CreateEventNoPokemon(void *fieldMap, void *gameSys);

void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx);

int SWEET_SCENT_EventMain(void *task, int *state, SweetScentWork *w);

int SWEET_SCENT_CheckWeatherClear(SweetScentWork *w);

void SWEET_SCENT_StartFade(void *task, void *gameSys, void *fieldMap);

int SWEET_SCENT_FadeMain(void *task, int *state, SweetScentFade *fade);

void SWEET_SCENT_FadeSetup(SweetScentFade *fade);

void SWEET_SCENT_FadeCleanup(SweetScentFade *fade);

void *SWEET_SCENT_CreateEventNoPokemon(void *fieldMap, void *gameSys) { return SWEET_SCENT_CreateEvent(gameSys, fieldMap, 0xff); }

void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx)
{
    void *task;
    SweetScentWork *w;

    task = GAME_EVENT_Create(gameSys, 0, SWEET_SCENT_EventMain, sizeof(SweetScentWork));
    w = GAME_EVENT_GetWork(task);
    MI_CpuFill8(w, 0, sizeof(SweetScentWork));
    w->partyIdx = partyIdx;
    w->gameSys = gameSys;
    w->fieldMap = fieldMap;
    w->fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    w->gameData = GAMESYSTEM_GetGameData(gameSys);
    return task;
}

int SWEET_SCENT_EventMain(void *task, int *state, SweetScentWork *w)
{
    void *sub;

    switch (*state) {
    case 0:
        if (w->partyIdx >= SWEET_SCENT_NO_POKEMON) {
            *state = 5;
            break;
        }
        FIELD_PLAYER_StartFormChange(w->fieldPlayer, 0x80);
        (*state)++;
    case 1:
        if (FIELD_PLAYER_StepFormChange(w->fieldPlayer) != 1)
            break;
        FLDMMDL_SetAcmd(FIELD_PLAYER_GetMmdl(w->fieldPlayer), 0xa2);
        (*state)++;
        break;
    case 2:
        if (FLDMMDL_EndAcmd(FIELD_PLAYER_GetMmdl(w->fieldPlayer)) != 1)
            break;
        sub = FLD3D_CI_StartPartyMemberSequence(w->gameSys, FIELDMAP_GetFld3dCi(w->fieldMap), w->partyIdx);
        if (sub != 0)
            GAME_EVENT_CallEvent(task, sub);
        (*state)++;
        break;
    case 3:
        FIELD_PLAYER_StartFormChange(w->fieldPlayer, 8);
        (*state)++;
    case 4:
        if (FIELD_PLAYER_StepFormChange(w->fieldPlayer) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (SWEET_SCENT_CheckWeatherClear(w) == 0) {
            *state = 8;
            break;
        }
        SWEET_SCENT_StartFade(task, w->gameSys, w->fieldMap);
        *state = 6;
        break;
    case 6:
        sub = (void *)FIELD_ENCOUNT_CheckWildEncount(FIELDMAP_GetEncount(w->fieldMap), 2);
        if (sub == 0) {
            *state = 7;
            break;
        }
        GAME_EVENT_CallEvent(task, sub);
        *state = 9;
        break;
    case 7:
        SCRIPT_SYS_CallScriptEvent(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        SCRIPT_SYS_CallScriptEvent(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->fieldMap));
        return 1;
    }
    return 0;
}

int SWEET_SCENT_CheckWeatherClear(SweetScentWork *w)
{
    if (WEATHER_GetWeatherId(FIELDMAP_GetWeather(w->fieldMap)) == 0) {
        return 1;
    }
    return 0;
}

void SWEET_SCENT_StartFade(void *task, void *gameSys, void *fieldMap)
{
    void *fadeTask;
    SweetScentFade *fade;

    fadeTask = GAME_EVENT_Create(gameSys, 0, SWEET_SCENT_FadeMain, sizeof(SweetScentFade));
    fade = GAME_EVENT_GetWork(fadeTask);
    fade->bgLayer = 3;
    fade->level = 0;
    fade->interval = 2;
    fade->timer = 0;
    fade->vreq = FIELDMAP_GetVReq(fieldMap);
    GAME_EVENT_CallEvent(task, fadeTask);
}

int SWEET_SCENT_FadeMain(void *task, int *state, SweetScentFade *fade)
{
    switch (*state) {
    case 0:
        SWEET_SCENT_FadeSetup(fade);
        GFL_USE_PlaySeDefaultVolume(0x683);
        *state = *state + 1;
        break;
    case 1:
        if (fade->timer++ >= fade->interval) {
            fade->level++;
            FLD_VREQ_SetMainBlendAlphaEv(fade->vreq, fade->level, 0x10 - fade->level);
            fade->timer = 0;
        }
        if (fade->level >= 8) {
            *state = *state + 1;
        }
        break;
    case 2:
        if (fade->timer++ < 0x1e) {
            *state = *state + 1;
        }
        break;
    case 3:
        if (fade->timer++ >= fade->interval) {
            fade->level--;
            FLD_VREQ_SetMainBlendAlphaEv(fade->vreq, fade->level, 0x10 - fade->level);
            fade->timer = 0;
        }
        if (fade->level == 0) {
            *state = *state + 1;
        }
        break;
    case 4:
        FLD_VREQ_SetMainBlendAlpha(fade->vreq, 0, 0, 0, 0x1f);
        FLD_VREQ_SetBgVisible(fade->vreq, fade->bgLayer, 0);
        *state = *state + 1;
        break;
    default:
        SWEET_SCENT_FadeCleanup(fade);
        return 1;
    }
    return 0;
}

void SWEET_SCENT_FadeSetup(SweetScentFade *fade)
{
    BgPoint pos;

    pos = gSweetScentFadeBgPos;
    BG_SYS_SetPlaneVisible(fade->bgLayer, 0);
    BG_SYS_LoadPltt(fade->bgLayer, &pos, 8, 0x20);
    BG_SYS_Init(fade->bgLayer, 1, 1, 0x100);
    BG_SYS_SetTileEntry(fade->bgLayer, 0x100, 0, 0, 0x20, 0x20, 1);
    BG_SYS_PushTile(fade->bgLayer);
    FLD_VREQ_SetMainBlendAlpha(fade->vreq, 8, 0x37, fade->level, 0x10 - fade->level);
    FLD_VREQ_SetBgVisible(fade->vreq, fade->bgLayer, 1);
}

void SWEET_SCENT_FadeCleanup(SweetScentFade *fade)
{
    BgPoint pos = {0, 0};

    BG_SYS_LoadPltt(fade->bgLayer, &pos, 8, 0x20);
    BG_SYS_SetTileEntry(fade->bgLayer, 0, 0, 0, 0x20, 0x20, 1);
    BG_SYS_PushTile(fade->bgLayer);
    BG_SYS_FreeTiles(fade->bgLayer, 1, 0x100);
}
