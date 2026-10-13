/*
 * function: NHTTPi_InitThreadInfo
 * address:  0x021BBE94
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_IsCreateCommThreadMessageQueueOff  0x021BBEAC  arm  ov114
 *
 *
 * Tail-call thunk to the unnamed ARM setter at 0x021BBEAC.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTPi_IsCreateCommThreadMessageQueueOff(void);

void NHTTPi_InitThreadInfo(u8 *a0)
{
    NHTTPi_IsCreateCommThreadMessageQueueOff();
}
