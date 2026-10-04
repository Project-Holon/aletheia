/*
 * function: func_0204F720
 * address:  0x0204F720
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Set or clear bit 9 of the record's u16 at +0x18 depending on whether the
 * caller's word is 1.  Both arms are conditional instructions and there is no
 * narrowing shift pair, so the field is a 1-bit bitfield assigned 1/0 rather
 * than a read-modify-write of the whole halfword, and the address is written
 * inside each arm so the condition is evaluated first.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj11449.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 lo : 9;
    u16 b9 : 1;
    u16 hi : 6;
};

void func_0204F720(void *p, u32 idx, u32 *flag)
{
    if (*flag == 1) {
        struct Rec *r = (struct Rec *)(*(u8 * *)&((struct Obj11449 *)p)->f8 + idx * 0x1c + 0x18);
        r->b9 = 1;
    } else {
        struct Rec *r = (struct Rec *)(*(u8 * *)&((struct Obj11449 *)p)->f8 + idx * 0x1c + 0x18);
        r->b9 = 0;
    }
}
