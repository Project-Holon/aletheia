/*
 * function: DWC_GHTTPCleanupRootCAList
 * address:  0x02179C98
 * packet:   pkt_ov015_02179C98
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWC_GHTTPCleanupRootCAList (libdwcghttp.TWL.HYB.thumb.a(dwc_ghttp.o))
 *
 * symbols:
 *   ghttpCleanupRootCAList  0x02179D30  thumb  ov015
 */

extern int ghttpCleanupRootCAList(char *url);

int DWC_GHTTPCleanupRootCAList(char *url)
{
    if (ghttpCleanupRootCAList(url) == 1)
        return 1;
    return 0;
}
