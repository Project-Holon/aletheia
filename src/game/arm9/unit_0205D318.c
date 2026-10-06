/*
 * file:     unit_0205D318.c
 * unit:     yes
 * function: func_0205D318, func_0205D3E0, func_0205D434, func_0205D470, func_0205D4D8, func_0205D588, func_0205D848, func_0205D8D4
 * address:  0x0205D318
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   strncmp 0x020949F4 arm
 *   FREESPOT_SSID 0x020A1620 data
 *   MI_CpuCopy8 0x02082D44 arm
 *   g_020A80A4 0x020A80A4 data
 *   NINTENDOWFC_SSID 0x020A1628 data
 */
typedef struct {
    unsigned char ispId[0x40];
    unsigned char ssid[2][0x20];
    unsigned char wep[4][0x10];
    unsigned char unkC0[0x11];
    unsigned char wep40[5];
    unsigned char unkD6[0x10];
    unsigned char wepMode:2;
    unsigned char wepNotation:6;
    unsigned char setType;
    unsigned char unkE8[8];
} NCFGApInfo;

typedef struct {
    unsigned char passphrase[0x20];
    unsigned char pmk[0x20];
    unsigned char ssid[2][0x20];
    unsigned char unk80;
    unsigned char wpaMode;
    unsigned char unk82[0x6e];
} NCFGApInfoEx_0205D318;

typedef struct {
    NCFGApInfo ap;
    unsigned char wifi[14];
    unsigned short crc;
} NCFGSlotInfo;

typedef struct {
    NCFGApInfo ap;
    unsigned char wifi[14];
    unsigned short crc;
    NCFGApInfoEx_0205D318 apEx;
    unsigned char rsvEx[14];
    unsigned short crcEx;
} NCFGSlotInfoEx;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short capaInfo;
    unsigned short rateSet[2];
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    unsigned char gameInfo[0x80];
} WMBssDesc;

typedef struct {
    unsigned char state;
    unsigned char type;
    unsigned char rssi;
    unsigned char channel:7;
    unsigned char find:1;
} ACFL;

typedef struct {
    unsigned char find:4;
    unsigned char duplicate:4;
    unsigned char type;
    unsigned char channel;
    unsigned char length;
    unsigned char ssid[32];
} ACSL;

typedef struct {
    unsigned char mode;
    unsigned char keyId;
    unsigned char key[80];
} WCMWepDesc;

typedef struct {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    ACSL searchList[21];
    ACFL findList[11];
    WMBssDesc bssDesc[11];
    unsigned long long timeOut;
    WCMWepDesc wepKey;
    unsigned char dmaNo;
    unsigned char powerMode:2;
    unsigned char authMode:2;
    unsigned char aroundCount:4;
    unsigned char connectType:4;
    unsigned char skipNetCheck:1;
    unsigned char useDSWireless:1;
    unsigned char duplicateFlag:1;
    unsigned char wpaSetting:1;
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} ACWORK;

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern int OS_IsRunOnTwl(void);
extern int strncmp(const char *s1, const char *s2, unsigned long n);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
int func_0205D318(int type);
unsigned char func_0205D3E0(WMBssDesc *bssdesc);
unsigned char func_0205D434(void);
unsigned char func_0205D470(ACWORK *wk);
unsigned char func_0205D4D8(ACWORK *wk);
unsigned char func_0205D588(ACWORK *wk);
unsigned char func_0205D848(ACWORK *wk);
unsigned char func_0205D8D4(ACWORK *wk);
extern const unsigned char FREESPOT_SSID[8];
extern const char g_020A80A4[];
extern const unsigned char NINTENDOWFC_SSID[11];





/*
 * sdk:      DWCi_AC_MakeSearchList (makelist.o)
 */
int func_0205D318(int type)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    switch (type) {
    case 0:
        MIi_CpuClear32(0, wk->searchList, sizeof(wk->searchList));
        wk->searchListNum = func_0205D470(wk);
        break;
    case 1:
        wk->searchListNum = func_0205D848(wk);
        wk->searchListNo = func_0205D8D4(wk);
        if (wk->searchListNum == 0) {
            return 0;
        }
        break;
    case 2:
        MIi_CpuClear32(0, wk->searchList, sizeof(wk->searchList));
        wk->searchListNo = 0;
        wk->searchListNum = func_0205D4D8(wk);
        if (wk->searchListNum == 0) {
            return 0;
        }
        break;
    }
    OS_IsRunOnTwl();
    return 1;
}





/*
 * sdk:      DWCi_AC_CheckFreespot (makelist.o)
 */
