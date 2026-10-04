/*
 * function: func_0218E0E4
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
 *   func_0218EFD4  0x0218EFD4  thumb
 */
#include "../include/Obj04202.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02049238(u32 a);
extern void func_0218EFD4(u8 *a);
extern void func_020307B0(void *a);

void func_0218E0E4(u8 *a)
{
    func_02049238(((struct Obj04202 *)a)->f4);
    func_02049238(((struct Obj04202 *)a)->f8);
    func_0218EFD4(a);
    func_020307B0(a);
}
