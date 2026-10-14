/*
 * function: POKETRADE_PROC_LoadSlotMonAlt
 * address: 0x021D8DD0
 * packet: pkt_ov119_021D8DD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007A18 0x02007A18 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 */
#include "../include/Obj00001.h"

struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, unsigned int box, unsigned int slot);
extern unsigned int POKEPARTY_GetCount(void *m);
typedef unsigned int   u32;
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *a);

void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = ((struct Obj00001 *)p)->f630;
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return func_02007A18(a, b, c);
        m = ((struct Obj00001 *)p)->f838;
        if (c < (int)POKEPARTY_GetCount(m) && c != -1)
            return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(m, c));
    }
    return 0;
}
