/*
 * function: DWC_CheckValidConsole
 * address:  0x02059760
 * packet:   pkt_02059760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckValidConsole (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWC_Auth_GetId                   0x02058fb4 arm
 *   DWCi_Acc_GetUserId               0x02059084 arm
 */

struct MATHCRC32Table {
    unsigned long table[256];
};

struct DWCstAccLoginId {
    unsigned long data[3];
};

struct DWCstAccUserData {
    unsigned long size;
    struct DWCstAccLoginId pseudo;
    struct DWCstAccLoginId authentic;
    int gs_profile_id;
    unsigned long flag;
    unsigned long gamecode;
    unsigned long reserved[5];
    unsigned long crc32;
};

extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
typedef struct DWCAuthWiFiId {
    unsigned long long uId;
    unsigned long long notAttestedId;
    unsigned long flg;
} DWCAuthWiFiId;

extern void DWC_Auth_GetId(DWCAuthWiFiId *id);
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);

int DWC_CheckValidConsole(struct DWCstAccUserData *userdata)
{
    DWCAuthWiFiId authid;

    if (DWCi_Acc_GetFlag_DataType(&userdata->authentic) == 0) {
        return 1;
    }
    DWC_Auth_GetId(&authid);
    if (!authid.flg) {
        return 0;
    }
    if (DWCi_Acc_GetUserId(&userdata->authentic) == authid.uId) {
        return 1;
    }
    return 0;
}
