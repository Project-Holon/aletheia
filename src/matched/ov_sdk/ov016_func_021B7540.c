/*
 * function: GetProductInfo
 * address:  0x021B7540
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss      0x021DC040  data
 *   AOSS_Memset   0x021B8240  thumb
 *   AOSS_Ntohs    0x021B834C  thumb
 *   AOSS_Memcpy   0x021B8230  thumb
 *   aoss_get_bin  0x021B75FC  thumb
 *   AOSS_Ntohl    0x021B8324  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol GetProductInfo (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7540.c \
 *       --func GetProductInfo --addr 0x021B7540 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../include/G_AOSS_BSS.h"

/*
 * aoss.o's main .bss section (3424 bytes at 0x021DC040). The vendor object
 * addresses these statics section-relative (one pool word for the section
 * base plus a field offset), so they are declared here as one object laid
 * out in the object's own order; member names are the vendor statics.
 */
typedef struct {
    unsigned char *p_name;
    unsigned int   p_name_len;
    unsigned int   sLevel;
    unsigned int   aLevel;
    unsigned int   apAddr;
    unsigned int   apMask;
    char           ip_chg;
    char           p_type;
} _AOSS_INFO;

typedef struct {
    unsigned long x;
    unsigned long mul;
    unsigned long add;
} MATHRandContext16;

typedef struct {
    int            SecurityType;    /* +0x000 */
    void          *bssList;         /* +0x004 */
    int            initflg;         /* +0x008 */
    void          *linkInfo;        /* +0x00C */
    unsigned int   gError;          /* +0x010 */
    void          *s_buf;           /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

extern struct AOSS_BSS aoss_bss;

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

typedef struct {
    char ProductInfo[5][128];
} PRODUCT_INFO_AOSS;

extern void *AOSS_Memset(void *s, int c, int n);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern unsigned long aoss_get_bin(void *ptr, int num);
extern unsigned long AOSS_Ntohl(unsigned long netlong);

int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo)
{
    int Num;
    int length;
    VariableData *Data;

    AOSS_Memset(ProductInfo, 0, 0x104);
    Data = (VariableData *)ProductData;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        if (length <= 0)
            return -1;
        switch (Data->DataID) {
        case 0:
            AOSS_Memcpy(ProductInfo->ProductInfo[0], Data->Data, length);
            break;
        case 1:
            AOSS_Memcpy(ProductInfo->ProductInfo[1], Data->Data, length);
            break;
        case 2:
            AOSS_Memcpy(ProductInfo->ProductInfo[2], Data->Data, length);
            break;
        case 3:
        case 4:
            Num = AOSS_Ntohs(Data->Data[0]);
            if (Num <= 0)
                return -2;
            break;
        case 5:
            aoss_bss.gData_apAddr = AOSS_Ntohl(aoss_get_bin(Data->Data, length));
            break;
        case 6:
            aoss_bss.gData_apMask = AOSS_Ntohl(aoss_get_bin(Data->Data, length));
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(ProductData + AOSS_Ntohs(Data->offset));
    }
    return 0;
}
