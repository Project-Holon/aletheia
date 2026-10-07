/*
 * function: func_02198D24
 * address:  0x02198D24
 * packet:   pkt_02198D24
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
 *   DWCca_ghttp_caList  0x021D4A68  data
 */

typedef int BOOL;

typedef unsigned int   u32;
extern int func_02198C4C(u32 a, u32 *b);
extern char DWCca_ghttp_caList[];

BOOL func_02198D24(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}
