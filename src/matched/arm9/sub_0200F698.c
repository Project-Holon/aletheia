/*
 * function: GFL_NET_ERR_SetBgmTrackVolume
 * address:  0x0200F698
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x02156B70 is the unlabelled ov009 leaf matched
 *           in src/matched/DWC_RAP_GetVchatEnabled.c (ov009/pkt_02156B70); it attests as
 *           `matched, overlay` under the ov009 hint.
 *
 * symbols:
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   DWC_RAP_GetVchatEnabled  0x02156B70  thumb  ov009
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *
 * Forwards its two arguments to GFL_USE_SetBgmTrackVolume unless both GFL_NET_IsNetTypeWifi()
 * and DWC_RAP_GetVchatEnabled() report nonzero; GFL_NET_IsNetTypeWifi is always called,
 * DWC_RAP_GetVchatEnabled only when the first call reports zero (a genuine
 * short-circuit, not an independent second check).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_SetBgmTrackVolume.c \
 *       --func GFL_NET_ERR_SetBgmTrackVolume --addr 0x0200F698 --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  GFL_NET_IsNetTypeWifi(void);
typedef signed short   s16;
extern s16 DWC_RAP_GetVchatEnabled(void);
extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);

void GFL_NET_ERR_SetBgmTrackVolume(void *a, void *b)
{
    if (GFL_NET_IsNetTypeWifi() == 0 || DWC_RAP_GetVchatEnabled() == 0) {
        GFL_USE_SetBgmTrackVolume((u32)a, (u32)b);
    }
}
