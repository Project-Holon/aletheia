/*
 * function: AstsSetInitRes
 * address:  0x021B7164
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
 *   GetProductInfo   0x021B7540  thumb
 *   GetSecurityType  0x021B796C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AstsSetInitRes (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7164.c \
 *       --func AstsSetInitRes --addr 0x021B7164 --region ov016 --cc ../2.0/sp1p2 --thumb
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
    tagASTSsubAttrHeader hdr;
    unsigned char        ProductData[1];
} tagASTSpktInitRes;

typedef struct {
    char ProductInfo[5][128];
} PRODUCT_INFO_AOSS;

extern int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern unsigned long AOSS_Ntohl(unsigned long netlong);
extern void aoss_set_error(unsigned int type);
extern int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo);
extern int GetSecurityType(unsigned int type);

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
