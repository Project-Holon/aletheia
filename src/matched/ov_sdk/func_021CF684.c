/*
 * function: DWCi_SETTINGlGetSsid
 * address:  0x021CF684
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTINGlGetSsid   0x021CF684  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *
 * Tail-call MI_CpuCopy8 with the global object +0x440, v and 0x20.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetSsid.c \
 *       --func DWCi_SETTINGlGetSsid --addr 0x021CF684 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void MI_CpuCopy8(char *, unsigned int, unsigned int);

void DWCi_SETTINGlGetSsid(unsigned int v)
{
    MI_CpuCopy8(*(char **)0x021DE644 + 0x440, v, 0x20);
}
