/*
 * function: func_0205E17C
 * address:  0x0205E17C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: SearchAround2ndLap (search.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   DWCi_AC_MakeSearchList   0x0205D318  arm
 *   GetStartChannel          0x0205E818  arm
 */

struct tagACWORK {
    char pad[0x14BB];
    unsigned char low : 4;
    unsigned char lap : 4;
    char pad2[5];
    unsigned char f14C1;
    char pad3[3];
    unsigned char f14C5;
};

extern int DWCi_AC_MakeSearchList(int type);
extern signed char GetStartChannel(int lap);

unsigned char func_0205E17C(struct tagACWORK *wk)
{
    wk->lap = wk->lap + 1;
    wk->f14C5 = 0;
    DWCi_AC_MakeSearchList(0);
    wk->f14C1 = GetStartChannel(1);
    return 3;
}
