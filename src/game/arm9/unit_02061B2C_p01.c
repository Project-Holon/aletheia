/*
 * file:     unit_02061B2C_p01.c
 * unit:     yes
 * function: func_02061B2C, func_02061B5C, func_02061B74, func_02061BB0, func_02061BC0, func_02061BD0, sub_02061C0C, func_02061C30
 * address:  0x02061B2C
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
 *   g_020A1718     0x020A1718  data
 *   func_020862F0  0x020862F0  arm
 *   func_02061878  0x02061878  arm
 *   func_02061840  0x02061840  arm
 *   g_02146B80     0x02146B80  data
 *   g_02146B80_cb  0x02146B80  data
 */
#include "../../matched/include/Obj07006.h"
#include "../../matched/include/Obj04778.h"
#include "../../matched/include/Obj11497.h"
#include "../../matched/include/Obj11498.h"

typedef unsigned int u32;

typedef void (*Fn)(u32, u32, u32);

typedef unsigned char  u8;

typedef unsigned short u16;

struct Obj02061BD0 {
    char pad0[8];
    u16 f8;
    char padA[2];
    u16 fC;
};

typedef signed int    s32;

struct Queue {
    void *unk_00;
    u32 capacity;
    u8 pad_08[8];
    s32 total;
};

extern void func_020862F0(u32, u32);
extern int func_02061860(u8 *p);
extern u32 func_02061840(u8 *p, u32 v);
extern int func_02061878(struct Obj02061BD0 *);
void func_02061B2C(u32 *s);
void func_02061B5C(u8 *p);
int func_02061B74(char *p);
u32 func_02061BB0(u8 *p);
u32 func_02061BC0(u8 *p);
u32 func_02061BD0(struct Obj02061BD0 *p);
void sub_02061C0C(void *a, u32 capacity);
void func_02061C30(void);
extern Fn g_020A1718[];
extern struct Queue g_02146B80;
extern struct Queue g_02146B80_cb;





/*
 * Table dispatch: the handler g_020A1718[s[0]] is fetched first, func_020862F0
 * gets (s[1], s[3]), then the handler gets (s[1], s[2], s[3]).  The re-read
 * tell (docs/FRONTEND-PINS.md): the image reloads all three fields after the
 * first call with one `ldmib r5, {r0, r1, r2}` at 0x02061B4C; 1.1p1 keeps s[3]
 * live from the first call's argument and emits `ldr r2, [r5, #0xc]` plus a
 * two-register ldmib (52 bytes, 20 out).  Under ../2.0/sp2 the same C is 44
 * bytes, 0 mismatches; EXACT* only because the follower 0x02061B5C
 * (src/matched/func_02061B5C.c) has no label.
 */
void func_02061B2C(u32 *s)
{
    Fn f = g_020A1718[s[0]];
    func_020862F0(s[1], s[3]);
    f(s[1], s[2], s[3]);
}







/*
 * Clears the cursor fields.  No relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061B5C.c \
 *       --func func_02061B5C --addr 0x02061B5C --arm --cc 1.1p1
 */
void func_02061B5C(u8 *p)
{
    ((struct Obj07006 *)p)->fA = 0;
    ((struct Obj07006 *)p)->f8 = 0;
    ((struct Obj07006 *)p)->fC = 0;
    ((struct Obj07006 *)p)->f10 = 0;
}






int func_02061B74(char *p)
{
    int v;
    if (func_02061860((u8 *)p))
        return 0;
    v = func_02061840((u8 *)p, ((struct Obj04778 *)p)->fA);
    *(volatile u16 *)&((struct Obj04778 *)p)->fA = (u16)v;
    *(volatile u16 *)&((struct Obj04778 *)p)->fC = (u16)(*(volatile u16 *)&((struct Obj04778 *)p)->fC + 1);
    return 1;
}







/*
 * Returns the base pointer plus the +8 halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BB0.c \
 *       --func func_02061BB0 --addr 0x02061BB0 --arm --cc 1.1p1
 */
u32 func_02061BB0(u8 *p)
{
    return ((struct Obj11497 *)p)->f0 + ((u32)((struct Obj11497 *)p)->f8 << 4);
}







/*
 * Returns the base pointer plus the +0xa halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BC0.c \
 *       --func func_02061BC0 --addr 0x02061BC0 --arm --cc 1.1p1
 */
