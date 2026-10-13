/*
 * file:     p_sta_sub.c
 * unit:     yes
 * function: P_STA_SUB_Create, P_STA_SUB_Delete, P_STA_SUB_Main, P_STA_SUB_LoadArcGraphics, P_STA_SUB_Exit, P_STA_SUB_CreateObjects, P_STA_SUB_DeleteObjects, P_STA_SUB_InitWindows, P_STA_SUB_Refresh, P_STA_SUB_FreeWindows, P_STA_SUB_HideSprite, P_STA_SUB_PrintWindows, P_STA_SUB_UpdatePet, P_STA_SUB_StartPetReaction, P_STA_SUB_StepPetTimer, P_STA_SUB_PetWiggle, P_STA_SUB_PetHop, P_STA_SUB_PetRise, P_STA_SUB_UpdateTouch, P_STA_SUB_TrackStrokes, P_STA_SUB_ResetStroke, P_STA_SUB_AddStrokeTurn, P_STA_SUB_UpdateLapFrames, P_STA_SUB_CreateMcss, P_STA_SUB_DeleteMcss, P_STA_SUB_SetPetOffset, P_STA_SUB_ApplyMcssOffset, P_STA_SUB_GetSpeciesAdjust
 * address:  0x021D65D8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * The cut at 0x021D65D8 from p_status.c is certain (__FILE__ anchor boundary).
 * Split from p_sta_oam.c: 0x021D65D8-0x021D7B00. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use PStaSubWork (PStatusWork.subWork).
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   _ffix 0x0209C494 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_02030734 0x02030734 arm
 *   P_STA_SUB_FileName 0x021DC818 data a1
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   MCSS_SetOfsScale 0x02015D30 thumb
 *   func_02048AFC 0x02048AFC arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021DC234 0x021DC234 data a4
 *   d_021DC228 0x021DC228 data a4
 *   d_021DC198 0x021DC198 data a4
 *   d_021DC210 0x021DC210 data a4
 *   d_021DC170 0x021DC170 data a4
 *   d_021DC178 0x021DC178 data a4
 *   d_021DC168 0x021DC168 data a4
 *   d_021DC158 0x021DC158 data a1
 *   d_021DC160 0x021DC160 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049F34 0x02049F34 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   d_021DC204 0x021DC204 data a4
 *   d_021DC21C 0x021DC21C data a4
 *   d_021DC1B0 0x021DC1B0 data a4
 *   d_021DC1A4 0x021DC1A4 data a4
 *   d_021DC18C 0x021DC18C data a4
 *   d_021DC1BC 0x021DC1BC data a4
 *   POKEPARTY_SetSlotFlag 0x0201ACDC thumb
 *   func_020452E8 0x020452E8 arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   d_021DC1D4 0x021DC1D4 data a4
 *   MCSS_SetPosition 0x02015C48 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   d_021DC1E0 0x021DC1E0 data a1
 *   d_021DC1F8 0x021DC1F8 data ov131 a4
 *   d_021DC240 0x021DC240 data ov131 a4
 *   d_021DC180 0x021DC180 data a4
 *   d_021DC1C8 0x021DC1C8 data ov131 a4
 *   MCSS_SetShadowRotateX 0x02015D80 thumb
 *   MCSS_SetShadowScale 0x02015CDC thumb
 *   MCSS_Del 0x02015BA4 thumb
 *   d_021DC1EC 0x021DC1EC data a4
 *   d_020A5078 0x020A5078 data a2
 *   func_0207C9D0 0x0207C9D0 arm
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   POKE_TOOL_IsBoxShiny 0x02017EB4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   MCSS_SetShadowAlpha  0x02015FD4  thumb  arm9
 *   MCSS_TOOL_AddPokeMcss  0x02017270  thumb  arm9
 *   MCSS_TOOL_SetAnimeStopCallback  0x020173B4  thumb  arm9
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb  arm9
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   POKEPARTY_GetSlotFlag  0x0201ACC4  thumb  arm9
 *   POKERUS_IsBoxInfected  0x0201B268  thumb  arm9
 *   POKERUS_IsBoxCured  0x0201B28C  thumb  arm9
 */

#include "p_status_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef int fx32;

struct Actor;
struct Unit;
struct Bmp;
struct BmpWin;
struct Strbuf;
struct MsgData;
struct WordSet;
struct BoxPokemon;
struct PokemonParam;
struct PokePersonal;

typedef struct { fx32 x, y, z; } VecFx32;

/* Direction of a stroke on the touch screen (y grows downward). */
typedef enum {
    STA_SUB_DIR_NONE,
    STA_SUB_DIR_RIGHT,
    STA_SUB_DIR_DOWN,
    STA_SUB_DIR_LEFT,
    STA_SUB_DIR_UP
} StaSubStrokeDir;

/* Set when a full circle was completed (the stroke went from up back to right). */
typedef enum {
    STA_SUB_LAP_NOT_DONE,
    STA_SUB_LAP_DONE
} StaSubLapFlag;

/* Pet reaction states (PStaSubWork.petState). */
enum {
    STA_SUB_PET_IDLE,
    STA_SUB_PET_WIGGLE,         /* horizontal strokes */
    STA_SUB_PET_HOP,            /* vertical strokes */
    STA_SUB_PET_RISE,           /* circular strokes */
    STA_SUB_PET_WIGGLE_END,
    STA_SUB_PET_HOP_END,
    STA_SUB_PET_RISE_END
};

/* Sprite flip states (PStaSubWork.flipState): dragging the Pokemon off its area swaps front and back sprite. */
enum {
    STA_SUB_FLIP_IDLE,
    STA_SUB_FLIP_TO_BACK,
    STA_SUB_FLIP_BACK,
    STA_SUB_FLIP_TO_FRONT
};

enum {
    STA_SUB_MCSS_FRONT,
    STA_SUB_MCSS_BACK
};

/* Indices of PStaSubWork.iconObj: 0..5 are the six marks. */
enum {
    STA_SUB_ICON_MARK_COUNT = 6,
    STA_SUB_ICON_SHINY = 6,
    STA_SUB_ICON_POKERUS_CURED = 7,
    STA_SUB_ICON_COUNT = 8
};

/* Where a stroke started and how often its direction changed. */
typedef struct StaSubStroke {
    u8 turnCount;                       /* 0x0 */
    u8 age;                             /* 0x1: frames since the last reset */
    u8 startX;                          /* 0x2 */
    u8 startY;                          /* 0x3 */
    unsigned int dir;                   /* 0x4: StaSubStrokeDir of the last accepted turn */
} StaSubStroke;

/* Sub-screen work of p_sta_sub.c (PStatusWork.subWork, 0x9C bytes): the Pokemon sprite, its icons and name/item windows,
 * and the touch-screen petting reactions. */
