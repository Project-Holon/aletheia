/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: func_021F5A80, func_021F5ABC, func_021F5AE4
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
 *   d_021F5B70 0x021F5B70 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F582C 0x021F582C thumb ov077
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5B24  0x021F5B24  thumb  ov079
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"

struct GameSystem;
struct FieldMap;

extern struct EncEffWork *func_02189A08(struct FieldMap *fieldMap);
extern void func_021CF580(struct EncEffWork *eff);
extern void *func_021F5260(void *gameSystem, const VecFx32 *cameraPos, void *build, void *draw);
extern void func_021F582C(EncEffGridWork *work);
extern void *func_021F5620(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
extern int func_021F5B24(EncEffGridCell *cell);
void *func_021F5A80(void *gameSystem, struct FieldMap *fieldMap);
void func_021F5ABC(void *gameSystem);
void func_021F5AE4(EncEffGridWork *work);
extern const VecFx32 d_021F5B70;

void *func_021F5A80(void *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = d_021F5B70;
    func_021CF580(func_02189A08(fieldMap));
    return func_021F5260(gameSystem, &cameraPos, func_021F5ABC, func_021F582C);
}


void func_021F5ABC(void *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 4;
    param.cellHeight = 4;
    param.initCallback = 0;
    param.stepCallback = func_021F5AE4;
    param.cellCallback = func_021F5B24;
    func_021F5620(gameSystem, &param, 0);
}


/*
 * Step callback: starts one more cell every frame, in cell order.
 *
 * Addresses are Black-image addresses.
 */
void func_021F5AE4(EncEffGridWork *work)
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
