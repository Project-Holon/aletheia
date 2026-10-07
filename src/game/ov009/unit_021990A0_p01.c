/*
 * file:     unit_021990A0_p01.c
 * unit:     yes
 * function: func_021991C8, func_0219922C, func_02199284, func_021992A8
 * address:  0x021991C8
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
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 *   g_021AE698  0x021AE698  data
 *   ArrayLength    0x02184200 arm
 *   gsDebugFormat  0x0217D254 arm
 *   ArrayFree      0x021841B0 arm
 *   negotiateList  0x021AE698 data
 *   g_021A5A84     0x021A5A84 data
 *   g_021A5A7C  0x021A5A7C  data
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 */
#include "../../matched/include/G_Magic6.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
struct SOCSockAddr;
typedef struct _NATNegotiator {
    int state;
    int cookie;
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

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_02184324(void *array, int n);
extern int ArrayLength(void *array);
extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void ArrayFree(struct DArrayImplementation *array);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
void func_021991C8(NATNegotiator *neg);
void NNFreeNegotiateList(void);
int func_02199284(const u8 *a);
void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern void *g_021AE698;
extern struct DArrayImplementation * negotiateList;
extern char g_021A5A84[];
extern struct Magic6 g_021A5A7C;


/*
 * sdk:      RemoveNegotiator (natneg.o)
 */
void func_021991C8(NATNegotiator *neg)
{
    int i;

    for (i = 0; i < func_02184200(g_021AE698); i++) {
        if (neg == func_02184208(g_021AE698, i)) {
            func_02184324(g_021AE698, i);
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
