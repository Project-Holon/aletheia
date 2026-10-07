/*
 * function: AOSS_seq_data_copy
 * address:  0x021B6D8C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss        0x021DC040  data
 *   SecurityInfo    0x021DC700  data
 *   AOSS_Memset     0x021B8240  thumb
 *   AOSS_Memcpy     0x021B8230  thumb
 *   AOSS_Strlen     0x021B8364  thumb
 *   aoss_check_str  0x021B6F84  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_seq_data_copy (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * SecurityInfo is the vendor static inside aoss_bss (+0x6C0); this function addresses it by
 * its own symbol (pool words SecurityInfo+0x8 and so on), so it is declared by name here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B6D8C.c \
 *       --func AOSS_seq_data_copy --addr 0x021B6D8C --region ov016 --cc ../2.0/sp1p2 --thumb
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
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[4][64];
} ASTS_DATA_WEP;

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[64];
} ASTS_DATA_TKIP;

typedef struct {
    int            ReNew;
    unsigned long  EncryptLevel;
    ASTS_DATA_WEP  WepData_40;
    ASTS_DATA_WEP  WepData_104;
    ASTS_DATA_TKIP TkipData;
    ASTS_DATA_TKIP AesData;
    char           BSSID[6];
} ASTS_DATA_INFO;

typedef struct {
    char ProductInfo[5][128];
} PRODUCT_INFO_AOSS;

struct product_info {
    unsigned char data[0x104];  /* layout not needed here */
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

extern ASTS_DATA_INFO SecurityInfo[2];
extern void *AOSS_Memset(void *s, int c, int n);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern int AOSS_Strlen(char *s);
extern int aoss_check_str(char *ptr, int count);

int AOSS_seq_data_copy(struct aoss_info *aossInfo)
{
    struct aoss_secure_info *ptr;
    ASTS_DATA_WEP *wep40;
    ASTS_DATA_WEP *wep104;
    ASTS_DATA_TKIP *tkip;
    ASTS_DATA_TKIP *aes;

    ptr = &aossInfo->secureInfo;
    wep40 = &SecurityInfo[0].WepData_40;
    wep104 = &SecurityInfo[0].WepData_104;
    tkip = &SecurityInfo[0].TkipData;
    aes = &SecurityInfo[0].AesData;
    if (ptr == 0)
        return -1;
    aossInfo->supportSecurity = aoss_bss.gData_sLevel & aoss_bss.gData_aLevel;
    AOSS_Memset(ptr, 0, sizeof(struct aoss_secure_info));
    if (aossInfo->supportSecurity & 1) {
        AOSS_Memcpy(ptr->WEP40Key1, wep40->Data[0], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key2, wep40->Data[1], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key3, wep40->Data[2], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key4, wep40->Data[3], wep40->KeyLen);
        if (aoss_check_str(wep40->SSID, AOSS_Strlen(wep40->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WEP40_SSID, wep40->SSID, AOSS_Strlen(wep40->SSID));
    }
    if (aossInfo->supportSecurity & 2) {
        AOSS_Memcpy(ptr->WEP104Key1, wep104->Data[0], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key2, wep104->Data[1], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key3, wep104->Data[2], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key4, wep104->Data[3], wep104->KeyLen);
        if (aoss_check_str(wep104->SSID, AOSS_Strlen(wep104->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WEP104_SSID, wep104->SSID, AOSS_Strlen(wep104->SSID));
    }
    if (aossInfo->supportSecurity & 4) {
        if (aoss_check_str(tkip->Data, tkip->KeyLen - 1) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_TKIP, tkip->Data, tkip->KeyLen);
        if (aoss_check_str(tkip->SSID, AOSS_Strlen(tkip->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_TKIP_SSID, tkip->SSID, AOSS_Strlen(tkip->SSID));
    }
    if (aossInfo->supportSecurity & 8) {
        if (aoss_check_str(aes->Data, aes->KeyLen - 1) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_AES, aes->Data, aes->KeyLen);
        if (aoss_check_str(aes->SSID, AOSS_Strlen(aes->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_AES_SSID, aes->SSID, AOSS_Strlen(aes->SSID));
    }
    aossInfo->aossResult = 0;
    return 0;

error:
    AOSS_Memset(ptr, 0, sizeof(struct aoss_secure_info));
    return -1;
}
