/*
 * function: AOSSi_Init
 * address:  0x021B61D0
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss              0x021DC040  data
 *   aoss_data             0x021DAAB4  data
 *   AOSSi_Alloc           0x021DCE20  data
 *   AOSSi_Free            0x021DCE2C  data
 *   aoss_release          0x021B6CF0  thumb
 *   AOSS_MALLOC           0x021B61B0  thumb
 *   AOSS_StatusExclusion  0x021B7098  thumb
 *   AOSS_Init_old         0x021B62C0  thumb
 *   AOSS_FREE             0x021B61C0  thumb
 *   AOSS_Close            0x021B82DC  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSSi_Init (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * AOSSi_Alloc and AOSSi_Free are aosslink.o's globals (0x021DCE20, 0x021DCE2C). The names of
 * struct product_info's members are placeholders (DWARF here gives only its size).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B61D0.c \
 *       --func AOSSi_Init --addr 0x021B61D0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../include/G_AOSS_BSS.h"
#include "../include/G_AOSS_DATA_SECTION.h"

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
    unsigned char  pad00[0x10];
    unsigned long  addr;       /* +0x10 */
    unsigned long  netmask;    /* +0x14 */
    unsigned long  router;     /* +0x18 */
    unsigned char  pad1C[0x58 - 0x1C];
} SOCConfig;

typedef struct {
    int       s_sFd;
    int       before;
    SOCConfig soconfig;
} AOSS_DATA_SECTION;

extern struct AOSS_DATA_SECTION aoss_data;

struct product_info {
    unsigned short reserved;    /* DWARF gives the size only; member names are not the vendor's */
    unsigned short length;
    unsigned char  name[256];
};

struct aoss_secure_info {
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
};

struct aoss_info {
    unsigned short          supportSecurity;
    struct product_info     productInfo;
    short                   retryCount_Scan;
    short                   retryInterval_Scan;
    short                   retryCount_Comu;
    short                   retryInterval_Comu;
    short                   selectInterval;
    char                    macAddress[6];
    unsigned char           aossResult;
    struct aoss_secure_info secureInfo;
};

extern void *(*AOSSi_Alloc)(unsigned long size);
extern void (*AOSSi_Free)(void *ptr);
extern void aoss_release(void);
extern void *AOSS_MALLOC(int a);
extern int AOSS_StatusExclusion(int stat);
extern int AOSS_Init_old(struct aoss_info *aossInfo);
extern void AOSS_FREE(void *a);
extern int AOSS_Close(int fd);

int AOSSi_Init(struct aoss_info *aossInfo)
{
    int ret;

    if (aossInfo->retryCount_Scan == 0 || aossInfo->retryCount_Scan < -1 ||
        aossInfo->retryInterval_Scan < -1 ||
        aossInfo->retryCount_Comu == 0 || aossInfo->retryCount_Comu < -1 ||
        aossInfo->retryInterval_Comu < -1 || aossInfo->selectInterval < -1 ||
        aossInfo->productInfo.length == 0 || aossInfo->productInfo.length > 256 ||
        aossInfo->productInfo.name[aossInfo->productInfo.length - 1] != 0)
        ret = -1;
    else
        ret = 0;
    if (AOSSi_Alloc == 0 || AOSSi_Free == 0)
        ret = -1;
    if (ret == -1) {
        aossInfo->aossResult = 0xF;
        aoss_release();
        return -1;
    }
    aoss_bss.s_buf = AOSS_MALLOC(0x5F8);
    if (aoss_bss.s_buf == 0) {
        aossInfo->aossResult = 0xF;
        aoss_release();
        return -1;
    }
    AOSS_StatusExclusion(-1);
    ret = AOSS_Init_old(aossInfo);
    AOSS_FREE(aoss_bss.s_buf);
    aoss_release();
    if (aoss_data.s_sFd != -1)
        AOSS_Close(aoss_data.s_sFd);
    return ret;
}
