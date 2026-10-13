/*
 * unit:     no
 * function: POKEGRA_RegisterPalettePP
 * address:  0x0202D8D0
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   POKEGRA_RegisterPalette  0x0202D7D8  thumb
 */

typedef unsigned int   u32;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_IsBoxShiny(void *p);
extern int POKEGRA_RegisterPalette(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                          unsigned short a8, unsigned short a9);

int POKEGRA_RegisterPalettePP(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9)
{
    int v1 = func_02017E88(a1, 5, 0);
    int v2 = func_02017E88(a1, 0x6f, 0);
    int v3 = func_02017E88(a1, 0x6e, 0);
    int v4 = POKE_TOOL_IsBoxShiny(a1);
    int v5 = func_02017E88(a1, 0x4c, 0);

    return POKEGRA_RegisterPalette(a0, v1, v2, v3, v4, a2, v5, a3, a8, a9);
}
