/*
 * file:     enceff_cell_grid.c
 * unit:     yes
 * function: ENCEFF_StartCellGrid, ENCEFF_CellGridEventMain, ENCEFF_StepCellGrid, ENCEFF_UpdateCellGrid, ENCEFF_DrawCellGrid
 * address:  0x021F5620
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Draw callback of the grid effect: draws the w*h grid of textured quads
 * through the geometry engine ports. Each cell is moved to its position,
 * scaled to its size, turned by its Y and Z angles (index = angle >> 4 into
 * the sin/cos table) and drawn with the quad's texture coordinates.
 * The only wildcard is the scale vector template (0x021F5A58 = 0x1000 x3,
 * compiler data right after the pool, read only by this function), written
 * as the initialiser of `sc` (mwcc copies its template).
 * Levers that matched it (register allocation is the whole difficulty):
 * the far texture corner as locals right after px/py; named col/row locals
 * with the column first in the products; the aggregates sit in an inner
 * block after the five setup stores so the file also matches with --lang c;
 * Translate and Scale as inline helpers (arguments first, as the original
 * loads z, y, x before the three stores); the cell pointer as the first
 * statement of the loop; px, py declared at function scope before n, a, b.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   ENCEFF_GetEffect 0x021CF51C thumb ov021
 *   G3X_SetClearColor 0x0207DD24 arm
 *   ENCEFF_DrawScreenTexEffect 0x021F52D8 thumb ov075
 *   MTX_RotY33_ 0x0207AF1C thumb
 *   MTX_RotZ33_ 0x0207AF38 thumb
 *   G3_MultMtx33 0x0207D934 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   d_021F5A58 0x021F5A58 data a4
 */
#include "enceff_base_types.h"
#include "enceff_grid_types.h"
#include "enceff_g3_inline.h"

struct Desc;
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void FADE_Start(u32 planes, s32 startLevel, s32 endLevel, s32 wait);
extern int FADE_IsActive(void);
extern struct GameEvent *ENCEFF_GetEffect(struct EncEffWork *eff);
extern void G3X_SetClearColor(u16 color, int alpha, int depth, int polygonId, int clearImage);
extern void ENCEFF_DrawScreenTexEffect(struct GameEvent *effect);
extern void MTX_RotY33_(Mtx33 *mtx, int sinValue, int cosValue);
extern void MTX_RotZ33_(Mtx33 *mtx, int sinValue, int cosValue);
extern void G3_MultMtx33(const Mtx33 *mtx);
void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
int ENCEFF_CellGridEventMain(struct GameEvent *event, int *state);
int ENCEFF_StepCellGrid(EncEffGridWork *work);
void ENCEFF_UpdateCellGrid(struct EncEffWork *eff);
void ENCEFF_DrawCellGrid(EncEffGridWork *work);
extern s16 FX_SinCosTable_[];



void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen)
{
    EncEffGridWork *work;
    void *event;
    int i;
    int cellWidth;
    int cellHeight;
    int cols;
    int rows;
    int pixelWidth;
    int pixelHeight;
    int originX;
    int originY;
    int cellCount;
    int col;
    int row;

    work = ENCEFF_AllocWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffGridWork), 0x50);
    event = GAME_EVENT_Create(gameSystem, 0, ENCEFF_CellGridEventMain, 0);
    cellWidth = param->cellWidth;
    cellHeight = param->cellHeight;
    pixelWidth = cellWidth * 8;
    pixelHeight = cellHeight * 8;
    cols = 0x20 / cellWidth;
    rows = 0x18 / cellHeight;
    work->cols = cols;
    work->rows = rows;
    originX = (cols / 2) * pixelWidth - pixelWidth / 2;
    originY = (rows / 2) * pixelHeight - pixelHeight / 2;
    cellCount = cols * rows;
    for (i = 0; i < cellCount; i++) {
        col = i % cols;
        work->cell[i].pos.x = (col * pixelWidth - originX) << 12;
        row = i / cols;
        work->cell[i].pos.y = (originY - row * pixelHeight) << 12;
        work->cell[i].pos.z = 0;
        work->cell[i].angleX = 0;
        work->cell[i].angleY = 0;
        work->cell[i].angleZ = 0;
        work->cell[i].active = 0;
        work->cell[i].finished = 0;
        work->cell[i].cellCallback = param->cellCallback;
    }
    work->stepCallback = param->stepCallback;
    if (param->initCallback != 0) {
        param->initCallback(work);
    }
    if (useSubScreen != 0) {
        work->fadeScreens = 0xC;
        work->clearColor = 0x7FFF;
    } else {
        work->fadeScreens = 3;
        work->clearColor = 0;
    }
    return event;
}



