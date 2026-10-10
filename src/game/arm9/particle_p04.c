/*
 * file:     particle_p04.c
 * unit:     yes
 * function: func_02050C04, func_02050C30, func_02050DB8, func_02050ED4, func_02050F1C, func_02050F4C, func_02050F7C, func_02050FAC, func_02050FDC, func_0205100C, func_0205103C, func_0205106C, func_0205109C, func_020510CC, func_020510FC, func_0205112C, func_0205115C, func_0205118C, func_020511BC, func_020511EC, func_0205121C, func_02051230, func_02051360, func_02051380, func_02051394, func_020513F8, func_02051414, func_020514F4, func_02051504, func_02051534, func_02051574, func_020515B4, func_020515CC, func_02051614, func_02051620, func_02051630, func_02051640, func_02051648, func_02051758
 * address:  0x02050C04
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146A88     0x02146A88  data
 *   g_020A7FC0     0x020A7FC0  data
 *   g_020A1590     0x020A1590  data
 *   g_020A1584     0x020A1584  data
 *   g_020A1578     0x020A1578  data
 *   g_020A15A8     0x020A15A8  data
 *   func_02030734  0x02030734  arm
 *   func_02052DC8  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02051620  0x02051620  arm
 *   func_0206168C  0x0206168C  arm
 *   func_020621FC  0x020621FC  arm
 *   func_02061824  0x02061824  arm
 *   func_02062594  0x02062594  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048F60  0x02048F60  arm
 *   func_02046BFC  0x02046BFC  arm
 *   func_02046C10  0x02046C10  arm
 *   func_0206164C  0x0206164C  arm
 *   func_02061808  0x02061808  arm
 *   func_02052A50  0x02052A50  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02051A3C  0x02051A3C  arm
 *   func_02051A54  0x02051A54  arm
 *   func_02051AA0  0x02051AA0  arm
 *   func_02051AB8  0x02051AB8  arm
 *   func_020528A8  0x020528A8  arm
 *   func_020528BC  0x020528BC  arm
 *   func_020528D0  0x020528D0  arm
 *   func_02052984  0x02052984  arm
 *   g_020A159C      0x020A159C  data
 *   g_02148B4C      0x02148B4C  data
 *   g_02148B98      0x02148B98  data
 *   g_02148C08      0x02148C08  data
 *   func_020467EC   0x020467EC  arm
 *   func_02046858   0x02046858  arm
 *   func_02046AFC   0x02046AFC  arm
 *   func_02046B40   0x02046B40  arm
 *   func_020479D8   0x020479D8  arm
 *   func_02048AD0   0x02048AD0  arm
 *   func_020526A8   0x020526A8  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   func_0206DB80   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *   func_020524C8 0x020524C8 arm
 *   func_0205250C  0x0205250C  arm
 *   func_02048A24  0x02048A24  arm
 */
#include "../../matched/include/Obj01319.h"
#include "../../matched/include/Obj02319.h"
#include "../../matched/include/Obj06994.h"
#include "../../matched/include/Obj11458.h"
#include "../../matched/include/Obj08873.h"
#include "../../matched/include/Obj01197.h"

struct Dst648;
struct Src648;
struct Node;
struct Head;
struct Light;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u32 x, y, z; } Vec3;

struct Emit {
    u32  f00;
    u8   pad04[0x08];
    u32  f0c;
    u32  f10;
    u32  f14;
    u8   pad18[0x1a];
    u16  f32;
    Vec3 f34;
    Vec3 f40;
    Vec3 f4c;
    u8   pad58[0x202];
    u8   f25a;
};

typedef struct {
    u8 pad_00[0x10];
    u8 *cur;
} Arena_02050F1C;

typedef signed int     s32;

typedef struct {
    u32 x, y, z;
} VecFx32;

typedef struct {
    u32 m[9];
} MtxFx33;

typedef struct {
    u32 w[8];
} Blk32;

typedef struct {
    u32 w[9];
} Blk36;

struct Src648 {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c;
};

