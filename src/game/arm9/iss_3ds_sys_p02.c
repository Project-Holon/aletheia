/*
 * file:     iss_3ds_sys_p02.c
 * unit:     yes
 * function: func_0202B90C, func_0202B914, func_0202B920, func_0202B928, func_0202B934, func_0202B93C, func_0202B944, func_0202B958, func_0202B9C8, func_0202B9E0, func_0202B9F0, func_0202BA24, func_0202BA60, func_0202BA7C, func_0202BA9C, func_0202BABC, func_0202BAE8
 * address:  0x0202B90C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202BB40  0x0202BB40  thumb
 *   func_0202BB48  0x0202BB48  thumb
 */
#include "../../matched/include/Obj15845.h"
#include "../../matched/include/Obj01019.h"
#include "../../matched/include/Obj02601.h"

struct Obj;
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned int  u32;

typedef struct { int x, y, z; } V3;

typedef unsigned short u16;

struct Item {
    u32 id;
    u32 unk;
};

struct Obj {
    u8 pad[0x264];
    const struct Item *items;
    u8 count;
};

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

typedef struct { int f0; V3 pos; int f10; int f14; int f18; } E;

typedef struct { char pad[0x24]; E e[1]; } M;

extern void func_0202BB40(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u16    func_0204961C(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void   func_02049238(void *h);
extern u32 func_020307B0(void *p);
extern void func_0202B944(void *obj);
extern u16 func_02005C44(void);
extern int func_0202BB48(int a0);
void func_0202B90C(u8 *a0);
void func_0202B914(struct Obj *o, u32 v);
void func_0202B920(void *m, int i, int a, int b);
int func_0202B928(int a, int b);
void func_0202B934(void *m, int i, const V3 *v);
void func_0202B93C(int a, void *b, void *c);
void sub_0202B944(void *obj);
void func_0202B958(u8 *p);
void func_0202B9C8(struct Obj *o);
int func_0202B9E0(int a0, int a1);
u8 func_0202B9F0(const struct Obj *p, u32 key);
void func_0202BA24(u8 *p);
void func_0202BA60(M *m, int i, int a, int b);
void func_0202BA7C(M *m, int i, const V3 *v);
void func_0202BA9C(char *p, const int *a, const int *b);
void func_0202BABC(u8 *o);





/*
 * A bare tail-call thunk, same shape as func_0202B8F4 (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BB41).  0x0202BB40 is itself another thunk (to
 * func_0202BA24), filed as src/matched/func_0202BB40.c in the same shard;
 * that entry is the matched witness for this pool word.
 */
void func_0202B90C(u8 *a0)
{
    func_0202BB40(a0);
}






/*
 * Clamps the second argument to 0x7f and stores it in the +8 byte.  No
 * relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B914.c \
 *       --func func_0202B914 --addr 0x0202B914 --thumb --cc 1.1p1
 */
void func_0202B914(struct Obj *o, u32 v)
{
    if (v > 0x7f) {
        v = 0x7f;
    }
    ((struct Obj15845 *)o)->f8 = (u8)v;
}






/*
 * Unlabelled arm9 leaf, filed as a relocation witness for ov021
 * func_021C4D14 (wave A1, lane 13).
 */
void func_0202B920(void *m, int i, int a, int b)
{
    func_0202BA60(m, i, a, b);
}





int func_0202B928(int a, int b)
{
    return *(int *)(a + b * 0x1c + 0x24);
}






/*
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C4E34
 * (wave A1, lane 13).
 */
void func_0202B934(void *m, int i, const V3 *v)
{
    func_0202BA7C(m, i, v);
}






void func_0202B93C(int a, void *b, void *c)
{
    func_0202BA9C((char *)a, b, c);
}






/*
 * A three-field initialiser on a far offset (0x264): a word cleared, a byte
 * cleared right after it, and a byte set to 0xff two past that. The offset
 * is past the Thumb ldr/str immediate reach, so the compiler computes the
 * base with a shift instead of an immediate, which is ordinary codegen for
 * a field this far out rather than anything hand written. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B944.c \
 *       --func sub_0202B944 --addr 0x0202B944 --cc 1.1p1 --thumb
 */
void sub_0202B944(void *obj)
{
    ((struct Obj01019 *)obj)->f264 = 0;
    ((struct Obj01019 *)obj)->f268 = 0;
    ((struct Obj01019 *)obj)->f269 = 0xff;
}






/*
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Same list dance as func_0202BEEC, on a node whose record table sits at
 * 0x264 and whose record count at 0x268; the node's own u16 id supplies the
 * selector.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B958.c \
 *       --func func_0202B958 --addr 0x0202B958 --thumb --cc 1.1p1
 */
void func_0202B958(u8 *p)
{
    u32  id = ((struct Obj01019 *)p)->f0;
    void *h = func_020490F4(0xb9, (u16)((id & 0x7fff) | 0x8000));
    u8   n = (u8)func_0204961C(h);
    u32  i;

    p[0x268] = n;
    ((struct Obj01019 *)p)->f264 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                             (const void *)0x020A7738, 0x178);

    for (i = 0; i < (u32)n; i++) {
        func_0204932C(h, i, (void *)(((struct Obj01019 *)p)->f264 + (i << 3)));
    }
    func_02049238(h);
}





/*
 * Releases the +0x264 field through the matched heap release func_020307B0,
 * then tears the object down through func_0202B944.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B9C8.c \
 *       --func func_0202B9C8 --addr 0x0202B9C8 --thumb --cc 1.1p1
 */
void func_0202B9C8(struct Obj *o)
{
    func_020307B0((void *)(((struct Obj01019 *)o)->f264));
    func_0202B944(o);
}




int func_0202B9E0(int a0, int a1){ if ((unsigned int)(*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0)))) != (unsigned int)(a1)) { *(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0))) = (unsigned char)a1; } else {  return a0; } }





