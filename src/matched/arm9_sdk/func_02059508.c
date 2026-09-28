/*
 * function: func_02059508
 * address:  0x02059508
 * packet:   pkt_02059508
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Acc_CreateUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_CreateTempLoginId       0x02059588 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
 *   MATHi_CRC32InitTableRev          0x02081ac0 arm
 *   MATH_CalcCRC32                   0x02081bb8 arm
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
extern void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);

void func_02059508(struct DWCstAccUserData *userdata, unsigned long gamecode)
{
    struct MATHCRC32Table table;

    MI_CpuFill8(userdata, 0, sizeof(struct DWCstAccUserData));
    userdata->size = sizeof(struct DWCstAccUserData);
    userdata->gs_profile_id = 0;
    userdata->gamecode = gamecode;
    DWCi_Acc_CreateTempLoginId(&userdata->pseudo);
    DWCi_Acc_SetFlag_DataType(&userdata->authentic, 0);
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}
