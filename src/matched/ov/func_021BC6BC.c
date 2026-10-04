/*
 * function: func_021BC6BC
 * address:  0x021BC6BC
 * packet:   pkt_021BC6BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021D50 0x02021D50  thumb
 *
 * Loads the word at +8 and tail-calls the function at 0x02021D51 (the thumb
 * address of the ARM9 function at 0x02021D50).
 *
 */

struct S02021D50;
extern void func_02021D50(struct S02021D50 *p);

void func_021BC6BC(char *p)
{
    func_02021D50((struct S02021D50 *)(*(int *)(p + 8)));
}
