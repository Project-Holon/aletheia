/*
 * file:     unit_0207312C_p03.c
 * unit:     yes
 * function: func_020734AC, func_02073500, func_02073548, func_02073598, func_020735EC, func_02073624, func_0207368C
 * address:  0x020734AC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E464     0x0214E464  data
 *   func_02060614  0x02060614  arm
 *   func_020605B4  0x020605B4  arm
 *   func_02074770  0x02074770  arm
 *   func_02060550  0x02060550  arm
 *   g_0214E018     0x0214E018  data
 *   func_020893D0    0x020893D0  arm
 *   func_02089330    0x02089330  arm
 *   g_0214E00C     0x0214E00C  data
 *   func_020604AC  0x020604AC  arm
 */
#include "../../matched/include/Obj00513.h"

struct DList;
struct Obj;
struct Voice;
struct Obj_02073548;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct Node { u8 pad00[8]; void *f08; void *f0c; };

struct Slot { u8 pad00[0x0c]; u8 list[0x24 - 0x0c]; };

typedef struct Obj_02073548_020734AC {
    char pad4[4];
    void *f4;
    char pad3d[0x3d - 8];
    u8 b3d;
} Obj_02073548_020734AC;

typedef struct Obj_02073548_02073598 {
    u8 pad[0x3d];
    u8 b3d;
} Obj_02073548_02073598;

typedef struct {
    u8 unk00[0x2c];
    u8 unk2c;
    u8 unk2d[0x3c - 0x2d];
    u8 unk3c;
} Obj020735EC;

typedef signed char s8;

struct Voice_02073624 { u8 p00[0x3d]; u8 b3d; };

struct Owner { u32 f00; };

struct Sub   { u8 p00[0xc]; struct Voice_0207368C *f0c; };

struct Voice_0207368C {
    struct Owner *f00;
    struct Sub   *f04;
    struct Sub   *f08;
    u8  p0c[0x2c - 0x0c];
    u8  b2c;
};

extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_02074770(struct Obj *o);
extern void func_02060550(volatile struct DList *list, void *before, void *elem);
extern void func_020893D0(u32 player, int vol);
extern void func_02089330(int playerNo);
extern void func_020604AC(void *list, void *node);
void *func_020734AC(s32 idx, void *owner);
int func_02073500(int a0);
void func_02073548(void *list, Obj_02073548_020734AC *obj);
void func_02073598(Obj_02073548_02073598 *obj);
void func_020735EC(Obj020735EC *p);
struct Voice_02073624 *func_02073624(s32 pri);
void func_0207368C(struct Voice_0207368C *v);
extern struct Slot g_0214E464[];
extern char g_0214E018[];
extern char g_0214E00C[];





/*
 * Takes the head node off the free list embedded at +0x0c of slot `idx` of the
 * g_0214E464 table, binds it to `owner` in both directions, drains the owner's
 * deferred requests through func_02074770, and returns the owner back.
 * Returns 0 when the free list is empty.
 *
 * THE TABLE STRIDE IS 0x24 AND THE LIST IS EMBEDDED AT +0x0c.  Both are fixed
 * by the head: `mov r2, #0x24 / mla r5, r0, r2, r3` is an indexed subscript on
 * a 0x24-stride array (the same table and stride matched func_0207312C and
 * func_02073344 already use), and the list argument is `add r0, r5, #0xc`, the
 * ADDRESS of an embedded object, not a loaded pointer.  Declaring the +0x0c
 * field as a `void *` and passing it emits an extra `ldr` and loses the add.
 *
 * THE LAST TWO STATEMENTS RE-READ n->f08 RATHER THAN REUSING `owner`.  The
 * image loads `ldr r0, [r4, #8]` twice, once for func_02074770's argument and
 * once for the return value, even though the value was just stored there from
 * r4's own `str r4, [r6, #8]`.  Writing `func_02074770(owner); return owner;`
 * folds both loads away and is 8 bytes short.  The re-read is what the C above
 * spells literally, and it is also why the two stores are written in the order
 * f0c-then-f08: the compiler does not reorder them and the second store is what
 * the following load depends on.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  Under dsi/1.1p1 -O4,p the slot base and
 * the owner are both live across the func_02060614 call, so 1.1p1 hoists them
 * into a SIXTH and SEVENTH callee-saved register: the frame becomes
 * `push {r3, r4, r5, r6, r7, lr}` against the image's `push {r4, r5, r6, lr}`,
 * `add r0, r5, #0xc` becomes `add r0, r6, #0xc` and the owner moves from r6 to
 * r7 -- every byte from +0x20 on shifts.  The image keeps the slot base in r5
 * and the owner in r6 and materialises what it needs at each use.  Under the
 * pin the same C is 84 bytes, 0 concrete mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020734AC.c \
 *       --func func_020734AC --addr 0x020734AC --cc ../2.0/sp2 --arm
 */
