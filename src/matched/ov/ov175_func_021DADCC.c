/*
 * function: func_021DADCC
 * address:  0x021DADCC
 * packet:   pkt_021DADCC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DF224  0x021DF224  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * Report-intention completion callback: on success copies the 0x28-byte session id into the report block (+0x34 of the record at +0x1464), otherwise records the result at +0x15c; then drops the pending-request count at +0x134.
 */
#include "../include/Obj10685.h"

typedef unsigned char u8;
typedef unsigned long u32;

extern void *func_021DF224(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void func_021DADCC(int result, char *obj)
{
    char *p = *(char * *)&((struct Obj10685 *)obj)->f1464 + 4;

    if (result == 0)
        MI_CpuCopy8(func_021DF224(), p + 0x30, 0x28);
    else
        ((struct Obj10685 *)obj)->f15C = result;
    (((struct Obj10685 *)obj)->f134)--;
}
