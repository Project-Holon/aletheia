/*
 * function: DecodePacket
 * address:  0x021B73BC
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_str_10375  0x021DAB20  data
 *   gSeqID          0x021DCDA0  data
 *   AOSS_Memcpy     0x021B8230  thumb
 *   AOSS_Strlen     0x021B8364  thumb
 *   CryptSeqNo      0x021B8068  thumb
 *   aoss_set_error  0x021B6D74  thumb
 *   AOSS_Ntohs      0x021B834C  thumb
 *   CheckSeqID      0x021B74B0  thumb
 *   AOSS_MALLOC     0x021B61B0  thumb
 *   DecodeRC4       0x021B7E78  thumb
 *   AOSS_FREE       0x021B61C0  thumb
 *   aoss_get_error  0x021B6D80  thumb
 *   AOSS_Htons      0x021B830C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol DecodePacket (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * aoss_str_10375 is the object's anonymous .data string literal @10375 (6 bytes), the
 * sequence-number key.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B73BC.c \
 *       --func DecodePacket --addr 0x021B73BC --region ov016 --cc ../2.0/sp1p2 --thumb
 */
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
    unsigned char  iv[2];
    unsigned char  Data[1];
} tagASTSpktCryptData;

extern unsigned char gSeqID[8];
extern char aoss_str_10375[];
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern int AOSS_Strlen(char *s);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern void aoss_set_error(unsigned int type);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID);
extern void *AOSS_MALLOC(int a);
extern int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData,
                     unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen);
extern void AOSS_FREE(void *a);
extern unsigned int aoss_get_error(void);
extern unsigned short AOSS_Htons(unsigned short hostshort);

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
