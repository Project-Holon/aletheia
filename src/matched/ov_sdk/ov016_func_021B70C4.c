/*
 * function: RecvMessage
 * address:  0x021B70C4
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Ntohs        0x021B834C  thumb
 *   DecodePacket      0x021B73BC  thumb
 *   AstsSetInitRes    0x021B7164  thumb
 *   AstsSetSecureRes  0x021B7240  thumb
 *   AstsRestartRes    0x021B7318  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol RecvMessage (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B70C4.c \
 *       --func RecvMessage --addr 0x021B70C4 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern int DecodePacket(unsigned char *tpkt);
extern int AstsSetInitRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
extern int AstsSetSecureRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
extern int AstsRestartRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);

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
