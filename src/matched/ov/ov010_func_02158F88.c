/*
 * function: SCRIPT_WORK_GetTrainerParam
 * address:  0x02158F88
 * packet:   pkt_ov010_02158F88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 SCRCMD_ClearFinishedSeSlots..SCRCMD_StopMarkedSeSlots: address of the field at +0x40.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *SCRIPT_WORK_GetTrainerParam(void *p)
{
    return (u8 *)p + 0x40;
}
