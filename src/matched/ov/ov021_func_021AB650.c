/*
 * function: FLD_SCENEAREA_ClearData
 * address:  0x021AB650
 * packet:   pkt_ov021_021AB650
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef struct {
    int pad[2];
    int f8;
    int fc;
    int f10;
    int f14;
} S;

void FLD_SCENEAREA_ClearData(S *s)
{
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = -1;
}
