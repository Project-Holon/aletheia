/*
 * file:     enceff_block_flip.c
 * unit:     yes
 * function: ENCEFF_BuildBlockFlip, ENCEFF_StartBlockFlip, ENCEFF_StepBlockFlip, ENCEFF_StepFlipCell
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
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   gBlockFlipCameraPos 0x021F5B70 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
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
void *ENCEFF_BuildBlockFlip(void *gameSystem, struct FieldMap *fieldMap);
void ENCEFF_StartBlockFlip(void *gameSystem);
void ENCEFF_StepBlockFlip(EncEffGridWork *work);
int ENCEFF_StepFlipCell(EncEffGridCell *cell);
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


/*
 * Cell callback of the block flip: the cell turns one full turn about its Y
 * axis (phase 0), then half a turn more (phase 1) to show its back, then is
 * done. Angles are 16 bit angles << 4.
 */
int ENCEFF_StepFlipCell(EncEffGridCell *cell)
{
    int phase = cell->phase;

    if (phase < 1) {
        s32 *angle = &cell->angleY;  /* the pointer changes the code (kept as the original) */
        int next = cell->angleY + 0x1000;

        cell->angleY = next;
        if (next >= 0x10000) {
            *angle = next - 0x10000;
            cell->phase = phase + 1;
        }
    } else if (phase == 1) {
        int next = cell->angleY + 0x1000;

        cell->angleY = next;
        if (next >= 0x8000) {
            cell->angleY = 0x8000;
            cell->phase = phase + 1;
        }
    } else {
        cell->finished = 1;
    }
    return cell->finished;
}
