/*
 * function: G3X_GetMtxStackLevelPJ
 * address:  0x0207DE5C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (72 bytes, no relocation): the PJ sibling of
 * G3X_GetMtxStackLevelPV (same shape, mask 0x2000 shifted by 13).
 */

typedef unsigned int u32;

int G3X_GetMtxStackLevelPJ(u32 *out)
{
    volatile u32 *p = (volatile u32 *)0x04000600;
    if (*p & 0x4000)
        return -1;
    *out = (*p & 0x2000) >> 13;
    return 0;
}
