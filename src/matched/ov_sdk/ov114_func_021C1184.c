/*
 * function: ghiEncyptorSetRootCAList
 * address:  0x021C1184
 * packet:   pkt_ov114_021C1184
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * `done:` return path matches as a goto; the extent reads EXACT* because
 * the unlabelled follower at 0x021C1210 is a 4-byte veneer pair, not part
 * of this function (report to the integrator, do not seed starts).
 *
 * symbols:
 *   d_021CE758    0x021CE758  data  a4
 *   d_021CE75C    0x021CE75C  data  a4
 *   d_021CE7B0    0x021CE7B0  data  a4
 *   sFuncNameGhiEncyptorSetRootCAList    0x021CE6AE  data  a1
 *   strcmp 0x020948E0  arm
 *   ghiEncryptorSetTwlRootCA 0x021C137C  arm
 *   gsDebugFormat 0x0217D254  arm
 */

extern char d_021CE758[];
extern char d_021CE75C[];
extern char d_021CE7B0[];
extern char sFuncNameGhiEncyptorSetRootCAList[];

extern int strcmp(const char *s1, const char *s2);
extern int ghiEncryptorSetTwlRootCA(char *url, void *theRootCAList);
extern void gsDebugFormat(int, int, int, void *, ...);

int ghiEncyptorSetRootCAList(int ctx, int arg)
{
    if (arg != 0 && ctx != 0) {
        if (strcmp((const char *)ctx, d_021CE758) != 0)
            goto done;
    }
    gsDebugFormat(8, 4, 1, d_021CE75C, d_021CE7B0, sFuncNameGhiEncyptorSetRootCAList, 0x74, ctx, arg);
    return 0;
done:
    return ghiEncryptorSetTwlRootCA((char *)ctx, (void *)arg);
}
