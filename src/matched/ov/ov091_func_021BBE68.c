/*
 * function: func_021BBE68
 * address:  0x021BBE68
 * packet:   pkt_021BBE68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *
 * blocker: target 0x0202822C has no `func_`/`sub_` label in the listings
 * (no witness at all), and no branch outside this 12-byte range reaches it,
 * so the `bl` site cannot be resolved.  All bytes are correct.
 
 *
 * DUPLICATE: src/matched/func_021BBE68.c (packet pkt_021BBE68) is the
 * promoted EXACT entry for this address; this copy shares the same packet
 * and is left parked so the address is not sharded twice.
*/

void APP_TASKMENU_WIN_SetDecide(char *p, int v);

void func_021BBE68(int p, int v)
{
    if (p) {
        APP_TASKMENU_WIN_SetDecide((char *)p, v);
    }
}
