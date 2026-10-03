/*
 * function: func_021D0BE4
 * address:  0x021D0BE4
 * packet:   pkt_ov021_021D0BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0200E588  0x0200E588  thumb
 *   func_021D0C58  0x021D0C58  thumb  ov021
 *   d_0209DF0C     0x0209DF0C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    int f00;
    u8 f04;
    u8 pad05;
    u16 f06;
    int f08;
    int f0C;
    int f10;
    int f14;
    u8 pad18[0x78 - 0x18];
    int f78;
    u8 pad7C[0x80 - 0x7C];
    int f80;
    u8 *f84;
    u16 *f88;
    int f8C;
} Work;

extern void *func_020122C0(int a, int b, void *cb, int size);
typedef unsigned int   u32;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern u32 func_0200E588(void);
extern void func_021D0C58(void);
extern u8 d_0209DF0C;

void *func_021D0BE4(int a, u8 *b, u16 *c)
{
    void *task;
    Work *w;

    task = func_020122C0(a, 0, func_021D0C58, 0x90);
    w = func_020124E8(task);
    w->f80 = a;
    w->f88 = c;
    w->f84 = b;
    w->f8C = 0;
    w->f00 = 0x2E;
    w->f08 = func_0200E588();
    w->f0C = *(int *)(b + 0x14C);
    w->f10 = d_0209DF0C;
    w->f14 = 0x200000;
    w->f78 = 1;
    w->f04 = 0;
    w->f06 = 0x8015;
    return task;
}
