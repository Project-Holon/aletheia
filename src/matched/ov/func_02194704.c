/*
 * function: TALKMSGWIN_LoadTexture
 * address:  0x02194704
 * packet:   pkt_02194704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to TALKMSGWIN_UploadTexture with no argument change.
 *
 * symbols:
 *   TALKMSGWIN_UploadTexture  0x02195530  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void TALKMSGWIN_UploadTexture(char *p);

void TALKMSGWIN_LoadTexture(char *a0)
{
    TALKMSGWIN_UploadTexture(a0);
}
