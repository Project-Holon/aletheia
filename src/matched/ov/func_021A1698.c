/*
 * function: FIELD_3DBG_LoadBillboardTexture
 * address:  0x021A1698
 * packet:   pkt_021A1698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_3DBG_IsTextureLoaded  0x021A1780  thumb  ov021
 *   FIELD_3DBG_FreeTexture  0x021A1750  thumb  ov021
 *   FIELD_3DBG_LoadTexture  0x021A16EC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07216.h"
#include "../include/Obj17994.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_3DBG_LoadTexture(u8 *d, void *a, const u8 *s, u32 n);
extern int FIELD_3DBG_FreeTexture(u32 a);
extern u32 FIELD_3DBG_IsTextureLoaded(u8 *p);

int FIELD_3DBG_LoadBillboardTexture(u32 a, int b, void *c, int d)
{
if (FIELD_3DBG_IsTextureLoaded((u8 *)(a + 32)) != 0) {
    FIELD_3DBG_FreeTexture((a + 32));
}
FIELD_3DBG_LoadTexture((u8 *)(a + 32), (void *)b, (const u8 *)c, d);
((struct Obj07216 *)((u8 *)(a)))->f1F = ((struct Obj17994 *)((u8 *)(c)))->f8;
((struct Obj07216 *)((u8 *)(a)))->f14 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f18 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f1C = 0;
return 0;
}

