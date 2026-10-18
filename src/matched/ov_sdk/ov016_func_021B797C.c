/*
 * function: SendMessage
 * address:  0x021B797C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   AOSS_StatusExclusion  0x021B7098  thumb
 *   AstsSetInitReq        0x021B79D0  thumb
 *   AstsSetSecureReq      0x021B7B14  thumb
 *   AstsRestartReq        0x021B7BF0  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol SendMessage (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B797C.c \
 *       --func SendMessage --addr 0x021B797C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct SEND_INFO SEND_INFO;

typedef struct {
    char SendSeqID[8];
} SEQID_INFO;

extern int AOSS_StatusExclusion(int stat);
extern int AstsSetInitReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd);
extern int AstsSetSecureReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd);
extern int AstsRestartReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd);

int SendMessage(int SendReq, SEND_INFO *send_info, SEQID_INFO *SendSeqID, int sFd)
{
    int ret;

    switch (SendReq) {
    case 0:
        AOSS_StatusExclusion(2);
        ret = AstsSetInitReq(send_info, SendSeqID, sFd);
        break;
    case 1:
        AOSS_StatusExclusion(3);
        ret = AstsSetSecureReq(send_info, SendSeqID, sFd);
        break;
    case 2:
        AOSS_StatusExclusion(5);
        ret = AstsRestartReq(send_info, SendSeqID, sFd);
        break;
    default:
        ret = -1;
        break;
    }
    return ret;
}
