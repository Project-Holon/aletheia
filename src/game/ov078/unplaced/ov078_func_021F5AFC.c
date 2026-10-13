/*
 * function: ENCEFF_StartRippleBurst
 * address:  0x021F5AFC
 * packet:   pkt_ov078_021F5AFC
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov078 ENCEFF_StartRipple with different constants: faster, higher drops
 * and a longer wait after the last one.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   ENCEFF_RippleEventMain  0x021F5748  thumb  ov078
 * Addresses are Black-image addresses.
 */
#include "../../ov077/enceff_base_types.h"
#include "../enceff_ripple_types.h"

struct GameSystem;
struct GameEvent;
struct EncEffWork;
struct FieldMap;
struct Desc;
extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern struct EncEffWork *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void *ENCEFF_AllocWork(struct EncEffWork *eff, u32 size, u32 heapId);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int ENCEFF_RippleEventMain(struct GameEvent *event, int *state);

void *ENCEFF_StartRippleBurst(void *gameSystem)
{
    EncEffRipple *ripple;
    void *event;
    int i;

    ripple = ENCEFF_AllocWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffRipple), 0x50);
    event = func_020122C0(gameSystem, 0, ENCEFF_RippleEventMain, 0);
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
