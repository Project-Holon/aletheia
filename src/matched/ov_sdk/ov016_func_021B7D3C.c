/*
 * function: SetPacketHeader
 * address:  0x021B7D3C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   AOSS_Htons   0x021B830C  thumb
 *   AOSS_Memcpy  0x021B8230  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol SetPacketHeader (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7D3C.c \
 *       --func SetPacketHeader --addr 0x021B7D3C --region ov016 --cc ../2.0/sp1p2 --thumb
 */

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

extern unsigned short AOSS_Htons(unsigned short hostshort);
extern void *AOSS_Memcpy(void *dest, void *src, int n);

void SetPacketHeader(tagASTSpktHeader *Hdr, short cmd, short size, short CryptType,
                     char crc8, char Fragment, unsigned char *SeqID)
{
    Hdr->PktVersion = AOSS_Htons(1);
    Hdr->PktID = 0;
    Hdr->PktSubID = 0;
    Hdr->cmd = AOSS_Htons(cmd);
    Hdr->type = 0;
    Hdr->size = AOSS_Htons(size);
    Hdr->CryptType = AOSS_Htons(CryptType);
    Hdr->crc8 = crc8;
    Hdr->Fragment = Fragment;
    AOSS_Memcpy(Hdr->SeqID, SeqID, 8);
}
