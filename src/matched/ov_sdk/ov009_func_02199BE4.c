/*
 * function: CheckNatifyStatus
 * address:  0x02199BE4
 * packet:   pkt_ov009_02199BE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CheckNatifyStatus (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   current_time       0x0217F264  arm  ov009
 *   NatifyThink        0x02198E74  arm  ov009
 *   DetermineNatType   0x02198E80  arm  ov009
 *   closesocket        0x0217EB2C  arm  ov009
 *   gNatnegGlobals         0x021AE698  data
 *   gNatNegNat         0x021AE6C8  data
 *   gNatSocks         0x021A5A70  data
 */

#include "../include/G_NatSocks.h"

typedef unsigned int u32;

typedef struct NAT
{
    char pad0[0x8C];
    int natType;
    int mappingScheme;
    char pad1[0x44];
} NAT;

typedef struct NatifyState
{
    int negotiateList;
    int pad;
    int natMappingScheme;
    void (*natifyCallback)(int success, NAT nat);
    u32 natifyStartTime;
} NatifyState;

typedef struct NatSocks NatSocks;

extern u32 current_time(void);
extern int NatifyThink();
extern int DetermineNatType();
extern int closesocket();
extern NatifyState gNatnegGlobals;
extern NAT gNatNegNat;
extern struct NatSocks gNatSocks;

int CheckNatifyStatus(int sock)
{
    int active = 1;
    int success;

    if (sock != -1)
    {
        if (current_time() - gNatnegGlobals.natifyStartTime < 10000)
            active = NatifyThink(sock, &gNatNegNat);
        else
            active = 0;
        if (active)
            goto done;
        success = DetermineNatType(&gNatNegNat);
        gNatnegGlobals.natifyCallback(success, gNatNegNat);
        gNatSocks.natType = gNatNegNat.natType;
        gNatnegGlobals.natMappingScheme = gNatNegNat.mappingScheme;
        if (gNatSocks.mappingSock != -1)
        {
            closesocket();
            gNatSocks.mappingSock = -1;
        }
        if (gNatSocks.ertSock != -1)
        {
            closesocket();
            gNatSocks.ertSock = -1;
        }
    }
done:
    return active;
}
