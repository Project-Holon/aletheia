/*
 * function: POKETRADE_PROC_CanTradeMon
 * address: 0x021DD0CC
 * packet: pkt_ov119_021DD0CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   POKE_REGULATION_IsInSpeciesTable 0x02019D84 thumb
 *   gTradeableSpecies 0x021E7718 data ov119 a4
 */
#include "../include/Obj22737.h"
typedef unsigned int   u32;
struct Sav;
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern int POKE_REGULATION_IsInSpeciesTable(unsigned short);
extern const int gTradeableSpecies[];
int POKETRADE_PROC_CanTradeMon(char *p, int a)
{
    int v, lock, r;
    unsigned i;
    v = POKE_TOOL_GetBoxValue((void *)a,5,0);
    i = 0;
    if (((struct Obj22737 *)p)->f118C == 3) {
        lock = POKE_TOOL_DecodeBoxParam((struct Sav *)a);
        for (; i < 15; i++) {
            r = POKE_TOOL_GetBoxValue((void *)a,gTradeableSpecies[i],0);
            if (r == 1) break;
        }
        POKE_TOOL_EncodeBoxParam((struct Sav *)a,lock);
        if (r) return 1;
        if (POKE_REGULATION_IsInSpeciesTable(v)) return 1;
    }
    return 0;
}
