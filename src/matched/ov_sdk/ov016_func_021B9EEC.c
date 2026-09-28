/*
 * function: GetFrameData
 * address:  0x021B9EEC
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol GetFrameData (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9EEC.c \
 *       --func GetFrameData --addr 0x021B9EEC --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _FRAMEHEADER {
    unsigned short FrameID;
    unsigned short DataLength;
    unsigned short Reserved;
} FRAMEHEADER;

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize)
{
    FRAMEHEADER *pfh;
    unsigned short *psum;
    unsigned long dwsum;
    unsigned char *lps;

    pfh = (FRAMEHEADER *)lpframe;
    dwsum = 0;
    *pid = SWAP16(pfh->FrameID);
    *psize = SWAP16(pfh->DataLength);
    psum = (unsigned short *)(lpframe + sizeof(FRAMEHEADER) + *psize);
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    if ((unsigned short)dwsum != SWAP16(*psum))
        return 0;
    return lpframe + sizeof(FRAMEHEADER);
}
