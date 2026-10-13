/*
 * function: FIELD_G3D_MAPPER_InitSlotRes
 * address:  0x0218DD14
 * packet:   pkt_ov021_0218DD14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills a 0x14-byte descriptor from src: word0 from FIELD_GROUND_ANIME_GetAnmEntry(src+0x68, a),
 * then src+0x64/+0x6c, the argument a, and b as a halfword at +0x10.
 * Callee of FIELD_G3D_MAPPER_Setup.  EXACT* (unlabelled follower 0x0218DD38).
 *
 * symbols:
 *   FIELD_GROUND_ANIME_GetAnmEntry  0x021A7404  thumb  ov021
 */
#include "../include/Obj00165.h"
#include "../include/Obj05978.h"

typedef unsigned char  u8;
extern int FIELD_GROUND_ANIME_GetAnmEntry(u8 *p, int a1);

void FIELD_G3D_MAPPER_InitSlotRes(int *dst, char *src, int a, int b)
{
    dst[0] = FIELD_GROUND_ANIME_GetAnmEntry((u8 *)(((struct Obj00165 *)src)->f68), a);
    dst[1] = ((struct Obj00165 *)src)->f64;
    dst[2] = ((struct Obj00165 *)src)->f6C;
    dst[3] = a;
    ((struct Obj05978 *)dst)->f10 = b;
}
