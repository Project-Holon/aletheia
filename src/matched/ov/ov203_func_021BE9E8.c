/*
 * function: DEMO3D_DATA_DeleteCapture
 * address:  0x021BE9E8
 * packet:   pkt_021BE9E8
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DEMO3D_DATA_DeleteTask 0x021BEA48 thumb
 */

extern void DEMO3D_DATA_DeleteTask(int *s, unsigned a, unsigned b, unsigned c);

void DEMO3D_DATA_DeleteCapture(int a)
{
    DEMO3D_DATA_DeleteTask((int *)a, 1, 0, 1);
}