struct PStaSubWork {
    void *mcss[2];                      /* 0x00: sprites, STA_SUB_MCSS_FRONT and STA_SUB_MCSS_BACK */
    unsigned int flipState;             /* 0x08: STA_SUB_FLIP_* */
    unsigned int showFront;             /* 0x0C: 1 = front sprite shown; kept in the party between screens */
    int isStaticSprite;                 /* 0x10: personal field 16 is 1, the sprite does not move when petted */
    int personalAttr38;                 /* 0x14: personal field 38, not read afterwards */
    struct BmpWin *nameWin;             /* 0x18: nickname, gender, level */
    struct BmpWin *itemWin;             /* 0x1C: held item */
    struct Actor *ballObj;              /* 0x20 */
    struct Actor *iconObj[STA_SUB_ICON_COUNT];  /* 0x24: marks, shiny, pokerus cured */
    struct Actor *pokerusObj;           /* 0x44 */
    struct Actor *conditionObj;         /* 0x48: status condition, replaces the pokerus icon */
    VecFx32 petOffset;                  /* 0x4C: sprite offset from the pet reaction */
    unsigned int didPet;                /* 0x58: 1 once a reaction started in this touch */
    unsigned int petState;              /* 0x5C: STA_SUB_PET_* */
    unsigned short petTimer;            /* 0x60: frames spent in the current reaction */
    unsigned short petFrame;            /* 0x62 */
    unsigned short petPhase;            /* 0x64 */
    unsigned short petHeight;           /* 0x66 */
    unsigned short petHeightTarget;     /* 0x68 */
    unsigned char pad_6A[2];
    unsigned int isTouching;            /* 0x6C: touch is held inside the Pokemon area */
    unsigned int lastTouchX;            /* 0x70 */
    unsigned int lastTouchY;            /* 0x74 */
    StaSubStroke horizStroke;           /* 0x78 */
    StaSubStroke vertStroke;            /* 0x80 */
    StaSubStroke circleStroke;          /* 0x88 */
    unsigned int circleSense;           /* 0x90: 1 = clockwise, 2 = counter-clockwise, 0 = unknown */
    unsigned char lapFrames[5];         /* 0x94: frames the last five laps took */
    unsigned char lapFrameCount;        /* 0x99: frames of the lap in progress */
    unsigned char lapIndex;             /* 0x9A: next slot of lapFrames */
    unsigned char flipFrame;            /* 0x9B: frame counter of the sprite flip */
};

/* One value per step of the turn animation. */
struct StaSubFrameTable { int frame[2]; };

/* Hit areas of the touch screen. */
struct TouchHitTable { StaTouchRect rect[3]; };