struct Dst648 {
    u8  pad00[0x20];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u8  pad32[0x229];
    u8  f25b;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_02052DC8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  MI_CpuFill8(void *dst, u32 v, u32 n);
extern void func_02051620(void);
extern void func_0206168C(u32 *src);
extern u32 func_020621FC(u32 h);
extern void func_02061824(void *p);
extern int func_02062594(u32 id);
extern u32 func_020307B0(void *p);
extern u32 func_02048AC4(void *ptr);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_02046BFC(void);
extern int func_02046C10(void);
extern void func_0206164C(u8 *p);
extern void func_02061808(u8 *p);
extern void func_02052A50(u32 a, u32 b);
extern void func_02030DA8(u32 a, u32 b, u8 *c, u32 d);
extern void func_020528A8(u32 a);
extern void func_020528BC(u32 a);
extern int  func_020528D0(u32 o, u32 alloc);
extern int  func_02052984(u32 o, u32 alloc);
extern void func_02030EAC(struct Node *n);
extern void func_020467EC(int p0);
extern void func_02046858(const u32 *src);
extern void func_02046AFC(u8 *dst);
extern void func_02046B40(u8 *a0);
extern void func_020479D8(void);
extern void func_02048AD0(struct Light *l);
extern void func_020526A8(struct Head *h, u32 a);
extern void func_0206A9DC(void *p);
extern void func_0206AA0C(VecFx32 *p);
extern void func_0206DB80(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity33_(MtxFx33 *p);
extern int func_02052770(u32 a);
extern int func_02052634(char *p, int b, int c);
extern int func_020525A0(char *p, int b, void (*fn)(void *));
extern void func_020524C8(void *p);
extern void func_0205250C(char *p, char *q);
extern int func_02048A24(int a0, int a1, int a2, int a3, int a4, int a5,
                         int a6, int a7, int a8, int a9, int a10, int a11);
int func_02050C04(int a, int b, int c, int d);
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
void func_02050DB8(u8 *p);
void func_02050ED4(void);
void *func_02050F1C(u32 size);
void *func_02050F4C(u32 size);
void *func_02050F7C(u32 size);
void *func_02050FAC(u32 size);
void *func_02050FDC(u32 size);
void *func_0205100C(u32 size);
void *func_0205103C(u32 size);
void *func_0205106C(u32 size);
void *func_0205109C(u32 size);
void *func_020510CC(u32 size);
void *func_020510FC(u32 size);
void *func_0205112C(u32 size);
void *func_0205115C(u32 size);
void *func_0205118C(u32 size);
void *func_020511BC(u32 size);
void *func_020511EC(u32 size);
int func_0205121C(u32 a, u32 b, u32 c);
void func_02051230(u8 *o, u32 a1, u32 a2, u32 a3);
void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
void func_02051380(void *p, void *r);
void func_02051394(u32 *p);
void func_020513F8(void *p, int a);
void func_02051414(u8 *a0);
int func_020514F4(u32 *p);
int func_02051504(void);
int func_02051534(void);
int func_02051574(void);
int func_020515B4(void *p, int b, int c);
int func_020515CC(int *p, int a, int b, int c);
int func_02051614(int **p);
asm void KeyValHashKey(void);
void func_02051630(void **p, void *q);
void *func_02051640(char *p);
void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, Vec3 *a3, Vec3 *a4, Vec3 *a5, u32 a6);
int func_02051758(int a0);
extern u32 *g_02146A88;
extern const char g_020A7FC0[];
extern Vec3 g_020A1590;
extern Vec3 g_020A1584;
extern Vec3 g_020A1578;
extern const u32 g_020A15A8[];
extern VecFx32  g_020A159C;
extern u32      g_02148B4C[];
extern u32      g_02148B98[];
extern u32      g_02148C08[];




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050C04.c \
 *       --func func_02050C04 --addr 0x02050C04 --cc 1.1p1 --arm
 */
int func_02050C04(int a, int b, int c, int d)
{
    return (int)func_02050C30(a, b, c, 5, 6, 63, d);
}




/*
 * particle.c, the emitter constructor (wave 13): find a free slot among the
 * sixteen in the 0x02146A88 table, allocate a 0x260-byte emitter (particle.c
 * line 285), clear it, copy the three default vectors in as struct
 * assignments, clear flag bit 0, wire the span fields from (a0, a1), publish
 * the emitter in its slot, optionally build the 3D block (a2 == 1), and store
 * func_02052DC8's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST, `extern const u32 g_020A15A8[];`.
 * Without const the element load may not move above the two argument stores
 * to the outgoing area (they could alias it), so the compiler schedules the
 * truncations and stores first; const lets it issue the table base load
 * first and the element load in the middle, as the image does.  The same
 * mechanism as docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md,
 * applied to a global array.  The note's argument order (a3, a4, a5 each
 * truncated with a (u16) cast at the use) and its three other decisions all
 * stand.
 */
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap)
{
    struct Emit *e;
    u32 *tab;
    int i = 0;

    tab = g_02146A88;
    do {
        if (tab[i] == 0)
            break;
        i++;
    } while (i < 16);
    if (i >= 16)
        return 0;

    e = (struct Emit *)func_02030734((u16)heap, 0x260, 0, g_020A7FC0, 285);
    MI_CpuFill8(e, 0, 0x260);
    e->f34 = g_020A1590;
    e->f40 = g_020A1584;
    e->f4c = g_020A1578;
    e->f32 = e->f32 & ~1u;
    MI_CpuFill8((void *)a0, 0, a1);
    e->f0c = a0;
    e->f10 = a0;
    e->f14 = a0 + a1;
    e->f25a = (u8)i;
    g_02146A88[i] = (u32)e;

    if (a2 == 1)
        func_02051648((struct Dst648 *)e, 0, 0x2000, 0, 0, 0, heap);

    e->f00 = func_02052DC8(g_020A15A8[i], 0x18, 0xc8, (u16)a3, (u16)a4, (u16)a5);
    return e;
}




