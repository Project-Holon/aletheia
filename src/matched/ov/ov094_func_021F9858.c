/*
 * function: BTLV_EFFVM_StartSePlayTask
 * address: 0x021F9858
 * packet: pkt_ov094_021F9858
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 *   BTLV_EFFECT_IsSeSuppressed 0x021F88E0 thumb ov094
 *   BTLV_EFFVM_ResolveSlotKey 0x021FCF2C thumb ov094
 *   BTLV_EFFVM_PlaySeWithParams 0x021FDB40 thumb ov094
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFVM_SePlayTaskMain 0x021FE54C thumb ov094
 *   BTLV_EFFVM_SePlayTaskEnd 0x021FE580 thumb ov094
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
extern void *VM_GetUserData(struct ScriptVm *vm);
extern int BTLV_EFFECT_IsSeSuppressed(void);
extern int BTLV_EFFVM_ResolveSlotKey(int a, int idx);
extern void BTLV_EFFVM_PlaySeWithParams(u32 a, int b, int c, int d, u32 e, u32 f, u32 g);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFVM_SePlayTaskMain(void *h, int *s);
extern void BTLV_EFFVM_SePlayTaskEnd(void *);
extern const char d_0220AE68[];

void BTLV_EFFVM_StartSePlayTask(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d)
{
    Work *w;
    Job *j;
    w = VM_GetUserData(vm);
    if (BTLV_EFFECT_IsSeSuppressed() == 1)
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
        if (BTLV_EFFVM_ResolveSlotKey((int)vm, c) & 1)
            c = 127;
        else
            c = -128;
    }
    if (g > 255)
        g = 255;
    if (h > 255)
        h = 255;
    if (d == 0) {
        BTLV_EFFVM_PlaySeWithParams(a, b, c, e, f, g, h);
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
    BTLV_EFFECT_RegisterTask(func_02030DA8(w->owner, (void (*)(void *, void *))BTLV_EFFVM_SePlayTaskMain, j, 0), BTLV_EFFVM_SePlayTaskEnd, 1);
}
