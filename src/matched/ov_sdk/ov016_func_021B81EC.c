/*
 * function: AOSS_Disconnect
 * address:  0x021B81EC
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SOC_Cleanup       0x0215FA90  arm
 *   AOSSi_Disconnect  0x021B8640  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Disconnect (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B81EC.c \
 *       --func AOSS_Disconnect --addr 0x021B81EC --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern int SOC_Cleanup(void);
extern int AOSSi_Disconnect(void);

int AOSS_Disconnect(void)
{
    if (SOC_Cleanup() < 0)
        return -1;
    return -(AOSSi_Disconnect() != 0);
}