/*
 * Addresses are Black-image addresses.
 */
int ENCEFF_CellGridEventMain(struct GameEvent *event, int *state)
{
    EncEffGridWork *work;

    work = ENCEFF_GetWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event))));
    switch (*state) {
    case 0:
        if (ENCEFF_StepCellGrid(work) == 0)
            break;
        FADE_Start(work->fadeScreens, 0, 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}



int ENCEFF_StepCellGrid(EncEffGridWork *work)
{
    int i;
    int cellCount;
    int doneCount;

    work->stepCallback(work);
    cellCount = work->cols * work->rows;
    doneCount = 0;
    for (i = 0; i < cellCount; i++) {
        EncEffGridCell *cell = &work->cell[i];
        int done = 0;

        if (cell->finished == 0) {
            if (cell->active != 0) {
                int (*callback)(EncEffGridCell *) = cell->cellCallback;

                if (callback == 0)
                    cell->finished = 1;
                else
                    done = callback(cell);
            }
        } else {
            done = 1;
        }
        if (done)
            doneCount++;
    }
    return doneCount >= cellCount;
}


/*
 * 2026-10-05: EXACT now that ov021 ENCEFF_GetEffect is filed; no source change.
 */
void ENCEFF_UpdateCellGrid(struct EncEffWork *eff) {
    struct GameEvent *effect = ENCEFF_GetEffect(eff);
    EncEffGridWork *work = ENCEFF_GetWork(eff);
    G3X_SetClearColor(work->clearColor,31,0x7FFF,0,0);
    ENCEFF_DrawScreenTexEffect(effect);
}


void ENCEFF_DrawCellGrid(EncEffGridWork *work)
{
    REG_MTX_PUSH = 0;
    REG_DIF_AMB = 0x7FFF7FFF;
    REG_SPE_EMI = 0x4210;
    REG_LIGHT_COLOR = 0x7FFF;
    REG_POLYGON_ATTR = 0x001F0081;
    {
        VecFx32 pos = {0, 0, 0};
        VecFx32 scale = {0x1000, 0x1000, 0x1000};
        Mtx33 mtx;
        int px, py, farX, farY;
        int cols, rows, cellCount, pixelWidth, pixelHeight, i, angleIndex, col, row;
        rows = work->rows;
        cols = work->cols;
        cellCount = cols * rows;
        pixelWidth = (0x20 / cols) << 3;
        pixelHeight = (0x18 / rows) << 3;
        scale.x = (pixelWidth / 8) << 12;
        scale.y = (pixelHeight / 8) << 12;
        for (i = 0; i < cellCount; i++) {
            EncEffGridCell *cell = &work->cell[i];
            REG_MTX_PUSH = 0;
            cols = work->cols;
            pos = cell->pos;
            col = i % cols;
            px = (col * pixelWidth) << 12;
            row = i / cols;
            py = (row * pixelHeight) << 12;
            farX = px + (pixelWidth << 12);
            farY = py + (pixelHeight << 12);
            G3_Translate(pos.x, pos.y, pos.z);
            G3_Scale(scale.x, scale.y, scale.z);
            angleIndex = cell->angleY >> 4;
            MTX_RotY33_(&mtx, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
            G3_MultMtx33(&mtx);
            angleIndex = cell->angleZ >> 4;
            MTX_RotZ33_(&mtx, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
            G3_MultMtx33(&mtx);
            REG_BEGIN_VTXS = 1;
            REG_NORMAL = 0x20000000;
            G3_TexCoord(px, py);
            REG_VTX_16 = 0x4000C000; REG_VTX_16 = 0;
            G3_TexCoord(px, farY);
            REG_VTX_16 = 0xC000C000; REG_VTX_16 = 0;
            G3_TexCoord(farX, farY);
            REG_VTX_16 = 0xC0004000; REG_VTX_16 = 0;
            G3_TexCoord(farX, py);
            REG_VTX_16 = 0x40004000; REG_VTX_16 = 0;
            REG_END_VTXS = 0;
            REG_MTX_POP = 1;
        }
        REG_MTX_POP = 1;
    }
}
