/*
 * function: FIELD_CAMERA_ANIME_Delete
 * address:  0x0218FE98
 * packet:   pkt_0218FE98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_CAMERA_ANIME_Free with no argument change.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Free  0x0218FF48  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_CAMERA_ANIME_Free(void *a0);

void FIELD_CAMERA_ANIME_Delete(void *a0)
{
    FIELD_CAMERA_ANIME_Free(a0);
}
