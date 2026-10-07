/*
 * file:     unit_021B6D8C_p02.c
 * unit:     yes
 * function: func_021B74B0, func_021B74F4, func_021B7540, func_021B75FC, func_021B7620, func_021B7774
 * address:  0x021B74B0
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gSeqID       0x021DCDA0  data
 *   AOSS_Memcmp  0x021B8210  thumb
 *   aoss_str_10375  0x021DAB20  data
 *   AOSS_Strlen     0x021B8364  thumb
 *   CryptSeqNo      0x021B8068  thumb
 *   AOSS_Ntohs      0x021B834C  thumb
 *   aoss_bss      0x021DC040  data
 *   AOSS_Memset   0x021B8240  thumb
 *   AOSS_Memcpy   0x021B8230  thumb
 *   AOSS_Ntohl    0x021B8324  thumb
 */
#include "../../matched/include/G_AOSS_BSS.h"

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
    unsigned short size;
    unsigned char  WEP[1];
} tagWepData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWepData           WEP;
} tagASTSpktWEP40;

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[4][64];
} ASTS_DATA_WEP;

typedef struct {
    unsigned short size;
    unsigned char  WpaPsk[1];
} tagWpaPskData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWpaPskData        WpaPsk;
} tagASTSpktTKIP;

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[64];
} ASTS_DATA_TKIP;

extern int AOSS_Memcmp(void *s1, void *s2, int n);
extern int AOSS_Strlen(char *s);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern void *AOSS_Memset(void *s, int c, int n);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern unsigned long AOSS_Ntohl(unsigned long netlong);
int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID);
int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo);
unsigned long aoss_get_bin(void *ptr, int num);
int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info);
int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info);
extern unsigned char gSeqID[8];
extern char aoss_str_10375[];
extern struct AOSS_BSS aoss_bss;


int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID)
{
    int i, flag, ret;

    ret = 0;
    flag = 0;
    for (i = 0; i < 6; i++) {
        if (gSeqID[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        if (AOSS_Memcmp(gSeqID, RecvSeqID, 6) != 0)
            ret = 1;
    } else if (CMD != 0x1000) {
        ret = 2;
    }
    return ret;
}


int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID)
{
    int ret = 0;

    CryptSeqNo(RecvSeqID, 8, aoss_str_10375, AOSS_Strlen(aoss_str_10375));
    if (AOSS_Memcmp(SendSeqID, RecvSeqID, 6) != 0) {
        ret -= 1;
    } else if (AOSS_Ntohs(*(unsigned short *)(SendSeqID + 6)) + 1 != AOSS_Ntohs(*(unsigned short *)(RecvSeqID + 6))) {
        ret -= 2;
    }
    return ret;
}


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

unsigned long aoss_get_bin(void *ptr, int num)
{
    unsigned long ret = 0;
    int i;
    unsigned char *p = (unsigned char *)ptr + (num - 1);

    for (i = 0; i < num; i++) {
        ret = (ret << 8) + *p--;
    }
    return ret;
}


int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info)
{
    VariableData *Data;
    unsigned int length;

    Data = (VariableData *)pWEP->WEP.WEP;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        switch (Data->DataID) {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            if (length > 5)
                return -1;
            break;
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
            if (length > 0xD)
                return -1;
            break;
        case 0x15:
        case 0x25:
            if (length > 0x21)
                return -1;
            break;
        }
        switch (Data->DataID) {
        case 0x10:
        case 0x20:
            AOSS_Memcpy(Info->Data[0], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x11:
        case 0x21:
            AOSS_Memcpy(Info->Data[1], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x12:
        case 0x22:
            AOSS_Memcpy(Info->Data[2], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x13:
        case 0x23:
            AOSS_Memcpy(Info->Data[3], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x15:
        case 0x25:
            if (length != 0 && Data->Data[length - 1] != 0)
                return -1;
            AOSS_Memcpy(Info->SSID, Data->Data, length);
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(pWEP->WEP.WEP + AOSS_Ntohs(Data->offset));
    }
    return 0;
}


int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info)
{
    VariableData *Data;
    unsigned int length;

    Data = (VariableData *)pWPA->WpaPsk.WpaPsk;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        switch (Data->DataID) {
        case 0x30:
        case 0x40:
            if (length > 0x40)
                return -1;
            break;
        case 0x35:
        case 0x45:
            if (length > 0x21)
                return -1;
            break;
        }
        switch (Data->DataID) {
        case 0x30:
        case 0x40:
            AOSS_Memcpy(Info->Data, Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x35:
        case 0x45:
            if (length != 0 && Data->Data[length - 1] != 0)
                return -1;
            AOSS_Memcpy(Info->SSID, Data->Data, length);
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(pWPA->WpaPsk.WpaPsk + AOSS_Ntohs(Data->offset));
    }
    return 0;
}
