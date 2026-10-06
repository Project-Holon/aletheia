/*
 * function: func_0202B7EC
 * address:  0x0202B7EC
 * packet:   pkt_0202B7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked: the only site, the ABS32 at +0008, names 0x0202B90C - the fourth
 * four-byte Thumb linker veneer of the run at 0x0202B8F4/8FC/904/90C
 * (`00 4b 18 47` + word 0x0202BB41).  Artifact class, hence permanent: no C
 * spelling produces it, and with the ARM-only `veneer` class it has no witness
 * of any other class either.  Every concrete byte reproduces.
 * symbols:
 *   sub_0202B90C  0x0202B90C  thumb
 */
#include "../include/Obj08804.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_0202B90C(void *p);

void func_0202B7EC(u8 *p, u32 b)
{
    sub_0202B90C(((struct Obj08804 *)p)->f24);
}
