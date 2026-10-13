/*
 * function: func_02035010
 * address:  0x02035010
 * packet:   pkt_02035010
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *   func_02035004 0x02035004 arm
 *
 * Wrapper: calls func_02035004 with the object gUiState points at as the first argument.
 */

typedef unsigned int u32;

extern char *gUiState;
extern void func_02035004(char *o, u32 a, u32 b);

void func_02035010(u32 a, u32 b)
{
    func_02035004(gUiState, a, b);
}
