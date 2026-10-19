/*
 * function: EVENT_BATTLE_GetResultFlag
 * address:  0x0216EFCC
 * packet:   pkt_ov010_0216EFCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, blocker of ov021 SCRCMD_PROC_FLD_StoreByteValue: byte table lookup, 0xFF maps to 1.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   d_021725B8     0x021725B8  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021725B8[];

u8 EVENT_BATTLE_GetResultFlag(int i)
{
    u8 v = d_021725B8[i];

    if (v == 0xff) {
        v = 1;
    }
    return v;
}