u8 func_0202B9F0(const struct Obj *p, u32 key)
{
    const struct Item *items = p->items;
    u8 count;
    u8 i;

    if (items == 0) {
        return 0xff;
    }

    count = p->count;
    for (i = 0; i < count; i++) {
        if (items[i].id == key) {
            return i;
        }
    }

    return 0xff;
}





/*
 * iss_3ds_sys.c: resets the 0x10 entries (record +0x24 stride 0x1c) and the
 * two parallel word arrays at +0x1e4 and +0x224.  EXACT* (the listing extent
 * runs on into the unlabelled 28-byte follower at 0x0202BA60).
 *
 * Two facts closed it after thirteen loop spellings had failed
 * (docs/notes/pkt_0202B9F0.c.txt): the counter is an enum, which keeps the
 * unfolded `cmp r4, #0x10; bge` entry guard with a plain increment
 * (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md), and the
 * three word stores write 0, not i: r3 is a copy of the counter taken once in
 * the preheader, when both are zero, and never incremented.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BA24.c \
 *       --func func_0202BA24 --addr 0x0202BA24 --thumb --cc 1.1p1
 */
void func_0202BA24(u8 *p)
{
    Slot i;
    for (i = 0; i < 0x10; i++) {
        *(u32 *)(p + i * 0x1c + 0x24) = 0;
        *(u32 *)(p + i * 0x1c + 0x38) = 0x7f;
        *(u16 *)(p + i * 0x1c + 0x3c) = 1 << i;
        *(u32 *)(p + i * 4 + 0x1e4) = 0;
        *(u32 *)(p + i * 4 + 0x224) = 0;
    }
}



void func_0202BA60(M *m, int i, int a, int b)
{
    E *e = &m->e[i];
    if (e->f0 != 1) {
        e->f0 = 1;
        e->f10 = a;
        e->f14 = b;
    }
}



static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}



/*
 * Unlabelled arm9 leaf, filed as the relocation witness for arm9 func_0202B934 (ov021 func_021C4E34)
 * (wave A1, lane 13).
 */
void func_0202BA7C(M *m, int i, const V3 *v)
{
    E *e = &m->e[i];

    if (e->f0 != 0)
        V3_Set(&e->pos, v->x, v->y, v->z);
}



static inline void set3(int *d, int x, int y, int z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}




void func_0202BA9C(char *p, const int *a, const int *b)
{
    set3((int *)(p + 0xC), a[0], a[1], a[2]);
    set3((int *)(p + 0x18), b[0], b[1], b[2]);
}




/*
 * Closed by the `matched` class: 0x0202B9F0 became an EXACT shard entry
 * (pkt_0202B9F0) in this wave.  The listing extent runs to 0x0202BAF4
 * because the follower at 0x0202BAE6 is unlabelled, so the verdict is EXACT*.
 */
void func_0202BABC(u8 *o)
{
    if (((struct Obj02601 *)o)->f4 != 0) {
        return;
    }
    ((struct Obj02601 *)o)->f4 = 1;
    func_0202B9E0((int)o, func_0202B9F0((const struct Obj *)o, func_02005C44()));
    func_0202BB48((int)o);
}


void func_0202BAE8(u32 *p);

void func_0202BAE8(u32 *p)
{
    if (p[1] != 0) {
        p[1] = 0;
    }
}
