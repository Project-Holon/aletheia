/*
 * function: BTLV_GAUGE_SetLowHpBgmPlaying
 * address:  0x02208900
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_GAUGE_SetLowHpBgmPlaying   0x02208900  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    char pad[0x440];
    unsigned int a : 2;
    unsigned int b : 1;
} S8900;

void BTLV_GAUGE_SetLowHpBgmPlaying(S8900 *p, int v)
{
    p->b = v;
}

