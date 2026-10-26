/*
 * file:     enceff_grid_spread.c
 * unit:     yes
 * function: ENCEFF_BuildGridSpread, ENCEFF_StartGridSpread, ENCEFF_InitGridSpread, ENCEFF_StepGridSpread, ENCEFF_UpdateGridSpreadCell, ENCEFF_IsGridSpreadQueued, ENCEFF_QueueGridSpreadCell, ENCEFF_QueueGridSpreadNeighbors, ENCEFF_StartGridSpreadWave
 * address:  0x021F5A80
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   gEncEffGridSpreadCameraPos 0x021F5D00 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"
#include "enceff_grid_spread_types.h"

extern void ENCEFF_LoadOverlays4B4D(struct EncEffWork *eff);
extern struct GameEvent *ENCEFF_StartScreenTexEffectFlash(struct GameSystem *gameSystem, VecFx32 *cameraPos,
                                       struct GameEvent *(*start)(struct GameSystem *gameSystem),
                                       void (*draw)(void *workArg));
extern void ENCEFF_DrawCellGrid(void *workArg);
extern void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
struct GameEvent *ENCEFF_BuildGridSpread(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartGridSpread(struct GameSystem *gameSystem);
void ENCEFF_InitGridSpread(EncEffGridWork *work);
void ENCEFF_StepGridSpread(EncEffGridWork *work);
int ENCEFF_UpdateGridSpreadCell(EncEffGridCell *cell);
int ENCEFF_IsGridSpreadQueued(int cellIndex, EncEffSpreadState *spread);
void ENCEFF_QueueGridSpreadCell(EncEffGridWork *work, int x, int y);
void ENCEFF_QueueGridSpreadNeighbors(EncEffGridWork *work, int cellIndex);
void ENCEFF_StartGridSpreadWave(EncEffGridWork *work);
extern const VecFx32 gEncEffGridSpreadCameraPos;


/*
 * Encounter effect of overlay 0x51: the screen picture is cut into 2x2 tile
 * cells that start in waves spreading from three seed cells. Builder of the
 * effect table: loads the helper overlays, then starts the screen texture effect.
 */
struct GameEvent *ENCEFF_BuildGridSpread(struct GameSystem *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = gEncEffGridSpreadCameraPos;
    ENCEFF_LoadOverlays4B4D(FIELDMAP_GetEncEff(fieldMap));
    return ENCEFF_StartScreenTexEffectFlash(gameSystem, &cameraPos, ENCEFF_StartGridSpread, ENCEFF_DrawCellGrid);
}



struct GameEvent *ENCEFF_StartGridSpread(struct GameSystem *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.initCallback = ENCEFF_InitGridSpread;
    param.stepCallback = ENCEFF_StepGridSpread;
    param.cellCallback = ENCEFF_UpdateGridSpreadCell;
    return ENCEFF_StartCellGrid(gameSystem, &param, 1);
}



/*
 * Addresses are Black-image addresses.
 */
void ENCEFF_InitGridSpread(EncEffGridWork *work)
{
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);

    spread->nextCount = 0;
    spread->waveCount = 0;
    spread->next[0] = 0x33;
    spread->nextCount++;
    spread->next[1] = 0x95;
    spread->nextCount++;
    spread->next[2] = 0x5B;
    spread->nextCount++;
}



void ENCEFF_StepGridSpread(EncEffGridWork *work)
{
    EncEffGridStepState *step = &work->step;
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);

    if (step->nextCell < work->cols * work->rows) {
        if (step->delay == 0) {
            int i;

            for (i = 0; i < spread->waveCount; i++)
                ENCEFF_QueueGridSpreadNeighbors(work, spread->wave[i]);
            ENCEFF_StartGridSpreadWave(work);
            step->delay = 1;
        } else {
            step->delay--;
        }
    }
}


int ENCEFF_UpdateGridSpreadCell(EncEffGridCell *cell)
{
    if (cell->pos.x < 0x100000) {
        int x = cell->pos.x;
        int velocityX = cell->velocityX;

        cell->pos.z = 0x1000;
        cell->pos.x = x + velocityX;
        cell->velocityX = velocityX + 0x1000;
        if (cell->angleY < 0x8000)
            cell->angleY += 0x200;
        else
            cell->angleY = 0x8000;
    } else {
        cell->finished = 1;
    }
    return cell->finished;
}


/*
 * Lever: declare index before bound to put index in r3 and bound in r4.
 */
int ENCEFF_IsGridSpreadQueued(int cellIndex, EncEffSpreadState *spread) {
    int i;
    int count = spread->nextCount;
    for (i=0; i<count; i++) {
        if (cellIndex == spread->next[i]) return 1;
    }
    return 0;
}



void ENCEFF_QueueGridSpreadCell(EncEffGridWork *work, int x, int y)
{
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);
    int cellIndex = x + y * work->cols;

    if (work->cell[cellIndex].active == 0) {
        if (ENCEFF_IsGridSpreadQueued(cellIndex, spread) == 0) {
            spread->next[spread->nextCount] = cellIndex;
            spread->nextCount++;
        }
    }
}



void ENCEFF_QueueGridSpreadNeighbors(EncEffGridWork *work, int cellIndex)
{
    int cols = work->cols;
    int x = cellIndex % cols;
    int y = cellIndex / cols;

    if (y - 1 >= 0)
        ENCEFF_QueueGridSpreadCell(work, x, y - 1);
    if (x + 1 < work->cols)
        ENCEFF_QueueGridSpreadCell(work, x + 1, y);
    if (y + 1 < work->rows)
        ENCEFF_QueueGridSpreadCell(work, x, y + 1);
    if (x - 1 >= 0)
        ENCEFF_QueueGridSpreadCell(work, x - 1, y);
}


void ENCEFF_StartGridSpreadWave(EncEffGridWork *work)
{
    int i;
    EncEffGridStepState *step = &work->step;
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);

    for (i = 0; i < spread->nextCount; i++) {
        EncEffGridCell *cell = &work->cell[spread->next[i]];

        if (cell->active == 0) {
            cell->active = 1;
            step->nextCell++;
            cell->velocityX = 0x1000;
            spread->wave[i] = spread->next[i];
        }
    }
    spread->waveCount = spread->nextCount;
    spread->nextCount = 0;
}
