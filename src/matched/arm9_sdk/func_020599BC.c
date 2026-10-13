/*
 * function: DWC_CreateExchangeToken
 * address:  0x020599BC
 * packet:   pkt_020599BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CreateExchangeToken (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_IsAuthentic             0x020596c8 arm
 *   DWCi_Acc_SetGsProfileId          0x02059100 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
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

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWCi_Acc_IsAuthentic(struct DWCstAccUserData *userdata);
extern void DWCi_Acc_SetGsProfileId(void *data, int gs_profile_id);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);

void DWC_CreateExchangeToken(struct DWCstAccUserData *userdata, void *token)
{
    MI_CpuFill8(token, 0, 12);
    if (!DWCi_Acc_IsAuthentic(userdata)) {
        *(struct DWCstAccLoginId *)token = userdata->pseudo;
        return;
    }
    DWCi_Acc_SetGsProfileId(token, userdata->gs_profile_id);
    DWCi_Acc_SetFlag_DataType(token, 3);
}
