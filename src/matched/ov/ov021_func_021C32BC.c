/*
 * function: SODATEYA_ReturnHeldItem
 * address:  0x021C32BC
 * packet:   pkt_ov021_021C32BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the Pokemon's held item to the bag when it fits.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetGameSystem(void *p);
struct Blk37;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

void SODATEYA_ReturnHeldItem(void **p, void *mon)
{
    void *bag = func_0200CA1C(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(p[1])));

    if (func_0200CED4(bag, POKE_TOOL_GetPartyValue(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}
