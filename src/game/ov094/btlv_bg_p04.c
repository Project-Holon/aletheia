/*
 * file:     btlv_bg_p04.c
 * unit:     yes
 * function: func_0220975C, func_0220977C, func_02209784, func_022097CC
 * address:  0x0220975C
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
 *   d_0220AEF0     0x0220AEF0  data  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02209A54  0x02209A54  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_0220986C  0x0220986C  thumb  ov094
 *   func_022099E8  0x022099E8  thumb  ov094
 */
typedef unsigned short u16;

typedef struct {
    void *f0;
    int f4;
    u16 f8;
} W_0220975C;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    char pad[8];
    u16 heap;               /* 0x08 */
} W_02209784;

typedef struct { int x, y, z; } Vec;

typedef struct {
    void *f0;
    u32 b0 : 1;
    u32 rest : 31;
} O;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
extern void *func_020056A0(void (*cb)(void *), void *ctx, int pri);
extern void func_02209A54(void *h);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern void func_0220986C(O *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                          void (*f1)(void *, void *));
extern void func_022099E8(void *, void *);
W_0220975C *func_0220975C(void *a, u16 heap);
void func_0220977C(void *p);
void func_02209784(W_02209784 *w, u32 a, u32 b);
void func_022097CC(O *o, int a, u32 mode, int x, int y, int s1, int s2, int s3);
extern char d_0220AEF0[];


W_0220975C *func_0220975C(void *a, u16 heap)
{
    W_0220975C *w = func_02030734(heap, 0xc, 1, d_0220AEF0, 0x48);
    w->f0 = a;
    w->f8 = heap;
    return w;
}


void func_0220977C(void *p)
{
    func_020307B0(p);
}


void func_02209784(W_02209784 *w, u32 a, u32 b)
{
    u32 *o;

    o = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEF0, 0x67);
    o[0] = a;
    o[1] = b;
    func_021F896C(func_020056A0(func_02209A54, o, 0), 0, 0);
}


void func_022097CC(O *o, int a, u32 mode, int x, int y, int s1, int s2, int s3)
{
    Vec w;
    Vec v;

    v.x = x << 12;
    v.y = y << 12;
    v.z = 0;
    w.x = func_020407E8(3) << 12;
    w.y = func_02040804(3) << 12;
    w.z = 0;
    if (mode == 4 && (a & 1))
        v.x *= -1;
    if (mode == 1) {
        v.x += w.x;
        v.y += w.y;
        v.z += w.z;
    }
    func_0220986C(o, mode, &w, &v, s1, s2, s3, func_022099E8);
    o->b0 = 1;
}
