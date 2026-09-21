/*
 * function: func_02047400
 * address:  0x02047400
 * packet:   pkt_02047400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   g_szG3DSystem   0x020A7EA8  data
 *   func_0206E954   0x0206E954  arm
 *   func_0206E964   0x0206E964  arm
 *   func_02030734   0x02030734  arm
 *   func_0206E348   0x0206E348  arm
 *   func_0206A2CC   0x0206A2CC  arm
 *   func_0206A4AC   0x0206A4AC  arm
 *   func_02069D14   0x02069D14  arm
 *
 * Construct a 0x7A14-tagged record (the sibling of func_02047564's 0x59D1
 * one): look the owner's +4 handle up through func_0206E954, index its
 * table by `n` to a byte offset, turn that into a pointer, optionally take
 * a second handle from a2, allocate 0x10 bytes out of the context's heap
 * with `g3d_system.c:1544` as the __FILE__/__LINE__ pair, fill the tag and
 * the two owner slots, and register it.
 *
 * WHY THE GOTOS.  Two earlier waves (see docs/notes/pkt_02047400.c.txt)
 * landed three instructions (12 bytes) short with the structured
 * `if (p) { b = p + 8; if (b) { if (n < p[9]) { ... } } }` plus a ternary
 * for q, in five spellings.  The residue was a front-end if-conversion:
 * mwcc predicated the five-instruction `ofs` body (`ldrhlo`/`addlo`/
 * `mlalo`) and therefore hoisted `ofs = 0` before the guards as
 * `mov r2, r4`, and it predicated the q selection as `moveq r5, #0`.
 *
 * The image does neither.  It gives `ofs = 0` its own out-of-line block at
 * +0x50 with TWO predecessors (the `b == 0` and the `n >= p[9]` guards) and
 * an unconditional `b` over it from the body, and it sends the `p == 0`
 * test straight to an out-of-line `q = 0` at +0x64.  Writing those two
 * join blocks as explicit `goto` targets is what reproduces them: with the
 * body no longer the only path into its successor, the front end has no
 * single-block region left to predicate, so the five instructions come out
 * bare and the missing `b` and `bne` appear.  This is the general form of
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * applied to a join rather than to an exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047400.c \
 *       --func func_02047400 --addr 0x02047400 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void *func_0206E954(void *);
extern void *func_0206E964(void *);
extern void *func_02030734(u32, int, int, void *, int);
extern void *func_0206E348(void *);
extern void func_0206A2CC(void *, void *);
extern void func_0206A4AC(void *, void *);
extern void func_02069D14(void *, void *);
extern u32 g_02146A5C;
extern char g_szG3DSystem[];

void *func_02047400(void *a0, u32 n, void *a2)
{
    u32 z;
    u8 *p;
    u8 *b;
    void *q;
    void *obj;
    u8 *ofs;
    u32 idx;
    u32 cnt;

    z = 0;
    p = func_0206E954(*(void **)((u8 *)a0 + 4));
    if (p == 0) goto qzero;
    b = p + 8;
    if (b == 0) goto ozero;
    if (n >= p[9]) goto ozero;
    idx = *(u16 *)(p + 0xe);
    cnt = *(u16 *)(b + idx);
    ofs = (u8 *)(cnt * n + (s32)(b + idx + 4));
    goto join;
ozero:
    ofs = 0;
join:
    if (ofs != 0) { q = (void *)(p + *(u32 *)ofs); goto have; }
qzero:
    q = 0;
have:
    ;

    if (a2 != 0) z = (u32)func_0206E964(*(void **)((u8 *)a2 + 4));

    obj = func_02030734(*(u16 *)((u8 *)*(void **)&g_02146A5C + 0x18),
                        0x10, 0, g_szG3DSystem, 0x608);
    *(u16 *)obj = 0x7A14;
    *(void **)((u8 *)obj + 8) = a0;
    *(void **)((u8 *)obj + 0xc) = a2;
    *(void **)((u8 *)obj + 4) = func_0206E348(*(void **)&g_02146A5C);
    if (z != 0) {
        func_0206A2CC(q, (void *)z);
        func_0206A4AC(q, (void *)z);
    }
    func_02069D14(*(void **)((u8 *)obj + 4), q);
    return obj;
}
