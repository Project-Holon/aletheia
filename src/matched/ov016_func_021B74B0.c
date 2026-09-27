/*
 * function: CheckSeqID
 * address:  0x021B74B0
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
 *   AOSS_Memcmp  0x021B8210  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol CheckSeqID (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B74B0.c \
 *       --func CheckSeqID --addr 0x021B74B0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

extern unsigned char gSeqID[8];
extern int AOSS_Memcmp(void *s1, void *s2, int n);

int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID)
{
    int i, flag, ret;

    ret = 0;
    flag = 0;
    for (i = 0; i < 6; i++) {
        if (gSeqID[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        if (AOSS_Memcmp(gSeqID, RecvSeqID, 6) != 0)
            ret = 1;
    } else if (CMD != 0x1000) {
        ret = 2;
    }
    return ret;
}
