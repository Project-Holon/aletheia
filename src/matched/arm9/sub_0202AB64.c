/*
 * unit:     yes
 * function: sub_0202AB64
 * address:  0x0202AB64
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A constructor-shaped clear on a small object: five words and a byte
 * zeroed, the third argument stored at offset 0, and a byte at +0x19 set to
 * 0xff. The second argument is never read; the compiler is free to reuse its
 * register (r1) as the zero source for every clearing store, which is why
 * the parameter has to stay declared even though nothing in the body names
 * it. No relocation of any kind. Matched as a one-function unit rather than
 * with `one`: disasm.py's extent for this address runs two bytes long
 * because it counts the linker's inter-section padding before the next
 * label (0x0202AB7C, a labelled veneer), and `tu` lays the compiled object
 * out on its own footprint instead of against that extent.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202AB64.c \
 *       --addr 0x0202AB64 --thumb
 */
#include "../include/Obj03492.h"

typedef unsigned char u8;
typedef unsigned int u32;

void sub_0202AB64(void *obj, u32 unused, u32 value)
{
    ((struct Obj03492 *)obj)->f4 = 0;
    ((struct Obj03492 *)obj)->f8 = 0;
    ((struct Obj03492 *)obj)->fC = 0;
    ((struct Obj03492 *)obj)->f10 = 0;
    ((struct Obj03492 *)obj)->f14 = 0;
    ((struct Obj03492 *)obj)->f18 = 0;
    ((struct Obj03492 *)obj)->f0 = value;
    ((struct Obj03492 *)obj)->f19 = 0xff;
}
