/*
 * function: DWC_CheckUserData
 * address:  0x02059718
 * packet:   pkt_02059718
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
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

int DWC_CheckUserData(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;
    unsigned long crc32;

    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    return crc32 == userdata->crc32;
}
