/*
 * function: UNION_MSG_DeleteWordSet
 * address: 0x0217F044
 * packet: pkt_ov019_0217F044
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_Delete 0x0201ED04 thumb
 */
#include "../include/Obj09417.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern u32 WORDSET_Delete(struct WordSet *p);
void UNION_MSG_DeleteWordSet(u8 *p)
{
    if (((struct Obj09417 *)p)->f2804 != 0) {
        WORDSET_Delete(((struct Obj09417 *)p)->f2804);
        ((struct Obj09417 *)p)->f2804 = 0;
    }
}
