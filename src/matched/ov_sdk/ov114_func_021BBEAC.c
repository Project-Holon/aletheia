/*
 * function: NHTTPi_IsCreateCommThreadMessageQueueOff
 * address:  0x021BBEAC
 * packet:   pkt_ov114_021BBEAC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlWiFi_base/libnhttp.TWL.HYB.a(nhttp_thread.o).  decl_line 106, param
 * threadInfo_p.
 */
typedef unsigned long u32;

void NHTTPi_IsCreateCommThreadMessageQueueOff(void *threadInfo_p)
{
    *(u32 *)((char *)threadInfo_p + 0xEC) = 0;
}
