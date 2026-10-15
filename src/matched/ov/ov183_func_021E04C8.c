/*
 * function: BR_CODEIN_CodeHitTestOptions
 * address:  0x021E04C8
 * packet:   pkt_ov183_021E04C8
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   g_021E3808     0x021E3808  data  ov183
 */
typedef struct Rect { unsigned int x0, y0, x1, y1; } Rect;

typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern Rect g_021E3808[];

int BR_CODEIN_CodeHitTestOptions(void)
{
    unsigned int x, y;
    int i;

    if (TOUCHPANEL_GetPointTrg(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}
