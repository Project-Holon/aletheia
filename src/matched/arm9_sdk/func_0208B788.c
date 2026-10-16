/*
 * function: MicGetResultCallback
 * address:  0x0208B788
 * packet:   pkt_0208B788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Netcheck_SetAllow302 (libdwcauth.TWL.HYB.a dwc_netcheck.o)
 *
 * symbols:
 *   DWChttp 0x02152FE0 data
 */

typedef struct DWCHttp {
    unsigned char pad[0x10];
    int allow302;
} DWCHttp;

extern DWCHttp DWChttp;

void MicGetResultCallback(int allow302)
{
    DWChttp.allow302 = allow302;
}
