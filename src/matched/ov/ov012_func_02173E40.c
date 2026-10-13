/*
 * function: UNION_COMMAND_RecvAppQuitAccept
 * address:  0x02173E40
 * packet:   pkt_ov012_02173E40
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    Nested null recheck retains the original dead second bne.
 * symbols:
 *   func_02034714  0x02034714  arm
 *   UNION_APP_SetQuitAccepted  0x02183F7C  thumb ov022
 */
#include "../include/Obj19265.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void UNION_APP_SetQuitAccepted(u8 *p);

void UNION_COMMAND_RecvAppQuitAccept(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19265 *)p)->f3528;
    if (q == 0) {
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
    } else {
        UNION_APP_SetQuitAccepted(q);
    }
}
