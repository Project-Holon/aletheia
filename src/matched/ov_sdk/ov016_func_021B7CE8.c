/*
 * function: PacketDataSet
 * address:  0x021B7CE8
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gSeqID       0x021DCDA0  data
 *   EncodeRC4    0x021B7DFC  thumb
 *   AOSS_Htons   0x021B830C  thumb
 *   AOSS_Memcpy  0x021B8230  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol PacketDataSet (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7CE8.c \
 *       --func PacketDataSet --addr 0x021B7CE8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned short size;
    unsigned char  iv[2];
    unsigned char  Data[1];
} tagASTSpktCryptData;

extern unsigned char gSeqID[8];
extern int EncodeRC4(unsigned char *srcData, unsigned char *EncodeData, int SizeOfData,
                     unsigned char *CRC, unsigned char *iv, unsigned char *key, int keylen);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern void *AOSS_Memcpy(void *dest, void *src, int n);

void PacketDataSet(int Type, unsigned char *pData, unsigned char *pPlaneData,
                   short *packet_size, short *CryptType, unsigned char *crc8)
{
    tagASTSpktCryptData *pcpt;

    if (Type == 1) {
        *CryptType = 1;
        pcpt = (tagASTSpktCryptData *)pData;
        EncodeRC4(pPlaneData, pcpt->Data, *packet_size, crc8, pcpt->iv, gSeqID, 8);
        pcpt->size = AOSS_Htons(*packet_size);
        *packet_size = *packet_size + 4;
    } else {
        AOSS_Memcpy(pData, pPlaneData, *packet_size);
    }
}