extern u32 func_020307B0(void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
extern void func_0204B878(struct Actor *actor, u16 anim);
extern void func_02048AD0(void *camera);
extern void func_020498F4(void *arc, u32 fileId, u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_020275E4(void);
extern int func_02027720(int ballId);
extern int func_0202772C(int ballId);
extern struct Actor *func_0204B294(void *unit, unsigned int chrRes, unsigned int plttRes, unsigned int cellRes, const void *pos, u16 space, u16 heapId);
extern void func_0204B3DC(struct Actor *actor, u32 enable);
extern void func_0204B3B4(struct Actor *actor);
extern u32 func_02017E88(void *mon, int paramId, void *out);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
extern void func_02045808(struct Strbuf *str);
extern void func_0201C724(void *printQue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, void *font, u16 color);
extern struct Bmp *func_02045770(struct BmpWin *win);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MCSS_ResetVanishFlag(void *mcss);
extern void MCSS_SetVanishFlag(void *mcss);
extern void MCSS_SetOfsPosition(void *mcss, const VecFx32 *src);
extern void MCSS_SetOfsScale(void *mcss, const VecFx32 *src);
extern void func_02048AFC(void *camera, const VecFx32 *pos);
extern int POKEPARTY_GetSlotFlag(void *party, u32 pos);
extern struct PokePersonal *func_0201ADE4(u32 species, int form, u32 heapId);
extern u32 func_0201AE1C(const struct PokePersonal *personal, u32 field);
extern void func_0201AE14(struct PokePersonal *personal);
extern struct BmpWin *func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern void func_02041B6C(u32 flag);
extern void *func_02049F34(u32 arcId, u32 fileId, u32 out, u32 heapId);
extern void *func_02049DB4(u32 arcId, u32 fileId, u32 a, u32 out, u16 heapId);
extern void func_0204ADEC(u32 plttRes, void *pltt, u32 a);
extern void func_0204A9D0(int chrRes, void *chr);
extern u32 POKERUS_IsBoxCured(struct BoxPokemon *mon);
extern u32 POKE_TOOL_IsBoxShiny(struct BoxPokemon *mon);
extern u32 POKE_TOOL_GetStatusCondition(struct PokemonParam *pp);
extern int func_020276C4(struct PokemonParam *pp);
extern u32 POKERUS_IsBoxInfected(struct BoxPokemon *mon);
extern void POKEPARTY_SetSlotFlag(void *party, u32 pos, u32 showFront);
extern u32 func_020452E8(struct BmpWin *win);
extern struct WordSet *func_0201EC64(u32 heapId);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const struct Strbuf *src, u32 a, u32 b, u32 c);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 POKE_TOOL_CalcBoxLevel(struct BoxPokemon *mon);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 a, u32 b);
extern void func_0201EF40(struct WordSet *wordSet, u32 index, u32 itemId);
extern void MCSS_ResetAnmStopFlag(void *mcss);
extern void MCSS_SetPosition(void *mcss, const VecFx32 *src);
extern int _ffix(float);
extern void MCSS_SetAnmStopFlag(void *mcss);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int TOUCHPANEL_HitCont(const struct TouchHitTable *table);
extern void *MCSS_TOOL_AddPokeMcss(void *mcssSys, void *mon, u32 face, u32 a, u32 b, u32 c);
extern void MCSS_SetShadowAlpha(void *mcss, int value);
extern void MCSS_SetShadowRotateX(void *mcss, u16 value);
extern void MCSS_TOOL_SetAnimeStopCallback(void *mcss);
extern void MCSS_SetShadowScale(void *mcss, const VecFx32 *src);
extern void MCSS_Del(void *mcssSys, void *mcss);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void MCSS_SetShadowOffset(void *mcss, const VecFx32 *src);
void *P_STATUS_GetPokePara(PStatusWork *wk);
int P_STATUS_GetPokeParaSource(PStatusWork *wk);
void *P_STA_SUB_Create(PStatusWork *wk);
void P_STA_SUB_Delete(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_Main(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_LoadArcGraphics(PStatusWork *wk, int unused, void *arc);
void P_STA_SUB_Exit(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_CreateObjects(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_DeleteObjects(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_InitWindows(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_Refresh(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_FreeWindows(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_HideSprite(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_PrintWindows(PStatusWork *wk, PStaSubWork *work, void *mon);
void P_STA_SUB_UpdatePet(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_StartPetReaction(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_StepPetTimer(PStatusWork *wk, PStaSubWork *work, u8 *strokeTurns);
int P_STA_SUB_PetWiggle(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_PetHop(PStatusWork *wk, PStaSubWork *work);
int P_STA_SUB_PetRise(PStatusWork *wk, PStaSubWork *work, int isRising);
void P_STA_SUB_UpdateTouch(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_TrackStrokes(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_ResetStroke(StaSubStroke *stroke, u32 x, u32 y);
void P_STA_SUB_AddStrokeTurn(StaSubStroke *stroke, u32 x, u32 y, int dir);
void P_STA_SUB_UpdateLapFrames(PStatusWork *wk, PStaSubWork *work, int lapDone);
void P_STA_SUB_CreateMcss(PStatusWork *wk, PStaSubWork *work, void *mon);
void P_STA_SUB_DeleteMcss(PStatusWork *wk, PStaSubWork *work);
void P_STA_SUB_SetPetOffset(PStatusWork *wk, PStaSubWork *work, int radius);
void P_STA_SUB_ApplyMcssOffset(PStatusWork *wk, PStaSubWork *work, VecFx32 *baseOfs);
void P_STA_SUB_GetSpeciesAdjust(PStatusWork *wk, PStaSubWork *work, VecFx32 *extraOfs, VecFx32 *frontScale);
extern const char P_STA_SUB_FileName[];
extern const s16 d_020A1B38[];
extern const VecFx32 d_021DC234;
extern const VecFx32 d_021DC228;
extern const VecFx32 d_021DC198;
extern const VecFx32 d_021DC210;
extern const struct StaSubFrameTable d_021DC170;
extern const struct StaSubFrameTable d_021DC178;
extern const struct StaSubFrameTable d_021DC168;
extern const u8 d_021DC158[];
extern const u8 d_021DC160[];
extern const VecFx32 d_021DC204;
extern const VecFx32 d_021DC21C;
extern const VecFx32 d_021DC1B0;
extern const VecFx32 d_021DC1A4;
extern const VecFx32 d_021DC18C;
extern const VecFx32 d_021DC1BC;
extern const VecFx32 d_021DC1D4;
extern const struct TouchHitTable d_021DC1E0;
extern const VecFx32 d_021DC1F8;
extern const VecFx32 d_021DC240;
extern const VecFx32 d_021DC180;
extern const VecFx32 d_021DC1C8;
extern const VecFx32 d_021DC1EC;
extern const short d_020A5078[];


void *P_STA_SUB_Create(PStatusWork *wk) {
    PStaSubWork *work = func_02030734(wk->heapId, 0x9c, 1, P_STA_SUB_FileName, 0x10d);
    work->mcss[STA_SUB_MCSS_FRONT] = 0;
    work->mcss[STA_SUB_MCSS_BACK] = 0;
    work->isTouching = 0;
    work->showFront = 1;
    work->flipState = STA_SUB_FLIP_IDLE;
    work->petState = STA_SUB_PET_IDLE;
    return work;
}

void P_STA_SUB_Delete(PStatusWork *wk, PStaSubWork *work) {
    func_020307B0(work);
}

void P_STA_SUB_Main(PStatusWork *wk, PStaSubWork *work) {
    u32 state = work->flipState;
    if (state == STA_SUB_FLIP_IDLE || state == STA_SUB_FLIP_BACK) {
        P_STA_SUB_UpdateTouch(wk, work);
        P_STA_SUB_UpdatePet(wk, work);
        return;
    }
    if (state == STA_SUB_FLIP_TO_FRONT) {
        VecFx32 cameraPos = d_021DC234;
        VecFx32 scale = d_021DC228;
        VecFx32 ofsPos = {0, 0, 0};
        u8 frame;
        work->flipFrame = work->flipFrame + 1;
        if (work->flipFrame > 5 && work->showFront == 0) {
            MCSS_ResetVanishFlag(work->mcss[STA_SUB_MCSS_FRONT]);
            MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_BACK]);
            work->showFront = 1;
        }
        frame = work->flipFrame;
        if (frame >= 10) {
            P_STA_SUB_SetPetOffset(wk, work, 0);
            work->flipState = STA_SUB_FLIP_IDLE;
        } else {
            u16 angle;
            cameraPos.x = frame * 0x19000 / 10 - 0x42000;
            angle = (work->flipFrame << 15) / 10;
            ofsPos.y = d_020A1B38[(angle >> 4) * 2] << 5;
            if (work->isStaticSprite == 1) ofsPos.y = 0;
            P_STA_SUB_SetPetOffset(wk, work, ofsPos.y);
        }
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_BACK], &ofsPos);
        MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_FRONT], &scale);
        func_02048AFC(wk->camera, &cameraPos);
        func_02048AD0(wk->camera);
    } else if (state == STA_SUB_FLIP_TO_BACK) {
        VecFx32 cameraPos = d_021DC198;
        VecFx32 scale = d_021DC210;
        u8 frame;
        work->flipFrame = work->flipFrame + 1;
        frame = work->flipFrame;
        if (frame < 3) {
            struct StaSubFrameTable scaleXTbl = d_021DC170;
            struct StaSubFrameTable scaleYTbl = d_021DC178;
            struct StaSubFrameTable cameraXTbl = d_021DC168;
            u8 step = frame - 1;
            scale.x = scaleXTbl.frame[step];
            scale.y = scaleYTbl.frame[step];
            cameraPos.x = cameraXTbl.frame[step];
            func_02048AFC(wk->camera, &cameraPos);
            func_02048AD0(wk->camera);
            MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_FRONT], &scale);
        } else {
            MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_FRONT]);
            MCSS_ResetVanishFlag(work->mcss[STA_SUB_MCSS_BACK]);
            MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_BACK], &scale);
            func_02048AFC(wk->camera, &cameraPos);
            func_02048AD0(wk->camera);
            work->showFront = 0;
            work->flipState = STA_SUB_FLIP_BACK;
            work->isTouching = 0;
        }
    }
}

void P_STA_SUB_LoadArcGraphics(PStatusWork *wk, int unused, void *arc)
{
    func_020498F4(arc, 0x3e, 2, 0, 0, 0, wk->heapId);
}

void P_STA_SUB_Exit(PStatusWork *wk, PStaSubWork *work) {
    P_STA_SUB_FreeWindows(wk, work);
}

void P_STA_SUB_CreateObjects(PStatusWork *wk, PStaSubWork *work) {
    StaOamActorPos pos[4];
    u8 i;
    pos[3].x = 168;
    pos[3].y = 8;
    pos[3].drawPriority = 10;
    pos[3].bgPriority = 1;
    pos[3].animSeq = 0;
    work->ballObj = func_0204B294(wk->clunit, wk->objRes[14], wk->objRes[1], wk->objRes[27], &pos[3], 0, wk->heapId);
    func_0204B3DC(work->ballObj, 0);
    pos[2].y = 128;
    pos[2].drawPriority = 10;
    pos[2].bgPriority = 1;
    for (i = 0; i < 8; i++) {
        pos[2].x = d_021DC158[i];
        pos[2].animSeq = d_021DC160[i];
        work->iconObj[i] = func_0204B294(wk->clunit, wk->objRes[15], wk->objRes[2], wk->objRes[28], &pos[2], 0, wk->heapId);
        func_0204B3DC(work->iconObj[i], 1);
    }
    pos[1].x = 236;
    pos[1].y = 26;
    pos[1].drawPriority = 10;
    pos[1].bgPriority = 1;
    pos[1].animSeq = 0;
    work->pokerusObj = func_0204B294(wk->clunit, wk->objRes[22], wk->objRes[9], wk->objRes[34], &pos[1], 0, wk->heapId);
    func_0204B3DC(work->pokerusObj, 0);
    pos[0].x = 241;
    pos[0].y = 31;
    pos[0].drawPriority = 10;
    pos[0].bgPriority = 1;
    pos[0].animSeq = 0;
    work->conditionObj = func_0204B294(wk->clunit, wk->objRes[23], wk->objRes[10], wk->objRes[35], &pos[0], 0, wk->heapId);
    func_0204B3DC(work->conditionObj, 0);
}

void P_STA_SUB_DeleteObjects(PStatusWork *wk, PStaSubWork *work) {
    u8 i;
    func_0204B3B4(work->conditionObj);
    func_0204B3B4(work->pokerusObj);
    for (i = 0; i < 8; i++) func_0204B3B4(work->iconObj[i]);
    func_0204B3B4(work->ballObj);
}

void P_STA_SUB_InitWindows(PStatusWork *wk, PStaSubWork *work) {
    void *mon = P_STATUS_GetPokePara(wk);
    struct PokePersonal *personal;
    int species, form;
    if (wk->param->ppt == 1) work->showFront = POKEPARTY_GetSlotFlag(wk->param->ppd, wk->pos); else work->showFront = 1;
    if (wk->isEgg == 0) {
        species = func_02017E88(mon, 5, 0);
        form = func_02017E88(mon, 111, 0);
        personal = func_0201ADE4((unsigned short)species, (unsigned short)form, wk->heapId);
        if (func_0201AE1C(personal, 16) == 1) work->isStaticSprite = 1; else work->isStaticSprite = 0;
        work->personalAttr38 = func_0201AE1C(personal, 38);
        func_0201AE14(personal);
    } else {
        work->isStaticSprite = 0;
        work->personalAttr38 = 0;
    }
    work->nameWin = func_020450F0(1, 19, 0, 13, 4, 14, 1);
    work->itemWin = func_020450F0(1, 19, 17, 13, 4, 14, 1);
    P_STA_SUB_PrintWindows(wk, work, mon);
}

/*
 * lever: block-local VecFx32 zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 */
void P_STA_SUB_Refresh(PStatusWork *wk, PStaSubWork *work)
{
    void *ballPltt, *ballChr;
    void *mon, *pp, *ballBuf;
    struct BmpWin *win;
    u32 ballId, ballArc, marks;
    u8 i, markBit;
    mon = P_STATUS_GetPokePara(wk);
    pp = (void *)P_STATUS_GetPokeParaSource(wk);
    P_STA_SUB_CreateMcss(wk, work, mon);
    win = work->nameWin;
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
    win = work->itemWin;
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
    ballId = func_02017E88(mon, 0x98, 0);
    ballArc = func_020275E4();
    ballBuf = func_02049F34(ballArc, func_02027720(ballId), (u32)&ballPltt, wk->heapId);
    func_0204ADEC(wk->objRes[1], ballPltt, 1);
    func_020307B0(ballBuf);
    ballArc = func_020275E4();
    ballBuf = func_02049DB4(ballArc, func_0202772C(ballId), 0, (u32)&ballChr, wk->heapId);
    func_0204A9D0((int)wk->objRes[14], ballChr);
    func_020307B0(ballBuf);
    func_0204B3DC(work->ballObj, 1);
    marks = func_02017E88(mon, 11, 0);
    for (i = 0, markBit = 1; i < STA_SUB_ICON_MARK_COUNT; markBit = (u8)(markBit << 1), i++) {
        if (marks & markBit) func_0204B878(work->iconObj[i], i * 2 + 1);
        else func_0204B878(work->iconObj[i], i * 2);
    }
    if (POKERUS_IsBoxCured(mon) == 1) func_0204B3DC(work->iconObj[STA_SUB_ICON_POKERUS_CURED], 1);
    else func_0204B3DC(work->iconObj[STA_SUB_ICON_POKERUS_CURED], 0);
    if (POKE_TOOL_IsBoxShiny(mon) == 1 && wk->isEgg == 0)
        func_0204B3DC(work->iconObj[STA_SUB_ICON_SHINY], 1);
    else func_0204B3DC(work->iconObj[STA_SUB_ICON_SHINY], 0);
    if (work->showFront == 1) {
        VecFx32 cameraPos = d_021DC204;
        VecFx32 scale = d_021DC21C;
        VecFx32 ofsPos = {0, 0, 0};
        VecFx32 baseOfs = d_021DC1B0;
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
        P_STA_SUB_ApplyMcssOffset(wk, work, &baseOfs);
        MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_FRONT], &scale);
        func_02048AFC(wk->camera, &cameraPos);
        func_02048AD0(wk->camera);
        work->flipState = STA_SUB_FLIP_IDLE;
    } else {
        VecFx32 cameraPos = d_021DC1A4;
        VecFx32 scale = d_021DC18C;
        VecFx32 ofsPos = {0, 0, 0};
        VecFx32 baseOfs = d_021DC1BC;
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
        P_STA_SUB_ApplyMcssOffset(wk, work, &baseOfs);
        MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_BACK], &scale);
        func_02048AFC(wk->camera, &cameraPos);
        func_02048AD0(wk->camera);
        work->flipState = STA_SUB_FLIP_BACK;
    }
    if ((u8)POKE_TOOL_GetStatusCondition(pp) != 0) {
        func_0204B878(work->conditionObj, func_020276C4(pp));
        func_0204B3DC(work->conditionObj, 1);
        func_0204B3DC(work->pokerusObj, 0);
    } else {
        func_0204B3DC(work->conditionObj, 0);
        if (POKERUS_IsBoxInfected(mon) == 1) func_0204B3DC(work->pokerusObj, 1);
        else func_0204B3DC(work->pokerusObj, 0);
    }
    {
        VecFx32 zero = {0, 0, 0};
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &zero);
        MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_BACK], &zero);
        work->horizStroke.turnCount = 0;
        work->horizStroke.age = 0;
        work->vertStroke.turnCount = 0;
        work->vertStroke.age = 0;
        work->isTouching = 0;
        work->petState = STA_SUB_PET_IDLE;
        work->circleStroke.turnCount = 0;
        work->circleStroke.age = 0;
    }
}

