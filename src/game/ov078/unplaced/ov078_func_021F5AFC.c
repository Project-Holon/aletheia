/*
 * function: func_021F5AFC
 * address:  0x021F5AFC
 * packet:   pkt_ov078_021F5AFC
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov078 func_021F5698 with different constants: faster, higher drops
 * and a longer wait after the last one.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5748  0x021F5748  thumb  ov078
 * Addresses are Black-image addresses.
 */
#include "../../ov077/enceff_base_types.h"
#include "../enceff_ripple_types.h"

struct GameSystem;
struct GameEvent;
struct EncEffWork;
struct FieldMap;
struct Desc;
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern struct EncEffWork *func_02189A08(struct FieldMap *fieldMap);
extern void *func_021CF52C(struct EncEffWork *eff, u32 size, u32 heapId);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5748(struct GameEvent *event, int *state);

void *func_021F5AFC(void *gameSystem)
{
    EncEffRipple *ripple;
    void *event;
    int i;

    ripple = func_021CF52C(func_02189A08(func_0201210C(gameSystem)), sizeof(EncEffRipple), 0x50);
    event = func_020122C0(gameSystem, 0, func_021F5748, 0);
    ripple->count = 7;
    ripple->wait = 0;
    ripple->period = 2;
    ripple->height = 0x555;
    ripple->next = 0x2d;
    ripple->startDelay = 0x37;
    ripple->fadeStarted = 0;
    for (i = 0; i < RIPPLE_VERTEX_COUNT; i++) {
        EncEffRippleVertex *vertex = &ripple->vertex[i];

        vertex->x = ((i % RIPPLE_COLS) << 12) / 16;
        vertex->y = ((i / RIPPLE_COLS) << 12) / 16;
        vertex->z = 0;
    }
    ripple->fadeScreens = 3;
    return event;
}