/*
 * Emitter teardown: release the two 0x40-entry resource tables (either as a
 * whole through func_0206168C / func_02061824, or entry by entry through
 * func_020621FC / func_02062594 depending on the flag byte at +0x258), drop
 * the block at +4 unless the +0x32 bit-0 bitfield says otherwise, unpublish
 * the emitter from the singleton's sixteen-slot table, release the 3D block
 * at +0x20 and free the record.
 *
 * CLOSES both residues of docs/notes/func_02050DB8.c.txt.
 *
 * 1. The note's HARD BLOCKER is gone without filing anything: 0x0206168C
 *    (and 0x02061824) had no branch outside this range, but both are traced
 *    `func_` labels, so the sole-ref/code sub-kind added 2026-09-21 attests
 *    them.  All nine sites resolve, none wildcarded.
 *
 * 2. The note's 20-byte register swap in the sixteen-entry search loop is
 *    closed by writing that loop WITHOUT a cursor local: `g_02146A88[j]`
 *    drawn fresh at both the read and the store, not `a = g_02146A88; a[j]`.
 *    Found with tools/permuter.py (hill, budget 500, mutation `expand(a x2)`).
 *    The note ruled out declaration order, a separate index, hoisting the
 *    counter and the pointer-walk form, but never tried expanding the cursor
 *    away; with the cursor gone the array pointer lands in r2 and the index
 *    in r1, which is the image's assignment.  The note's other finding for
 *    this loop still holds and is still needed: the element goes into a named
 *    local `t` before the compare, or the compare comes out `cmp r5, r0`.
 *
 * Two more spelling tells found on the way to size-exact, neither in the note:
 *   * the two 0x40-entry loops read the element as `((u32 *)(p + 0x58))[i]`
 *     but store it as `*(u32 *)(p + i * 4 + 0x58)`.  Spelled the SAME way at
 *     both ends the compiler CSEs the address into a callee-saved register
 *     and holds it across the call, which drops the image's second
 *     `add r0, r5, r6, lsl #2` -- four bytes per loop, eight in total, and a
 *     sixth register in the frame.  Two different spellings of one address
 *     defeat the CSE and give the image's recompute-per-use.
 *   * the +0x32 guard is `((u32)(f << 31) >> 31) == 0`: the cast to u32 is
 *     what makes the second shift `lsrs` rather than `asrs` (the u16 field
 *     promotes to int, and a plain `>> 31` on an int is arithmetic).  A
 *     `& 1` mask folds to a single `tst` and is four bytes short, per the
 *     note.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050DB8.c \
 *       --func func_02050DB8 --addr 0x02050DB8 --cc 1.1p1 --arm
 *   EXACT, 284 bytes, 9 relocation sites, all resolved.
 */
