/*
 * function: SAVEDATA_SetFailHook
 * address:  0x02034704
 * packet:   pkt_02034704
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_0214699C   0x0214699C  data  a4
 */

typedef unsigned int u32;

extern u32 d_0214699C[];

void SAVEDATA_SetFailHook(u32 v)
{
    d_0214699C[3] = v;
}
