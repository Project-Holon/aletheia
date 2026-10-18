/*
 * function: AstsSetSecureRes
 * address:  0x021B7240
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss         0x021DC040  data
 *   CheckRecvSeqID   0x021B74F4  thumb
 *   AOSS_Ntohs       0x021B834C  thumb
 *   AOSS_Ntohl       0x021B8324  thumb
 *   aoss_set_error   0x021B6D74  thumb
 *   AOSS_Memset      0x021B8240  thumb
 *   GetSecurityData  0x021B785C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AstsSetSecureRes (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7240.c \
 *       --func AstsSetSecureRes --addr 0x021B7240 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern unsigned long AOSS_Ntohl(unsigned long netlong);
extern void aoss_set_error(unsigned int type);
extern void *AOSS_Memset(void *s, int c, int n);
extern int GetSecurityData(int Mode, unsigned char *pData, int Length, ASTS_DATA_INFO *SecurityInfo,
                           PRODUCT_INFO_AOSS *Info);

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