void P_STA_SUB_FreeWindows(PStatusWork *wk, PStaSubWork *work) {
    PStatusParam *param = wk->param;
    if (param->ppt == 1) POKEPARTY_SetSlotFlag(param->ppd, wk->dispPos, work->showFront);
    func_020452E8(work->itemWin);
    func_020452E8(work->nameWin);
}

void P_STA_SUB_HideSprite(PStatusWork *wk, PStaSubWork *work)
{
    P_STA_SUB_DeleteMcss(wk, work);
    func_0204B3DC(work->ballObj, 0);
}

void P_STA_SUB_PrintWindows(PStatusWork *wk, PStaSubWork *work, void *mon)
{
    struct WordSet *wordSet;
    struct Strbuf *buf, *name, *text;
    wordSet = func_0201EC64(wk->heapId);
    buf = func_020457B0(32, wk->heapId);
    name = func_020457B0(32, wk->heapId);
    func_02017E88(mon, 115, name);
    func_0201EE0C(wordSet, 0, name, 0, 1, 2);
    text = func_02045EC0(wk->msgData, 0);
    func_0201F250(wordSet, buf, text);
    func_0201C724(wk->printQue, func_02045770(work->nameWin), 25, 1, buf, wk->font, 1088);
    func_02045808(name); func_02045808(text); func_02045808(buf); func_0201ED04(wordSet);
    if (wk->isEgg == 0 && func_02017E88(mon, 173, 0) == 1) {
        u32 gender = func_02017E88(mon, 110, 0);
        if (gender == 0) {
            buf = func_02045EC0(wk->msgData, 1);
            func_0201C724(wk->printQue, func_02045770(work->nameWin), 89, 1, buf, wk->font, 5312);
            func_02045808(buf);
        } else if (gender == 1) {
            buf = func_02045EC0(wk->msgData, 2);
            func_0201C724(wk->printQue, func_02045770(work->nameWin), 89, 1, buf, wk->font, 3200);
            func_02045808(buf);
        }
    }
    if (wk->isEgg == 0) {
        struct Strbuf *levelText;
        wordSet = func_0201EC64(wk->heapId); buf = func_020457B0(16, wk->heapId);
        func_0201EFA4(wordSet, 0, POKE_TOOL_CalcBoxLevel(mon), 3, 0, 1);
        levelText = func_02045EC0(wk->msgData, 3);
        func_0201F250(wordSet, buf, levelText);
        func_0201C724(wk->printQue, func_02045770(work->nameWin), 9, 17, buf, wk->font, 1088);
        func_02045808(levelText); func_02045808(buf); func_0201ED04(wordSet);
    }
    buf = func_02045EC0(wk->msgData, 4);
    func_0201C724(wk->printQue, func_02045770(work->itemWin), 10, 1, buf, wk->font, 1088);
    func_02045808(buf);
    {
        struct Strbuf *itemText;
        wordSet = func_0201EC64(wk->heapId); buf = func_020457B0(16, wk->heapId);
        func_0201EF40(wordSet, 0, func_02017E88(mon, 6, 0));
        itemText = func_02045EC0(wk->msgData, 5);
        func_0201F250(wordSet, buf, itemText);
        func_0201C724(wk->printQue, func_02045770(work->itemWin), 6, 17, buf, wk->font, 1088);
        func_02045808(itemText); func_02045808(buf); func_0201ED04(wordSet);
    }
}

