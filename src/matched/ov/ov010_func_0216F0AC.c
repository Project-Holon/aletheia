/*
 * function: func_0216F0AC
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
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0216F40C  0x0216F40C  thumb  ov010
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

extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern W *func_0203159C(void *heap, int size, int id);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0216F40C(void *a, int b, int c, int d, u16 e);

int func_0216F0AC(void *a, int b, T24 *c)
{
    W *w;

    func_0203064C(1, 0x26, 0x18000);
    w = func_0203159C(a, 0x20, 0x26);
    func_02082BCC(w, 0, 0x20);
    w->f00 = 0x26;
    w->f18 = func_02030734((u16)w->f00, 0x18, 1, d_02172B64, 0x9f);
    *w->f18 = *c;
    *(void **)w->f18 = func_02030734((u16)w->f00, 0x678, 1, d_02172B64, 0xa1);
    func_0216F40C(*(void **)w->f18, c->w[1], 0, w->f18->w[2], (u16)w->f00);
    w->f1c = ((struct Obj19150 *)(*(char **)w->f18))->f6;
    return 1;
}
