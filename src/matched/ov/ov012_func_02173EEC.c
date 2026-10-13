/*
 * function: UNION_COMMAND_RecvAppSetting
 * address:  0x02173EEC
 * packet:   pkt_ov012_02173EEC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_02034714  0x02034714  arm
 *   func_02183F98  0x02183F98  thumb ov022
 */
#include "../include/Obj19267.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0203D378(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183F98(void *p, const void *value);

void UNION_COMMAND_RecvAppSetting(int a, int b, void *value, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 1) {
        q = *(u8 * *)&((struct Obj19267 *)p)->f3528;
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183F98(q, value);
    }
}
