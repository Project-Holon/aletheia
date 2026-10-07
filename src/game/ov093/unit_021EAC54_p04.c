/*
 * file:     unit_021EAC54_p04.c
 * unit:     yes
 * function: func_021EAE44, func_021EAE54, func_021EAE64, func_021EAE74
 * address:  0x021EAE44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689B670   0x0689B670  thumb  ov095
 *   func_0689B69C   0x0689B69C  thumb  ov095
 *   func_0689B790   0x0689B790  thumb  ov095
 *   func_021EAE98  0x021EAE98  thumb  ov093
 */
#include "../../matched/include/Obj07847.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern void func_021EAE98(void *a, void *b);
void func_021EAE44(E64 *p);
void func_021EAE54(E64 *p);
void func_021EAE64(E64 *p);
void func_021EAE74(char *p, u32 a, u32 b);


/*
 * Resolved: func_0689B670 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }
 */
void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAE54(E64 *p) { func_0689B69C(p[0x6].f0); }


/*
 * Resolved: func_0689B790 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }
 */
void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }


void func_021EAE74(char *p, u32 a, u32 b)
{
    ((struct Obj07847 *)p)->f160 = a;
    ((struct Obj07847 *)p)->f164 = b;
    ((struct Obj07847 *)p)->f16C = 0;
    func_021EAE98(((struct Obj07847 *)p)->f180, p + 0x160);
}
