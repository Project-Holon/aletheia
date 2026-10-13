/*
 * function: FLDMMDL_ACMD_Walk3FMove
 * address:  0x02198D7C
 * packet:   pkt_02198D7C
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
 *   FLDMMDL_ACMD_WalkTableMove       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A44  data
 */

typedef int BOOL;

typedef unsigned int   u32;
extern int FLDMMDL_ACMD_WalkTableMove(u32 a, u32 *b);
extern char DWCca_ghttp_caList[];

BOOL FLDMMDL_ACMD_Walk3FMove(char *url)
{
    if (FLDMMDL_ACMD_WalkTableMove((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}
