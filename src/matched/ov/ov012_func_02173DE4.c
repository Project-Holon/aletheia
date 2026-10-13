/*
 * function: UNION_COMMAND_RecvAppQuitRequest
 * address:  0x02173DE4
 * packet:   pkt_ov012_02173DE4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    Nested null recheck retains the original dead second bne.
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_02034714  0x02034714  arm
 *   func_02183F6C  0x02183F6C  thumb ov022
 */
#include "../include/Obj19264.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0203D378(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183F6C(u8 *p, u8 a);

void UNION_COMMAND_RecvAppQuitRequest(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 * *)&((struct Obj19264 *)p)->f3528;
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F6C(q, (u8)a);
        }
    }
}
