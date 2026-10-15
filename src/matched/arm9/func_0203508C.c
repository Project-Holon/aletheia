/*
 * function: UI_SetResumeAndSuspendHooks
 * address:  0x0203508C
 * packet:   pkt_0203508C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gUiState    0x021469BC  data
 *   func_02035080 0x02035080  arm
 *   func_02035120 0x02035120  arm
 */
#include "../include/Obj08822.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *gUiState;
struct Obj02035080;
struct Obj02035120;
extern void func_02035080(struct Obj02035080 *p, u32 a, u32 b);
extern void func_02035120(struct Obj02035120 *p, u32 a, u32 b);

void UI_SetResumeAndSuspendHooks(u32 a, u32 b, u32 c)
{
    u8 *g = gUiState;

    if (g[0x41] != 0) {
        if (((struct Obj08822 *)g)->f18 != 0) {
            ((void (*)(u32)) * (u32 *)(g + 0x18))(((struct Obj08822 *)g)->f2C);
        }
        if (a != 0) {
            ((void (*)(u32))a)(c);
        }
    }
    func_02035080((struct Obj02035080 *)gUiState, a, c);
    func_02035120((struct Obj02035120 *)gUiState, b, c);
}
