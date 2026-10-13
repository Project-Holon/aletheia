/*
 * function: DWC_InitGHTTP
 * address:  0x021BF558
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcGhttpParamList  0x021D3B20  data
 *   ghttpStartup  0x021C1FF8  arm  ov114
 *
 *
 * Bumps the 0x021D3B20 generation counter and reports success.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned int u32;
extern void ghttpStartup(void);
extern int gDwcGhttpParamList[];

int DWC_InitGHTTP(void)
{
    ghttpStartup();
    gDwcGhttpParamList[0]++;
    return 1;
}
