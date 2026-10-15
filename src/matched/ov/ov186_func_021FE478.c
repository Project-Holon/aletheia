/*
 * function: BR_UTIL_StepLine
 * address: 0x021FE478
 * packet: pkt_ov186_021FE478
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { int x, y; } Pair;
int BR_UTIL_StepLine(int *p, Pair *out, int step)
{
    int done = 0;
    int progress = step - p[6];
    if (progress < 0)
        progress = 0;
    p[4] = p[0] + (p[2] - p[0]) * progress / p[7];
    p[5] = p[1] + (p[3] - p[1]) * progress / p[7];
    if (progress >= p[7]) {
        *(Pair *)(p + 4) = *(Pair *)(p + 2);
        done = 1;
    }
    if (out) {
        *out = *(Pair *)(p + 4);
    }
    return done;
}
