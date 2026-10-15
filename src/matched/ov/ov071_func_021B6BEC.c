/*
 * function: MONOLITH_TOOL_HighlightButtonFlash
 * address:  0x021B6BEC
 * packet:   pkt_ov071_021B6BEC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   MONOLITH_TOOL_SetHighlightMode  0x021B6DB4  thumb  ov071
 */

typedef unsigned int   u32;
struct Obj;
void MONOLITH_TOOL_HighlightButtonFlash(void *p, int *tbl, int n, int sel, int c)
{
    void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
    void MONOLITH_TOOL_SetHighlightMode(int *p, int a, int idx);
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            CLACT_SetActorPaletteOffset((struct Obj *)tbl[i * 4], 1, 1);
            MONOLITH_TOOL_SetHighlightMode(p, 2, c);
        } else {
            CLACT_SetActorPaletteOffset((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
}
