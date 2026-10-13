/*
 * function: GIMMICK43_GetLiftAnimeIndex
 * address:  0x021F3FBC
 * packet:   pkt_ov043_021F3FBC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from GIMMICK43_LiftEventMain. The result goes through
 * the local r: four direct returns invert the first arm's branch (3 bytes).
 *
 * symbols:
 *   sGimmick43LiftAnimeFlip     0x021F4328  data  ov043
 */

extern int sGimmick43LiftAnimeFlip[];

int GIMMICK43_GetLiftAnimeIndex(int *a, int i)
{
    int r;

    if (a[i]) {
        if (sGimmick43LiftAnimeFlip[i]) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if (sGimmick43LiftAnimeFlip[i]) {
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}
