/*
 * file:     unit_021B6D8C_p01.c
 * unit:     yes
 * function: func_021B6D8C, func_021B6F84, func_021B6FA8, func_021B7024, func_021B7068, func_021B7098, func_021B70C4, func_021B7164, func_021B7240, func_021B7318, func_021B73BC, func_021B74B0, func_021B74F4, func_021B7540, func_021B75FC, func_021B7620, func_021B7774, GetBssidData, GetSecurityData
 * address:  0x021B6D8C
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
 *   aoss_bss        0x021DC040  data
 *   SecurityInfo    0x021DC700  data
 *   AOSS_Memset     0x021B8240  thumb
 *   AOSS_Memcpy     0x021B8230  thumb
 *   AOSS_Strlen     0x021B8364  thumb
 *   aoss_str_10367  0x021DAB14  data
 *   AOSS_Memcmp     0x021B8210  thumb
 *   aoss_str_10375  0x021DAB20  data
 *   AOSS_Rand    0x021B8378  thumb
 *   AOSS_Htons   0x021B830C  thumb
 *   aoss_data     0x021DAAB4  data
 *   AOSSi_Status  0x021B89C8  thumb
 *   AOSS_Ntohs        0x021B834C  thumb
 *   AOSS_Ntohl       0x021B8324  thumb
 *   aoss_set_error   0x021B6D74  thumb
 *   GetSecurityType  0x021B796C  thumb
 *   gSeqID          0x021DCDA0  data
 *   CryptSeqNo      0x021B8068  thumb
 *   AOSS_MALLOC     0x021B61B0  thumb
 *   DecodeRC4       0x021B7E78  thumb
 *   AOSS_FREE       0x021B61C0  thumb
 *   aoss_get_error  0x021B6D80  thumb
 *   AttrNo        0x021DAAB0  data
 *   GetWEPData    0x021B7620  thumb
 *   GetWPAData    0x021B7774  thumb
 *   GetBssidData  0x021B782C  thumb
 */
#include "../../matched/include/G_AOSS_BSS.h"
#include "../../matched/include/G_AOSS_DATA_SECTION.h"
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

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_rateset {
    unsigned long Num;
    unsigned char Rates[14];
} WLLA_RATESET;

typedef struct wlla_bss_info {
    WLLA_SSID     Ssid;
    unsigned long Channel;
    unsigned long Noise;
    unsigned long Signal;
    unsigned char Bssid[6];
    WLLA_RATESET  SupportRates;
    unsigned long BeaconPeriod;
    unsigned long Capability;
} WLLA_BSS_INFO;

typedef struct wlla_bss_list {
    unsigned long Num;
    WLLA_BSS_INFO BssInfo[1];
} WLLA_BSS_LIST;

typedef struct wlla_key {
    unsigned long Len;
    unsigned char Key[13];
} WLLA_KEY;

typedef struct wlla_connect_param {
    WLLA_SSID     Ssid;
    unsigned long AuthAlgo;
    WLLA_KEY      Key;
} WLLA_CONNECT_PARAM;

typedef struct {
    char SendSeqID[8];
} SEQID_INFO;

/*
 * aoss.o's 96-byte .data section (0x021DAAB4): s_sFd, AOSS_StatusExclusion's
 * static before, and soconfig, declared as one object because the vendor
 * object addresses them section-relative.
 */
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

typedef struct SEND_INFO SEND_INFO;

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
    int            sockfd;
    int            recvlen;
    unsigned long  cli_ip;
    unsigned char  packet[1500];
    unsigned short port;
    unsigned char  IfHwAddress[8];
    unsigned long  MyIp_addr;
} RECV_INFO;

typedef struct {
    tagASTSsubAttrHeader hdr;
    unsigned long        Result;
} tagASTSpktResult;

typedef struct {
    tagASTSsubAttrHeader hdr;
    unsigned char        ProductData[1];
} tagASTSpktInitRes;

typedef struct {
    unsigned short size;
    unsigned char  iv[2];
    unsigned char  Data[1];
} tagASTSpktCryptData;

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

typedef struct {
    unsigned short size;
    unsigned char  WEP[1];
} tagWepData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWepData           WEP;
} tagASTSpktWEP40;

typedef struct {
    unsigned short size;
    unsigned char  WpaPsk[1];
} tagWpaPskData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWpaPskData        WpaPsk;
} tagASTSpktTKIP;

typedef struct {
    unsigned short size;
    unsigned char  Bssid[1];
} tagBssidData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagBssidData         Bssid;
} tagASTSpktBssid;

extern void *AOSS_Memset(void *s, int c, int n);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern int AOSS_Strlen(char *s);
extern int AOSS_Memcmp(void *s1, void *s2, int n);
extern int AOSS_Rand(void);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern int AOSSi_Status(int stat);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern unsigned long AOSS_Ntohl(unsigned long netlong);
extern void aoss_set_error(unsigned int type);
extern int GetSecurityType(unsigned int type);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern void *AOSS_MALLOC(int a);
extern int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData,
                     unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen);
