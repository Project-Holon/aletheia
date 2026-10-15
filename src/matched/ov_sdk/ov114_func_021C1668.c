/*
 * function: SslAuthCallback
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
 *   gsDebugFormat                    0x0217d254 arm  ov009
 *   sGhttpEncryptionFileName                       0x021ce7b0 data
 *   sFuncNameSslAuthCallback                       0x021ce686 data
 *   sGhttpSslReceivedCertficate                       0x021ce8f8 data
 *   sGhttpLSCnI                       0x021ce920 data
 *   sGhttpCertificateIsOutOfDate                       0x021ce93c data
 *   sGhttpSslServerNameDoesNot                       0x021ce970 data
 *   sGhttpSslNoRootCaInstalled                       0x021ce9ac data
 *   sGhttpSslBadSignatureDoNot                       0x021ce9e4 data
 *   sGhttpSslUnknownSignatureAlgorithm                       0x021cea14 data
 *   sGhttpSslUnknownPublicKeyAlrorithm                       0x021cea44 data
 */

typedef struct CPSSslConnection {
    char pad0[0x5b0];
    char subject[0x100];        /* +0x5b0 */
    char issuer[0x100];         /* +0x6b0 */
    char name[0x100];           /* +0x7b0 */
} CPSSslConnection;

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern char sGhttpEncryptionFileName[];       /* __FILE__ */
extern char sFuncNameSslAuthCallback[];       /* __FUNCTION__ */
extern char sGhttpSslReceivedCertficate[];
extern char sGhttpLSCnI[];
extern char sGhttpCertificateIsOutOfDate[];
extern char sGhttpSslServerNameDoesNot[];
extern char sGhttpSslNoRootCaInstalled[];
extern char sGhttpSslBadSignatureDoNot[];
extern char sGhttpSslUnknownSignatureAlgorithm[];
extern char sGhttpSslUnknownPublicKeyAlrorithm[];

int SslAuthCallback(int result, CPSSslConnection *con, int level)
{
    gsDebugFormat(8, (char *)4, 8, sGhttpSslReceivedCertficate, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 938);
    gsDebugFormat(8, (char *)4, 8, sGhttpLSCnI, level, con->issuer, con->name, con->subject);

    if (result & 0x8000) {
        gsDebugFormat(8, (char *)4, 2, sGhttpCertificateIsOutOfDate, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 946);
        result &= ~0x8000;
    }
    if (result & 0x4000) {
        gsDebugFormat(8, (char *)4, 2, sGhttpSslServerNameDoesNot, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 954);
        result &= ~0x4000;
    }

    switch (result & 0xff) {
    case 0:
        break;
    case 1:
        gsDebugFormat(8, (char *)4, 2, sGhttpSslNoRootCaInstalled, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 963);
        break;
    case 2:
        gsDebugFormat(8, (char *)4, 2, sGhttpSslBadSignatureDoNot, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 969);
        break;
    case 3:
        gsDebugFormat(8, (char *)4, 2, sGhttpSslUnknownSignatureAlgorithm, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 975);
        break;
    case 4:
        gsDebugFormat(8, (char *)4, 2, sGhttpSslUnknownPublicKeyAlrorithm, sGhttpEncryptionFileName, sFuncNameSslAuthCallback, 981);
        break;
    }
    return result;
}
