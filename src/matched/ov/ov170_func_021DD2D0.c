/*
 * function: BOX2_MAIN_GetMonAt
 * address:  0x021DD2D0
 * packet:   pkt_ov170_021DD2D0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   func_02007A18 0x02007A18 thumb
 */

extern unsigned POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, unsigned i);
extern int POKE_TOOL_CastToBoxParam(void *p);
typedef unsigned int   u32;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b)
{
    if (a == 0xFF || b >= 0x1E) {
        if (b >= 0x1E)
            b -= 0x1E;
        if (POKEPARTY_GetCount((*p)[2]) > b)
            return POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember((*p)[2], b));
    } else if (b != 0xFF) {
        return (int)func_02007A18((*p)[1], a, b);
    }
    return 0;
}
