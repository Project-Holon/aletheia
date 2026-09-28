/*
 * function: DWCi_Http_InitCpsSocket
 * address:  0x0217988C
 * packet:   pkt_ov009_0217988C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_InitCpsSocket (dwc_http.o)
 *
 * symbols:
 *   MI_CpuFill8      0x02082bcc  arm
 *   CPS_SocRegister  0x0215aa5c  arm
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SocRegister(void *soc);

static void DWCi_Http_InitCpsSocket(char *http)
{
    MI_CpuFill8(http + 0x1138, 0, 0xa0);
    *(unsigned long *)(http + 0x1180) = 0xb68;
    *(unsigned long *)(http + 0x1184) = *(unsigned long *)(http + 0x1a08);
    *(unsigned long *)(http + 0x118c) = 0x5ea;
    *(unsigned long *)(http + 0x1190) = *(unsigned long *)(http + 0x1a0c);
    CPS_SocRegister(http + 0x1138);
}
