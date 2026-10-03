/*
 * function: func_021F9858
 * address: 0x021F9858
 * packet: pkt_ov094_021F9858
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
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
 */
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
} Job;
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern int func_021F88E0(void);
extern int func_021FCF2C(void *vm, u32 idx);
extern void func_021FDB40(u32 a, int b, int c, int d, u32 e, u32 f, u32 g);
extern Job *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE54C(void *, void *);
extern void func_021FE580(void *);
extern const char d_0220AE68[];

void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d)
{
    Work *w;
    Job *j;
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
        if (func_021FCF2C(vm, c) & 1)
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
    j = func_02030734((w->heap & 0x7fff) | 0x8000, 0x24, 0, d_0220AE68, 0x431);
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
    func_021F896C(func_02030DA8(w->owner, func_021FE54C, j, 0), func_021FE580, 1);
}
