/*
 * function: func_02196CD8
 * address:  0x02196CD8
 * packet:   pkt_ov021_02196CD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * State step: registers the next handler through func_02196034.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196C68  0x02196C68  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09494.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196A60(u8 *p);
extern void func_02196C68(u8 *p);
extern void func_02196804(u8 *p);

void func_02196CD8(u8 *p)
{
    if (((struct Obj09494 *)p)->fC == 2) {
        if (((struct Obj09494 *)p)->f8 == 5) {
            ((struct Obj09494 *)p)->f8 = 1;
            func_02196034(p, func_02196A60, 0x4DD);
        } else {
            func_02196034(p, func_02196C68, 0x4E1);
        }
    } else {
        func_02196034(p, func_02196804, 0x4E5);
    }
}
