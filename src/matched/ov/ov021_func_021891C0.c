/*
 * function: func_021891C0
 * address:  0x021891C0
 * packet:   pkt_ov021_021891C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020140E4  0x020140E4  thumb
 *   func_021CD1C8  0x021CD1C8  thumb
 *   func_021CD204  0x021CD204  thumb
 *   func_02050080  0x02050080  arm
 *   func_021CD214  0x021CD214  thumb
 *   func_021CD1F0  0x021CD1F0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09442.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Sub020140BCObj;
extern u8 func_020140E4(struct Sub020140BCObj *p);
extern u32 func_021CD1C8(u32 a);
extern void func_021CD204(u32 a, u32 b);
extern u32 func_02050080(u32 *p);
extern void func_021CD214(u8 *s, void *o);
extern int func_021CD1F0(void *a);

void func_021891C0(u8 *a)
{
    u16 v = (((struct Obj09442 *)a)->f0 & 0x7FFF) | 0x8000;
    u32 h;
    u32 t;

    t = func_020140E4((struct Sub020140BCObj *)(((struct Obj09442 *)a)->fC));
    h = func_021CD1C8(v);
    func_021CD204(h, t);
    func_021CD214((u8 *)h, (void *)func_02050080((u32 *)(((struct Obj09442 *)a)->fB0)));
    func_021CD1F0((void *)h);
}
