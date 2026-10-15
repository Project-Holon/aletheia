/*
 * function: SHINKA_DEMO_GRAPHIC_Update
 * address:  0x02205A10
 * packet:   pkt_02205A10
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_GRAPHIC_Update3d 0x02205C58 thumb ov195
 */

extern void SHINKA_DEMO_GRAPHIC_Update3d(char *a);

void SHINKA_DEMO_GRAPHIC_Update(char *a)
{
    SHINKA_DEMO_GRAPHIC_Update3d(a + 8);
}
