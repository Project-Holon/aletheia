/*
 * function: MakeSendSeqID
 * address:  0x021B7068
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Memcpy  0x021B8230  thumb
 *   AOSS_Rand    0x021B8378  thumb
 *   AOSS_Htons   0x021B830C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol MakeSendSeqID (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7068.c \
 *       --func MakeSendSeqID --addr 0x021B7068 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    char SendSeqID[8];
} SEQID_INFO;

extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern int AOSS_Rand(void);
extern unsigned short AOSS_Htons(unsigned short hostshort);

void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr)
{
    short *Num;
    int i;

    for (i = 0; i < Cnt; i++) {
        AOSS_Memcpy(SeqID->SendSeqID, Mymacaddr, 6);
        Num = (short *)&SeqID->SendSeqID[6];
        *Num = AOSS_Rand();
        *Num = AOSS_Htons(*Num);
        SeqID++;
    }
}
