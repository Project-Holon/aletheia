/*
 * function: func_021661F0
 * address:  0x021661F0
 * packet:   pkt_ov009_021661F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_GetGameInfo (libwcm.TWL.HYB.a aplist.o)
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02703250  0x02703250  arm  twl
 *   @12437         0x021A19B0  data
 *
 * Returns the WMGameInfo of a BSS descriptor: NWM vendor element path on TWL, validated inline gameInfo on DS. The tag initializer copies from the vendor template @12437 at 0x021A19B0 (template class, ov009 scope).
 */

typedef struct WMGameInfo {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
    unsigned char attribute;
    unsigned short parentMaxSize;
    unsigned short childMaxSize;
    unsigned short userGameInfo[56];
} WMGameInfo;

typedef struct WCMBssDesc {
    unsigned short length;
    unsigned char pad0[0x3C - 2];
    unsigned short gameInfoLength;
    unsigned short elementCount;
    WMGameInfo gameInfo;
} WCMBssDesc;

typedef struct NWMInfoElements {
    unsigned char id;
    unsigned char length;
    unsigned short element[1];
} NWMInfoElements;

typedef struct WCMWork {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork;

extern int func_021657C8(void);
extern int OS_IsRunOnTwl(void);
extern NWMInfoElements *func_02703250();

WMGameInfo *func_021661F0(WCMBssDesc *bssDesc)
{
    WCMWork *w = (WCMWork *)func_021657C8();
    NWMInfoElements *elem;
    WMGameInfo *gameInfo;
    unsigned char tag[4] = { 0x00, 0x09, 0xBF, 0x00 };

    if (bssDesc == 0) return 0;
    if (OS_IsRunOnTwl()) {
        if (w->deviceId == 2) {
            elem = 0;
            if (bssDesc->elementCount != 0) {
                elem = func_02703250(bssDesc, 0xDD, tag);
            }
            if (elem != 0) {
                gameInfo = (WMGameInfo *)&elem->element[4];
                if (gameInfo->magicNumber == 1) return gameInfo;
            }
        }
    } else {
        if (w->deviceId == 1) {
            unsigned short len = bssDesc->gameInfoLength;
            if (len != 0) {
                int ok = 0;
                if (len >= 0x10 && len <= 0x80) {
                    if (len == bssDesc->gameInfo.userGameInfoLength + 0x10 && bssDesc->gameInfo.magicNumber == 1 && bssDesc->length == ((unsigned long)(len + 0x41) >> 1)) ok = 1;
                }
                if (ok == 1) return &bssDesc->gameInfo;
            }
        }
    }
    return 0;
}
