/*
 * function: ENTRANCE_CAMERA_Delete
 * address:  0x021BDCB8
 * packet:   pkt_021BDCB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   ENTRANCE_CAMERA_DeleteAnime  0x021BDDAC  thumb  ov021
 *   ENTRANCE_CAMERA_FreeWork  0x021BDD74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void ENTRANCE_CAMERA_DeleteAnime(void *p);
extern void ENTRANCE_CAMERA_FreeWork(void *p);

void ENTRANCE_CAMERA_Delete(u8 *p)
{
    ENTRANCE_CAMERA_DeleteAnime(p);
    ENTRANCE_CAMERA_FreeWork(p);
}
