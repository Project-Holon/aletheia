/*
 * file:     btlv_effvm_p29.c
 * unit:     yes
 * function: func_021F93F4, func_021F9478
 * address:  0x021F93F4
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
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   d_02209DCC     0x02209DCC  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   func_0201121C  0x0201121C  thumb
 *   func_0201126C  0x0201126C  thumb
 *   func_02011298  0x02011298  thumb
 *   func_02011324  0x02011324  thumb
 *   func_021F8198  0x021F8198  thumb  ov094
 *   func_021FE410  0x021FE410  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 */
struct ScriptVm;
struct ScriptVmParams;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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
} T_021F93F4;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
    char pad[0x1E4];
    void *h;            /* 0x1E8 */
} T_021F9478;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern int func_02011298(struct ScriptVm *vm);
extern void *func_02011324(struct ScriptVm *vm);
extern void func_021F8198(int a, int b);
extern void func_021FE410(T_021F9478 *t, int a, int b, int c);
extern u32 func_020307B0(void *p);
void *func_021F93F4(void *a, u32 b);
int func_021F9478(void *vm);
extern char d_0220AE68[];
extern char d_02209DCC[];


void *func_021F93F4(void *a, u32 b)
{
    T_021F93F4 *t;
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
    vm = func_0201121C(b, (const struct ScriptVmParams *)d_02209DCC);
    func_0201126C(vm, t);
    return vm;
}


int func_021F9478(void *vm)
{
    int r;
    T_021F9478 *t;

    r = func_02011298(vm);
    t = func_02011324(vm);
    if (t->b7)
        return 0;
    if (r == 0 && t->h != 0) {
        func_021F8198(1, 2);
        if (t->b6 == 0)
            func_021FE410(t, 0x6B000, 0x7F000, 0x14);
        func_020307B0(t->h);
        t->h = 0;
    }
    return r;
}
