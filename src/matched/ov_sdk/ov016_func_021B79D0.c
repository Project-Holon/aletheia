/*
 * function: AstsSetInitReq
 * address:  0x021B79D0
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
 *   gSeqID           0x021DCDA0  data
 *   aoss_str_10375   0x021DAB20  data
 *   AOSS_Memset      0x021B8240  thumb
 *   AOSS_MALLOC      0x021B61B0  thumb
 *   aoss_set_error   0x021B6D74  thumb
 *   AOSS_Memcpy      0x021B8230  thumb
 *   SetStaData       0x021B7C5C  thumb
 *   AOSS_FREE        0x021B61C0  thumb
 *   AOSS_Htons       0x021B830C  thumb
 *   PacketDataSet    0x021B7CE8  thumb
 *   CryptSeqNo       0x021B8068  thumb
 *   SetPacketHeader  0x021B7D3C  thumb
 *   SendPacketUDP    0x021B7D94  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AstsSetInitReq (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * aoss_str_10375 is the object's anonymous .data string literal @10375 (6 bytes), the
 * sequence-number key. DWARF leaves out the unused first parameter (SEND_INFO *send_info),
 * which SendMessage passes in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B79D0.c \
 *       --func AstsSetInitReq --addr 0x021B79D0 --region ov016 --cc ../2.0/sp1p2 --thumb
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
    tagASTSsubAttrHeader info;
    unsigned char        StaData[1];
} tagASTSpktRequest;

extern unsigned char gSeqID[8];
extern char aoss_str_10375[];
extern void *AOSS_Memset(void *s, int c, int n);
extern void *AOSS_MALLOC(int a);
extern void aoss_set_error(unsigned int type);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern short SetStaData(char *StaData);
extern void AOSS_FREE(void *a);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern void PacketDataSet(int Type, unsigned char *pData, unsigned char *pPlaneData,
                          short *packet_size, short *CryptType, unsigned char *crc8);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern void SetPacketHeader(tagASTSpktHeader *Hdr, short cmd, short size, short CryptType,
                            char crc8, char Fragment, unsigned char *SeqID);
extern int SendPacketUDP(unsigned char *packet, int size, unsigned char Mac, int port);

int AstsSetInitReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd)
{
    struct UdpIpMsg *send_msg;
    short packet_size;
    short CryptType;
    tagASTSpktRequest *PlaneData;
    unsigned char wrkSeqID[8];
    unsigned char crc8;
    unsigned char *pData;

    crc8 = 0;
    packet_size = 0;
    CryptType = 0;
    send_msg = aoss_bss.s_buf;
    AOSS_Memset(send_msg, 0, sizeof(struct UdpIpMsg));
    PlaneData = AOSS_MALLOC(0x210);
    if (PlaneData == 0) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memset(PlaneData, 0, 0x210);
    pData = send_msg->udpipmsg + sizeof(tagASTSpktHeader);
    AOSS_Memcpy(gSeqID, pSeqID->SendSeqID, 8);
    AOSS_Memcpy(wrkSeqID, gSeqID, 8);
    packet_size = SetStaData((char *)PlaneData->StaData);
    if (packet_size < 0) {
        aoss_set_error(3);
        if (PlaneData != 0)
            AOSS_FREE(PlaneData);
        return -1;
    }
    PlaneData->info.SubAttrNo = 0;
    PlaneData->info.length = AOSS_Htons(packet_size);
    packet_size += 4;
    PacketDataSet(0, pData, (unsigned char *)PlaneData, &packet_size, &CryptType, &crc8);
    CryptType |= 0x10;
    if (CryptSeqNo(wrkSeqID, 8, aoss_str_10375, 6) != 0) {
        aoss_set_error(2);
        if (PlaneData != 0)
            AOSS_FREE(PlaneData);
        return -1;
    }
    SetPacketHeader((tagASTSpktHeader *)send_msg, 0x1000, packet_size, CryptType, crc8, 0x11, wrkSeqID);
    packet_size += sizeof(tagASTSpktHeader);
    SendPacketUDP(send_msg->udpipmsg, packet_size, 0xFF, sFd);
    if (PlaneData != 0)
        AOSS_FREE(PlaneData);
    return 0;
}
