/*
 * file:     unit_021771F8.c
 * function: DWC_GHTTPCleanupRootCAList
 * address:  0x021771F8
 * packet:   pkt_ov014_021771F8
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWC_GHTTPCleanupRootCAList (libdwcghttp.TWL.HYB.thumb.a(dwc_ghttp.o))
 *
 * symbols:
 *   ghttpCleanupRootCAList  0x02178E4C  thumb  ov014
 */

extern int ghttpCleanupRootCAList(char *url);

int DWC_GHTTPCleanupRootCAList(char *url)
{
    if (ghttpCleanupRootCAList(url) == 1)
        return 1;
    return 0;
}
