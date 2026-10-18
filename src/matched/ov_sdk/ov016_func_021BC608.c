/*
 * function: PutMac
 * address:  0x021BC608
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PutHex  0x021BC5D4  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol PutMac (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC608.c \
 *       --func PutMac --addr 0x021BC608 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern int PutHex(char *lpwrite, char ch);

int PutMac(char *lpwrite, char *lps)
{
    char *lpw;
    int i;

    lpw = lpwrite;
    for (i = 0; i < 6; i++) {
        lpw += PutHex(lpw, *lps++);
        if (i < 5)
            *lpw++ = ':';
    }
    *lpw = 0;
    return lpw - lpwrite;
}
