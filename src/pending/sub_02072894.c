/*
 * function: sub_02072894
 * address:  0x02072894
 * packet:   pkt_02072894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_0214BAC0  0x0214BAC0  data
 *   g_0214BB00  0x0214BB00  data
 *
 * capped at MATCH: one unresolved relocation site.
 *   unresolved: 0208A0A4 (arm, from name) has no witness outside
 *               02072894..020728E8
 * class: label. The only branch to 0x0208A0A4 in the image is this file's own
 * call, so the site stays wildcarded until 0x0208A0A4 is itself a manifest
 * entry (it is not in this lane's target list). Everything else is
 * byte-correct: 84 compiled bytes, 84 original, 3 relocation sites, 2 resolved
 * (g_0214BAC0 x10, g_0214BB00 x5 - both literal class).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02072894.c \
 *       --func sub_02072894 --addr 0x02072894 --cc 1.1p1 --arm
 */

typedef signed char s8;

extern s8 g_0214BAC0;
extern unsigned char g_0214BB00[];

int sub_0208A0A4(void *p, int a0, int a1, int a2);

int sub_02072894(int a0, int a1, int a2)
{
    void *p;

    if (g_0214BAC0 < 0) {
        p = 0;
    } else {
        p = (void *)(g_0214BB00 + g_0214BAC0 * 0x11E0);
    }
    if (p == 0) return 0;
    return sub_0208A0A4(p, a0, a1, a2);
}
