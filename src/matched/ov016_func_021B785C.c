/*
 * function: GetSecurityData
 * address:  0x021B785C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AttrNo        0x021DAAB0  data
 *   aoss_bss      0x021DC040  data
 *   AOSS_Ntohs    0x021B834C  thumb
 *   GetWEPData    0x021B7620  thumb
 *   GetWPAData    0x021B7774  thumb
 *   GetBssidData  0x021B782C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol GetSecurityData (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * AttrNo is the function-static table AttrNo$8937 (2 bytes of .data at 0x021DAAB0), declared
 * extern because the vendor object addresses it by its own symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B785C.c \
 *       --func GetSecurityData --addr 0x021B785C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
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

typedef struct SEND_INFO SEND_INFO;

typedef struct {
    char SendSeqID[8];
} SEQID_INFO;

typedef struct {
    unsigned short PktVersion;
    unsigned short PktID;
    unsigned short PktSubID;
    unsigned short cmd;
    unsigned short type;
    unsigned short size;
    unsigned short CryptType;
    unsigned char  crc8;
    unsigned char  Fragment;
    unsigned char  SeqID[8];
} tagASTSpktHeader;

typedef struct {
    unsigned char  SubAttrNo;
    unsigned char  SubAttrVer;
    unsigned short length;
} tagASTSsubAttrHeader;

struct UdpIpMsg {
    unsigned char udpipmsg[1500];
};

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

typedef struct tagASTSpktWEP40 tagASTSpktWEP40;
typedef struct tagASTSpktTKIP tagASTSpktTKIP;
typedef struct tagASTSpktBssid tagASTSpktBssid;

extern unsigned char AttrNo[];
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info);
extern int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info);
extern int GetBssidData(tagASTSpktBssid *pBssid, char *BSSID);

int GetSecurityData(int Mode, unsigned char *pData, int Length, ASTS_DATA_INFO *SecurityInfo,
                    PRODUCT_INFO_AOSS *Info)
{
    tagASTSsubAttrHeader *pSec;
    int size;
    int wLen;
    int ret;
    int Level;
    int Len;

    Level = 0;
    if (Length <= 0)
        return -2;
    for (;;) {
        pSec = (tagASTSsubAttrHeader *)pData;
        if (pSec->SubAttrNo == AttrNo[Mode])
            break;
        size = AOSS_Ntohs(pSec->length) + 4;
        Length -= size;
        pData += size;
        if (Length <= 0)
            return -4;
    }
    pData += 4;
    Len = AOSS_Ntohs(pSec->length);
    do {
        switch (*pData) {
        case 3:
            ret = GetWEPData((tagASTSpktWEP40 *)pData, &SecurityInfo[Mode].WepData_40);
            Level |= 1;
            break;
        case 4:
            ret = GetWEPData((tagASTSpktWEP40 *)pData, &SecurityInfo[Mode].WepData_104);
            Level |= 2;
            break;
        case 5:
            ret = GetWPAData((tagASTSpktTKIP *)pData, &SecurityInfo[Mode].TkipData);
            Level |= 4;
            break;
        case 6:
            ret = GetWPAData((tagASTSpktTKIP *)pData, &SecurityInfo[Mode].AesData);
            Level |= 8;
            break;
        case 10:
            ret = GetBssidData((tagASTSpktBssid *)pData, Info->ProductInfo[Mode + 3]);
            break;
        default:
            ret = -3;
            break;
        }
        if (ret != 0)
            return ret;
        wLen = AOSS_Ntohs(((tagASTSsubAttrHeader *)pData)->length) + 4;
        Len -= wLen;
        pData += wLen;
    } while (Len > 0);
    aoss_bss.gData.aLevel |= Level;
    return 0;
}
