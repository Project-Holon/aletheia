/*
 * function: func_021C8338
 * address: 0x021C8338
 * packet: pkt_ov093_021C8338
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 14-byte function.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 */
#include "../include/Obj21118.h"
typedef unsigned char u8;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5C30(unsigned char *);
int func_021C8338(unsigned char *p, int i)
{
    return func_021D5C30(func_021B9934(*(char * *)&((struct Obj21118 *)p)->f8, i));
}
