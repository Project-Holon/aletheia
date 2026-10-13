/*
 * function: FIELD_CAMERA_Delete
 * address:  0x0218E0E4
 * packet:   pkt_ov021_0218E0E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_DeleteDelay  0x0218EFD4  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 */
#include "../include/Obj04202.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void ARC_TOOL_DeleteHandle(u32 a);
extern void FIELD_CAMERA_DeleteDelay(u8 *a);
extern u32 func_020307B0(void *p);

void FIELD_CAMERA_Delete(u8 *a)
{
    ARC_TOOL_DeleteHandle(((struct Obj04202 *)a)->f4);
    ARC_TOOL_DeleteHandle(((struct Obj04202 *)a)->f8);
    FIELD_CAMERA_DeleteDelay(a);
    func_020307B0(a);
}
