/*
 * function: func_02164728
 * address:  0x02164728
 * packet:   pkt_ov010_02164728
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks a 177-entry, 10-byte-stride table; entries flagged at +3 pass a
 * 20% roll and are handed to func_0201433C as halfword +0 plus 900.
 *
 * symbols:
 *   func_0201440C  0x0201440C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0201433C  0x0201433C  thumb
 *   d_02171534     0x02171534  data  ov010  a2
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12359.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_0201440C(u8 *a);
extern u32 func_020056EC(u32 range);
extern void func_0201433C(char *a0, int a1);
extern u8 d_02171534[];

void func_02164728(void *o)
{
    u32 i;
    if (func_0201440C(o) != 0) {
        for (i = 0; i < 0xb1; i++) {
            u8 *p = d_02171534 + i * 10;
            if (p[3] != 0) {
                if (func_020056EC(100) < 20) {
                    func_0201433C(o, (u16)(((struct Obj12359 *)p)->f0 + 900));
                }
            }
        }
    }
}
