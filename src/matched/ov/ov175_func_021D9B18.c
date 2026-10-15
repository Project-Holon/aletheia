/*
 * function: WIFIBATTLEMATCH_NET_CopyCompResponse
 * address: 0x021D9B18
 * packet: pkt_ov175_021D9B18
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 * leaf: copy128 bytes from response+0x1c to save+0x54.
 */
extern void MI_CpuCopy8(const void *, void *, int);
void WIFIBATTLEMATCH_NET_CopyCompResponse(char *save, char *response)
{
    MI_CpuCopy8(response + 0x1c, save + 0x54, 128);
}
