/*
 * function: FLD_EXP_OBJ_GetAnimeLastFrame
 * address:  0x021BE748
 * packet:   pkt_021BE748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Unblocked: the bl to G3D_SYSTEM_GetAnimeObj (0x02047674, an unlabelled ARM leaf
 * getter emitted as data words) is now attested `matched` by the arm9
 * source src/matched/G3D_SYSTEM_GetAnimeObj.c.  The listing extent still runs two
 * bytes long to the next label, hence EXACT*.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18259.h"
#include "../include/Obj18260.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int G3D_SYSTEM_GetAnimeObj(int p);

int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a)
{
return ((*(u16 *)((u8 *)(((struct Obj18260 *)((u8 *)(G3D_SYSTEM_GetAnimeObj(((struct Obj18259 *)((u8 *)(a)))->fC))))->f8) + 4) << 12) - (1 << 12));
}