void func_02050DB8(u8 *p)
{
    int i;
    u32 z = 0;

    func_02051620();

    if (p[0x258] & 1) {
        func_0206168C((u32 *)(p + 0x58));
    } else if (p[0x258] & 2) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x58))[i] != 0) {
                func_020621FC(((u32 *)(p + 0x58))[i]);
                *(u32 *)(p + i * 4 + 0x58) = z;
            }
        }
    }

    if (p[0x258] & 4) {
        func_02061824(p + 0x158);
    } else if (p[0x258] & 8) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x158))[i] != 0) {
                func_02062594(((u32 *)(p + 0x158))[i]);
                *(u32 *)(p + i * 4 + 0x158) = z;
            }
        }
    }

    {
        u32 h = ((struct Obj01319 *)p)->f4;
        p[0x258] = (u8)z;
        ((struct Obj01319 *)p)->f8 = z;
        if (h != 0) {
            if (((u32)((((struct Obj01319 *)p)->f32) << 31) >> 31) == 0) {
                func_020307B0((void *)h);
                ((struct Obj01319 *)p)->f4 = z;
            }
        }
    }

    {
        int j = 0;
        for (;;) {
            u32 t = g_02146A88[j];
            if (t == (u32)p) {
                g_02146A88[j] = z;
                break;
            }
            j++;
            if (j >= 0x10)
                break;
        }
    }

    if (((struct Obj01319 *)p)->f20 != 0)
        func_02048AC4((void *)(((struct Obj01319 *)p)->f20));

    func_020307B0(p);
}




/*
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through func_02050DB8, then the table pointer itself is handed to
 * func_020307B0 and cleared.  The global is re-read from its own slot before
 * every use, which is what the loop's `ldr r0, [r4]` at the top is; the two
 * pool words are the same address, so both `ldr r4, [pc, ...]` load one word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050ED4.c \
 *       --func func_02050ED4 --addr 0x02050ED4 --cc 1.1p1 --arm
 */
void func_02050ED4(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        u32 v = g_02146A88[i];

        if (v != 0)
            func_02050DB8((u8 *)v);
    }
    func_020307B0((void *)((u32)g_02146A88));
    g_02146A88 = 0;
}


void *func_02050F1C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[0];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_02050F4C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[1];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_02050F7C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[2];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_02050FAC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[3];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_02050FDC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[4];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205100C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[5];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205103C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[6];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205106C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[7];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205109C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[8];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_020510CC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[9];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_020510FC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[10];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205112C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[11];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205115C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[12];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_0205118C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[13];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_020511BC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[14];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}


void *func_020511EC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[15];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}





/*
 * Truncating forwarding wrapper: zero-extend the third argument to u16 and
 * tail-call func_02048F60.  The ARM9 listing emits it as a .word run (no
 * func_ label), so a `matched` entry is the only witness its callers can
 * use.
 */
int func_0205121C(u32 a, u32 b, u32 c)
{
    return (int)func_02048F60(a, b, (unsigned short)c);
}





/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_02051230(u8 *o, u32 a1, u32 a2, u32 a3)
{
    u32 f;
    u32 v;
    u32 z;
    s32 i;

    z = 0;
    f = (func_02046BFC() == 1) ? 1 : 2;
    v = func_02046C10();
    if (v == 1)
        v = 4;
    else
        v = 8;
    f |= v;
    o[0x258] = (u8)f;
    if (f & 1) {
        func_0206164C(o + 0x58);
        ((struct Obj02319 *)o)->f18 = 0x02051A3C;
    } else if (f & 2) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x58 + i * 4) = z;
        ((struct Obj02319 *)o)->f18 = 0x02051A54;
        *(u16 *)(o + 0x200 + 0x5c) = z;
    }
    if (f & 4) {
        func_02061808(o + 0x158);
        ((struct Obj02319 *)o)->f1C = 0x02051AA0;
    } else if (f & 8) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x158 + i * 4) = z;
        ((struct Obj02319 *)o)->f1C = 0x02051AB8;
        *(u16 *)(o + 0x200 + 0x5e) = z;
    }
    v = ((struct Obj02319 *)o)->f0;
    ((struct Obj02319 *)o)->f4 = a1;
    func_02052A50(v, a1);
    if (a2 == 1) {
        func_02051394((u32 *)o);
        return;
    }
    if (a3 == 0)
        return;
    func_02030DA8(a3, 0x020513F8, o, 0);
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051360.c \
 *       --func func_02051360 --addr 0x02051360 --cc 1.1p1 --arm
 */
