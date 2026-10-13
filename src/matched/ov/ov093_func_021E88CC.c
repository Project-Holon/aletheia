/*
 * function: BTLV_CORE_LoadDsiOverlay
 * address:  0x021E88CC
 * packet:   pkt_ov093_021E88CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OS_GetConsoleType  0x02085CBC  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   gBtlvCoreDsiOverlayLoaded  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 OS_GetConsoleType(void);
extern int GF_OVERLAY_Load(signed int handle);
extern u8 ov140_id[];
extern int gBtlvCoreDsiOverlayLoaded;

void BTLV_CORE_LoadDsiOverlay(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        GF_OVERLAY_Load((int)ov140_id);
        gBtlvCoreDsiOverlayLoaded = 1;
    } else {
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}
