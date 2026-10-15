/*
 * function: OEKAKI_RegisterPlayerName
 * address: 0x021857F4
 * packet: pkt_ov023_021857F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
#include "../include/Obj00525.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct WordSet;
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void OEKAKI_RegisterPlayerName(char *p, int a, int i)
{
    char *v;
    v = UNION_APP_GetMemberEntry(**(u8 ** *)&((struct Obj00525 *)p)->f4, (u8)i);
    if (v != 0)
        WORDSET_SetSlotMyStatus(((struct Obj00525 *)p)->f10, a, v);
}
