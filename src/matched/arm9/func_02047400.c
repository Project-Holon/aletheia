/*
 * function: G3D_SYSTEM_CreateRender
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
 *   _G3dSystem      0x02146A5C  data
 *   g_szG3DSystem   0x020A7EA8  data
 *   NNS_G3dGetMdlSet   0x0206E954  arm
 *   NNS_G3dGetTex   0x0206E964  arm
 *   func_02030734   0x02030734  arm
 *   NNS_G3dAllocRenderObj   0x0206E348  arm
 *   func_0206A2CC   0x0206A2CC  arm
 *   func_0206A4AC   0x0206A4AC  arm
 *   func_02069D14   0x02069D14  arm
 *
 * Construct a 0x7A14-tagged record (the sibling of G3D_SYSTEM_CreateAnime's 0x59D1
 * one): look the owner's +4 handle up through NNS_G3dGetMdlSet, index its
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
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_CreateRender.c \
 *       --func G3D_SYSTEM_CreateRender --addr 0x02047400 --cc 1.1p1 --arm
 */
#include "../include/Obj04073.h"
#include "../include/Obj09057.h"
#include "../include/Obj11417.h"
#include "../include/Obj16035.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern int NNS_G3dGetMdlSet(int p0);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *NNS_G3dAllocRenderObj(void *);
extern void func_0206A2CC(void *, void *);
extern void func_0206A4AC(void *, void *);
extern void func_02069D14(void *, void *);
extern u32 _G3dSystem;
extern char g_szG3DSystem[];

void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2)
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
    p = (u8 *)NNS_G3dGetMdlSet((int)(((struct Obj09057 *)a0)->f4));
    if (p == 0) goto qzero;
    b = p + 8;
    if (b == 0) goto ozero;
    if (n >= p[9]) goto ozero;
    idx = ((struct Obj11417 *)p)->fE;
    cnt = *(u16 *)(b + idx);
    ofs = (u8 *)(cnt * n + (s32)(b + idx + 4));
    goto join;
ozero:
    ofs = 0;
join:
    if (ofs != 0) { q = (void *)(p + ((struct Obj16035 *)ofs)->f0); goto have; }
qzero:
    q = 0;
have:
    ;

    if (a2 != 0) z = (u32)NNS_G3dGetTex(((struct Obj09057 *)a2)->f4);

    obj = func_02030734(*(u16 *)((u8 *)*(void **)&_G3dSystem + 0x18),
                        0x10, 0, g_szG3DSystem, 0x608);
    ((struct Obj04073 *)obj)->f0 = 0x7A14;
    ((struct Obj04073 *)obj)->f8 = a0;
    ((struct Obj04073 *)obj)->fC = a2;
    ((struct Obj04073 *)obj)->f4 = NNS_G3dAllocRenderObj(*(void **)&_G3dSystem);
    if (z != 0) {
        func_0206A2CC(q, (void *)z);
        func_0206A4AC(q, (void *)z);
    }
    func_02069D14(((struct Obj04073 *)obj)->f4, q);
    return obj;
}
