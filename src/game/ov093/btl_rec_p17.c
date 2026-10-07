/*
 * file:     btl_rec_p17.c
 * unit:     yes
 * function: func_021EF8C8, func_021EF8E8, func_021EF8F8
 * address:  0x021EF8C8
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
 *   func_021EF9F4  0x021EF9F4  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EFA94  0x021EFA94  thumb  ov093
 *   func_021EFAD8  0x021EFAD8  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 */
#include "../../matched/include/G_Countdown.h"

typedef unsigned int u32;

typedef struct { u32 v; } Slot;

extern int func_021EF9F4(void *mem, u32 b, Slot c, int d);
extern int func_021EFA94(void *mem, int a);
extern int func_021EFAD8(char *a, u32 b, u32 c);
int func_021EF8C8(u32 a, Slot c);
int func_021EF8E8(int a);
int DWC_StartUtilityEx(int a, int b);
extern struct Countdown d_021F63F4;
extern char HeapMem;


int func_021EF8C8(u32 a, Slot c)
{
    return func_021EF9F4(&(*(char *)&d_021F63F4), a, c, 1);
}


int func_021EF8E8(int a)
{
    return func_021EFA94(&(*(char *)&d_021F63F4), a);
}


int DWC_StartUtilityEx(int a, int b)
{
    return func_021EFAD8(&HeapMem, a, b);
}
