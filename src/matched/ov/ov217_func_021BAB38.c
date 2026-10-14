/*
 * function: func_021BAB38
 * address:  0x021BAB38
 * packet:   pkt_ov217_021BAB38
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 */

extern int PALETTE_ANIME_Restore(char *p);

void func_021BAB38(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Restore((char *)(*(int *)(self + i * 4 + 0x38)));
    }
}