u32 func_02061BC0(u8 *p)
{
    return ((struct Obj11498 *)p)->f0 + ((u32)((struct Obj11498 *)p)->fA << 4);
}




/*
 * The load/store interleave tell of the 2.0 front end (docs/FRONTEND-PINS.md):
 * the image stores the call result (`strh r0, [r4, #8]` at 0x02061BF4) before
 * loading the counter (`ldrh r1, [r4, #0xc]` at 0x02061BF8); 1.1p1 hoists the
 * load above the store (6 bytes out).  Under ../2.0/sp2 the same C is 60
 * bytes, 0 mismatches.
 */
u32 func_02061BD0(struct Obj02061BD0 *p)
{
    if (func_02061878(p) != 0) {
        return 0;
    }
    p->f8 = func_02061840((u8 *)p, p->f8);
    p->fC -= 1;
    return 1;
}



/*
 * func_02061B5C (0x02061B5C) is named by two words in the whole image: the
 * pool word at 0x02061C28 inside this function, and the one at 0x02061C3C
 * inside the unlabelled stub at 0x02061C30 (the same tail call without the
 * two stores). Neither disasm.py's tracer nor its prologue sweep ever reach
 * 0x02061C30 (no `lr`-saving prologue, nothing branches to it), so that
 * second pool word used to sit in an anonymous `.word` run; disasm.py's
 * index_hidden_pool_words() now finds it (it decodes as a genuine PC-relative
 * load in the run right after this function's own `bx ip`, and its value
 * reads back as a pointer into arm9), so `literal` witnesses func_02061B5C
 * from outside this function's own 0x02061C0C..0x02061C30 range.
 *
 * Installs the request-buffer base and capacity into the queue object at
 * 0x02146B80 and tail
 * calls func_02061B5C on it (docs/idioms/tail-call-is-a-pool-word-and-bx.md,
 * hence the `ldr ip` / `bx ip` pair rather than a `b`). The same queue object
 * is the one src/pending/sub_02061CA4.c pushes requests onto, and the stub at
 * 0x02061C30 is the same tail call without the two stores.
 *
 * The one shape question this function poses is why 0x02146B80 costs two pool
 * words. Written as one symbol, mwcc common-subexpressions the two references
 * and emits `mov r0, r2` where the original emits a second `ldr r0, [pc]`,
 * three bytes wrong and four bytes short; `volatile`, an address-of-member
 * argument, a cast through `void *` and a cast of the store base all still
 * CSE. Two distinct declarations at the address are the only spelling that
 * reproduces the pair, so that is what this file uses: `g_02146B80_cb` for
 * the base/capacity slots and `g_02146B80` for the queue the tail call takes.
 * Writing the two stores as a static helper the compiler might inline instead
 * makes it worse, not better: mwcc emits a real tail call to the helper and
 * merges the two stores into one `stm`, which the original does not have.
 *
 * Historically reported EXACT* before the follower at 0x02061C30 had its
 * own label. Current verification reports EXACT for the 36-byte function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02061C0C.c \
 *       --func sub_02061C0C --addr 0x02061C0C --cc 1.1p1 --arm
 */
void sub_02061C0C(void *a, u32 capacity)
{
    g_02146B80_cb.unk_00 = a;
    g_02146B80_cb.capacity = capacity;
    func_02061B5C((u8 *)(&g_02146B80));
}


/*
 * Unlabelled tail-call stub right after sub_02061C0C (same tail call to
 * func_02061B5C on the 0x02146B80 queue, without the two callback stores).
 * Front-end tell (docs/FRONTEND-PINS.md rule 2): the image issues the callee
 * pool load first, `ldr ip, [pc, #4]` at 0x02061C30, then `ldr r0, [pc, #4]`
 * at 0x02061C34. dsi/1.1p1 (and 1.1p1, 1.2) schedule the pool load after the
 * argument write (docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-
 * last-argument-write.md), the two loads transposed, 8 bytes out; the same C
 * under ../2.0/sp2 (also ../1.2/sp2, ../2.0/sp2p2) is 12 bytes, 0 mismatches.
 * Neighbour func_02061BD0 carries the same ../2.0/sp2 pin.
 * Witness for ov131 func_021D48E4.
 */
void func_02061C30(void)
{
    func_02061B5C((u8 *)(&g_02146B80));
}
