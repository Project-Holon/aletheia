/*
 * function: func_02198E2C
 * address:  0x02198E2C
 * packet:   pkt_02198E2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TwlDWC GHTTP root CA list setter (libdwcghttp / dwc_ghttp.o).
 * Forwards the URL and this file's CA list to ghttpSetRootCAList and
 * returns whether it reports success (1).
 *
 * symbols:
 *   func_02198C4C       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A9C  data
 */

typedef int BOOL;

extern int  func_02198C4C(char *url, const void *list);
extern char DWCca_ghttp_caList[];

BOOL func_02198E2C(char *url)
{
    if (func_02198C4C(url, DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}