/*
 * follower: 021D703C complete reset helper is included; 021D7060 is filed
 *   separately. Reset contains constant stores only, preserving order.
 * semantic: unsigned full-word state dispatch guarded at six by the
 *   original; byte counters compared directly. No signed arithmetic.
 */
void P_STA_SUB_UpdatePet(PStatusWork *wk, PStaSubWork *work)
{
    switch (work->petState) {
    case STA_SUB_PET_IDLE:
        if (work->horizStroke.turnCount > 10) { work->petState = STA_SUB_PET_WIGGLE; P_STA_SUB_StartPetReaction(wk, work); }
        if (work->vertStroke.turnCount > 10) { work->petState = STA_SUB_PET_HOP; P_STA_SUB_StartPetReaction(wk, work); }
        if (work->circleStroke.turnCount > 20) { work->petState = STA_SUB_PET_RISE; P_STA_SUB_StartPetReaction(wk, work); }
        break;
    case STA_SUB_PET_WIGGLE:
        P_STA_SUB_PetWiggle(wk, work);
        if (P_STA_SUB_StepPetTimer(wk, work, &work->horizStroke.turnCount) == 0) work->petState = STA_SUB_PET_WIGGLE_END;
        break;
    case STA_SUB_PET_WIGGLE_END:
        if (P_STA_SUB_PetWiggle(wk, work) == 1) work->petState = STA_SUB_PET_IDLE;
        break;
    case STA_SUB_PET_HOP:
        P_STA_SUB_PetHop(wk, work);
        if (P_STA_SUB_StepPetTimer(wk, work, &work->vertStroke.turnCount) == 0) work->petState = STA_SUB_PET_HOP_END;
        break;
    case STA_SUB_PET_HOP_END:
        if (P_STA_SUB_PetHop(wk, work) == 1) work->petState = STA_SUB_PET_IDLE;
        break;
    case STA_SUB_PET_RISE:
        P_STA_SUB_PetRise(wk, work, 1);
        if (P_STA_SUB_StepPetTimer(wk, work, &work->circleStroke.turnCount) == 0) work->petState = STA_SUB_PET_RISE_END;
        break;
    case STA_SUB_PET_RISE_END:
        if (P_STA_SUB_PetRise(wk, work, 0) == 1) {
            MCSS_ResetAnmStopFlag(work->mcss[STA_SUB_MCSS_FRONT]);
            work->petState = STA_SUB_PET_IDLE;
        }
        break;
    }
}

void P_STA_SUB_StartPetReaction(PStatusWork *wk, PStaSubWork *work)
{
    work->didPet = 1;
    work->petPhase = 0;
    work->petHeightTarget = 0;
    work->petFrame = 0;
    work->petHeight = 0;
    work->petTimer = 0;
}

