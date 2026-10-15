/*
 * function: DWCi_AC_IsSupportWPA
 * address:  0x0205AB54
 * packet:   pkt_0205AB54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_IsSupportWPA (beacon.o)
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   NWM_GetInfoElements 0x02703208 arm
 *   NWM_GetVenderInfoElements 0x02703250 arm
 *   g_020A161C 0x020A161C data
 *
 * g_020A161C is the initialiser of wpaTag (@16091: 00 50 F2 01, the WPA OUI
 * and type); the object copies it bytewise, spelled here as a struct copy.
 */

typedef struct WCMBssDesc WCMBssDesc;
typedef struct NWMInfoElements NWMInfoElements;
typedef struct {
    unsigned char b[4];
} WPATAG;

extern const WPATAG g_020A161C;

extern int OS_IsRunOnTwl(void);
extern NWMInfoElements *NWM_GetInfoElements(WCMBssDesc *bssDesc, unsigned char elementID);
extern NWMInfoElements *NWM_GetVenderInfoElements(WCMBssDesc *bssDesc, unsigned char elementID, unsigned char *ouiType);

int DWCi_AC_IsSupportWPA(WCMBssDesc *bssDesc)
{
    WPATAG wpaTag;
    NWMInfoElements *elem;

    if (OS_IsRunOnTwl()) {
        elem = NWM_GetInfoElements(bssDesc, 0x30);
        if (elem == 0) {
            wpaTag = g_020A161C;
            elem = NWM_GetVenderInfoElements(bssDesc, 0xdd, wpaTag.b);
            if (elem == 0) {
                return 0;
            }
        }
    }
    return 1;
}
