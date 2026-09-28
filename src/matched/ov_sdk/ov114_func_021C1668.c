/*
 * function: func_021C1668
 * address:  0x021C1668
 * packet:   pkt_ov114_021C1668
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SslAuthCallback (ghttpencryption.o, static)
 *
 * symbols:
 *   func_0217D254                    0x0217d254 arm  ov009
 *   g_021CE7B0                       0x021ce7b0 data
 *   g_021CE686                       0x021ce686 data
 *   g_021CE8F8                       0x021ce8f8 data
 *   g_021CE920                       0x021ce920 data
 *   g_021CE93C                       0x021ce93c data
 *   g_021CE970                       0x021ce970 data
 *   g_021CE9AC                       0x021ce9ac data
 *   g_021CE9E4                       0x021ce9e4 data
 *   g_021CEA14                       0x021cea14 data
 *   g_021CEA44                       0x021cea44 data
 */

typedef struct CPSSslConnection {
    char pad0[0x5b0];
    char subject[0x100];        /* +0x5b0 */
    char issuer[0x100];         /* +0x6b0 */
    char name[0x100];           /* +0x7b0 */
} CPSSslConnection;

extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern char g_021CE7B0[];       /* __FILE__ */
extern char g_021CE686[];       /* __FUNCTION__ */
extern char g_021CE8F8[];
extern char g_021CE920[];
extern char g_021CE93C[];
extern char g_021CE970[];
extern char g_021CE9AC[];
extern char g_021CE9E4[];
extern char g_021CEA14[];
extern char g_021CEA44[];

int func_021C1668(int result, CPSSslConnection *con, int level)
{
    func_0217D254(8, 4, 8, g_021CE8F8, g_021CE7B0, g_021CE686, 938);
    func_0217D254(8, 4, 8, g_021CE920, level, con->issuer, con->name, con->subject);

    if (result & 0x8000) {
        func_0217D254(8, 4, 2, g_021CE93C, g_021CE7B0, g_021CE686, 946);
        result &= ~0x8000;
    }
    if (result & 0x4000) {
        func_0217D254(8, 4, 2, g_021CE970, g_021CE7B0, g_021CE686, 954);
        result &= ~0x4000;
    }

    switch (result & 0xff) {
    case 0:
        break;
    case 1:
        func_0217D254(8, 4, 2, g_021CE9AC, g_021CE7B0, g_021CE686, 963);
        break;
    case 2:
        func_0217D254(8, 4, 2, g_021CE9E4, g_021CE7B0, g_021CE686, 969);
        break;
    case 3:
        func_0217D254(8, 4, 2, g_021CEA14, g_021CE7B0, g_021CE686, 975);
        break;
    case 4:
        func_0217D254(8, 4, 2, g_021CEA44, g_021CE7B0, g_021CE686, 981);
        break;
    }
    return result;
}
