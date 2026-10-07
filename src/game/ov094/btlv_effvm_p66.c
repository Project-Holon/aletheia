/*
 * file:     btlv_effvm_p66.c
 * unit:     yes
 * function: func_021FFB04, func_021FFBBC
 * address:  0x021FFB04
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02015C30  0x02015C30  thumb
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_022010D0  0x022010D0  thumb  ov094
 *   func_022011FC  0x022011FC  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 *   func_02016068 0x02016068 thumb
 *   func_0220074C 0x0220074C thumb ov094
 *   func_02201234 0x02201234 thumb ov094
 *   func_022012CC 0x022012CC thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../matched/include/Obj06309.h"

#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x5c - 4];
} Entry;

typedef struct {
    void *owner;            /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad510[0x514 - 0x510];
    int mask[6];            /* 0x514 */
    char pad52c[0x540 - 0x52c];
    u16 heap;               /* 0x540 */
    u8 cnt[6][14];          /* 0x542 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    int v[3];               /* 0x08 */
    char pad14[0x14];
    int f28;                /* 0x28 */
} Obj;

typedef struct { int x, y, z; } Vec;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_02015C30(void *p, u32 *out);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern int func_021F935C(int x);
extern void func_022010D0(void *task, char *q);
extern void func_022011FC(void *p);
extern int func_022019F4(char *p, int key);
extern u8 func_02016068(void *p);
extern void func_0220074C(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern void func_02201234(void *o, char *q);
extern void func_022012CC(void *p);
void func_021FFB04(Work *w, Obj *s);
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);
extern const char d_0220AE7C[];


void func_021FFB04(Work *w, Obj *s)
{
    Obj *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AE7C, 0x660);
    int idx = func_022019F4((char *)w, s->key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    *o = *s;
    o->w = w;
    func_02015C30(w->e[idx].h, (u32 *)o->v);
    w->cnt[0][o->key]++;
    o->f28 = w->cnt[0][o->key];
    func_021F896C(func_02030DA8(w->owner, (void *)func_022010D0, o, 0), func_022011FC, 2);
    w->mask[0] |= func_021F935C(o->key);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02016068_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int padbits : 24; unsigned int value : 4; } Data;
 * u8 func_02016068(Data *p) { return p->value; }
 */
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(func_02016068(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x5a4 + key))++;
    func_0220074C(w, key, kind, &start, &end, a, b, c, (void *)func_02201234, func_022012CC, 0, *(u8 *)(w + 0x5a4 + key));
    ((struct Obj06309 *)w)->f530 |= func_021F935C(key);
}
