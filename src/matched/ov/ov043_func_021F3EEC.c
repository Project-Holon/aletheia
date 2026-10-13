/*
 * function: GIMMICK43_IsInLiftZone
 * address:  0x021F3EEC
 * packet:   pkt_ov043_021F3EEC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from GIMMICK43_LiftEventMain. Each field gets its own
 * pool word (sGimmick43LiftZones + 0/8/4/C). The loads must be written in field
 * order x, y, w, h: loading w before y swaps the index and value registers
 * (17 bytes).
 *
 * symbols:
 *   sGimmick43LiftZones  0x021F4480  data  ov043
 */

typedef unsigned char u8;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int a;
    int b;
} R;

extern R sGimmick43LiftZones[];

int GIMMICK43_IsInLiftZone(u8 i, int x, int y)
{
    int x0;
    int y0;
    int w;
    int h;

    x0 = sGimmick43LiftZones[i].x;
    y0 = sGimmick43LiftZones[i].y;
    w = sGimmick43LiftZones[i].w;
    h = sGimmick43LiftZones[i].h;
    if (x0 <= x && x <= x0 + w - 1 && y0 <= y && y <= y0 + h - 1) {
        return 1;
    }
    return 0;
}
