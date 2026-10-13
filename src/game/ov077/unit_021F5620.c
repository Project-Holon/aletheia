/*
 * file:     unit_021F5620.c
 * unit:     yes
 * function: ENCEFF_StartCellGrid, ENCEFF_CellGridEventMain, ENCEFF_StepCellGrid, ENCEFF_UpdateCellGrid
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
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   ENCEFF_GetEffect 0x021CF51C thumb ov021
 *   G3X_SetClearColor 0x0207DD24 arm
 *   ENCEFF_DrawScreenTexEffect 0x021F52D8 thumb ov075
 */
#include "enceff_base_types.h"
#include "enceff_grid_types.h"

struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void FADE_Start(u32 planes, s32 startLevel, s32 endLevel, s32 wait);
extern int FADE_IsActive(void);
extern struct GameEvent *ENCEFF_GetEffect(struct EncEffWork *eff);
extern void G3X_SetClearColor(u16 color, int alpha, int depth, int polygonId, int clearImage);
extern void ENCEFF_DrawScreenTexEffect(struct GameEvent *effect);
void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
int ENCEFF_CellGridEventMain(struct GameEvent *event, int *state);
int ENCEFF_StepCellGrid(EncEffGridWork *work);
void ENCEFF_UpdateCellGrid(struct EncEffWork *eff);


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
    event = func_020122C0(gameSystem, 0, ENCEFF_CellGridEventMain, 0);
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

    work = ENCEFF_GetWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(func_020124E4(event))));
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
