/*
 * function: func_021D881C
 * address:  0x021D881C
 * packet:   pkt_021D881C
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23147.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec;
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);

void func_021D881C(void *a, u8 *p)
{
    func_02045C04(((struct Obj23147 *)p)->f50);
    func_020307B0(p);
}
