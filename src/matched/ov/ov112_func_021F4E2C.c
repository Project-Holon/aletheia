/*
 * function: func_021F4E2C
 * address: 0x021F4E2C
 * packet: pkt_ov112_021F4E2C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
#include "../include/Obj05311.h"
#include "../include/Obj05312.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;
void func_021F4E2C(void *unused, u8 *s, u8 *d)
{
    ((struct Obj05312 *)d)->f10 = ((struct Obj05311 *)s)->f10 + 8192;
    ((struct Obj05312 *)d)->f14 = ((struct Obj05311 *)s)->f14 + 8192;
    ((struct Obj05312 *)d)->f18 = ((struct Obj05311 *)s)->f18 - 2048;
    ((struct Obj05312 *)d)->f1C = ((struct Obj05311 *)s)->f1C;
    ((struct Obj05312 *)d)->f1E = ((struct Obj05311 *)s)->f1E;
    ((struct Obj05312 *)d)->f2 = ((struct Obj05311 *)s)->f2;
    ((Flags *)d)->flag = ((Flags *)s)->flag;
}
