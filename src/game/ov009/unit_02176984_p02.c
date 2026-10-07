/*
 * file:     unit_02176984_p02.c
 * unit:     yes
 * function: func_02176AA8, func_02176ABC, func_02176B34
 * address:  0x02176AA8
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
 *   s_bInNNThink          0x021AAA20 data
 */
typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x618];
    int nnCookie;            /* +0x618 */
};

struct NNThinkGlobal
{
    int f0;
    int f4;
    int f8;
};

extern int func_02175F3C(void);
extern void func_0219D158(int keyid, char *key);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void NNCancel(int cookie);
extern void NNFreeNegotiateList(void);
void func_02176AA8(int v);
void func_02176ABC(void);
void DWCi_NNFreeNegotiateList(void);
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A21BC[];
extern char g_021A20D4[];
extern char g_021A20E0[];
extern char g_021A217C[];
extern struct NNThinkGlobal s_bInNNThink;


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
    if (s_bInNNThink.f0 != 0) {
        s_bInNNThink.f8 = 1;
    } else {
        NNFreeNegotiateList();
    }
}
