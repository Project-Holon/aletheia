/*
 * function: BTLV_GAUGE_IsLowHpBgmPlaying
 * address:  0x022088F4
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_GAUGE_IsLowHpBgmPlaying   0x022088F4  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    char pad[0x440];
    unsigned int a : 2;
    unsigned int f : 1;
} S88F4;

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(S88F4 *p)
{
    return p->f;
}

