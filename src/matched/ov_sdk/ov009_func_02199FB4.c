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
 *   gNatNegCancelNotFoundFmt               0x021A5E2C data
 *   gNatNegCancelFmt               0x021A5E5C data
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
extern char gNatNegCancelNotFoundFmt[];
extern char gNatNegCancelFmt[];

void NNCancel(int cookie)
{
    struct _NATNegotiator *neg = FindNegotiatorForCookie(cookie);

    if (neg == 0) {
        gsDebugFormat(7, 4, 4, gNatNegCancelNotFoundFmt, cookie);
        return;
    }
    gsDebugFormat(7, 4, 8, gNatNegCancelFmt, cookie);
    if (neg->sock != -1) {
        closesocket(neg->sock);
        neg->sock = -1;
    }
    neg->f1c = 6;
}
