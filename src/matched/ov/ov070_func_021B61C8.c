/*
 * function: func_021B61C8
 * address: 0x021B61C8
 * packet: pkt_ov070_021B61C8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 */
#include "../include/Obj00002.h"
typedef unsigned char u8;
struct Item;
extern unsigned int func_02007F7C(const struct Item *arr, unsigned int n);
typedef unsigned int   u32;
extern u32 func_02007FA0(u8 *base, u32 id);
int func_021B61C8(u8 *p)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return func_02007F7C((const struct Item *)(p + 0x20), 0x136);
    return func_02007FA0(((struct Obj00002 *)p)->f18, ((struct Obj00002 *)p)->f80C);
}
