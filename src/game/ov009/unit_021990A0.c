/*
 * file:     unit_021990A0.c
 * unit:     yes
 * function: func_021990A0, func_021990D4, func_02199138, func_021991C8, func_0219922C, func_02199284, func_021992A8
 * address:  0x021990A0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217F264     0x0217F264  arm  ov009
 *   func_0217F790     0x0217F790  arm  ov009
 *   func_0217F7AC     0x0217F7AC  arm  ov009
 *   negotiateList     0x021AE698  data
 *   Matchup3Hostname  0x021AE69C  data
 *   natMappingScheme  0x021AE6A0  data
 *   natifyCallback    0x021AE6A4  data
 *   natifyStartTime   0x021AE6A8  data
 *   ClientUniqueID    0x021AE6AC  data
 *   Matchup2Hostname  0x021AE6B0  data
 *   Matchup1Hostname  0x021AE6B4  data
 *   activeNatify      0x021AE6B8  data
 *   matchup3ip        0x021AE6BC  data
 *   matchup2ip        0x021AE6C0  data
 *   matchup1ip        0x021AE6C4  data
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   gsDebugFormat  0x0217D254 arm
 *   ArrayFree      0x021841B0 arm
 *   g_021A5A84     0x021A5A84 data
 *   g_021A5A7C  0x021A5A7C  data
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 */
#include "../../matched/include/G_Magic6.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
struct DArrayImplementation;
struct _NAT;
struct SOCSockAddr;
typedef struct DArrayImplementation *DArray;

typedef enum { NAT_MAPPING_UNKNOWN } NatMappingScheme;

typedef struct _NATNegotiator {
    int state;
    int cookie;
    int data[0x13];
} NATNegotiator;

typedef unsigned char u8;

struct DArrayImplementation
{
    int count;
};

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

extern unsigned int func_0217F264(void);
extern void func_0217F790(unsigned long seed);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern int ArrayLength(void *array);
extern void *func_02184208(void *array, int n);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_02184234(void *array, void *newElem);
extern void func_02184324(void *array, int n);
extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void ArrayFree(struct DArrayImplementation *array);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
int func_021990A0(void);
NATNegotiator *func_021990D4(int cookie);
NATNegotiator *func_02199138(void);
void func_021991C8(NATNegotiator *neg);
void NNFreeNegotiateList(void);
int func_02199284(const u8 *a);
void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern struct DArrayImplementation * negotiateList;
extern char g_021A5A84[];
extern struct Magic6 g_021A5A7C;



unsigned int matchup2ip = 0;


unsigned int matchup3ip = 0;


static int activeNatify = 0;


char *Matchup1Hostname = 0;


char *Matchup2Hostname = 0;


int ClientUniqueID = 0;


static unsigned int natifyStartTime = 0;


void (*natifyCallback)(int, struct _NAT) = 0;


static NatMappingScheme natMappingScheme = 0;


char *Matchup3Hostname = 0;


DArray negotiateList = 0;


unsigned int matchup1ip = 0;



int func_021990A0(void)
{
    if (ClientUniqueID == 0)
    {
        func_0217F790(func_0217F264());
        ClientUniqueID = func_0217F7AC(1, 0x7fffffff);
    }
    return ClientUniqueID;
}



NATNegotiator *func_021990D4(int cookie)
{
    int i;
    NATNegotiator *neg;

    if (!negotiateList)
        return 0;
    for (i = 0; i < ArrayLength(negotiateList); i++) {
        neg = (NATNegotiator *)func_02184208(negotiateList, i);
        if (neg->cookie == cookie)
            return neg;
    }
    return 0;
}



/*
 * sdk:      AddNegotiator (natneg.o)
 */
NATNegotiator *func_02199138(void)
{
    NATNegotiator _neg = {0};

    if (!negotiateList)
        negotiateList = func_02184144(sizeof(NATNegotiator), 4, 0);
    func_02184234(negotiateList, &_neg);
    return (NATNegotiator *)func_02184208(negotiateList, ArrayLength(negotiateList) - 1);
}




/*
 * sdk:      RemoveNegotiator (natneg.o)
 */
void func_021991C8(NATNegotiator *neg)
{
    int i;

    for (i = 0; i < ArrayLength(negotiateList); i++) {
        if (neg == func_02184208(negotiateList, i)) {
            func_02184324(negotiateList, i);
            return;
        }
    }
}




void NNFreeNegotiateList(void)
{
    if (negotiateList == 0)
        return;
    gsDebugFormat(7, 3, 8, g_021A5A84, ArrayLength(negotiateList));
    ArrayFree(negotiateList);
    negotiateList = 0;
}




/*
 * Set when the six-byte test of the object at 0x021A5A7C fails.
 */
int func_02199284(const u8 *a)
{
    return func_020923F0(a, (const u8 *)((char *)&g_021A5A7C), 6) == 0;
}




/*
 * sdk:      SendPacket (natneg.o)
 */
void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len)
{
    SOCSockAddrIn saddr;

    saddr.family = 2;
    saddr.port = SWAP16(toport);
    saddr.addr = toaddr;
    func_0217ECA4(sock, data, len, 0, (struct SOCSockAddr *)(&saddr), 8);
}