void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3)
{
    func_02051230(p, a1, a2, a3);
    ((struct Obj02319 *)p)->f32 = (u16)((((struct Obj02319 *)p)->f32 & ~1) | 1);
}






/*
 * Tail call with two zero arguments. Filed as the witness for ov094 func_021FA12C.
 */
void func_02051380(void *p, void *r)
{
    func_02051230((u8 *)p, (u32)r, 0, 0);
}







/*
 * Publishes the emitter into the singleton's current-emitter slot (+0x44 of
 * the 0x02146A88 pointee, i.e. word index 0x11), routes each of the emitter's
 * two handler words at +0x18 and +0x1C to one of two handlers on null, then
 * clears the slot again.
 *
 * CLOSES the wall recorded in docs/notes/pkt_02051394.c.txt, which was not a
 * codegen residue at all: the note's two unresolved sites 0x020528A8 and
 * 0x020528BC are now EXACT entries of shard pkt_020526A8, so both attest
 * through `sole-ref/code` and the file needed only its remaining 10-byte
 * codegen gap closed.
 *
 * That gap was statement form.  The condition field and the call's argument
 * must both be read into NAMED LOCALS, and by plain ASSIGNMENT STATEMENTS
 * placed after the publish store, not by initialisers at the declarations:
 *   - inline (`if (p[6] == 0) func_020528BC(p[0]);`) the compiler folds the
 *     condition into r0 and issues `cmp` before the argument load, so the
 *     image's `ldr r1, [r4, #0x18]` / `ldr r0, [r4]` / `cmp r1, #0` triple
 *     comes out in the wrong order in BOTH blocks (10 bytes out);
 *   - as initialisers at the top of the body the two loads hoist ABOVE the
 *     `str r4, [r0, #0x44]` publish and the first block loses six more bytes
 *     (14 out).
 * Assignment statements after the store reproduce all 25 instructions.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051394.c \
 *       --func func_02051394 --addr 0x02051394 --cc 1.1p1 --arm
 */
