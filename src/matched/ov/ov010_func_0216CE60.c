/*
 * function: FLDMMDL_AddMmdl
 * address:  0x0216CE60
 * packet:   pkt_0216CE60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_AddMmdlCore  0x0216CDC4  thumb
 */

void FLDMMDL_AddMmdlCore(int a, int b, int c, int d);

void FLDMMDL_AddMmdl(int a, int b, int c)
{
    FLDMMDL_AddMmdlCore(a, b, c, 0);
}
