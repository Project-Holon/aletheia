/*
 * function: func_021F93F4
 * address:  0x021F93F4
 * packet:   pkt_ov094_021F93F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   d_02209DCC     0x02209DCC  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad0[8];
    void *a;            /* 8 */
    char pad1[0x40];
    int v4c[16];        /* 0x4C */
    char padx[0x40];
    int vcc[4];         /* 0xCC */
    char pad2[0x238 - 0xDC];
    u16 h238;           /* 0x238 */
    char pad3[2];
    int f23c;           /* 0x23C */
    char pad4[4];
    int f244;           /* 0x244 */
    char pad5[0x26C - 0x248];
    int e26c[6];        /* 0x26C */
} T;

extern char d_0220AE68[];
extern char d_02209DCC[];

struct ScriptVm;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ScriptVmParams;
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);

void *func_021F93F4(void *a, u32 b)
{
    T *t;
    void *vm;
    int i;

    t = func_02030734(b, 0x2AC, 1, d_0220AE68, 0x27D);
    t->h238 = b;
    t->a = a;
    t->f23c = 1;
    t->f244 = 1;
    for (i = 0; i < 16; i++)
        t->v4c[i] = -1;
    for (i = 0; i < 4; i++)
        t->vcc[i] = -1;
    for (i = 0; i < 6; i++)
        t->e26c[i] = -1;
    vm = VM_Create(b, (const struct ScriptVmParams *)d_02209DCC);
    VM_Init(vm, t);
    return vm;
}