void *func_020734AC(s32 idx, void *owner)
{
    struct Slot *s = &g_0214E464[idx];
    struct Node *n = func_02060614((struct DList *)s->list, 0);
    if (n == 0) return 0;
    func_020605B4((volatile struct DList *)s->list, n);
    n->f0c = owner;
    ((struct Node *)owner)->f08 = n;
    func_02074770(n->f08);
    return n->f08;
}






int func_02073500(int a0){ int t0, t1; ((struct Obj00513 *)((char *)(a0)))->f2E = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2D = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2F = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f34 = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f3E = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f40 = (unsigned char)0x7f; ((struct Obj00513 *)((char *)(a0)))->f41 = (unsigned char)0x7f; t0 = func_02075B94((int)(a0 + 0x1c), (int)0x7f); t1 = func_02075BAC((int)(a0 + 0x1c), (int)0x7f00, (int)1); return t1; }






void func_02073548(void *list, Obj_02073548_020734AC *obj)
{
    Obj_02073548_020734AC *curr = (Obj_02073548_020734AC *)func_02060614(list, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = (Obj_02073548_020734AC *)func_02060614(list, curr);
    }
    func_02060550(list, curr, obj);
    obj->f4 = list;
}




/*
 * Priority-ordered insert into the g_0214E018 list.  Walks the list with the
 * generic iterator func_02060614 (a null cursor asks for the head, a node asks
 * for its successor), stops at the first node whose b3d priority byte is
 * strictly greater than the new object's, and inserts before it with
 * func_02060550.  Running off the end leaves `curr` null, which is
 * func_02060550's "append" case, so one loop serves both.
 *
 * TWO INDEPENDENT ERRORS were fixed to close this, and only the first is
 * interesting:
 *
 * 1. THE LIST OBJECT IS AN ARRAY, NOT A POINTER.  The parked version declared
 *    `extern void *g_0214E018;` and passed `g_0214E018`, so every call site
 *    emitted an extra `ldr r0, [r0]` to LOAD the pointer out of the object.
 *    The image has no such load: it hands the ADDRESS 0x0214E018 straight to
 *    the callee.  `extern char g_0214E018[];` is the spelling every matched
 *    sibling in this range already uses (func_0207312C, func_020731E0), and
 *    this file disagreeing with them was the whole of the 47-byte residue's
 *    tail.  Fixing it alone took the file to 8 bytes out, all in the head.
 *
 * 2. PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 *    docs/families/cluster_020726D0.h).  With the declaration fixed, dsi/1.1p1
 *    still hoists the g_0214E018 pool word into callee-saved r4 BEFORE the
 *    `mov r5, r0` (giving `ldr r4,[pc,#0x44] / mov r5,r0 / mov r0,r4`) and
 *    serves both the entry call and the loop call from it.  The image instead
 *    materialises the entry call's argument from its OWN pool word
 *    (`ldr r0,[pc,#0x40]` at 0x020735A0) and only loads r4 at 0x020735B4,
 *    AFTER the early-exit test -- i.e. it does not pay for the loop's base on
 *    the path that never reaches the loop.  Two distinct pool entries for one
 *    symbol, the cluster's signature.  Under the pin the same C is 84 bytes,
 *    0 concrete mismatches.
 *
 * The comparison is UNSIGNED (`blo` at 0x020735C4), so b3d is u8 and the test
 * is `obj->b3d < curr->b3d`; a signed spelling emits `blt`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02073598.c \
 *       --func func_02073598 --addr 0x02073598 --cc ../2.0/sp2 --arm
 */
