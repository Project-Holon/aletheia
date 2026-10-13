/*
 * function: FLD_SCENEAREA_SetData
 * address:  0x021AB634
 * packet:   pkt_ov021_021AB634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb
 */

typedef struct {
    int pad[2];
    int f8;
    int fc;
    int f10;
    int f14;
} S;

extern void FLD_SCENEAREA_ClearData(S *s);

void FLD_SCENEAREA_SetData(S *s, int a, int b, int c)
{
    FLD_SCENEAREA_ClearData(s);
    s->f8 = a;
    s->fc = c;
    s->f10 = b;
    s->f14 = -1;
}
