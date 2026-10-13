/*
 * file:     dwc_match_15.c
 * unit:     yes
 * function: func_02176984, func_021769E0, func_02176A8C, func_02176AA8, func_02176ABC, func_02176B34
 * address:  0x02176984
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
 *   func_021684CC  0x021684CC  arm
 *   sub_02095EAC   0x02095EAC  arm
 *   g_021A21C8     0x021A21C8  data
 *   g_021A21E8     0x021A21E8  data
 *   g_021A2208     0x021A2208  data
 *   g_021A222C     0x021A222C  data
 *   g_021A224C     0x021A224C  data
 *   g_021A2280     0x021A2280  data
 *   g_021A22C4     0x021A22C4  data
 *   g_021A22F0     0x021A22F0  data
 *   g_021A2324     0x021A2324  data
 *   g_021A2340     0x021A2340  data
 *   g_021AAA20  0x021AAA20  data
 *   func_0219D158  0x0219D158  arm  ov009
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A2164     0x021A2164  data
 *   g_021A21BC     0x021A21BC  data
 *   g_021A20D4     0x021A20D4  data
 *   g_021A20E0     0x021A20E0  data
 *   g_021A217C     0x021A217C  data
 *   DWCi_GetMatchCnt      0x02175F3C arm
 *   NNCancel              0x02199FB4 arm
 *   NNFreeNegotiateList   0x0219922C arm
 */
#include "../../matched/include/G_NNThinkGlobal.h"

typedef unsigned int   u32;

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x618];
    int nnCookie;            /* +0x618 */
};

extern int func_021684CC(char *key, char *value, char *string, char separator);
extern u32 sub_02095EAC(u32 a0, u32 *a1, u32 mode);
extern unsigned long long func_020870D0(int a);
extern int func_02175F3C(void);
extern void func_0219D158(int keyid, char *key);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void NNCancel(int cookie);
extern void NNFreeNegotiateList(void);
unsigned char func_02176984(char *a0);
char *func_021769E0(unsigned char denyReason);
void func_02176A8C(int a, int b);
void func_02176AA8(int v);
void func_02176ABC(void);
void DWCi_NNFreeNegotiateList(void);
extern char g_021A21C8[];
extern char g_021A21E8[];
extern char g_021A2208[];
extern char g_021A222C[];
extern char g_021A224C[];
extern char g_021A2280[];
extern char g_021A22C4[];
extern char g_021A22F0[];
extern char g_021A2324[];
extern char g_021A2340[];
extern struct NNThinkGlobal g_021AAA20;
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A21BC[];
extern char g_021A20D4[];
extern char g_021A20E0[];
extern char g_021A217C[];



unsigned char func_02176984(char *a0)
{
    char buf[4] = {0};
    unsigned char r = 0;

    if (func_021684CC((char *)0x021A208Cu, buf, a0 + 8, 0x2F) > 0)
        r = (unsigned char)sub_02095EAC((u32)buf, 0, 10);
    return r;
}



/*
 * sdk:      DWCi_GetResvDenyReasonString (dwc_match.o)
 */
char *func_021769E0(unsigned char denyReason)
{
    switch (denyReason) {
    case 0x10:
        return g_021A21C8;
    case 0x11:
        return g_021A21E8;
    case 0x12:
        return g_021A2208;
    case 0x13:
        return g_021A222C;
    case 0x14:
        return g_021A224C;
    case 0x15:
        return g_021A2280;
    case 0x16:
        return g_021A22C4;
    case 0x17:
        return g_021A22F0;
    case 0x18:
        return g_021A2324;
    default:
        return g_021A2340;
    }
}



/*
 * Stores both words the call returns into the module state block.
 */
void func_02176A8C(int a, int b)
{
    unsigned long long v = func_020870D0(a);

    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}



/*
 * Stores the argument at +0x678 of the module block.
 */
void func_02176AA8(int v)
{
    *(int *)(func_02175F3C() + 0x678) = v;
}



/*
 * sdk:      DWCi_RegisterMatchmakeKeys (dwc_match.o)
 */
void func_02176ABC(void)
{
    func_0219D158(0x32, g_021A20A4);
    func_0219D158(0x33, g_021A2170);
    func_0219D158(0x34, g_021A2164);
    func_0219D158(0x35, g_021A21BC);
    func_0219D158(0x36, g_021A20D4);
    func_0219D158(0x37, g_021A20E0);
    func_0219D158(0x38, g_021A217C);
}



void DWCi_NNFreeNegotiateList(void)
{
    NNCancel(DWCi_GetMatchCnt()->nnCookie);
    if (g_021AAA20.bInNNThink != 0) {
        g_021AAA20.bNNFreeNegotiateList = 1;
    } else {
        NNFreeNegotiateList();
    }
}
