/*
 * function: DWC_Auth_SetCustomNas
 * address:  0x02177EC8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the word at the state object.
 *
 * symbols:
 *   gDwcHttpParamArg  0x021A2358  data
 */

extern char gDwcHttpParamArg[];

void DWC_Auth_SetCustomNas(int v)
{
    *(int *)gDwcHttpParamArg = v;
}

