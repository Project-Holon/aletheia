/*
 * function: func_02037234
 * address:  0x02037234
 * packet:   pkt_02037234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resets a sixteen-byte record: both halfwords at +8 and +0x0A become 0xFFFF
 * (the "no value" sentinel) and the words at +0 and +4 and the halfword at
 * +0x0C are cleared.  The sentinel cannot be encoded as an ARM immediate, so it
 * comes out of the function's own literal pool; the stores then run in the
 * order the source writes them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037234.c \
 *       --func func_02037234 --addr 0x02037234 --cc 1.1p1 --arm
 */
#include "../include/Obj05733.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02037234(u8 *p)
{
    ((struct Obj05733 *)p)->fC = 0;
    ((struct Obj05733 *)p)->f8 = 0xFFFF;
    ((struct Obj05733 *)p)->fA = 0xFFFF;
    ((struct Obj05733 *)p)->f4 = 0;
    ((struct Obj05733 *)p)->f0 = 0;
}
