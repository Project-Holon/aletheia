/*
 * function: func_02073344
 * address:  0x02073344
 * packet:   pkt_0207312C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E464  0x0214E464  data
 *
 * Pinned ../2.0/sp2 on the documented "kept constants" tell: under 1.1p1 -O4,p
 * the three `return 0` sites and the null argument of func_02060614 CSE into a
 * single hoisted `mov r7, #0`, giving 156 bytes against the original's 152 and
 * permuting the whole callee-saved allocation (obj r4->r6, slot r6->r4,
 * pri r7->r5).  The image instead materialises each zero fresh
 * (`mov r1, #0` at 0x0207337C-4, `moveq r0, #0` at 0x0207338C, 0x0207339C,
 * 0x020733B4).  Four 1.1p1 spellings measured (separate node local, decl
 * reorder, early read of o->f0, explicit (void *)0 cast) all hoist the zero.
 * Under the pin the same C is 152 bytes, 0 concrete mismatches.
 *
 * PROMOTED TO EXACT, 2026-09-21, with NO change to the C.  It was parked at
 * MATCH because the PC24 site at +0x68 had no witness: func_02073624 has
 * exactly one branch anywhere in the image (the `bl` at 0x020733AC inside this
 * very function), so `label` refused it.  0x02073624 is now filed as
 * src/matched/func_02073624.c (104 bytes, shard pkt_02073624, same ../2.0/sp2
 * kept-constants pin), and the site resolves `matched x1`.  All six
 * relocations are attested.
 */
#include "../../../matched/include/Obj00513.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef signed int s32;

struct Node { u8 p0[0x3d]; u8 b3d; };
struct Slot { u8 p0[8]; u16 h08; u8 p0a[0x18 - 0xa]; u32 f18; u8 p1c[0x24 - 0x1c]; };
struct Obj { struct Node *f0; };

extern struct Slot g_0214E464[];
struct DList;
struct Obj_02073548;
struct Voice;
extern void func_02072EA8(u32 * volatile *pp);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020735EC(struct Node *p);
extern struct Voice *func_02073624(s32 pri);
extern void func_02073548(void *list, struct Obj_02073548 *obj);

struct Node *func_02073344(struct Obj *o, s32 idx, s32 pri)
{
    struct Slot *s = &g_0214E464[idx];
    struct Node *e = o->f0;

    if (e != 0) {
        func_02072EA8((u32 * volatile*)o);
    }
    if (s->h08 >= s->f18) {
        e = func_02060614((struct DList *)s, 0);
        if (e == 0) {
            return 0;
        }
        if (pri < e->b3d) {
            return 0;
        }
        func_020735EC(e);
    }
    e = (struct Node *)func_02073624(pri);
    if (e == 0) {
        return 0;
    }
    func_02073548(s, (struct Obj_02073548 *)e);
    *(struct Obj * *)&((struct Obj00513 *)e)->f0 = o;
    o->f0 = e;
    return e;
}
