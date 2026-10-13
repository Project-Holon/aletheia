/*
 * function: func_021D3D50
 * address: 0x021D3D50
 * packet: pkt_ov093_021D3D50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetWeight 0x021D67D8 thumb ov093
 */
#include "../include/Obj21205.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021B9934(char *p, int i);
typedef unsigned int   u32;
extern void BTL_POKEPARAM_SetWeight(u8 *p, u32 n);
int func_021D3D50(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21205 *)p)->f4, (u8)a[0]);
    BTL_POKEPARAM_SetWeight(obj, (u16)a[1]);
    return 1;
}
