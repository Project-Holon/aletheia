/*
 * function: FLDMMDL_MOVE_GridToVectorPos
 * address:  0x02164280
 * packet:   pkt_ov010_02164280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p)
{
    p[0] = (x << 16) + 0x8000;
    p[2] = (y << 16) + 0x8000;
}
