/*
 * function: func_021F9948
 * address: 0x021F9948
 * packet: pkt_ov094_021F9948
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_0207C768 0x0207C768 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE594 0x021FE594 thumb ov094
 *   func_021FE690 0x021FE690 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
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
} Job;
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE594(void *h, int *s);
extern void func_021FE690(void *);
extern const char d_0220AE68[];
#define FX(x) ((int)(((x) > 0) ? (0.5f + (float)((x) << 12)) : ((float)((x) << 12) - 0.5f)))

void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration)
{
    Work *w;
    Job *j;
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
