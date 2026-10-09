/*
 * file:     unit_02059108_p04.c
 * unit:     yes
 * function: func_02059644, func_020596B0, func_020596C8, DWC_IsValidFriendData
 * address:  0x02059644
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

typedef struct DWCAuthWiFiId {
    unsigned long long uId;
    unsigned long long notAttestedId;
    unsigned long flg;
} DWCAuthWiFiId;

extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
extern void DWC_Auth_GetId(DWCAuthWiFiId *id);
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *loginid);
int func_020596B0(void *loginid);
int DWCi_Acc_IsAuthentic(void *userdata);
int DWC_IsValidFriendData(void *frienddata);



/*
 * sdk:      DWCi_Acc_CheckConsoleUserId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059644(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;

    DWC_Auth_GetId(&authid);
    if (authid.flg) {
        return DWCi_Acc_GetUserId(loginid) == authid.uId;
    }
    return DWCi_Acc_GetUserId(loginid) == authid.notAttestedId;
}



/*
 * The ARM9 listing labels this address func_020596B0; it calls DWCi_Acc_GetFlag_DataType, so it is a dwc_account.o static (the SDK table's DWC_GHTTPCleanupRootCAList attribution here does not match the linked bytes).
 */
int func_020596B0(void *loginid)
{
    return DWCi_Acc_GetFlag_DataType(loginid) == 1;
}



int DWCi_Acc_IsAuthentic(void *userdata)
{
    return func_020596B0((char *)userdata + 16);
}


int DWC_IsValidFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlag_DataType(frienddata);
    return type != 0;
}
