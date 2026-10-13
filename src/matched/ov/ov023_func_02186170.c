/*
 * function: OEKAKI_UpdateMemberSlots
 * address:  0x02186170
 * packet:   pkt_ov023_02186170
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_APP_GetMemberEntry  0x02184180  thumb  ov022
 */
#include "../include/Obj20363.h"


extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);

int OEKAKI_UpdateMemberSlots(char *p)
{
    int i;
    int r;

    r = 0;
    for (i = 0; i < 5; i++) {
        *(int *)(p + i * 8 + 0x1cc) = *(int *)(p + i * 8 + 0x1c8);
        *(int *)(p + i * 8 + 0x1c8) = (int)UNION_APP_GetMemberEntry((unsigned char *)(**(int * *)&((struct Obj20363 *)p)->f4), (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + i * 8 + 0x1cc) != *(int *)(p + i * 8 + 0x1c8))
            r = 1;
    }
    return r;
}
