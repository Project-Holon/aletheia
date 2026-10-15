/*
 * function: ghiEncryptorSslCleanupFunc
 * address:  0x021C1C98
 * packet:   pkt_ov114_021C1C98
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021CE7B0    0x021CE7B0  data  a4
 *   sFuncNameGhiEncryptorSslCleanupFunc    0x021CE713  data  a1
 *   sGhttpGamespySslTwlEngineCleanup    0x021CED3C  data  a4
 *   gsifree 0x0217EAE0  arm
 *   gsDebugFormat 0x0217D254  arm
 */

extern char d_021CE7B0[];
extern char sFuncNameGhiEncryptorSslCleanupFunc[];
extern char sGhttpGamespySslTwlEngineCleanup[];

extern void gsifree(void *);
extern void gsDebugFormat(int, int, int, void *, ...);

int ghiEncryptorSslCleanupFunc(int unused, unsigned int *p)
{
    gsDebugFormat(8, 4, 0xf, sGhttpGamespySslTwlEngineCleanup, d_021CE7B0, sFuncNameGhiEncryptorSslCleanupFunc, 0x4d5);
    if (p != 0) {
        unsigned int *q = (unsigned int *)p[0];
        if (q != 0) {
            if (q[0] != 0)
                gsifree((void *)q[0]);
            gsifree(q);
            p[0] = 0;
        }
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
    return 1;
}
