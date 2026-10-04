/*
 * function: func_0203CFA0
 * address:  0x0203CFA0
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CFA0.c \
 *       --func func_0203CFA0 --addr 0x0203CFA0 --cc 1.1p1 --arm
 */
#include "../include/Obj15976.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern u32 func_0203B1D8(void);

void func_0203CFA0(void)
{
    u8 *s = func_0203D788();
    u8 *p;

    if (func_0203B1D8() != 0)
        return;
    if (s == 0 || ((struct Obj15976 *)s)->f340 == 0)
        return;

    p = func_0203D798();
    switch (p[0x65]) {
    case 1:
    case 2:
        return;
    }

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);
}