unsigned char func_0205D3E0(WMBssDesc *bssdesc)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    if (wk->connectType == 0 || wk->connectType == 6) {
        if (strncmp((char *)bssdesc->ssid, (const char *)FREESPOT_SSID, 8) == 0) {
            return 0x14;
        }
    }
    return 0;
}





/*
 * sdk:      DWCi_AC_GetSearchListNum (makelist.o)
 */
unsigned char func_0205D434(void)
{
    unsigned char num;
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    for (num = 0; num < 21; num++) {
        if (wk->searchList[num].length == 0) {
            break;
        }
    }
    return num;
}





/*
 * sdk:      MakeAroundList (makelist.o)
 */
unsigned char func_0205D470(ACWORK *wk)
{
    ACSL *list = wk->searchList;
    unsigned char num;

    num = func_0205D588(wk);
    list += num;
    if (wk->connectType == 0 || wk->connectType == 6) {
        MI_CpuCopy8(FREESPOT_SSID, list->ssid, 8);
        list->length = 8;
        list->type = 0x14;
        num++;
    }
    return num;
}




/*
 * sdk:      MakeStealthList (makelist.o)
 *
 * g_020A80A4 is the object's anonymous 8-byte SSID literal (@16449).
 */
unsigned char func_0205D4D8(ACWORK *wk)
{
    unsigned char num;
    ACSL *list = wk->searchList;

    num = func_0205D588(wk);
    list += num;
    if (wk->connectType == 0 || wk->connectType == 4) {
        MI_CpuCopy8(g_020A80A4, list->ssid, 8);
        list->length = 8;
        list->type = 0x12;
        num++;
        list++;
    }
    if (wk->connectType == 0 || wk->connectType == 8) {
        MI_CpuCopy8(NINTENDOWFC_SSID, list->ssid, 11);
        list->length = 11;
        list->type = 0x16;
        num++;
    }
    return num;
}



static inline int SetList(ACSL *list, const unsigned char *ssid, unsigned char type)
{
    unsigned char len;

    for (len = 0; len < 32; len++) {
        if (ssid[len] == 0) {
            break;
        }
        list->ssid[len] = ssid[len];
    }
    if (len != 0) {
        list->length = len;
        list->type = type;
        return 1;
    }
    return 0;
}



/*
 * sdk:      MakeUserList (makelist.o)
 */
unsigned char func_0205D588(ACWORK *wk)
{
    int i;
    unsigned char num;
    NCFGSlotInfo *info;
    NCFGSlotInfoEx *info2;
    ACSL *list;

    num = 0;
    info = wk->userInfo;
    info2 = wk->userInfoEx;
    list = wk->searchList;
    for (i = 0; i < 3; i++, info++) {
        if ((wk->connectType == 0 || wk->connectType == i + 1) && info->ap.setType != 0xff) {
            if (SetList(list, info->ap.ssid[0], i)) {
                num++;
                list++;
            }
            if (info->ap.setType == 1) {
                if (SetList(list, info->ap.ssid[1], i + 3)) {
                    num++;
                    list++;
                }
            }
        }
    }
    if (OS_IsRunOnTwl()) {
        for (i = 0; i < 3; i++, info2++) {
            if ((wk->connectType == 0 || wk->connectType == i + 11) && info2->ap.setType != 0xff) {
                if (SetList(list, info2->ap.ssid[0], i + 6)) {
                    num++;
                    list++;
                }
                if (info2->ap.setType == 1 || info2->ap.setType == 0x11) {
                    if (SetList(list, info2->ap.ssid[1], i + 9)) {
                        num++;
                        list++;
                    }
                    if (SetList(list, info2->apEx.ssid[0], i + 12)) {
                        num++;
                        list++;
                    }
                    if (SetList(list, info2->apEx.ssid[1], i + 15)) {
                        num++;
                        list++;
                    }
                }
            }
        }
    }
    return num;
}



/*
 * sdk:      MakeDifferChannelList (makelist.o)
 */
unsigned char func_0205D848(ACWORK *wk)
{
    int i;
    unsigned char num = 0;

    for (i = 0; i < wk->findListNum; i++) {
        if (wk->findList[i].state == 0 && wk->bssDesc[i].channel - 1 != wk->findList[i].channel) {
            wk->findList[i].find = 0;
            num++;
        } else {
            wk->findList[i].find = 1;
        }
    }
    return num;
}



/*
 * sdk:      CheckDifferChannelStart (makelist.o)
 */
unsigned char func_0205D8D4(ACWORK *wk)
{
    unsigned char i;
    unsigned char no = 0;

    for (i = 0; i < wk->findListNum; i++) {
        if (!wk->findList[i].find) {
            no = i;
            break;
        }
    }
    return no;
}
