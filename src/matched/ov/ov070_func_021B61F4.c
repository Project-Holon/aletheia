/*
 * function: ITEMMENU_RegisterItemName
 * address: 0x021B61F4
 * packet: pkt_ov070_021B61F4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 */
#include "../include/Obj20661.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b)
{
    WORDSET_Callback_EF40(((struct Obj20661 *)p)->f520, a, b);
}
