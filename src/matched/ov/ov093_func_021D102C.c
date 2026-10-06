/*
 * function: func_021D102C
 * address: 0x021D102C
 * packet: pkt_ov093_021D102C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 */
#include "../include/Obj13368.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_021B8588(void **p);
typedef unsigned int u32;
struct S2;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
int func_021D102C(char *p)
{
    if (func_021B8588(((struct Obj13368 *)p)->f0) == 3 && func_021D5B68(func_021B9C00(((struct Obj13368 *)p)->f118, 0)) != 0) return 1;
    return 0;
}
