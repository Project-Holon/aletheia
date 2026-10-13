/*
 * function: FIELD_CAMERA_ReadSetting
 * address:  0x0218E260
 * packet:   pkt_0218E260
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
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09175.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *, u32, u32, u32, void *);

void FIELD_CAMERA_ReadSetting(void *a, void *b)
{
ARC_TOOL_GetHandleMemberSize((struct ArcFile *)(((struct Obj09175 *)((u8 *)(a)))->f4), 0);
ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)((struct Obj09175 *)((u8 *)(a)))->f4, 0, (44 * ((struct Obj09175 *)((u8 *)(a)))->f10), 44, b);
}

