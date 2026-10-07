/*
 * file:     event_field_proclink_p12.c
 * unit:     yes
 * function: func_0215FEC8, func_0215FED4
 * address:  0x0215FEC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021712AC     0x021712AC  data
 *   func_02188CCC   0x02188CCC  thumb
 *   func_021A12BC   0x021A12BC  thumb
 */
#include "../../matched/include/Obj12045.h"
#include "../../matched/include/Obj17708.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void *func_02188CCC(int);
extern void func_021A12BC(void *, int);
u32 func_0215FEC8(u32 n);
int func_0215FED4(void *a0, void *a1);
extern const u32 d_021712AC[];


/*
 * Unlabelled leaf after func_0215FD0C (bl from 0x0215FDD0).
 */
u32 func_0215FEC8(u32 n)
{
    return d_021712AC[n];
}


/*
 * Conditional arm9 pair call on the record's second field; the first
 * call's result is the first operand either way.
 */
int func_0215FED4(void *a0, void *a1)
{
    void *v = func_02188CCC(((struct Obj12045 *)a1)->fC);

    if (((struct Obj17708 *)a0)->f24 == 0)
        func_021A12BC(v, ((struct Obj12045 *)a1)->f10);

    return 1;
}
