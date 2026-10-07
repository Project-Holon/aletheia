/*
 * file:     btlv_effvm_p32.c
 * unit:     yes
 * function: func_021F9858, func_021F9948, func_021F9A7C, func_021F9AA4
 * address:  0x021F9858
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
 *   func_02011324 0x02011324 thumb
 *   func_021F88E0 0x021F88E0 thumb ov094
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_021FDB40 0x021FDB40 thumb ov094
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE54C 0x021FE54C thumb ov094
 *   func_021FE580 0x021FE580 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   func_0207C768 0x0207C768 arm
 *   func_021FE594 0x021FE594 thumb ov094
 *   func_021FE690 0x021FE690 thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02006BB4 0x02006BB4 thumb
 */
#include "../../matched/include/Obj13584.h"

#define FX(x) ((int)(((x) > 0) ? (0.5f + (float)((x) << 12)) : ((float)((x) << 12) - 0.5f)))
struct ScriptVm;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u32 flags;
    u32 f4;
    void *owner;
    char pad[0x238 - 12];
    u16 heap;
} Work;

typedef struct {
    Work *work;
    u32 a;
    int b;
    int c;
    int d;
    int e;
    u32 f;
    int g;
    int h;
} Job_021F9858;

typedef struct {
    Work *work;
    u32 a;
    int mode;
    int c;
    int x;
    int dest;
    int fx;
    int delta;
    int e;
    int f;
    int remaining;
    int zero;
    int g;
    int duration;
} Job_021F9948;

extern void *func_02011324(struct ScriptVm *vm);
extern int func_021F88E0(void);
extern int func_021FCF2C(int a, int idx);
extern void func_021FDB40(u32 a, int b, int c, int d, u32 e, u32 f, u32 g);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE54C(void *h, int *s);
extern void func_021FE580(void *);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021FE594(void *h, int *s);
extern void func_021FE690(void *);
extern void func_02006BB4(u32 i);
void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);
void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);
void func_021F9A7C(void *a);
void func_021F9AA4(void *a);
extern const char d_0220AE68[];


void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d)
{
    Work *w;
    Job_021F9858 *j;
    w = func_02011324(vm);
    if (func_021F88E0() == 1)
        return;
    w->flags |= 0x1000;
    if (c == 2)
        c = 0;
    else if (c <= 1) {
        if (c & 1)
            c = 127;
        else
            c = -128;
    } else {
        if (func_021FCF2C((int)vm, c) & 1)
            c = 127;
        else
            c = -128;
    }
    if (g > 255)
        g = 255;
    if (h > 255)
        h = 255;
    if (d == 0) {
        func_021FDB40(a, b, c, e, f, g, h);
        return;
    }
    j = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE68, 0x431);
    j->work = w;
    j->a = a;
    j->b = b;
    j->c = c;
    j->d = d;
    j->e = e;
    j->f = f;
    j->g = g;
    j->h = h;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, (void (*)(void *, void *))func_021FE54C, j, 0), func_021FE580, 1);
}


void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration)
{
    Work *w;
    Job_021F9948 *j;
    float ff;
    int fd;
    w = func_02011324(vm);
    j = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0x455);
    j->work = w;
    j->a = a;
    j->mode = mode;
    j->c = c;
    j->x = x;
    j->dest = dest;
    j->e = e;
    j->f = f;
    j->remaining = f;
    j->zero = 0;
    j->g = g;
    j->duration = duration * 2;
    if (mode == 1 && j->duration == 0)
        j->duration = 2;
    j->fx = FX(j->x);
    if (j->f > 0)
        ff = 0.5f + (float)(j->f << 12);
    else
        ff = (float)(j->f << 12) - 0.5f;
    fd = FX(j->dest - j->x);
    j->delta = func_0207C768(fd, (int)ff);
    func_021F896C(func_02030DA8(w->owner, (void (*)(void *, void *))func_021FE594, j, 0), func_021FE690, 1);
    w->flags |= 8;
}


/*
 * Stops every live sound slot of the owner's work (six words at 0x26c, -1 = free).
 */
void func_021F9A7C(void *a)
{
    char *s = func_02011324(a);
    int i;

    for (i = 0; i < 6; i++) {
        if (((int *)(s + 0x26c))[i] != -1)
            func_02006BB4(((int *)(s + 0x26c))[i]);
    }
}


/*
 * Clears the two words at 0x2a4 and 0x2a8 of the owner's work.
 */
void func_021F9AA4(void *a)
{
    char *s = func_02011324(a);
    ((struct Obj13584 *)s)->f2A4 = 0;
    ((struct Obj13584 *)s)->f2A8 = 0;
}
