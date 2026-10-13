/*
 * function: SCRCMD_WORK_AddAnimeTask
 * address:  0x0215A6DC
 * packet:   pkt_ov010_0215A6DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores v in the first zero word among the eight slots at +0x14 of the
 * object at +0x20.
 *
 * symbols:
 *   (none)
 */

void SCRCMD_WORK_AddAnimeTask(int *p, int v)
{
    int i;
    int *e;
    int *q;

    q = (int *)p[8];
    for (i = 0; i < 8; i++) {
        e = q + i;
        if (e[5] == 0) {
            e[5] = v;
            return;
        }
    }
}
