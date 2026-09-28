/*
 * function: NNCancel
 * address:  0x02199FB4
 * packet:   pkt_ov009_02199FB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NNCancel (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   FindNegotiatorForCookie  0x021990D4 arm
 *   gsDebugFormat            0x0217D254 arm
 *   closesocket              0x0217EB2C arm
 *   g_021A5E2C               0x021A5E2C data
 *   g_021A5E5C               0x021A5E5C data
 */

typedef unsigned char u8;

struct _NATNegotiator
{
    u8 pad0[0x18];
    int sock;                /* +0x18 */
    int f1c;                 /* +0x1c */
};

extern struct _NATNegotiator * FindNegotiatorForCookie(int cookie);
extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern int closesocket(int sock);
extern char g_021A5E2C[];
extern char g_021A5E5C[];

void NNCancel(int cookie)
{
    struct _NATNegotiator *neg = FindNegotiatorForCookie(cookie);

    if (neg == 0) {
        gsDebugFormat(7, 4, 4, g_021A5E2C, cookie);
        return;
    }
    gsDebugFormat(7, 4, 8, g_021A5E5C, cookie);
    if (neg->sock != -1) {
        closesocket(neg->sock);
        neg->sock = -1;
    }
    neg->f1c = 6;
}
