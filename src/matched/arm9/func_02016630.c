/*
 * function: func_02016630
 * address:  0x02016630
 * packet:   pkt_020163C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The mcss.c rebind routine (line 0x8AB), twin of func_020163C4.  Closed
 * in wave 15 from 21 bytes out by the same declaration: the descriptor
 * parameter is const struct Src *, which fixes the argument load order
 * at every constructor call site.  History:
 * docs/notes/func_02016630.c.txt.
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   data_020A72CC  0x020A72CC  data
 *   func_02016880  0x02016880  thumb
 */
#include "../include/Obj00696.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj_02016880;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
struct ArcFile;
extern void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02063790(void *p);
extern void func_020637D4(void *p);
extern void sub_02016028(void *p, u32 flag);
extern void func_02016C60(void *a, void *b);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02016880(void *a0, struct Obj_02016880 *a1);

extern char data_020A72CC[];

struct Obj {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Ctx {
    void *f00;
    void *f04;
    void *f08;
    u8 pad0c[8];
    void **f14;
    u8 pad18[0x18];
    u32 f30;
    u32 f34;
    u32 (*f38)(void *, void *, u32);
    u32 f3c;
};

struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
};

void func_02016630(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    void *h;
    struct Obj *p;
    u32 flag;
    u32 *q;

    h = a0->f00;
    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    func_02063790(a1 + 0x9C);
    func_020637D4(a1 + 0xC0);

    ((struct Obj00696 *)a1)->fC = func_02049FFC(h, (u32)(((struct Src *)a2)->f0c), 0,
                                          (u32)((void *)(a1 + 0x10)),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f1C = func_0204A07C(h, (u32)a2->f10, 1, (u32)(a1 + 0x20),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    flag = 1;
    ((struct Obj00696 *)a1)->f14 = func_0204A0FC(h, (u32)a2->f14, 0, (u32)(a1 + 0x18),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f24 = func_0204A17C(h, (u32)a2->f18, 0, (u32)(a1 + 0x28),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    sub_02016028(a1, 0);

    q = func_02049250(h, (u32)a2->f1c, (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    *(u32 * *)&((struct Obj00696 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj00696 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x8AB);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = func_02049DF4(h, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = func_02049F78(h, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj00696 *)a1)->fD4 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3);
    ((struct Obj00696 *)a1)->fD8 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3 + 1);
    ((struct Obj00696 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj00696 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void *)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        func_02016C60(a1, p);
    }
    if (a0->f08 != 0) {
        ((struct Obj00696 *)a1)->f0 = func_02030DA8(a0->f08, func_02016880, p, 0);
    } else {
        ((struct Obj00696 *)a1)->f0 = func_020056A0(func_02016880, p, 0);
    }
}

