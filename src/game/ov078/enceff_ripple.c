/*
 * file:     enceff_ripple.c
 * unit:     yes
 * function: ENCEFF_BuildRippleKind02, ENCEFF_BuildRippleKind36, ENCEFF_StartRipple, ENCEFF_RippleEventMain, ENCEFF_UpdateRipple, ENCEFF_DrawRipple, ENCEFF_StepRipple, ENCEFF_StartRippleBurst
 * address:  0x021F5620
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Twin of ov078 ENCEFF_StartRipple with different constants: faster, higher drops
 * and a longer wait after the last one.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   gRippleCameraPos 0x021F5BC8 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlay4B 0x021CF59C thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   gRippleBurstCameraPos 0x021F5BBC data a4
 *   ENCEFF_StartScreenTexEffect 0x021F529C thumb ov075
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   ENCEFF_GetEffect 0x021CF51C thumb ov021
 *   G3X_SetClearColor 0x0207DD24 arm
 *   ENCEFF_DrawScreenTexEffect 0x021F52D8 thumb ov075
 *   gRippleTranslate     0x021F5BB0  data  a4
 *   gRippleScale     0x021F5BD4  data  a4
 */
#include "../arm9/gamesystem.h"
#include "../ov021/fieldmap.h"
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_g3_inline.h"
#include "enceff_ripple_types.h"

struct GameSystem;
struct GameEvent;
struct EncEffWork;
struct FieldMap;
struct Desc;
extern void ENCEFF_LoadOverlay4B(struct EncEffWork *eff);
#include "../ov075/enceff_screen_tex.h"
extern void *ENCEFF_AllocWork(struct EncEffWork *eff, u32 size, u32 heapId);
#include "../arm9/game_event.h"
extern void *ENCEFF_GetWork(struct EncEffWork *eff);
#include "../arm9/fade.h"
extern struct GameEvent *ENCEFF_GetEffect(struct EncEffWork *eff);
#include "../arm9/g3x.h"
struct EncEffScreenTexWork;
void *ENCEFF_BuildRippleKind02(void *gameSystem, struct FieldMap *fieldMap);
void *ENCEFF_BuildRippleKind36(void *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartRipple(struct GameSystem *gameSystem);
int ENCEFF_RippleEventMain(struct GameEvent *event, int *state, void *work);
void ENCEFF_UpdateRipple(struct EncEffWork *eff);
void ENCEFF_DrawRipple(void *rippleArg);
int ENCEFF_StepRipple(EncEffRipple *ripple);
struct GameEvent *ENCEFF_StartRippleBurst(struct GameSystem *gameSystem);
extern const VecFx32 gRippleCameraPos;
extern const VecFx32 gRippleBurstCameraPos;
extern const VecFx32 gRippleTranslate;
extern const VecFx32 gRippleScale;




void *ENCEFF_BuildRippleKind02(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = gRippleCameraPos;
    ENCEFF_LoadOverlay4B((struct EncEffWork *)FIELDMAP_GetEncEff(fieldMap));
    return ENCEFF_StartScreenTexEffectFlash((struct GameSystem *)gameSystem, (VecFx32 *)&cameraPos, ENCEFF_StartRipple, ENCEFF_DrawRipple);
}




/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ENCEFF_LoadOverlays4B4D extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target ENCEFF_LoadOverlay): veneer-like, not C. Needs a label in layout.
 */
void *ENCEFF_BuildRippleKind36(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = gRippleBurstCameraPos;
    ENCEFF_LoadOverlay4B((struct EncEffWork *)FIELDMAP_GetEncEff(fieldMap));
    return ENCEFF_StartScreenTexEffect((struct GameSystem *)gameSystem, (VecFx32 *)&cameraPos, ENCEFF_StartRippleBurst, ENCEFF_DrawRipple);
}





/*
 * Addresses are Black-image addresses.
 */
struct GameEvent *ENCEFF_StartRipple(struct GameSystem *gameSystem)
{
    EncEffRipple *ripple;
    void *event;
    int i;

