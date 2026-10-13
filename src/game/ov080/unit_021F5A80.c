/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: ENCEFF_BuildGridColumnFlip, ENCEFF_StartGridColumnFlip, ENCEFF_StepGridColumnFlip
 * address:  0x021F5A80
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gEncEffGridColumnFlipCameraPos 0x021F5B64 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 *   ENCEFF_UpdateGridColumnFlipCell  0x021F5B44  thumb  ov080
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"

extern void ENCEFF_LoadOverlays4B4D(struct EncEffWork *eff);
extern struct GameEvent *ENCEFF_StartScreenTexEffectFlash(struct GameSystem *gameSystem, VecFx32 *cameraPos,
                                       struct GameEvent *(*start)(struct GameSystem *gameSystem),
                                       void (*draw)(EncEffGridWork *work));
extern void ENCEFF_DrawCellGrid(EncEffGridWork *work);
extern void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
extern int ENCEFF_UpdateGridColumnFlipCell(EncEffGridCell *cell);
struct GameEvent *ENCEFF_BuildGridColumnFlip(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartGridColumnFlip(struct GameSystem *gameSystem);
void ENCEFF_StepGridColumnFlip(EncEffGridWork *work);
extern const VecFx32 gEncEffGridColumnFlipCameraPos;

/*
 * Encounter effect of overlay 0x50: the screen picture is cut into 2x2 tile
 * cells and the cells turn over column by column. Builder of the effect table:
 * loads the helper overlays, then starts the screen texture effect.
 */
struct GameEvent *ENCEFF_BuildGridColumnFlip(struct GameSystem *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = gEncEffGridColumnFlipCameraPos;
    ENCEFF_LoadOverlays4B4D(FIELDMAP_GetEncEff(fieldMap));
    return ENCEFF_StartScreenTexEffectFlash(gameSystem, &cameraPos, ENCEFF_StartGridColumnFlip, ENCEFF_DrawCellGrid);
}


/* Start function of the screen texture effect: creates the cell grid. */
struct GameEvent *ENCEFF_StartGridColumnFlip(struct GameSystem *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.initCallback = 0;
    param.stepCallback = ENCEFF_StepGridColumnFlip;
    param.cellCallback = ENCEFF_UpdateGridColumnFlipCell;
    return ENCEFF_StartCellGrid(gameSystem, &param, 1);
}


/*
 * Addresses are Black-image addresses.
 */
/* Step callback: every second frame the next column of cells starts to turn. */
void ENCEFF_StepGridColumnFlip(EncEffGridWork *work)
{
    EncEffGridStepState *step = &work->step;

    if (step->nextCell < work->cols) {
        if (step->delay == 0) {
            int row;

            for (row = 0; row < work->rows; row++)
                work->cell[step->nextCell + row * work->cols].active = 1;
            step->nextCell++;
            step->delay = 1;
        } else {
            step->delay--;
        }
    }
}
