/*
 * function: func_020597F0
 * address:  0x020597F0
 * packet:   pkt_020597F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Acc_SetLoginIdToUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
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

void func_020597F0(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id)
{
    struct MATHCRC32Table table;

    userdata->authentic = *loginid;
    userdata->gs_profile_id = gs_profile_id;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}
