/*
 * file:     eventdata_system_p07.c
 * unit:     yes
 * function: func_0216208C, func_0216209C, func_021620A0
 * address:  0x0216208C
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
 *   func_02162358  0x02162358  thumb  ov010
 *   func_021622F4  0x021622F4  thumb  ov010
 */
#include "../../matched/include/Obj18951.h"
#include "../../matched/include/Obj18952.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_02162358();
extern int func_021622F4();
int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
int func_021620A0(int a0);


/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021871F8.
 */
int func_0216208C(char *p, int unused)
{
    if (((struct Obj18951 *)p)->f2 & 8)
        return 1;
    return 0;
}


u16 func_0216209C(char *p)
{
    return ((struct Obj18952 *)p)->f26;
}


int func_021620A0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02162358(a0);
loc_021620A8:
a0 = t4 + 0;
    a0 = func_021622F4(a0);
loc_021620AE:
    return a0;}
