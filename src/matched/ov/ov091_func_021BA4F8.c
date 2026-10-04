/*
 * function: func_021BA4F8
 * address:  0x021BA4F8
 * packet:   pkt_ov091_021BA4F8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B90F8  0x021B90F8  thumb  ov091
 *   func_0201A59C  0x0201A59C  thumb
 */
#include "../include/Obj00009.h"
#include "../include/Obj20864.h"
#include "../include/Obj20865.h"
#include "../include/Obj20866.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021B90F8(u8 *a);
extern int func_0201A59C(void *a0, void *a1, void *a2);

void func_021BA4F8(u8 *a)
{
    u8 i;
    u8 j;
    u8 *rules;
    int st;

    if (((struct Obj00009 *)a)->f250 != 0)
        return;
    st = a[0xc];
    if (st == 0x13)
        return;
    if (st == 0x15)
        return;
    if (st == 0)
        return;
    if (st == 1)
        return;
    if (st == 6)
        func_021B90F8(a);
    ((struct Obj00009 *)a)->f250 = 1;
    if (((struct Obj00009 *)a)->f278 == 1)
        a[0xc] = 0x11;
    else
        a[0xc] = 0x14;
    ((struct Obj20864 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f3C = 6;
    ((struct Obj20865 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f40 = 0;
    if (((struct Obj00009 *)a)->f118 != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    rules = *(u8 * *)&((struct Obj20866 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f14;
    if (func_0201A59C(rules, (void *)(**(int * *)&((struct Obj00009 *)a)->f280), *(u8 * *)&((struct Obj00009 *)a)->f280 + 0x49) != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    for (j = 0; j < rules[2]; j++)
        (*(u8 **)(a + 0x280))[0x49 + j] = j + 1;
}
