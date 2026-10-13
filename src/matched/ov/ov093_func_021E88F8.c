/*
 * function: BTLV_CORE_UnloadDsiOverlay
 * address:  0x021E88F8
 * packet:   pkt_ov093_021E88F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   gBtlvCoreDsiOverlayLoaded  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GF_OVERLAY_Unload(int handle);
extern u8 ov140_id[];
extern int gBtlvCoreDsiOverlayLoaded;

void BTLV_CORE_UnloadDsiOverlay(void)
{
    if (gBtlvCoreDsiOverlayLoaded != 0) {
        GF_OVERLAY_Unload((int)ov140_id);
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}
