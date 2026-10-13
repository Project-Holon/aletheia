/*
 * function: FIELD_CAMERA_ANIME_GetCurrentParam
 * address:  0x0218FE78
 * packet:   pkt_0218FE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_CAMERA_ANIME_ReadParam with no argument change.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_ReadParam  0x021900C4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_CAMERA_ANIME_ReadParam();

void FIELD_CAMERA_ANIME_GetCurrentParam(void)
{
    FIELD_CAMERA_ANIME_ReadParam();
}
