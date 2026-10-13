/*
 * function: FIELDMAP_DrawEnd
 * address:  0x021890AC
 * packet:   pkt_ov021_021890AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   sDrawEndFuncs     0x021D35B4  data  a4
 */

typedef int (*Fn)(unsigned char *p);

extern Fn sDrawEndFuncs[];
void G3D_SYSTEM_DrawEnd(int x);

void FIELDMAP_DrawEnd(unsigned char *p)
{
    G3D_SYSTEM_DrawEnd(sDrawEndFuncs[*(int *)(p + 0x12C)](p));
}
