/*
 * function: FIELD_G3D_MAP_GetTextureRes
 * address:  0x02169578
 * packet:   pkt_ov010_02169578
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: forwarding tail call to FIELD_G3D_MAP_PickTextureRes.
 *
 * symbols:
 *   FIELD_G3D_MAP_PickTextureRes  0x02169A68  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *FIELD_G3D_MAP_PickTextureRes(int a0);

int FIELD_G3D_MAP_GetTextureRes(unsigned char *a)
{
    return (int)FIELD_G3D_MAP_PickTextureRes((int)a);
}
