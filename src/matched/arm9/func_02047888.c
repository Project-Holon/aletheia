/*
 * function: G3D_SYSTEM_GetObjectAnimeFrameMax
 * address:  0x02047888
 * packet:   pkt_02047888
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Looks up entry idx of the table at a[2]; on a hit stores the u16 at
 * entry->f4->f8->f4 shifted to 20.12 fixed point and returns 1.  Filed as the
 * witness for ov021 FLDEFF_BUBBLE_Update.
 */

typedef unsigned short u16;

int G3D_SYSTEM_GetObjectAnimeFrameMax(int *a, int idx, int *out)
{
    int *p = ((int **)a[2])[idx];
    if (p == 0) {
        return 0;
    }
    *out = ((u16 *)((int *)p[1])[2])[2] << 12;
    return 1;
}