    ripple = ENCEFF_AllocWork((struct EncEffWork *)FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffRipple), 0x50);
    event = GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, ENCEFF_RippleEventMain, 0);
    ripple->count = 7;
    ripple->wait = 0;
    ripple->period = 8;
    ripple->height = 0x400;
    ripple->next = 0;
    ripple->startDelay = 0x32;
    ripple->fadeStarted = 0;
    for (i = 0; i < RIPPLE_VERTEX_COUNT; i++) {
        EncEffRippleVertex *vertex = &ripple->vertex[i];

        vertex->x = ((i % RIPPLE_COLS) << 12) / 16;
        vertex->y = ((i / RIPPLE_COLS) << 12) / 16;
        vertex->z = 0;
    }
    ripple->fadeScreens = 0xc;
    return event;
}





int ENCEFF_RippleEventMain(struct GameEvent *event, int *state, void *work)
{
    EncEffRipple *ripple;

    ripple = ENCEFF_GetWork((struct EncEffWork *)FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event))));
    switch (*state) {
    case 0:
        if (ripple->startDelay != 0) {
            (ripple->startDelay)--;
        } else if (ripple->fadeStarted == 0) {
            FADE_Start(ripple->fadeScreens, 0, 0x10, 0);
            ripple->fadeStarted = 1;
        }
        if (ENCEFF_StepRipple(ripple) != 0) {
            ripple->wait = 6;
            (*state)++;
        }
        break;
    case 1:
        if (ripple->wait != 0) {
            (ripple->wait)--;
        } else if (FADE_IsActive() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}




/*
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF51C (no label witness). Filed src/matched/ov/ENCEFF_GetEffect.c (EXACT, 4-byte accessor); it needs a manifest shard to count as a witness.
 */
void ENCEFF_UpdateRipple(struct EncEffWork *eff) {
    struct GameEvent *effect = ENCEFF_GetEffect(eff);
    G3X_SetClearColor(0x4210,31,0x7FFF,0,0);
    ENCEFF_DrawScreenTexEffect((struct EncEffScreenTexWork *)effect);
}




/*
 * volatile: G3 geometry FIFO registers 0x04000444-0x04000504, written by the SDK inlines (stores only)
 *
 * Draws the 33 x 25 vertex grid ENCEFF_StartRipple / ENCEFF_StartRippleBurst build as
 * quad strips.
 * Levers: the six vertex fields are loaded into locals before the stores
 * (inline loads give an 0x30 frame); j declared before the row pointer
 * (slot order); the element pointer is spelled `vertex + j * 33 + i` with no
 * row local, so the scaled row base is hoisted and `i = 0` lands last in
 * the preheader (a row local or `&w[j * 33 + i]` schedules it early or
 * hoists j * 33 unscaled).
 *
 * Addresses are Black-image addresses.
 */
void ENCEFF_DrawRipple(void *rippleArg)
{
    EncEffRipple *ripple = rippleArg;
    VecFx32 translate;
    VecFx32 scale;
    int j;
    int i;
    EncEffRippleVertex *v;
    fx32 t;
    fx16 x0, x1, y0, y1, z0, z1;

    j = 0;
    REG_MTX_PUSH = j;
    REG_DIF_AMB = 0x7FFF7FFF;
    REG_SPE_EMI = 0x4210;
    REG_LIGHT_COLOR = 0x7FFF;
    REG_POLYGON_ATTR = 0x001F00C1;
    translate = gRippleTranslate;
    scale = gRippleScale;
    G3_Translate(translate.x, translate.y, translate.z);
    G3_Scale(scale.x, scale.y, scale.z);
    for (; j < RIPPLE_ROWS - 1; j++) {
        REG_BEGIN_VTXS = 3;
        t = j << 15;
        for (i = 0; i < RIPPLE_COLS; i++) {
            v = ripple->vertex + j * RIPPLE_COLS + i;
            x0 = v[0].x;
            x1 = v[RIPPLE_COLS].x;
            y0 = v[0].y;
            y1 = v[RIPPLE_COLS].y;
            z0 = v[0].z;
            z1 = v[RIPPLE_COLS].z;
            REG_NORMAL = 0x20000000;
            G3_TexCoord(i << 15, t);
            G3_Vtx(x0, -y0, z0);
            G3_TexCoord(i << 15, t + 0x8000);
            G3_Vtx(x1, -y1, z1);
        }
        REG_END_VTXS = 0;
    }
    REG_MTX_POP = 1;
}




/*
 * One step of the ripple over the 33 x 25 grid ENCEFF_StartRipple /
 * ENCEFF_StartRippleBurst allocate (0x19E0 bytes); the vertex list is drawn by
 * ENCEFF_DrawRipple. Returns 1 when the effect is over.
 * Levers: period/next are u16 (ldrh); each neighbour coordinate is a
 * temporary (x = col - 1, ...) so the +-1 is not folded into the load
 * offset; the element pointer p is a named local declared before col/row
 * (without it row takes r0 and the quotient is never moved to r1).
 *
 * Addresses are Black-image addresses.
 */
int ENCEFF_StepRipple(EncEffRipple *ripple)
{
    s16 height[RIPPLE_VERTEX_COUNT];
    int i;
    EncEffRippleVertex *vertex;
    int col;
    int row;
    int left;
    int right;
    int above;
    int below;
    int x;
    int y;
    s16 diff;

    for (i = 0; i < RIPPLE_VERTEX_COUNT; i++)
        height[i] = ripple->vertex[i].z;
    if (ripple->count > 0) {
        if (ripple->wait == 0) {
            ripple->vertex[RIPPLE_CENTER].z = ripple->height;
            ripple->wait = ripple->period;
            ripple->count--;
        } else {
            ripple->wait--;
        }
        if (ripple->count <= 0) {
            if (ripple->next == 0) {
                ripple->wait = 6;
                return 1;
            }
            ripple->wait = ripple->next;
        }
    } else {
        ripple->wait--;
        if (ripple->wait <= 0) {
            ripple->wait = 6;
            return 1;
        }
    }
    for (i = 0; i < RIPPLE_VERTEX_COUNT; i++) {
        col = i % RIPPLE_COLS;
        row = i / RIPPLE_COLS;
        x = col - 1;
        left = (x >= 0) ? height[x + row * RIPPLE_COLS] : 0;
        x = col + 1;
        right = (x < RIPPLE_COLS) ? height[x + row * RIPPLE_COLS] : 0;
        y = row - 1;
        above = (y >= 0) ? height[col + y * RIPPLE_COLS] : 0;
        y = row + 1;
        below = (y < RIPPLE_ROWS) ? height[col + y * RIPPLE_COLS] : 0;
        vertex = &ripple->vertex[i];
        diff = (left + right + above + below) / 4 - vertex->z;
        ripple->velocityZ[i] += diff;
        vertex->z += ripple->velocityZ[i];
        if (vertex->z > 0x1000)
            vertex->z = 0x1000;
        if (vertex->z < -0x1000)
            vertex->z = -0x1000;
        if (col == 0 || col == RIPPLE_COLS - 1 || row == 0 || row == RIPPLE_ROWS - 1)
            vertex->z = 0;
    }
    return 0;
}


struct GameEvent *ENCEFF_StartRippleBurst(struct GameSystem *gameSystem)
{
    EncEffRipple *ripple;
    void *event;
    int i;

    ripple = ENCEFF_AllocWork((struct EncEffWork *)FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffRipple), 0x50);
    event = GAME_EVENT_Create((struct GameSystem *)gameSystem, 0, ENCEFF_RippleEventMain, 0);
    ripple->count = 7;
    ripple->wait = 0;
    ripple->period = 2;
    ripple->height = 0x555;
    ripple->next = 0x2d;
    ripple->startDelay = 0x37;
    ripple->fadeStarted = 0;
    for (i = 0; i < RIPPLE_VERTEX_COUNT; i++) {
        EncEffRippleVertex *vertex = &ripple->vertex[i];

        vertex->x = ((i % RIPPLE_COLS) << 12) / 16;
        vertex->y = ((i / RIPPLE_COLS) << 12) / 16;
        vertex->z = 0;
    }
    ripple->fadeScreens = 3;
    return event;
}
