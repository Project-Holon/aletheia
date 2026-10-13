/*
 * function: FLD_VREQ_ApplyChangeBlendBrightness
 * address:  0x021D3384
 * packet:   pkt_ov021_021D3384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWCi_WindowG2x_ChangeBlendBrightness_  0x0207D6C0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void DWCi_WindowG2x_ChangeBlendBrightness_(u32 addr, int brightness);

void FLD_VREQ_ApplyChangeBlendBrightness(u32 *p, int main)
{
    if (main) {
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, p[0]);
    } else {
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04001050, p[0]);
    }
}