void func_02051394(u32 *p)
{
    u32 a;
    u32 v;

    g_02146A88[0x11] = (u32)p;

    a = p[6];
    v = p[0];
    if (a == 0)
        func_020528BC(v);
    else
        func_02052984(v, a);

    a = p[7];
    v = p[0];
    if (a == 0)
        func_020528A8(v);
    else
        func_020528D0(v, a);

    g_02146A88[0x11] = 0;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020513F8.c \
 *       --func func_020513F8 --addr 0x020513F8 --cc 1.1p1 --arm
 */
void func_020513F8(void *p, int a)
{
    func_02051394((u32 *)a);
    func_02030EAC(p);
}






/*
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for func_0206A9DC, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to func_0206AA0C; then the shared call func_020526A8 and, when
 * the block is still there, the teardown.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051414.c.txt had it at 152 bytes out,
 * 220 against 224): the three setup-only locals are declared in a NESTED
 * BLOCK with INITIALISERS -- `VecFx32 v = g_020A159C; MtxFx33 m;
 * VecFx32 z = {0, 0, 0};`.  The aggregate initialiser `{0, 0, 0}` is what
 * keeps &z in a callee-saved register (r6) and stores the zero through it,
 * which costs the image's extra r7 (&v) and the push of r3/r7.  Assigning the
 * three fields, a pointer local, an inline VEC_Set, a compound literal and
 * the same locals in the if-block without initialisers all stay at 152 out.
 *
 * g_020A159C resolves through sole-ref/self (its only pool word is inside
 * this function; the ROM word equals the relocation), func_020526A8 through
 * sole-ref/code.
 */
void func_02051414(u8 *a0)
{
    Blk32    b;
    Blk36    g;

    if (((struct Obj06994 *)a0)->f20 != 0) {
        func_020467EC((int)(&b));
        func_02046AFC((u8 *)(&g));
        {
            VecFx32  v = g_020A159C;
            MtxFx33  m;
            VecFx32  z = {0, 0, 0};
            MTX_Identity33_(&m);
            func_0206A9DC(&z);
            MI_Copy36B(&m, g_02148C08);
            g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
            func_0206AA0C(&v);
        }
        func_02048AD0((struct Light *)(((struct Obj06994 *)a0)->f20));
        func_020479D8();
        func_0206DB80();
    }
    func_020526A8((struct Head *)(((struct Obj06994 *)a0)->f0), (u32)g_02148B98);
    if (((struct Obj06994 *)a0)->f20 == 0)
        return;
    func_02046858((const u32 *)(&b));
    func_02046B40((u8 *)(&g));
    func_020479D8();
    func_0206DB80();
}






/*
 * NOTE ON PACKET: this 16-byte leaf sits at 0x020514F4..0x02051504, in the
 * four-byte gap between packet pkt_02051230 (ends 0x020514F4) and packet
 * pkt_02051504 (starts 0x02051504) - the last instruction word of the
 * 0x02051414 dump plus a pool word.  The listing does label it
 * (`func_020514F4` at asm/arm9/src/019_0204D434.s:5680), but its only caller
 * in the whole image is the `bl` at 0x02051594 inside func_02051574, which is
 * itself inside pkt_02051504's range, so the `label` class cannot attest it for
 * that caller.  Filing it here as its own entry makes it a `matched` witness
 * for func_02051574 instead, which is the only reason it is in this shard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020514F4.c \
 *       --func func_020514F4 --addr 0x020514F4 --cc 1.1p1 --arm
 */
int func_020514F4(u32 *p)
{
    return func_02052770(*p);
}






/*
 * Counts the non-NULL entries of the 16-slot pointer table g_02146A88.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051504.c \
 *       --func func_02051504 --addr 0x02051504 --cc 1.1p1 --arm
 */
int func_02051504(void)
{
    int n = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0)
            n++;
    }
    return n;
}






/*
 * For every live slot of g_02146A88, calls func_02051414 with the slot value;
 * returns how many slots were live (not what the callee returned).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051534.c \
 *       --func func_02051534 --addr 0x02051534 --cc 1.1p1 --arm
 */
int func_02051534(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0) {
            func_02051414((u8 *)g_02146A88[i]);
            n++;
        }
    }
    return n;
}





/*
 * Same walk as func_02051534, but each live slot goes to func_020514F4 -
 * the pair is a start/stop pass over the same 16-entry table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051574.c \
 *       --func func_02051574 --addr 0x02051574 --cc 1.1p1 --arm
 */
int func_02051574(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88[i] != 0) {
            func_020514F4((u32 *)g_02146A88[i]);
            n++;
        }
    }
    return n;
}





/*
 * Promoted by parks lane 2: the callee 0x02052634 was filed first as an
 * EXACT entry (src/matched/func_02052634.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515B4.c \
 *       --func func_020515B4 --addr 0x020515B4 --cc 1.1p1 --arm
 */
int func_020515B4(void *p, int b, int c)
{
    int r = func_02052634((char *)(((struct Obj11458 *)p)->f0), b, c);
    ((struct Obj11458 *)p)->f8 = r;
    return r;
}




/*
 * Promoted by parks lane 2: the callee 0x020525A0 was filed first as an
 * EXACT entry (src/matched/func_020525A0.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * EXACT: every byte is identical and the listing extent is now 72 bytes
 * (it once ran on to 0x02051620 for want of a label at 0x02051610).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515CC.c \
 *       --func func_020515CC --addr 0x020515CC --cc 1.1p1 --arm
 */
