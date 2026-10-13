/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: func_021F5A80, func_021F5ABC, func_021F5AEC, func_021F5B30, func_021F5B94, func_021F5BCC, func_021F5BFC, func_021F5C3C
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
 * symbols:
 *   d_021F5D00 0x021F5D00 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F582C 0x021F582C thumb ov077
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5CA0  0x021F5CA0  thumb  ov081
 */
#include "../ov077/enceff_base_types.h"
#include "../ov077/enceff_grid_types.h"
#include "unit_021F5A80_types.h"

extern void func_021CF580(struct EncEffWork *eff);
extern struct GameEvent *func_021F5260(struct GameSystem *gameSystem, VecFx32 *cameraPos,
                                       struct GameEvent *(*start)(struct GameSystem *gameSystem),
                                       void (*draw)(EncEffGridWork *work));
extern void func_021F582C(EncEffGridWork *work);
extern void *func_021F5620(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
extern void func_021F5CA0(EncEffGridWork *work);
struct GameEvent *func_021F5A80(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *func_021F5ABC(struct GameSystem *gameSystem);
void func_021F5AEC(EncEffGridWork *work);
void func_021F5B30(EncEffGridWork *work);
int func_021F5B94(EncEffGridCell *cell);
int func_021F5BCC(int cellIndex, EncEffSpreadState *spread);
void func_021F5BFC(EncEffGridWork *work, int x, int y);
void func_021F5C3C(EncEffGridWork *work, int cellIndex);
extern const VecFx32 d_021F5D00;

/*
 * Encounter effect of overlay 0x51: the screen picture is cut into 2x2 tile
 * cells that start in waves spreading from three seed cells. Builder of the
 * effect table: loads the helper overlays, then starts the screen texture effect.
 */
struct GameEvent *func_021F5A80(struct GameSystem *gameSystem, struct FieldMap *fieldMap) {
    VecFx32 cameraPos = d_021F5D00;
    func_021CF580(func_02189A08(fieldMap));
    return func_021F5260(gameSystem, &cameraPos, func_021F5ABC, func_021F582C);
}


struct GameEvent *func_021F5ABC(struct GameSystem *gameSystem)
{
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.initCallback = func_021F5AEC;
    param.stepCallback = func_021F5B30;
    param.cellCallback = func_021F5B94;
    return func_021F5620(gameSystem, &param, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F5AEC(EncEffGridWork *work)
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


void func_021F5B30(EncEffGridWork *work)
{
    EncEffGridStepState *step = &work->step;
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);

    if (step->nextCell < work->cols * work->rows) {
        if (step->delay == 0) {
            int i;

            for (i = 0; i < spread->waveCount; i++)
                func_021F5C3C(work, spread->wave[i]);
            func_021F5CA0(work);
            step->delay = 1;
        } else {
            step->delay--;
        }
    }
}

int func_021F5B94(EncEffGridCell *cell)
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
int func_021F5BCC(int cellIndex, EncEffSpreadState *spread) {
    int i;
    int count = spread->nextCount;
    for (i=0; i<count; i++) {
        if (cellIndex == spread->next[i]) return 1;
    }
    return 0;
}


void func_021F5BFC(EncEffGridWork *work, int x, int y)
{
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);
    int cellIndex = x + y * work->cols;

    if (work->cell[cellIndex].active == 0) {
        if (func_021F5BCC(cellIndex, spread) == 0) {
            spread->next[spread->nextCount] = cellIndex;
            spread->nextCount++;
        }
    }
}


void func_021F5C3C(EncEffGridWork *work, int cellIndex)
{
    int cols = work->cols;
    int x = cellIndex % cols;
    int y = cellIndex / cols;

    if (y - 1 >= 0)
        func_021F5BFC(work, x, y - 1);
    if (x + 1 < work->cols)
        func_021F5BFC(work, x + 1, y);
    if (y + 1 < work->rows)
        func_021F5BFC(work, x, y + 1);
    if (x - 1 >= 0)
        func_021F5BFC(work, x - 1, y);
}
