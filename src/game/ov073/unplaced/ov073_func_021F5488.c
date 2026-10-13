/*
 * function: func_021F5488
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
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */
#include "../../ov021/fieldmap_types.h"

typedef unsigned int u32;
typedef signed int s32;

struct GameSystem;
struct GameEvent;

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern void func_0204E720(u32 flags, s32 start, s32 end, s32 step);
extern int func_0204E804(void);

/*
 * Event run when the name cut-in cannot start: fades both screens to black
 * (flags 3) and ends when the fade is done. The field map lookup result is
 * not used.
 */
int func_021F5488(struct GameEvent *event, int *state)
{
    func_0201210C(func_020124E4(event));
    switch (*state) {
    case 0:
        func_0204E720(3, 0, 0x10, 3);
        *state = *state + 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
