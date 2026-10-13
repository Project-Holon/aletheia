/*
 * function: SOUND_OBJ_Delete
 * address:  0x021C4DA8
 * packet:   pkt_021C4DA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12132.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct IcaAnime;
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern u32 func_020307B0(void *p);

int SOUND_OBJ_Delete(void *a)
{
if (((struct Obj12132 *)((u8 *)(a)))->f10 != 0) {
    ICA_ANIME_Delete((struct IcaAnime *)(((struct Obj12132 *)((u8 *)(a)))->f10));
}
return func_020307B0(a);
}

