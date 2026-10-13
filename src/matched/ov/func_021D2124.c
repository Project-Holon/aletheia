/*
 * function: EVENT_PERAP_RECORD_Cleanup
 * address:  0x021D2124
 * packet:   pkt_021D2124
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
 *   EVENT_PERAP_RECORD_DeletePokeIcon  0x021D201C  thumb  ov021
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04135.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0201F7A8(void *desc, u32 kind);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern int EVENT_PERAP_RECORD_DeletePokeIcon(u32 a, u32 b, u32 c, u32 d);

int EVENT_PERAP_RECORD_Cleanup(u32 a, u32 b, u32 c, u32 d)
{
EVENT_PERAP_RECORD_DeletePokeIcon(a, b, c, d);
func_0201F7A8((void *)(((struct Obj04135 *)((u8 *)(a)))->f30), 1);
return BMP_WIN_Delete((struct Descriptor *)(((struct Obj04135 *)((u8 *)(a)))->f30));
}

