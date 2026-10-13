/*
 * function: OEKAKI_CountMembers
 * address: 0x02185F50
 * packet: pkt_ov023_02185F50
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index declared before count places i in r4 and n in r5.
 * symbols:
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 */
#include "../include/Obj20359.h"
typedef unsigned char u8;
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
int OEKAKI_CountMembers(char *p)
{
    int i;
    int n;
    n = 0;
    for (i = 0; i < 5; i++) {
        if (UNION_APP_GetMemberEntry(**(u8 ** *)&((struct Obj20359 *)p)->f4, (u8)i) != 0)
            n++;
    }
    return n;
}
