/*
 * function: BILLBOARD_GetImagePlttKey
 * address:  0x0204F32C
 * packet:   pkt_0204F32C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
void BILLBOARD_GetImagePlttKey(int p0, int p1, int p2){ *(int *)p2 = *(int *)(((p1 * 0x28 + *(int *)(p0 + 4)) + 36)); }
