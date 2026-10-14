/*
 * function: BTLV_MCSS_Draw
 * address:  0x021FEE9C
 * packet:   pkt_021FEE9C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_Draw  0x02014D2C  thumb
 */

struct McssSys;
void MCSS_Draw(struct McssSys *sys);

void BTLV_MCSS_Draw(int *p)
{
    MCSS_Draw((struct McssSys *)p[1]);
}