int func_020515CC(int *p, int a, int b, int c)
{
    int r;
    if (*(int *)((char *)((struct Obj08873 *)p)->f0 + 8) >= 0x18)
        return -1;
    g_02146A88[0x10] = c;
    r = func_020525A0((void *)p[0], a, (void (*)(void *))b);
    g_02146A88[0x10] = 0;
    p[2] = r;
    return r;
}




/*
 * Returns word 2 of the object at *p. Filed as the witness for ov094 func_021FC744.
 */
int func_02051614(int **p)
{
    return (*p)[2];
}




asm void KeyValHashKey(void)
{
    ldr r0, [r0]
    ldr ip, =func_020524C8
    bx ip
}





/*
 * Dereference the first argument and tail-call func_0205250C with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 */
void func_02051630(void **p, void *q)
{
    func_0205250C(*p, q);
}





/*
 * Unlabelled ARM leaf in the ARM9 module. Reads the word at +0xC.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void *func_02051640(char *p)
{
    return ((struct Obj01319 *)p)->fC;
}





/*
 * Constructor for the 0x25c-byte emitter record: defaults the three pointer
 * arguments, zeroes three words, stores the id halfword, stamps the 0x25b
 * byte from the source record or from zero, then hands twelve arguments to
 * func_02048A24 and stores its return at +0x20.
 *
 * CLOSES the 268/272 near miss written up in docs/notes/func_02051648.c.txt,
 * whose whole residue was one missing `mov r0, #0`: the compiler kept the
 * prologue's live zero across the branch and reused it for the null arm's
 * first two statements, where the image re-materialises it.
 *
 * The lever is STATEMENT ORDER, found by tools/permuter.py (hill, budget 300,
 * mutation `reorder(+3)`): the three zero stores are written BETWEEN the a4
 * and a5 defaults, not after all three.  Interleaving them that way puts the
 * `ldreq ip, [pc, ...]` for a5 after the three `str r0` of the prologue zero,
 * which is what kills that zero's live range before the branch and forces the
 * null arm to build its own.  Written with all three defaults first the zero
 * survives and the arm is four bytes short; that is the note's residue.  The
 * reorder is value-preserving: the defaults and the stores touch disjoint
 * objects (three parameters versus three fields of `this`).
 *
 * The note's other findings are all still load-bearing and unchanged:
 *   * `src != 0` is the FALL-THROUGH arm; the null arm is the `beq`.
 *   * the three pointer defaults are evaluated unconditionally before the
 *     branch and the compiler predicates each (`ldreq r3, [pc, ...]`).
 *   * `this->f25b = (u8)src->f00` casts the WORD field: the image is
 *     `ldr r2, [lr]` then `strb`, not `ldrb`.
 *   * a6 is truncated at the USE with `(u16)`, not declared `u16`; declared
 *     u16 the compiler emits a single `ldrh` and the file is 2 bytes short
 *     (docs/families/particle.h records this tell for the whole family).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051648.c \
 *       --func func_02051648 --addr 0x02051648 --cc 1.1p1 --arm
 *   EXACT, 272 bytes, 5 relocation sites, all resolved (label x2, literal x3).
 */
void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, Vec3 *a3,
                   Vec3 *a4, Vec3 *a5, u32 a6)
{
    if (a3 == 0) a3 = &g_020A1590;
    if (a4 == 0) a4 = &g_020A1584;

    this->f24 = 0;
    this->f28 = 0;
    this->f2c = 0;

    if (a5 == 0) a5 = &g_020A1578;

    this->f30 = a2;

    if (src != 0) {
        this->f25b = (u8)src->f00;
        this->f20 = func_02048A24(src->f00, src->f04, src->f08, src->f0c,
                                  src->f10, src->f14, src->f18, src->f1c,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    } else {
        this->f25b = 0;
        this->f20 = func_02048A24(0, 0xb50, 0xb50, 0x1555,
                                  0, 0x1000, 0x384000, 0,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    }
}




int func_02051758(int a0)
{
    struct Obj01197 *o = (struct Obj01197 *)a0;

    func_02048AC4((void *)o->f20);
    o->f20 = 0;
    return 0;
}
