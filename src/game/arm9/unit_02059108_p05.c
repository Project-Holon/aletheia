/*
 * file:     unit_02059108_p05.c
 * unit:     yes
 * function: DWC_CreateUserData, func_02059718, func_02059760, func_020597C8, func_020597F0
 * address:  0x020596FC
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
 *   MATHi_CRC32InitTableRev          0x02081ac0 arm
 *   MATH_CalcCRC32                   0x02081bb8 arm
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWC_Auth_GetId                   0x02058fb4 arm
 *   DWCi_Acc_GetUserId               0x02059084 arm
 *   DWCi_Acc_IsValidLoginId          0x020596b0 arm
 */
struct DWCstAccUserData;
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

extern void *func_0205A10C(void);
extern void DWCi_Acc_CreateUserData(void *userdata, unsigned long gamecode);
extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
extern void DWC_Auth_GetId(DWCAuthWiFiId *id);
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
extern int DWCi_Acc_IsValidLoginId(void *loginid);
void DWC_CreateUserData(void *userdata);


void DWC_CreateUserData(void *userdata)
{
    DWCi_Acc_CreateUserData(userdata, (long unsigned int)func_0205A10C());
}



/*
 * sdk:      DWC_CheckUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059718(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;
    unsigned long crc32;

    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    return crc32 == userdata->crc32;
}


/*
 * sdk:      DWC_CheckValidConsole (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059760(struct DWCstAccUserData *userdata)
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


/*
 * sdk:      DWC_CheckHasProfile (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_020597C8(struct DWCstAccUserData *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 0x10) && ((int *)userdata)[7] > 0;
}


/*
 * sdk:      DWCi_Acc_SetLoginIdToUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_020597F0(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id)
{
    struct MATHCRC32Table table;

    userdata->authentic = *loginid;
    userdata->gs_profile_id = gs_profile_id;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}
