/*
 * function: func_0205987C
 * address:  0x0205987C
 * packet:   pkt_0205987C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Acc_ClearDirty (libdwcaccount.TWL.HYB.a(dwc_account.o))
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

void func_0205987C(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;

    userdata->flag &= ~1;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
}
