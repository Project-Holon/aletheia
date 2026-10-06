/*
 * function: func_02173FE0
 * address: 0x02173FE0
 * packet: pkt_ov012_02173FE0
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02183FB8 0x02183FB8 thumb ov022
 *   d_02175624 0x02175624 data a1
 */
#include "../include/Obj12449.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183FB8(int, void *, u8, int);
extern u8 d_02175624[];
void func_02173FE0(int a, int x, int y, u8 *p)
{
    if (((struct Obj12449 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    func_02183FB8(((struct Obj12449 *)p)->f3528, p, a, y);
}
