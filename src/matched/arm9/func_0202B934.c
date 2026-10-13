/*
 * function: func_0202B934
 * address:  0x0202B934
 * packet:   pkt_0202B934
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C4E34
 * (wave A1, lane 13).
 *
 * symbols:
 *   ISS_3DS_SYS_SetSourcePosImpl  0x0202BA7C  thumb
 */

typedef struct { int x, y, z; } V3;

extern void ISS_3DS_SYS_SetSourcePosImpl(void *m, int i, const V3 *v);

void func_0202B934(void *m, int i, const V3 *v)
{
    ISS_3DS_SYS_SetSourcePosImpl(m, i, v);
}
