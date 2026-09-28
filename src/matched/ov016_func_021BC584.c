/*
 * function: GetTickCount
 * address:  0x021BC584
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol GetTickCount (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC584.c \
 *       --func GetTickCount --addr 0x021BC584 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern unsigned long long OS_GetTick(void);

unsigned long GetTickCount(void)
{
    return (unsigned long)((OS_GetTick() * 64) / 0x82EA);
}
