/*
 * function: TRCARD_SYS_Init
 * address:  0x0216F0AC
 * packet:   pkt_ov010_0216F0AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   TRCARD_SYS_BuildProfile  0x0216F40C  thumb  ov010
 *   d_02172B64     0x02172B64  data  ov010
 */
#include "../include/Obj19150.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int w[6];
} T24;

typedef struct {
    u32 f00;
    u8 pad04[0x14];
    T24 *f18;
    int f1c;
} W;

extern char d_02172B64[];

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int b, unsigned int c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Profile;
extern void TRCARD_SYS_BuildProfile(struct Profile *out, void *save, int mode, int flag, volatile u16 heap);

int TRCARD_SYS_Init(void *a, int b, T24 *c)
{
    W *w;

    GFL_HEAP_CreateChildHeap(1, 0x26, 0x18000);
    w = PROCSYS_AllocProcWork(a, 0x20, 0x26);
    MI_CpuFill8(w, 0, 0x20);
    w->f00 = 0x26;
    w->f18 = func_02030734((u16)w->f00, 0x18, 1, d_02172B64, 0x9f);
    *w->f18 = *c;
    *(void **)w->f18 = func_02030734((u16)w->f00, 0x678, 1, d_02172B64, 0xa1);
    TRCARD_SYS_BuildProfile(*(void **)w->f18, (void *)c->w[1], 0, w->f18->w[2], (u16)w->f00);
    w->f1c = ((struct Obj19150 *)(*(char **)w->f18))->f6;
    return 1;
}
