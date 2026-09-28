/*
 * function: changeScanChannel
 * address:  0x021F4560
 * packet:   pkt_ov107_021F4560
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   WM_GetAllowedChannel             0x0208ee60 arm
 */
typedef unsigned short u16;

struct WMScanExParam {
    char _0[6];
    u16 channel;
};

extern u16 WM_GetAllowedChannel(void);

static int changeScanChannel(struct WMScanExParam *p)
{
    u16 i;
    u16 channel_bmp;
    u16 channel;

    channel_bmp = WM_GetAllowedChannel();
    if (channel_bmp == 0)
        return 0;
    i = 0;
    channel = p->channel;
    do {
        if ((channel_bmp & channel) != 0 && p->channel != channel) {
            p->channel = channel;
            break;
        }
        i = (u16)(i + 1);
        channel = (u16)(channel == 0 ? 1 : channel << 1);
    } while (i < 16);
    return 1;
}
