/*
 * function: func_02035040
 * address:  0x02035040
 * packet:   pkt_02035040
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *   func_02035034 0x02035034 arm
 *
 * Wrapper: calls func_02035034 with the object gUiState points at as the first argument.
 */

typedef unsigned int u32;

extern char *gUiState;
extern void func_02035034(char *o, u32 a, u32 b);

void func_02035040(u32 a, u32 b)
{
    func_02035034(gUiState, a, b);
}
