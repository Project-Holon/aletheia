/*
 * function: aoss_data_init
 * address:  0x021B6D1C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss     0x021DC040  data
 *   gSeqID       0x021DCDA0  data
 *   AOSS_Memset  0x021B8240  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol aoss_data_init (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B6D1C.c \
 *       --func aoss_data_init --addr 0x021B6D1C --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct product_info {
    unsigned char  dataType;
    unsigned short dataLen;
    unsigned char  productName[256];
} PRODUCT_INFO;

typedef struct aoss_secure_info {
    unsigned char WEP40Key1[6];
    unsigned char WEP40Key2[6];
    unsigned char WEP40Key3[6];
    unsigned char WEP40Key4[6];
    unsigned char WEP40_SSID[33];
    unsigned char WEP104Key1[14];
    unsigned char WEP104Key2[14];
    unsigned char WEP104Key3[14];
    unsigned char WEP104Key4[14];
    unsigned char WEP104_SSID[33];
    unsigned char WPA_PSK_TKIP[64];
    unsigned char WPA_PSK_TKIP_SSID[33];
    unsigned char WPA_PSK_AES[64];
    unsigned char WPA_PSK_AES_SSID[33];
} AOSS_SECURE_INFO;

typedef struct aoss_info {
    unsigned short   supportSecurity;
    PRODUCT_INFO     productInfo;
    short            retryCount_Scan;
    short            retryInterval_Scan;
    short            retryCount_Comu;
    short            retryInterval_Comu;
    short            selectInterval;
    char             macAddress[6];
    unsigned char    aossResult;
    AOSS_SECURE_INFO secureInfo;
} AOSS_INFO;

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

extern AOSS_BSS aoss_bss;

extern unsigned char gSeqID[8];
extern void *AOSS_Memset(void *s, int c, int n);

void aoss_data_init(AOSS_INFO *aossInfo)
{
    AOSS_Memset(gSeqID, 0, 8);
    aoss_bss.gError = 1;
    AOSS_Memset(&aoss_bss.gData, 0, sizeof(_AOSS_INFO));
    aoss_bss.gData.p_name = aossInfo->productInfo.productName;
    aoss_bss.gData.p_name_len = aossInfo->productInfo.dataLen;
    aoss_bss.gData.sLevel = aossInfo->supportSecurity & 0xf;
    aoss_bss.gData.p_type = aossInfo->productInfo.dataType;
    aoss_bss.gData.aLevel = 0;
    aoss_bss.gData.apAddr = 0xc0a80b01;
    aoss_bss.gData.ip_chg = 0;
}
