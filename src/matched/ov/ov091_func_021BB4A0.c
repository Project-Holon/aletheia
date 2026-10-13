/*
 * function: PLIST_PLATE_CheckSelection
 * address:  0x021BB4A0
 * packet:   pkt_ov091_021BB4A0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */
#include "../include/Obj13251.h"
#include "../include/Obj20884.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int PLIST_PLATE_CheckSelection(u8 *p, int *s)
{
    int a;
    int b;
    u8 *q;
    u8 i;

    if (s[7] != 6) {
        return 1;
    }
    i = 0;
    a = POKE_TOOL_GetPartyValue((void *)s[0], 5, 0);
    b = POKE_TOOL_GetPartyValue((void *)s[0], 6, 0);
    q = *(u8 * *)&((struct Obj20884 *)(*(u8 * *)&((struct Obj13251 *)p)->f280))->f14;
    do {
        u8 v;
        v = (*(u8 **)(p + 0x280))[i + 0x49];
        if (v >= 1) {
            void *e = **(void ***)(p + 0x15C + v * 4);
            int x = POKE_TOOL_GetPartyValue(e, 5, 0);
            int y = POKE_TOOL_GetPartyValue(e, 6, 0);
            if (a == x && q[8] == 0) {
                return 2;
            }
            if (b == y && b != 0 && q[9] == 0) {
                return 3;
            }
        }
        i = i + 1;
    } while (i < 6);
    if (p[0x105] == q[3]) {
        return 4;
    }
    return 0;
}
