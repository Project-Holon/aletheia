/*
 * file:     unit_021771F8.c
 * function: DWC_GHTTPCleanupRootCAList, func_0217720C, func_02177214
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
 *   func_02177C3C  0x02177C3C  thumb  ov014
 *   func_02177C44  0x02177C44  thumb  ov014
 */

extern int ghttpCleanupRootCAList(char *url);
extern unsigned int func_02177C3C(void);
extern int func_02177C44(void);
unsigned int func_0217720C(void);
int func_02177214(void);

int DWC_GHTTPCleanupRootCAList(char *url)
{
    if (ghttpCleanupRootCAList(url) == 1)
        return 1;
    return 0;
}

unsigned int func_0217720C(void)
{
    return func_02177C3C();
}

int func_02177214(void)
{
    return func_02177C44();
}
