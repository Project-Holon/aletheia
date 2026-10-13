/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: ENCEFF_BuildBlockFlip, ENCEFF_StartBlockFlip, ENCEFF_StepBlockFlip
 * address:  0x021F5A80
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gBlockFlipCameraPos 0x021F5B70 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 *   ENCEFF_StepFlipCell  0x021F5B24  thumb  ov079
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"

struct GameSystem;
struct FieldMap;

extern struct EncEffWork *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void ENCEFF_LoadOverlays4B4D(struct EncEffWork *eff);
extern void *ENCEFF_StartScreenTexEffectFlash(void *gameSystem, const VecFx32 *cameraPos, void *build, void *draw);
extern void ENCEFF_DrawCellGrid(EncEffGridWork *work);
extern void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
extern int ENCEFF_StepFlipCell(EncEffGridCell *cell);
void *ENCEFF_BuildBlockFlip(void *gameSystem, struct FieldMap *fieldMap);
void ENCEFF_StartBlockFlip(void *gameSystem);
void ENCEFF_StepBlockFlip(EncEffGridWork *work);
extern const VecFx32 gBlockFlipCameraPos;

void *ENCEFF_BuildBlockFlip(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = gBlockFlipCameraPos;
    ENCEFF_LoadOverlays4B4D(FIELDMAP_GetEncEff(fieldMap));
    return ENCEFF_StartScreenTexEffectFlash(gameSystem, &cameraPos, ENCEFF_StartBlockFlip, ENCEFF_DrawCellGrid);
}


void ENCEFF_StartBlockFlip(void *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 4;
    param.cellHeight = 4;
    param.initCallback = 0;
    param.stepCallback = ENCEFF_StepBlockFlip;
    param.cellCallback = ENCEFF_StepFlipCell;
    ENCEFF_StartCellGrid(gameSystem, &param, 0);
}


/*
 * Step callback: starts one more cell every frame, in cell order.
 *
 * Addresses are Black-image addresses.
 */
void ENCEFF_StepBlockFlip(EncEffGridWork *work)
{
    EncEffGridStepState *step = &work->step;
    int cellCount = work->cols * work->rows;

    if (step->nextCell < cellCount) {
        if (step->delay == 0) {
            work->cell[step->nextCell].active = 1;
            step->nextCell++;
            step->delay = 0;
        } else {
            step->delay--;
        }
    }
}
