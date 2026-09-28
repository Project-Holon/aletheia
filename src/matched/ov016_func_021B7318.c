/*
 * function: AstsRestartRes
 * address:  0x021B7318
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CheckRecvSeqID  0x021B74F4  thumb
 *   AOSS_Ntohs      0x021B834C  thumb
 *   AOSS_Ntohl      0x021B8324  thumb
 *   aoss_set_error  0x021B6D74  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AstsRestartRes (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7318.c \
 *       --func AstsRestartRes --addr 0x021B7318 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern unsigned long AOSS_Ntohl(unsigned long netlong);
extern void aoss_set_error(unsigned int type);

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
