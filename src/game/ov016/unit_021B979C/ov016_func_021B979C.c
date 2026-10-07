/*
 * function: alarmCallback
 * address:  0x021B979C
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AtermApc_callback  0x021B976C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol alarmCallback (name from the vendor
 * object; a 12-byte local with no label in function_starts.txt, witnessed by the ABS32 at
 * ConnectAP+0x118). atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its
 * .comment), which is the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c).
 * AtermApc_callback is installed as the APC user callback (event, arg); DWARF drops the
 * unused arg, and this caller passes it as zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B979C.c \
 *       --func alarmCallback --addr 0x021B979C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern void AtermApc_callback(int event, void *arg);

static void alarmCallback(void *event)
{
    AtermApc_callback((int)event, 0);
}
