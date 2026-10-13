/*
 * function: ENCEFF_NameCutInFadeOutEventMain
 * address:  0x021F5488
 * packet:   pkt_ov073_021F5488
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */
#include "../../ov021/fieldmap_types.h"

typedef unsigned int u32;
typedef signed int s32;

struct GameSystem;
struct GameEvent;

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern void FADE_Start(u32 flags, s32 start, s32 end, s32 step);
extern int FADE_IsActive(void);

/*
 * Event run when the name cut-in cannot start: fades both screens to black
 * (flags 3) and ends when the fade is done. The field map lookup result is
 * not used.
 */
int ENCEFF_NameCutInFadeOutEventMain(struct GameEvent *event, int *state)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 0x10, 3);
        *state = *state + 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
