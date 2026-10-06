/*
 * function: func_02073624
 * address:  0x02073624
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E00C     0x0214E00C  data
 *   g_0214E018     0x0214E018  data
 *   func_02060614  0x02060614  arm
 *   func_020605B4  0x020605B4  arm
 *   func_020735EC  0x020735EC  arm
 *   func_02073598  0x02073598  arm
 *
 * Voice allocator: take the head of the free list at 0x0214E00C; if it is
 * empty, take the head of the ACTIVE list at 0x0214E018 instead and steal it,
 * but only if the caller's priority is at least the victim's, else return 0.
 * Move the chosen node onto the free list, stamp the priority and attach it.
 *
 * b3d is UNSIGNED (`u8`).  The image loads it with `ldrb r1, [r4, #0x3d]` at
 * 0x02073650; declared `s8` the compiler emits `ldrsb`, 3 concrete bytes out at
 * the same 104 and otherwise identical.  The compare is still signed (`movlt`)
 * because the priority parameter is s32.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md), which
 * docs/notes/pkt_02073624.c.txt predicted at this address.  The two list-walk
 * calls each take a literal 0 as their second argument and the image
 * materialises it FRESH at both, `mov r1, #0` at 0x02073630 (`00 10 a0 e3`) and
 * again at 0x02073644, and reuses it for neither the `movlt r0, #0` early exit
 * at 0x02073658 nor anything else.  1.1p1 -O4,p CSEs all three into a single
 * hoisted `mov r4, #0` above the first call, then spends `mov r1, r4` at each
 * call site and `movlt r0, r4` at the exit; that costs a fourth callee-saved
 * register and turns the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`)
 * into `push {r4, r5, r6, lr}` with the node in r5 and the priority in r6,
 * 108 bytes against the original's 104 and 96 concrete bytes out.  Under the
 * pin the same C is 104 bytes, 0 mismatches.
 *
 * Filing this address unblocks src/pending/func_02073344.c, whose PC24 site at
 * +0x68 had no witness for this function.
 */

typedef unsigned char u8; typedef signed char s8; typedef unsigned int u32;
typedef signed int s32;

struct Voice { u8 p00[0x3d]; u8 b3d; };

extern char g_0214E00C[];
extern char g_0214E018[];

struct DList;
struct Obj_02073548;
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_020735EC(struct Voice *v);
extern void func_02073598(struct Obj_02073548 *obj);

struct Voice *func_02073624(s32 pri)
{
    struct Voice *v;

    v = func_02060614((struct DList *)g_0214E00C, 0);
    if (v == 0) {
        v = func_02060614((struct DList *)g_0214E018, 0);
        if (pri < v->b3d) {
            return 0;
        }
        func_020735EC(v);
    }
    func_020605B4((volatile struct DList *)g_0214E00C, v);
    v->b3d = (u8)pri;
    func_02073598((struct Obj_02073548 *)v);
    return v;
}