int P_STA_SUB_StepPetTimer(PStatusWork *wk, PStaSubWork *work, u8 *strokeTurns)
{
    if (*strokeTurns < 10) {
        ++work->petTimer;
        if (work->petTimer > 24) return 0;
    } else work->petTimer = 0;
    return 1;
}

/*
 * semantic: phase u16<<15 <=2147450880; dividing by 15 then truncating
 *   to u16 leaves a full index <=8190. Speed is explicitly a low byte;
 *   phase*speed <=16711425, division by 15 fits signed int. Signed sample
 *   times 16 fits int. All later shifts and vector additions/subtractions
 *   use u32 wrap, converted to the compiler's signed word for _fflt.
 *   _ffix is called explicitly: the original unsigned speed shift can
 *   convert to float outside int range; no C float-to-int cast is assumed.
 *   The template initializes every base word; zero initializes ofsPos.
 */
int P_STA_SUB_PetWiggle(PStatusWork *wk, PStaSubWork *work)
{
    VecFx32 pos = d_021DC1D4;
    VecFx32 ofsPos = {0, 0, 0};
    int radius = 0;
    int sample, step;
    u32 friendLevel;
    u8 speed;
    float f;
    if (work->isStaticSprite == 0) {
        sample = d_020A1B38[((u16)((work->petFrame << 15) / 15) >> 4) * 2];
        friendLevel = wk->friendship >> 6;
        if (friendLevel) f = 0.5f + (float)(friendLevel << 12);
        else f = (float)(friendLevel << 12) - 0.5f;
        radius = (u32)(sample * 16) + (u32)_ffix(f);
        ofsPos.y = radius;
        P_STA_SUB_SetPetOffset(wk, work, radius);
    } else {
        ofsPos.y = radius;
        P_STA_SUB_SetPetOffset(wk, work, radius);
    }
    speed = (u8)((wk->friendship >> 6) + 16);
    step = (work->petFrame * speed) / 15;
    switch (work->petPhase) {
    case 0:
        if (step > 0) f = 0.5f + (float)(int)((u32)step << 12);
        else f = (float)(int)((u32)step << 12) - 0.5f;
        pos.x += (u32)_ffix(f);
        break;
    case 1:
        step = speed - step;
        if (step > 0) f = 0.5f + (float)(int)((u32)step << 12);
        else f = (float)(int)((u32)step << 12) - 0.5f;
        pos.x += (u32)_ffix(f);
        break;
    case 2:
        if (step > 0) f = 0.5f + (float)(int)((u32)step << 12);
        else f = (float)(int)((u32)step << 12) - 0.5f;
        pos.x -= (u32)_ffix(f);
        break;
    case 3:
        step = speed - step;
        if (step > 0) f = 0.5f + (float)(int)((u32)step << 12);
        else f = (float)(int)((u32)step << 12) - 0.5f;
        pos.x -= (u32)_ffix(f);
        break;
    }
    MCSS_SetPosition(work->mcss[STA_SUB_MCSS_FRONT], &pos);
    MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
    ++work->petFrame;
    if (work->petFrame > 15) {
        work->petFrame = 0;
        ++work->petPhase;
        if (work->petPhase > 3) { work->petPhase = 0; return 1; }
    }
    return 0;
}

int P_STA_SUB_PetHop(PStatusWork *wk, PStaSubWork *work) {
    VecFx32 ofsPos = {0, 0, 0};
    int sample;
    unsigned friendLevel;
    float f;
    if (work->isStaticSprite == 0) {
        sample = d_020A1B38[((unsigned short)((work->petFrame << 15) / 20) >> 4) * 2];
        friendLevel = wk->friendship >> 6;
        if (friendLevel) f = 0.5f + (float)(friendLevel << 12); else f = (float)(friendLevel << 12) - 0.5f;
        ofsPos.y = (sample << 5) + (int)f;
        P_STA_SUB_SetPetOffset(wk, work, ofsPos.y);
    }
    MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
    ++work->petFrame;
    if (work->petFrame > 20) { work->petFrame = 0; return 1; }
    return 0;
}

int P_STA_SUB_PetRise(PStatusWork *wk, PStaSubWork *work, int isRising)
{
    VecFx32 ofsPos = {0, 0, 0};
    u32 lapAverage;
    u8 i;
    u16 delta;
    int height;
    float f;
    if (work->isStaticSprite == 1) return 1;
    if (isRising == 1) {
        lapAverage = 0;
        for (i = 0; i < 5; i++) lapAverage += work->lapFrames[i];
        lapAverage /= 5U;
        if (lapAverage < 10) lapAverage = 10;
        if (lapAverage > 20) lapAverage = 20;
        delta = 20 - lapAverage;
        work->petHeightTarget = 2048 + (6144 * delta) / 10;
        ofsPos.y += d_020A1B38[((u32)((work->petFrame * 546) >> 4)) * 2] * 4;
        ++work->petFrame;
        if (work->petFrame > 120) work->petFrame = 0;
    } else work->petHeightTarget = 0;
    if (work->petHeight < work->petHeightTarget) ++work->petHeight;
    if (work->petHeight > work->petHeightTarget) {
        if (isRising == 0) {
            if (work->petHeight >= 32) work->petHeight -= 32;
            else work->petHeight = 0;
        } else --work->petHeight;
    }
    height = work->petHeight;
    if (height) f = 0.5f + (float)(height * 4096);
    else f = (float)(height * 4096) - 0.5f;
    ofsPos.y += (int)f / 16;
    P_STA_SUB_SetPetOffset(wk, work, ofsPos.y);
    MCSS_SetOfsPosition(work->mcss[STA_SUB_MCSS_FRONT], &ofsPos);
    MCSS_SetAnmStopFlag(work->mcss[STA_SUB_MCSS_FRONT]);
    if (work->petHeight == 0 && work->petHeightTarget == 0) return 1;
    return 0;
}

/*
 * note 2026-10-02 (lane R4): the loop stores 0 (the copy of r4 before the loop is the
 *   zero already in r4), not the counter; the three post-loop stores are 0 too.
 */
