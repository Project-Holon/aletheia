/*
 * function: POKETRADE_PROC_RecvMonChunk0
 * address:  0x021D90AC
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 *
 * symbols:
 *   POKETRADE_PROC_RecvMonChunkCommon  0x021D9038  thumb  ov119
 */

extern int POKETRADE_PROC_RecvMonChunkCommon(int a, int b, int c, int d, int e, int f);

int POKETRADE_PROC_RecvMonChunk0(int a, int b, int c, int d, int e)
{
    return POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 0);
}

