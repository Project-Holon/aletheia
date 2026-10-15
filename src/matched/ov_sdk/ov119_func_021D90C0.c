/*
 * function: POKETRADE_PROC_RecvMonChunk1
 * address:  0x021D90C0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWCi_EncSessionGetReuseHashAsync: sixth argument is one.
 *
 * symbols:
 *   POKETRADE_PROC_RecvMonChunkCommon  0x021D9038  thumb  ov119
 */

extern int POKETRADE_PROC_RecvMonChunkCommon(int a, int b, int c, int d, int e, int f);

int POKETRADE_PROC_RecvMonChunk1(int a, int b, int c, int d, int e)
{
    return POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 1);
}

