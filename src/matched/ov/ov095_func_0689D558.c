/*
 * function: BTL_POSPOKE_GetEmptyPosList
 * address:  0x0689D558
 * packet:   pkt_ov095_0689D558
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTL_POSPOKE_GetEmptyPosList  0x0689D558  thumb
 *
 * Unlabelled leaf (push {r3-r6}, no lr) after BTL_POSPOKE_UpdatePosOfPoke in the handed
 * extent.  Collects the indices of the 3-byte records whose first byte is
 * non-zero, second byte equals `key` and third byte is 0x1f; returns the count.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 BTL_POSPOKE_GetEmptyPosList(u8 *a, int key, u8 *out)
{
    u32 n;
    u32 i;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (a[i * 3] != 0 && key == a[i * 3 + 1] && a[i * 3 + 2] == 0x1f)
            out[n++] = i;
    }
    return n;
}