void P_STA_SUB_UpdateTouch(PStatusWork *wk, PStaSubWork *work) {
    struct TouchHitTable hitTable = d_021DC1E0;
    u32 x, y;
    int isTouch, isHeld, hitArea;
    u8 i;
    TOUCHPANEL_GetPointCont(&x, &y);
    if (wk->isEgg != 0) return;
    isTouch = func_02035C60();
    isHeld = func_02035C38();
    hitArea = TOUCHPANEL_HitCont(&hitTable);
    if (work->flipState == STA_SUB_FLIP_IDLE) {
        if (hitArea == 0 || (hitArea == 1 && isTouch == 0)) {
            if (isTouch == 1) {
                work->isTouching = 1;
                work->didPet = 0;
                P_STA_SUB_ResetStroke(&work->horizStroke, x, y);
                P_STA_SUB_ResetStroke(&work->vertStroke, x, y);
                P_STA_SUB_ResetStroke(&work->circleStroke, x, y);
                for (i = 0; i < 5; i++) work->lapFrames[i] = 0;
                work->lapFrameCount = 0;
                work->lapIndex = 0;
                work->circleSense = 0;
            } else if (isHeld == 1 && work->isTouching == 1) {
                P_STA_SUB_TrackStrokes(wk, work);
            }
            work->lastTouchX = x;
            work->lastTouchY = y;
        } else {
            if (work->isTouching == 1 && work->didPet == 0 && work->petState == STA_SUB_PET_IDLE) {
                work->flipState = STA_SUB_FLIP_TO_BACK;
                work->flipFrame = 0;
            }
            P_STA_SUB_ResetStroke(&work->horizStroke, x, y);
            P_STA_SUB_ResetStroke(&work->vertStroke, x, y);
            P_STA_SUB_ResetStroke(&work->circleStroke, x, y);
            work->isTouching = 0;
        }
    } else if (work->flipState == STA_SUB_FLIP_BACK) {
        if (hitArea == 0 || (hitArea == 1 && isTouch == 0)) {
            if (isTouch == 1) work->isTouching = 1;
        } else if (work->isTouching == 1) {
            work->isTouching = 0;
            work->flipState = STA_SUB_FLIP_TO_FRONT;
            work->flipFrame = 0;
        }
    }
}

/*
 * note: three coordinate pairs (x,y from TOUCHPANEL_GetPointCont) are compared against
 *   the stroke start points (startX/startY of the three strokes) and dispatched to P_STA_SUB_AddStrokeTurn /
 *   P_STA_SUB_ResetStroke. dir=0 is written before ++vertStroke.age and lapDone=0
 *   after circleDy; this places the r3/r4 zero registers.
 * note 2026-10-02 (lane R5): the circle x delta is spelled
 *   `dx=circleStroke.startX; dx=(s8)(x-dx);`. The byte is loaded into dx's own register
 *   (r1, the register that later holds the s8 result), so the subtraction
 *   reads ldrb r1 / ldr r0,x / subs r0,r0,r1. A separate byte temporary or a
 *   direct (s8)(x-startX) put the byte in r0 (3 bytes off).
 */
void P_STA_SUB_TrackStrokes(PStatusWork *wk, PStaSubWork *work)
{
    u32 x, y;
    int dx, dy, circleDx, circleDy;
    StaSubStrokeDir dir;
    StaSubLapFlag lapDone;
    u32 sense;
    u32 *senseRef;
    TOUCHPANEL_GetPointCont(&x, &y);
    dx = (s8)(x - work->horizStroke.startX);
    dy = (s8)(y - work->horizStroke.startY);
    if ((work->horizStroke.dir == 0 || work->horizStroke.dir == 3) && dx > 16)
        P_STA_SUB_AddStrokeTurn(&work->horizStroke, x, y, 1);
    if (work->horizStroke.dir <= 1 && dx < -16)
        P_STA_SUB_AddStrokeTurn(&work->horizStroke, x, y, 3);
    if (dy > 16 || dy < -16 || work->horizStroke.age > 20)
        P_STA_SUB_ResetStroke(&work->horizStroke, x, y);
    ++work->horizStroke.age;
    dx = (s8)(x - work->vertStroke.startX);
    dy = (s8)(y - work->vertStroke.startY);
    if ((work->vertStroke.dir == 0 || work->vertStroke.dir == 4) && dy > 16)
        P_STA_SUB_AddStrokeTurn(&work->vertStroke, x, y, 2);
    if ((work->vertStroke.dir == 0 || work->vertStroke.dir == 2) && dy < -16)
        P_STA_SUB_AddStrokeTurn(&work->vertStroke, x, y, 4);
    if (dx > 16 || dx < -16 || work->vertStroke.age > 20)
        P_STA_SUB_ResetStroke(&work->vertStroke, x, y);
    dir = STA_SUB_DIR_NONE;
    ++work->vertStroke.age;
    circleDx = work->circleStroke.startX;
    circleDx = (s8)(x - circleDx);
    circleDy = (s8)(y - work->circleStroke.startY);
    lapDone = STA_SUB_LAP_NOT_DONE;
    if (circleDx > 16) dir = STA_SUB_DIR_RIGHT;
    else if (circleDx < -16) dir = STA_SUB_DIR_LEFT;
    else if (circleDy > 16) dir = STA_SUB_DIR_DOWN;
    else if (circleDy < -16) dir = STA_SUB_DIR_UP;
    if (dir != STA_SUB_DIR_NONE && (u32)dir != work->circleStroke.dir) {
        if (work->circleStroke.dir + 1 == (u32)dir ||
            (work->circleStroke.dir == STA_SUB_DIR_UP && dir == STA_SUB_DIR_RIGHT)) {
            sense = work->circleSense;
            if (sense <= 1) {
                work->circleSense = 1;
                P_STA_SUB_AddStrokeTurn(&work->circleStroke, x, y, dir);
                if (work->circleStroke.dir == STA_SUB_DIR_UP) lapDone = STA_SUB_LAP_DONE;
            } else {
                work->circleSense = 0;
                P_STA_SUB_ResetStroke(&work->circleStroke, x, y);
            }
        } else if (work->circleStroke.dir - 1 == (u32)dir ||
            (work->circleStroke.dir == STA_SUB_DIR_RIGHT && dir == STA_SUB_DIR_UP)) {
            senseRef = &work->circleSense;
            if (*senseRef == 2 || work->circleSense == 0) {
                work->circleSense = 2;
                P_STA_SUB_AddStrokeTurn(&work->circleStroke, x, y, dir);
                if (work->circleStroke.dir == STA_SUB_DIR_UP) lapDone = STA_SUB_LAP_DONE;
            } else {
                work->circleSense = 0;
                P_STA_SUB_ResetStroke(&work->circleStroke, x, y);
            }
        } else if (work->circleStroke.dir == STA_SUB_DIR_NONE) {
            work->circleStroke.dir = dir;
        }
    }
    if (work->circleStroke.age > 20) {
        work->circleSense = 0;
        P_STA_SUB_ResetStroke(&work->circleStroke, x, y);
    }
    P_STA_SUB_UpdateLapFrames(wk, work, lapDone);
    ++work->circleStroke.age;
}

