/*
 * function: CheckRecvSeqID
 * address:  0x021B74F4
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
 *   AOSS_Strlen     0x021B8364  thumb
 *   CryptSeqNo      0x021B8068  thumb
 *   AOSS_Memcmp     0x021B8210  thumb
 *   AOSS_Ntohs      0x021B834C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol CheckRecvSeqID (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 * aoss_str_10375 is the object's anonymous .data string literal @10375 (6 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B74F4.c \
 *       --func CheckRecvSeqID --addr 0x021B74F4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

extern char aoss_str_10375[];
extern int AOSS_Strlen(char *s);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern int AOSS_Memcmp(void *s1, void *s2, int n);
extern unsigned short AOSS_Ntohs(unsigned short netshort);

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
