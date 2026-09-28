/*
 * function: func_020592D0
 * address:  0x020592D0
 * packet:   pkt_020592D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Acc_CreateFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   MATHi_CRC8InitTable              0x02081940 arm
 *   MATH_CalcCRC8                    0x02081b3c arm
 *   MATH_MD5Init                     0x02081120 arm
 *   MATH_MD5Update                   0x02081164 arm
 *   MATH_MD5GetHash                  0x0208122c arm
 */

struct MATHMD5Context {
    unsigned char data[88];
};

struct MATHCRC8Table {
    unsigned char table[256];
};

extern void MATHi_CRC8InitTable(struct MATHCRC8Table *table, unsigned char poly);
extern unsigned char MATH_CalcCRC8(struct MATHCRC8Table *table, void *data, unsigned long dataLength);
extern void MATH_MD5Init(struct MATHMD5Context *context);
extern void MATH_MD5Update(struct MATHMD5Context *context, void *input, unsigned long length);
extern void MATH_MD5GetHash(struct MATHMD5Context *context, void *digest);

unsigned long long func_020592D0(int gs_profile_id, unsigned long gamecode, int method)
{
    unsigned long code[2];
    int hash;
    struct MATHCRC8Table table;
    struct MATHMD5Context context;
    unsigned char digest[16];

    code[0] = (unsigned long)gs_profile_id;
    code[1] = gamecode;
    if (method == 0) {
        MATHi_CRC8InitTable(&table, 7);
        hash = MATH_CalcCRC8(&table, code, sizeof(code));
    } else {
        MATH_MD5Init(&context);
        MATH_MD5Update(&context, code, sizeof(code));
        MATH_MD5GetHash(&context, digest);
        hash = digest[0] >> 1;
    }
    return ((unsigned long long)(hash & 0x7f) << 32) | (unsigned long)gs_profile_id;
}