extern void AOSS_FREE(void *a);
extern unsigned int aoss_get_error(void);
int AOSS_seq_data_copy(struct aoss_info *aossInfo);
int aoss_check_str(char *ptr, int count);
int checkAP(WLLA_BSS_LIST *list);
int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap);
void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr);
int AOSS_StatusExclusion(int stat);
int RecvMessage(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *SendSeqID);
int AstsSetInitRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int AstsSetSecureRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int AstsRestartRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int DecodePacket(unsigned char *tpkt);
int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID);
int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo);
unsigned long aoss_get_bin(void *ptr, int num);
int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info);
int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info);
int GetBssidData(tagASTSpktBssid *pBssid, char *BSSID);
int GetSecurityData(int Mode, unsigned char *pData, int Length, ASTS_DATA_INFO *SecurityInfo, PRODUCT_INFO_AOSS *Info);
extern struct AOSS_BSS aoss_bss;
extern ASTS_DATA_INFO SecurityInfo[2];
extern char aoss_str_10367[];
extern char aoss_str_10375[];
extern struct AOSS_DATA_SECTION aoss_data;
extern unsigned char gSeqID[8];
extern unsigned char AttrNo[];





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

int aoss_check_str(char *ptr, int count)
{
    int i;
    unsigned char str;

    for (i = 0; i < count; i++) {
        str = *ptr++;
        if (str < 0x20 || str > 0x7f)
            return -1;
    }
    return 0;
}


int checkAP(WLLA_BSS_LIST *list)
{
    int count, ret, num;
    int find;

    ret = 0;
    find = 0;
    num = list->Num;
    if (num == 0)
        return 5;
    if (list->Num > 64)
        num = 64;
    for (count = 0; count < num; count++) {
        if (list->BssInfo[count].Capability & 1) {
            if (list->BssInfo[count].Ssid.Len == AOSS_Strlen(aoss_str_10367) &&
                AOSS_Memcmp(list->BssInfo[count].Ssid.Ssid, aoss_str_10367, AOSS_Strlen(aoss_str_10367)) == 0)
                find++;
        }
    }
    if (find > 1)
        ret = 4;
    if (find == 0)
        ret = 5;
    return ret;
}


int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap)
{
    ap->Ssid.Len = AOSS_Strlen(aoss_str_10367);
    AOSS_Memcpy(ap->Ssid.Ssid, aoss_str_10367, ap->Ssid.Len);
    ap->AuthAlgo = 1;
    ap->Key.Len = AOSS_Strlen(aoss_str_10375);
    if (ap->Key.Len > 13)
        return -1;
    AOSS_Memcpy(ap->Key.Key, aoss_str_10375, ap->Key.Len);
    return 0;
}


void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr)
{
    short *Num;
    int i;

    for (i = 0; i < Cnt; i++) {
        AOSS_Memcpy(SeqID->SendSeqID, Mymacaddr, 6);
        Num = (short *)&SeqID->SendSeqID[6];
        *Num = AOSS_Rand();
        *Num = AOSS_Htons(*Num);
        SeqID++;
    }
}


int AOSS_StatusExclusion(int stat)
{
    if (stat == -1) {
        aoss_data.before = stat;
        return 0;
    }
    if (aoss_data.before != stat) {
        aoss_data.before = stat;
        return AOSSi_Status(stat);
    }
    return 0;
}


int RecvMessage(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *SendSeqID)
{
    int ret;
    tagASTSpktHeader *hdr;

    hdr = (tagASTSpktHeader *)recv_info->packet;
    if (AOSS_Ntohs(hdr->PktVersion) < 1) {
        (*Retry)++;
        return Mode;
    }
    if (hdr->Fragment != 0x11) {
        (*Retry)++;
        return Mode;
    }
    ret = DecodePacket(recv_info->packet);
    if (ret > 0) {
        (*Retry)++;
        return Mode;
    }
    switch (AOSS_Ntohs(hdr->cmd)) {
    case 0x1010:
        Mode = AstsSetInitRes(Mode, recv_info, Retry, SendSeqID);
        break;
    case 0x2010:
        Mode = AstsSetSecureRes(Mode, recv_info, Retry, SendSeqID);
        break;
    case 0x3010:
        Mode = AstsRestartRes(Mode, recv_info, Retry, SendSeqID);
        break;
    }
    return Mode;
}


int AstsSetInitRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    unsigned long *Ret;
    tagASTSpktInitRes *plv;
    tagASTSpktHeader *ptr;
    int ret;

    if (Mode != 0) {
        (*Retry)++;
        return Mode;
    }
    ptr = (tagASTSpktHeader *)recv_info->packet;
    plv = (tagASTSpktInitRes *)(recv_info->packet + sizeof(tagASTSpktHeader));
    if (CheckRecvSeqID(pSeqID->SendSeqID, ptr->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohs(plv->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (plv->hdr.SubAttrNo == 7) {
        Ret = (unsigned long *)plv->ProductData;
        if (AOSS_Ntohl(*Ret) == -2)
            aoss_set_error(0x14);
        else if (AOSS_Ntohl(*Ret) == -3)
            aoss_set_error(0x15);
        else
            aoss_set_error(0x18);
        return -1;
    }
    if (plv->hdr.SubAttrNo != 1) {
        (*Retry)++;
        return Mode;
    }
    ret = GetProductInfo((char *)plv->ProductData, (PRODUCT_INFO_AOSS *)aoss_bss.ProductInfo);
    if (ret < 0) {
        if (ret == -2) {
            aoss_set_error(0x16);
            return -1;
        }
        (*Retry)++;
        return Mode;
    }
    aoss_bss.SecurityType = GetSecurityType(AOSS_Ntohs(ptr->CryptType));
    *Retry = 0;
    return 1;
}


int AstsSetSecureRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    tagASTSpktResult *temp;
    unsigned char *pData;
    tagASTSpktHeader *ptr;

    if (Mode != 1) {
        (*Retry)++;
        return Mode;
    }
    ptr = (tagASTSpktHeader *)recv_info->packet;
    pData = recv_info->packet + sizeof(tagASTSpktHeader);
    if (CheckRecvSeqID(pSeqID[1].SendSeqID, ptr->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    temp = (tagASTSpktResult *)pData;
    if (AOSS_Ntohs(temp->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (temp->hdr.SubAttrNo == 7) {
        if (AOSS_Ntohl(temp->Result) == -2)
            aoss_set_error(0x14);
        else if (AOSS_Ntohl(temp->Result) == -3)
            aoss_set_error(0x15);
        else
            aoss_set_error(0x18);
        return -1;
    }
    AOSS_Memset(aoss_bss.SecurityInfo, 0, sizeof(aoss_bss.SecurityInfo));
    if (GetSecurityData(0, pData, AOSS_Ntohs(ptr->size), (ASTS_DATA_INFO *)aoss_bss.SecurityInfo,
                        (PRODUCT_INFO_AOSS *)aoss_bss.ProductInfo) < 0) {
        (*Retry)++;
        return Mode;
    }
    if ((aoss_bss.gData_aLevel & aoss_bss.gData_sLevel) == 0)
        return Mode;
    *Retry = 0;
    return 2;
}


int AstsRestartRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    tagASTSpktResult *rslt;

    if (Mode != 2) {
        (*Retry)++;
        return Mode;
    }
    rslt = (tagASTSpktResult *)(recv_info->packet + sizeof(tagASTSpktHeader));
    if (CheckRecvSeqID(pSeqID[2].SendSeqID, ((tagASTSpktHeader *)recv_info->packet)->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    if (rslt->hdr.SubAttrNo != 7) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohs(rslt->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohl(rslt->Result) == 0)
        return 100;
    if (AOSS_Ntohl(rslt->Result) == -2) {
        aoss_set_error(0x14);
        return -1;
    }
    if (AOSS_Ntohl(rslt->Result) == -3) {
        aoss_set_error(0x15);
        return -1;
    }
    aoss_set_error(0x18);
    return -1;
}


int DecodePacket(unsigned char *tpkt)
{
    int size;
    unsigned char wrkSeqID[8];
    unsigned char *DecodeData;
    tagASTSpktCryptData *pRc4;
    tagASTSpktHeader *hdr;

    hdr = (tagASTSpktHeader *)tpkt;
    pRc4 = (tagASTSpktCryptData *)(tpkt + sizeof(tagASTSpktHeader));
    AOSS_Memcpy(wrkSeqID, hdr->SeqID, 8);
    if (CryptSeqNo(wrkSeqID, 8, aoss_str_10375, AOSS_Strlen(aoss_str_10375)) == -1) {
        aoss_set_error(2);
        return -100;
    }
    size = CheckSeqID(AOSS_Ntohs(hdr->cmd), wrkSeqID);
    if (size != 0)
        return size;
    if (AOSS_Ntohs(hdr->cmd) == 0x1000)
        AOSS_Memcpy(gSeqID, wrkSeqID, 8);
    if ((AOSS_Ntohs(hdr->CryptType) & 0xF) == 0)
        return 0;
    size = AOSS_Ntohs(pRc4->size);
    DecodeData = AOSS_MALLOC(size);
    if (DecodeData == 0) {
        aoss_set_error(2);
        return 100;
    }
    if (DecodeRC4(pRc4->Data, DecodeData, size, hdr->crc8, pRc4->iv, gSeqID, 8) < 0) {
        AOSS_FREE(DecodeData);
        if (aoss_get_error() == 2)
            return 100;
        return 200;
    }
    AOSS_Memcpy(pRc4, DecodeData, size);
    hdr->size = AOSS_Htons(size);
    AOSS_FREE(DecodeData);
    return 0;
}



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


int GetBssidData(tagASTSpktBssid *pBssid, char *BSSID)
{
    VariableData *Data;
    int length;

    Data = (VariableData *)pBssid->Bssid.Bssid;
    length = AOSS_Ntohs(Data->length);
    if (length <= 0)
        return -1;
    if (Data->DataID != 0x70)
        return -1;
    AOSS_Memcpy(BSSID, Data->Data, length);
    return 0;
}


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
    aoss_bss.gData_aLevel |= Level;
    return 0;
}
