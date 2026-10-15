/*
 * function: SHINKA_DEMO_GRAPHIC_DrawEnd
 * address:  0x02205A1C
 * packet:   pkt_02205A1C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_GRAPHIC_Draw3dEnd 0x02205C6C thumb ov195
 */

extern void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *);

void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a)
{
    SHINKA_DEMO_GRAPHIC_Draw3dEnd(a + 8);
}
