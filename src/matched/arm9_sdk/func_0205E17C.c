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
 * sdk:      SearchAround2ndLap (search.o)
 *
 * symbols:
 *   DWCi_AC_MakeSearchList           0x0205d318 arm
 *   GetStartChannel                  0x0205e818 arm
 */

typedef struct tagACWORK {
    unsigned char before[0x14BB];
    unsigned char powerMode : 2;
    unsigned char authMode : 2;
    unsigned char aroundCount : 4;
    unsigned char flags14BC;
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
} tagACWORK;

extern int DWCi_AC_MakeSearchList(int type);
extern signed char GetStartChannel(int lap);

static unsigned char func_0205E17C(tagACWORK *wk)
{
    wk->count = 0;
    wk->aroundCount++;
    DWCi_AC_MakeSearchList(0);
    wk->searchChannel = GetStartChannel(1);
    return 3;
}
