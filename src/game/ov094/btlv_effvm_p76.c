/*
 * file:     btlv_effvm_p76.c
 * unit:     yes
 * function: func_02201098, func_022010D0
 * address:  0x02201098
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
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   d_020A1B38 0x020A1B38 data a4
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_02015C78 0x02015C78 thumb
 */
#include "../../matched/include/Obj06318.h"
#include "../../matched/include/Obj02439.h"

#define FIX(x) ((int)(((x) > 0.0f) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
struct S02030EE8;
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work;

typedef struct {
    char body[0x24];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x38 */
} Ctx;

typedef unsigned int   u32;

typedef short s16;

typedef long long s64;

typedef struct Vec { int x, y, z; } Vec;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F935C(int x);
extern int func_022019F4(char *, int);
extern void func_021F89BC(void *);
extern void func_02015C78(void *, u32 *);
void func_02201098(void *h);
void func_022010D0(void *task, char *q);
extern const s16 d_020A1B38[];


/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key, as in sibling
 * func_022011FC. With one spelling CSE hoists key ahead of the index and it
 * loads first (the +0x50 twins' order); with two spellings key is
 * copy-propagated and c->w loads first, as the image does.
 */
void func_02201098(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06318 *)c)->f4) ^ 0xFFFFFFFF;
}

/*
 * lever: Separate x/y/z clears preserve the original store order.
 */
void func_022010D0(void *task, char *q)
{
    char *p = *(char * *)&((struct Obj02439 *)q)->f0;
    Vec v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj02439 *)q)->f4);
    char *e;
    int off;
    int n, f;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj02439 *)q)->f28 != *(u8 *)(p + ((struct Obj02439 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    ((struct Obj02439 *)q)->f18 += ((struct Obj02439 *)q)->f1C;
    n = d_020A1B38[((((struct Obj02439 *)q)->f18 & 0x0ffff000) >> 16) * 2];
    f = FIX((float)n / 4096.0f);
    f = (int)(((s64)f * ((struct Obj02439 *)q)->f20 + 0x800) >> 12);
    if (((struct Obj02439 *)q)->f14 != 0) v.y = f;
    else v.x = f;
    func_02015C78(*(void **)(e + off), (u32 *)&v);
    ((struct Obj02439 *)q)->f24 -= 1;
    if (((struct Obj02439 *)q)->f24 == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        func_02015C78(*(void **)(e + off), (u32 *)&v);
        func_021F89BC(task);
    }
}
