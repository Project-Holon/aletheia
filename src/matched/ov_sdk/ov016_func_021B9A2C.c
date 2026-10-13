/*
 * function: func_021B9A2C
 * address:  0x021B9A2C
 * packet:   pkt_ov016_021B9A2C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      CheckAccessPoint (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   memcpy  0x02092344  arm
 *   strlen  0x0209477C  arm
 *   memcmp  0x020923F0  arm
 *   sAtermsetTable1  0x021DABC4  data
 *
 * atermset.o carries the 3.0.0.126 stamp (the 2.0/sp1p2 front end), as the other
 * atermset.o files do. memcmp must come from a header named string.h so the
 * inner loop keeps pOldList->NumberOfItems and SsidLength across the calls;
 * the libc/memcmp/string.h variant declares it. The DWARF places i in r6 (the
 * stealth scan over the old list); the other ranges of i share one stack slot.
 */

#include "../arm9_sdk/libc/memcmp/string.h"

typedef struct _NDIS_802_11_SSID {
    unsigned long SsidLength;
    unsigned char Ssid[32];
    unsigned char pad[4];
} NDIS_802_11_SSID;

typedef struct _WLAN_BSSID {
    NDIS_802_11_SSID Ssid;          /* +0x00 */
    unsigned char MacAddress[6];    /* +0x28 */
    unsigned short Privacy;         /* +0x2e */
} WLAN_BSSID;

typedef struct _BSSID_LIST {
    unsigned long NumberOfItems;
    WLAN_BSSID Bssid[1];
} BSSID_LIST;

extern char sAtermsetTable1[7];

static int func_021B9A2C(BSSID_LIST *pNewList, BSSID_LIST *pOldList, unsigned long *ApNo)
{
    int flagDetect;
    int Result;
    int flagNew;
    int flagOld;
    WLAN_BSSID *pNewBss;
    WLAN_BSSID *pOldBss;
    unsigned long j;
    unsigned long i;

    flagDetect = 0;
    Result = 0;
    pNewBss = pNewList->Bssid;
    pOldBss = pOldList->Bssid;
    for (i = 0; i < pNewList->NumberOfItems; i++) {
        char newSSID[34] = {0};

        memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
        newSSID[pNewBss->Ssid.SsidLength] = 0;
        for (j = 0; j < pOldList->NumberOfItems; j++) {
            if (pNewBss->Ssid.SsidLength == 0 || pNewBss->Ssid.SsidLength > 32)
                break;
            if (pNewBss->Ssid.SsidLength == 1 &&
                (pNewBss->Ssid.Ssid[0] == 0 || pNewBss->Ssid.Ssid[0] == ' '))
                break;
            if (memcmp(newSSID, pOldBss->Ssid.Ssid, strlen(newSSID)) == 0 &&
                memcmp(pNewBss->MacAddress, pOldBss->MacAddress, 6) == 0 &&
                pNewBss->Privacy != pOldBss->Privacy && pNewBss->Privacy == 0) {
                flagDetect = 1;
                break;
            }
            pOldBss++;
        }
        if (flagDetect)
            break;
        pNewBss++;
        pOldBss = pOldList->Bssid;
    }

    if (!flagDetect) {
        char newSSID[34] = {0};

        flagNew = 0;
        flagOld = 0;
        pNewBss = pNewList->Bssid;
        pOldBss = pOldList->Bssid;
        for (i = 0; i < pOldList->NumberOfItems; i++) {
            memcpy(newSSID, pOldBss->Ssid.Ssid, 32);
            newSSID[pOldBss->Ssid.SsidLength] = 0;
            if (memcmp(newSSID, sAtermsetTable1, strlen(sAtermsetTable1)) == 0 && pOldBss->Privacy == 0) {
                flagOld = 1;
                break;
            }
            pOldBss++;
        }
        for (i = 0; i < pNewList->NumberOfItems; i++) {
            memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
            newSSID[pNewBss->Ssid.SsidLength] = 0;
            if (strlen(newSSID) == strlen(sAtermsetTable1) &&
                memcmp(newSSID, sAtermsetTable1, strlen(sAtermsetTable1)) == 0 && pNewBss->Privacy == 0) {
                flagNew = 1;
                break;
            }
            pNewBss++;
        }
        if (flagNew && !flagOld)
            flagDetect = 1;
    }
    if (flagDetect) {
        *ApNo = i;
        Result = 1;
    }
    return Result;
}
