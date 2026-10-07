/*
 * file:     unit_021B95A0_p13.c
 * unit:     yes
 * function: func_021BB0E4, func_021BB0F8
 * address:  0x021BB0E4
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BB138 0x021BB138 thumb ov068
 */
#include "../../matched/include/Obj20650.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_0203EFC8(const u8 *, const u8 *, u32);
extern void func_02082BCC(void *, u32, u32);
extern void func_021BB138(void *, int);
int func_021BB0E4(const u8 *p, const u8 *q);
void func_021BB0F8(u8 *p, int value, int callback);

int func_021BB0E4(const u8 *p, const u8 *q)
{
    if (func_0203EFC8(p, q, 5) == 0) return 1;
    return 0;
}

void func_021BB0F8(u8 *p, int value, int callback)
{
    func_02082BCC(p, 0, 16);
    ((struct Obj20650 *)p)->fC = value;
    func_021BB138(p, callback);
}
