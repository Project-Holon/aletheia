/*
 * file:     btl_rec_p16.c
 * unit:     yes
 * function: func_021EF894, func_021EF8A4, func_021EF8B8
 * address:  0x021EF894
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EF9B0  0x021EF9B0  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 *   func_021EF9D0  0x021EF9D0  thumb  ov093
 */
#include "../../matched/include/G_Countdown.h"

typedef unsigned int   u32;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

extern int func_021EF9B0(u32 *p);
extern int *func_021EF9C0(int *p, int a, int b);
extern u32 func_021EF9D0(Countdown *p);
int func_021EF894(void);
int DWC_StartUtilityEx(int a, int b);
u32 func_021EF8B8(void);
extern struct Countdown d_021F63F4;
extern char HeapMem;


int func_021EF894(void)
{
    return func_021EF9B0((u32 *)(&(*(char *)&d_021F63F4)));
}


int DWC_StartUtilityEx(int a, int b)
{
    return (int)func_021EF9C0((int *)(&HeapMem), a, b);
}


/*
 * Tail call into the countdown leaf func_021EF9D0 with the static record.
 *
 * 2026-10-03: byte-correct, MATCH only because 0x021EF9D0 has no label yet.
 * Its witness is filed EXACT as src/matched/ov/ov093_func_021EF9D0.c; once
 * the integrator seeds that start this verifies EXACT.
 */
u32 func_021EF8B8(void)
{
    return func_021EF9D0(((Countdown *)&d_021F63F4));
}
