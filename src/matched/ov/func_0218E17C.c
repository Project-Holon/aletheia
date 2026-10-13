/*
 * function: FIELD_CAMERA_SetSetting
 * address:  0x0218E17C
 * packet:   pkt_0218E17C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word at +0x10, then tail calls with both arguments.
 *
 * symbols:
 *   FIELD_CAMERA_ReloadSetting  0x0218E160  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_CAMERA_ReloadSetting(u32 a);

void FIELD_CAMERA_SetSetting(u32 *p, u32 v)
{
    p[4] = v;
    FIELD_CAMERA_ReloadSetting((u32)p);
}
