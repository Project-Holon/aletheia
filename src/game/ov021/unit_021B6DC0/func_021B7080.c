/*
 * function: func_021B7080
 * address:  0x021B7080
 * packet:   pkt_021B7080
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
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF18  0x0200BF18  thumb
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj18098.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 *func_0200BE48(void *sys);
extern u32 func_0200BF18(u32, u32);
struct Big;
extern void *func_02012EBC(struct Big *p);

int func_021B7080(u32 a, u32 b, u32 c, u32 d)
{
return func_0200BF18((u32)func_0200BE48((void *)func_02012EBC((struct Big *)b)), ((struct Obj18098 *)((u8 *)(c)))->f0);
}

