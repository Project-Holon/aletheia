/*
 * file:     unit_021F5620.c
 * unit:     yes
 * function: func_021F5620, func_021F565C, func_021F5698, func_021F5748, func_021F57D4, func_021F5800, func_021F5950
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
 * symbols:
 *   d_021F5BC8 0x021F5BC8 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF59C 0x021CF59C thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   d_021F5BBC 0x021F5BBC data a4
 *   func_021F529C 0x021F529C thumb ov075
 *   func_021F5AFC 0x021F5AFC thumb ov078
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 *   d_021F5BB0     0x021F5BB0  data  a4
 *   d_021F5BD4     0x021F5BD4  data  a4
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_g3_inline.h"
#include "enceff_ripple_types.h"

struct GameSystem;
struct GameEvent;
struct EncEffWork;
struct FieldMap;
struct Desc;

extern struct EncEffWork *func_02189A08(struct FieldMap *fieldMap);
extern void func_021CF59C(struct EncEffWork *eff);
extern void *func_021F5260(void *gameSystem, const VecFx32 *cameraPos, void *build, void *draw);
extern void *func_021F529C(void *gameSystem, const VecFx32 *cameraPos, void *build, void *draw);
extern void *func_021F5AFC(void *gameSystem);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern void *func_021CF52C(struct EncEffWork *eff, u32 size, u32 heapId);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern EncEffRipple *func_021CF560(struct EncEffWork *eff);
extern void func_0204E720(u32 planes, s32 startLevel, s32 endLevel, s32 wait);
extern int func_0204E804(void);
extern struct GameEvent *func_021CF51C(struct EncEffWork *eff);
extern void func_0207DD24(u16 color, int alpha, int depth, int polygonId, int clearImage);
extern void func_021F52D8(struct GameEvent *effect);
void *func_021F5620(void *gameSystem, struct FieldMap *fieldMap);
void *func_021F565C(void *gameSystem, struct FieldMap *fieldMap);
void *func_021F5698(void *gameSystem);
int func_021F5748(struct GameEvent *event, int *state);
void func_021F57D4(struct EncEffWork *eff);
void func_021F5800(EncEffRipple *ripple);
int func_021F5950(EncEffRipple *ripple);
extern const VecFx32 d_021F5BC8;
extern const VecFx32 d_021F5BBC;
extern const VecFx32 d_021F5BB0;
extern const VecFx32 d_021F5BD4;



void *func_021F5620(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = d_021F5BC8;
    func_021CF59C(func_02189A08(fieldMap));
    return func_021F5260(gameSystem, &cameraPos, func_021F5698, func_021F5800);
}



/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ov021_func_021CF580 extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target func_021CF564): veneer-like, not C. Needs a label in layout.
 */
void *func_021F565C(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = d_021F5BBC;
    func_021CF59C(func_02189A08(fieldMap));
    return func_021F529C(gameSystem, &cameraPos, func_021F5AFC, func_021F5800);
}




/*
 * Addresses are Black-image addresses.
 */
void *func_021F5698(void *gameSystem)
{
    EncEffRipple *ripple;
    void *event;
    int i;

    ripple = func_021CF52C(func_02189A08(func_0201210C(gameSystem)), sizeof(EncEffRipple), 0x50);
    event = func_020122C0(gameSystem, 0, func_021F5748, 0);
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




int func_021F5748(struct GameEvent *event, int *state)
{
    EncEffRipple *ripple;

    ripple = func_021CF560(func_02189A08(func_0201210C(func_020124E4(event))));
    switch (*state) {
    case 0:
        if (ripple->startDelay != 0) {
            (ripple->startDelay)--;
        } else if (ripple->fadeStarted == 0) {
            func_0204E720(ripple->fadeScreens, 0, 0x10, 0);
            ripple->fadeStarted = 1;
        }
        if (func_021F5950(ripple) != 0) {
            ripple->wait = 6;
            (*state)++;
        }
        break;
    case 1:
        if (ripple->wait != 0) {
            (ripple->wait)--;
        } else if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF51C (no label witness). Filed src/matched/ov/ov021_func_021CF51C.c (EXACT, 4-byte accessor); it needs a manifest shard to count as a witness.
 */
void func_021F57D4(struct EncEffWork *eff) {
    struct GameEvent *effect = func_021CF51C(eff);
    func_0207DD24(0x4210,31,0x7FFF,0,0);
    func_021F52D8(effect);
}



/*
 * volatile: G3 geometry FIFO registers 0x04000444-0x04000504, written by the SDK inlines (stores only)
 *
 * Draws the 33 x 25 vertex grid func_021F5698 / func_021F5AFC build as
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
void func_021F5800(EncEffRipple *ripple)
{
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
    translate = d_021F5BB0;
    scale = d_021F5BD4;
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
 * One step of the ripple over the 33 x 25 grid func_021F5698 /
 * func_021F5AFC allocate (0x19E0 bytes); the vertex list is drawn by
 * func_021F5800. Returns 1 when the effect is over.
 * Levers: period/next are u16 (ldrh); each neighbour coordinate is a
 * temporary (x = col - 1, ...) so the +-1 is not folded into the load
 * offset; the element pointer p is a named local declared before col/row
 * (without it row takes r0 and the quotient is never moved to r1).
 *
 * Addresses are Black-image addresses.
 */
int func_021F5950(EncEffRipple *ripple)
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