void P_STA_SUB_ResetStroke(StaSubStroke *stroke, u32 x, u32 y)
{
    stroke->turnCount = 0;
    stroke->dir = 0;
    stroke->age = 0;
    stroke->startX = x;
    stroke->startY = y;
}

void P_STA_SUB_AddStrokeTurn(StaSubStroke *stroke, u32 x, u32 y, int dir)
{
    stroke->turnCount = stroke->turnCount + 1;
    stroke->dir = dir;
    stroke->age = 0;
    stroke->startX = x;
    stroke->startY = y;
}

void P_STA_SUB_UpdateLapFrames(PStatusWork *wk, PStaSubWork *work, int lapDone)
{
    if (lapDone == 1)
    {
        u8 frames = work->lapFrameCount;
        work->lapFrames[work->lapIndex] = frames;
        work->lapFrameCount = 0;
        work->lapIndex = (u8)(work->lapIndex + 1);
        if (work->lapIndex >= 5)
            work->lapIndex = 0;
    }
    work->lapFrameCount = (u8)(work->lapFrameCount + 1);
}

/*
 * note: 2026-10-02 relaunch R9. The +0xAA/+0xAC str/movs swap was a
 *   scheduler effect of the pre-allocation instruction count before group 2
 *   (a no-arg call inserted earlier shifts it; a band of 5 positions swaps).
 *   MCSS_TOOL_SetAnimeStopCallback is declared void(void *): its body only forwards to
 *   func_02015F2C, and an int return adds one result copy per call, which
 *   put the second store inside the band. ov195 declares it the same way.
 */
void P_STA_SUB_CreateMcss(PStatusWork *wk, PStaSubWork *work, void *mon)
{
    VecFx32 extraOfs = d_021DC1F8;
    VecFx32 frontScale = d_021DC240;
    VecFx32 backScale = d_021DC180;
    VecFx32 baseOfs = d_021DC1C8;
    void *pp = (void *)P_STATUS_GetPokeParaSource(wk);
    P_STA_SUB_GetSpeciesAdjust(wk, work, &extraOfs, &frontScale);
    work->mcss[STA_SUB_MCSS_FRONT] = MCSS_TOOL_AddPokeMcss(wk->mcssSys, pp, 0, 0xd8000, 0x48000, 0);
    MCSS_SetShadowAlpha(work->mcss[STA_SUB_MCSS_FRONT], 2);
    MCSS_SetShadowRotateX(work->mcss[STA_SUB_MCSS_FRONT], 0xd555);
    MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_FRONT], &frontScale);
    MCSS_TOOL_SetAnimeStopCallback(work->mcss[STA_SUB_MCSS_FRONT]);
    MCSS_SetShadowScale(work->mcss[STA_SUB_MCSS_FRONT], &extraOfs);
    work->mcss[STA_SUB_MCSS_BACK] = MCSS_TOOL_AddPokeMcss(wk->mcssSys, pp, 1, 0xd8000, 0x48000, 0);
    MCSS_SetShadowAlpha(work->mcss[STA_SUB_MCSS_BACK], 2);
    MCSS_SetShadowRotateX(work->mcss[STA_SUB_MCSS_BACK], 0xd555);
    MCSS_SetOfsScale(work->mcss[STA_SUB_MCSS_BACK], &backScale);
    MCSS_TOOL_SetAnimeStopCallback(work->mcss[STA_SUB_MCSS_BACK]);
    MCSS_SetShadowScale(work->mcss[STA_SUB_MCSS_BACK], &extraOfs);
    P_STA_SUB_SetPetOffset(wk, work, 0);
    P_STA_SUB_ApplyMcssOffset(wk, work, &baseOfs);
    if (work->showFront == 1) {
        MCSS_ResetVanishFlag(work->mcss[STA_SUB_MCSS_FRONT]);
        MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_BACK]);
        return;
    }
    MCSS_ResetVanishFlag(work->mcss[STA_SUB_MCSS_BACK]);
    MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_FRONT]);
}

void P_STA_SUB_DeleteMcss(PStatusWork *wk, PStaSubWork *work) {
    MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_FRONT]);
    MCSS_SetVanishFlag(work->mcss[STA_SUB_MCSS_BACK]);
    MCSS_Del(wk->mcssSys, work->mcss[STA_SUB_MCSS_FRONT]);
    MCSS_Del(wk->mcssSys, work->mcss[STA_SUB_MCSS_BACK]);
    work->mcss[STA_SUB_MCSS_FRONT] = 0;
    work->mcss[STA_SUB_MCSS_BACK] = 0;
}

static inline int fxMul(int a, int b) { return (int)(((long long)a * b + 0x800LL) >> 12); }

void P_STA_SUB_SetPetOffset(PStatusWork *wk, PStaSubWork *work, int radius) {
    VecFx32 baseOfs = d_021DC1EC;
    work->petOffset.x = fxMul(d_020A5078[10], radius);
    work->petOffset.y = fxMul(d_020A5078[11], radius);
    work->petOffset.z = 0;
    P_STA_SUB_ApplyMcssOffset(wk, work, &baseOfs);
}

void P_STA_SUB_ApplyMcssOffset(PStatusWork *wk, PStaSubWork *work, VecFx32 *baseOfs) {
    VecFx32 sum;
    func_0207C9D0(baseOfs, &work->petOffset, &sum);
    MCSS_SetShadowOffset(work->mcss[STA_SUB_MCSS_FRONT], &sum);
    MCSS_SetShadowOffset(work->mcss[STA_SUB_MCSS_BACK], &sum);
}

void P_STA_SUB_GetSpeciesAdjust(PStatusWork *wk, PStaSubWork *work, VecFx32 *extraOfs, VecFx32 *frontScale) {
    int species = func_02017E88(P_STATUS_GetPokePara(wk), 5, 0);
    if (species == 5) { frontScale->y = 0x299a; extraOfs->y = 0xf4cd; return; }
    if (species == 37) { extraOfs->y = 0xfb33; return; }
    if (species == 86) { extraOfs->x = 0x10666; extraOfs->y = 0x10666; return; }
    if (species == 155) { extraOfs->x = 0xfe66; extraOfs->y = 0xfb33; return; }
    if (species == 179) { extraOfs->x = 0x10333; extraOfs->y = 0x10333; return; }
    if (species == 225) { extraOfs->x = 0xfccd; extraOfs->y = 0xfccd; return; }
    if (species == 248) { extraOfs->x = 0xfccd; extraOfs->y = 0xfccd; return; }
    if (species == 310) { extraOfs->x = 0xf800; extraOfs->y = 0xf800; return; }
    if (species == 311) { extraOfs->x = 0xfb33; extraOfs->y = 0xfb33; return; }
    if (species == 391) { extraOfs->x = 0xfb33; extraOfs->y = 0xf99a; }
}
