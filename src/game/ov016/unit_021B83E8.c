/*
 * file:     unit_021B83E8.c
 * unit:     yes
 * function: func_021B83E8, func_021B83F4
 * address:  0x021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj09184.h"
#include "../../matched/include/Obj12103.h"

typedef unsigned int u32;

typedef unsigned short u16;

void func_021B83E8(void *rec);
int func_021B83F4(int v, void *rec);


/*
 * Clear a u32 and two u16 fields of a small record.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B83E8.c \
 *       --func func_021B83E8 --addr 0x021B83E8 --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B83E8(void *rec)
{
    ((struct Obj09184 *)rec)->f0 = 0;
    ((struct Obj09184 *)rec)->f4 = 0;
    ((struct Obj09184 *)rec)->f6 = 0;
}


int func_021B83F4(int v, void *rec)
{
    ((struct Obj12103 *)rec)->f0 = v;
    ((struct Obj12103 *)rec)->f4 = 1;
    return 1;
}