void func_02073598(Obj_02073548_02073598 *obj)
{
    Obj_02073548_02073598 *curr = func_02060614((struct DList *)g_0214E018, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = func_02060614((struct DList *)g_0214E018, curr);
    }
    func_02060550((volatile struct DList *)g_0214E018, curr, obj);
}



/*
 * Tears the player down: in state 2 first sets the volume to -723, then stops
 * the sequence and calls the state machine again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020735EC.c \
 *       --func func_020735EC --addr 0x020735EC --cc 1.1p1 --arm
 */
void func_020735EC(Obj020735EC *p)
{
    if (p->unk2c == 2) {
        func_020893D0(p->unk3c, -723);
    }
    func_02089330(p->unk3c);
    func_0207368C((struct Voice_0207368C *)((struct Voice *)p));
}



/*
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
struct Voice_02073624 *func_02073624(s32 pri)
{
    struct Voice_02073624 *v;

    v = func_02060614((struct DList *)g_0214E00C, 0);
    if (v == 0) {
        v = func_02060614((struct DList *)g_0214E018, 0);
        if (pri < v->b3d) {
            return 0;
        }
        func_020735EC((Obj020735EC *)v);
    }
    func_020605B4((volatile struct DList *)g_0214E00C, v);
    v->b3d = (u8)pri;
    func_02073598((Obj_02073548_02073598 *)((struct Obj_02073548 *)v));
    return v;
}



/*
 * Voice teardown, the counterpart of func_02073624: clear the back-pointer in
 * the owner, unlink from the f04 sub-list, unlink from the f08 sub-list if it
 * has one, then move the node from the active list at 0x0214E018 back to the
 * free list at 0x0214E00C and clear the state byte.
 *
 * The lever, and the whole reason docs/notes/pkt_02073624.c.txt left this one
 * open at 84 bytes: the inner func_020604AC call's second argument is
 * `v->f08`, NOT `v`.  The image's guard load `ldr r1, [r4, #8]` at 0x020736C0
 * IS the argument register -- the `cmp r1, #0` / `beq` pair tests the value in
 * place and the call site then only has to compute r0.  Passing `v` costs a
 * fresh `mov r1, r4` and 4 bytes, and forces the guard load into r0.  Every
 * other call in the body does pass `v`, which is what makes the odd one out
 * easy to miss.  The sub-list base is `(char *)v->f04 + 0xc`, read into r5
 * before the FIRST func_020605B4 call and reused, not re-read.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md), the same
 * one as this packet's func_02073624.c.  The image materialises each zero
 * fresh: `movne r0, #0` at 0x0207369C for the owner pair, `mov r0, #0` at
 * 0x020736B8 for f04, `mov r1, #0` at 0x020736D8 for the f08 pair and
 * `mov r0, #0` at 0x020736FC for b2c.  1.1p1 -O4,p CSEs all four into one
 * hoisted `mov r5, #0`, which costs a further callee-saved register and turns
 * the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`) into
 * `push {r4, r5, r6, lr}` with the sub-list base displaced from r5 to r6; the
 * same 132 bytes with 40 concrete bytes out.  Under the pin the same C is
 * 132 bytes, 0 mismatches.
 */
void func_0207368C(struct Voice_0207368C *v)
{
    struct Sub *s;

    if (v->f00 != 0) {
        v->f00->f00 = 0;
        v->f00 = 0;
    }
    s = v->f04;
    func_020605B4((volatile struct DList *)s, v);
    v->f04 = 0;
    if (v->f08 != 0) {
        func_020604AC((char *)s + 0xc, v->f08);
        v->f08->f0c = 0;
        v->f08 = 0;
    }
    func_020605B4((volatile struct DList *)g_0214E018, v);
    func_020604AC(g_0214E00C, v);
    v->b2c = 0;
}
