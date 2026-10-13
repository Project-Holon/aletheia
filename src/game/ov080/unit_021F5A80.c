/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: func_021F5A80, func_021F5ABC, func_021F5AE8
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
 *   d_021F5B64 0x021F5B64 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F582C 0x021F582C thumb ov077
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5B44  0x021F5B44  thumb  ov080
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"

extern void func_021CF580(struct EncEffWork *eff);
extern struct GameEvent *func_021F5260(struct GameSystem *gameSystem, VecFx32 *cameraPos,
                                       struct GameEvent *(*start)(struct GameSystem *gameSystem),
                                       void (*draw)(EncEffGridWork *work));
extern void func_021F582C(EncEffGridWork *work);
extern void *func_021F5620(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
extern int func_021F5B44(EncEffGridCell *cell);
struct GameEvent *func_021F5A80(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *func_021F5ABC(struct GameSystem *gameSystem);
void func_021F5AE8(EncEffGridWork *work);
extern const VecFx32 d_021F5B64;

/*
 * Encounter effect of overlay 0x50: the screen picture is cut into 2x2 tile
 * cells and the cells turn over column by column. Builder of the effect table:
 * loads the helper overlays, then starts the screen texture effect.
 */
struct GameEvent *func_021F5A80(struct GameSystem *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = d_021F5B64;
    func_021CF580(func_02189A08(fieldMap));
    return func_021F5260(gameSystem, &cameraPos, func_021F5ABC, func_021F582C);
}


/* Start function of the screen texture effect: creates the cell grid. */
struct GameEvent *func_021F5ABC(struct GameSystem *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.initCallback = 0;
    param.stepCallback = func_021F5AE8;
    param.cellCallback = func_021F5B44;
    return func_021F5620(gameSystem, &param, 1);
}


/*
 * Addresses are Black-image addresses.
 */
/* Step callback: every second frame the next column of cells starts to turn. */
void func_021F5AE8(EncEffGridWork *work)
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
