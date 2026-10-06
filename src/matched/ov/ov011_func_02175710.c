/*
 * unit:     yes
 * function: func_02175710, func_0217574C
 * address:  0x02175710
 * packet:   pkt_ov011_02175710
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0217574C is an unlabelled leaf (bit 1 of the byte at +0x904).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02161FEC  0x02161FEC  thumb  ov010
 */
#include "../include/Obj00269.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Lo3 {
    u16 v  : 3;
    u16 hi : 13;
} Lo3;

struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012B8C(void *p, u32 v);
extern void func_02161FEC(char *p, u16 v);

void func_02175710(u8 *o, u32 v)
{
    void *p;

    p = func_020120F4(((struct Obj00269 *)o)->f0);
    ((Lo3 *)(o + 0x86))->v = v;
    func_02012B8C(p, v);
    func_02161FEC((char *)(o + 0x35c), (u8)v);
}

typedef struct Flags {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags;

void func_0217574C(u8 *o, u32 v)
{
    ((Flags *)(o + 0x904))->f = (u8)v;
}
