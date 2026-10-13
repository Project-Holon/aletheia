/*
 * function: func_021DD2B4
 * address:  0x021DD2B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD2D0  0x021DD2D0  thumb  ov170
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb  arm9
 *
 * Open the range, then feed the handle to the second call.
 */



typedef unsigned int   u32;
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
void func_021DD2B4(int a, int b, int c, int d, int e)
{
    int r = func_021DD2D0((void ***)a, c, b);
    if (r)
        POKE_TOOL_SetBoxValue((void *)r, d, e);
}
