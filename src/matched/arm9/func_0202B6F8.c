/*
 * function: func_0202B6F8
 * address:  0x0202B6F8
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted out of src/pending: the tail call's pool word holds the Thumb entry
 * of func_0202BEBC, which acquired an EXACT manifest entry, so the `matched`
 * class now witnesses the ABS32 site.  Every byte is hard, including the
 * two-byte alignment pad the front end emits between the code and the pool.
 */
#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202BEBC(u8 *p);

void func_0202B6F8(u8 *p)
{
    func_0202BEBC(*(u8 * *)&((struct Obj02010 *)p)->f1C);
}
