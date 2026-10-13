/*
 * function: UNION_MSG_CreateWordSet
 * address: 0x0217F020
 * packet: pkt_ov019_0217F020
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EC74 0x0201EC74 thumb
 *   UNION_MSG_RegisterPartnerWords 0x0217EE90 thumb ov019
 */
#include "../include/Obj00484.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
struct Self;
extern void UNION_MSG_RegisterPartnerWords(struct Self *self);
void UNION_MSG_CreateWordSet(u8 *p)
{
    if (((struct Obj00484 *)p)->f2804 == 0) {
        ((struct Obj00484 *)p)->f2804 = func_0201EC74(5, 0x40, 0x41);
        UNION_MSG_RegisterPartnerWords((struct Self *)p);
    }
}
