/*
 * function: WIH_SetScanTarget
 * address: 0x02178714
 * packet: pkt_ov014_02178714
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *gWihWork;
extern void MI_CpuCopy8(void *src, void *dst, int n);
void WIH_SetScanTarget(u16 value, void *src)
{
    *(u16 *)(gWihWork + 0x1eb2) = value;
    MI_CpuCopy8(src, gWihWork + 0x140a, 6);
}
