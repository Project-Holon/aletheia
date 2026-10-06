/*
 * function: func_021F5334
 * address:  0x021F5334
 * packet:   pkt_ov076_021F5334
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcard is the THM_CALL at +0x118 to the arm9
 * leaf func_02047888 (unlabelled ARM, 48 bytes, Ilias's), which has no
 * witness outside this range.  Reading the frame count into `cur` before
 * the f38 test is what loads it ahead of the compare (3 lines otherwise).
 *
 * blocker:
 *   0x02047888 arm9 ARM, verified EXACT (--arm, no --region) by the ov021
 *   func_021D0750 lane; copied from src/pending/ov/ov021_func_021D0750.c:
 *     typedef unsigned short u16;
 *     int func_02047888(int *a, int idx, int *out) {
 *         int *p = ((int **)a[2])[idx];
 *         if (p == 0) { return 0; }
 *         *out = ((u16 *)((int *)p[1])[2])[2] << 12;
 *         return 1;
 *     }
 *
 * Task callback that func_021F52D8 registers: ov073 func_021F53C8's fade
 * states 0-2, then a 3D model load, a frame-count wait with a fade-out
 * and the teardown.  The work block is the 0x44 bytes func_021F52D8
 * allocates (f4 = b, f2C/f30 = c/d, f34 = fade plane, f40 = -1 sound).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02080C44  0x02080C44  arm
 *   func_02080294  0x02080294  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202E560  0x0202E560  thumb
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0202E610  0x0202E610  thumb
 *   func_021899F0  0x021899F0  thumb  ov021
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02047888  0x02047888  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02047828  0x02047828  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Work {
    int f0;
    u8 *f4;
    u32 f8;
    int fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    u32 f2C;
    u32 f30;
    int f34;
    int f38;
    s32 f3C;
    int f40;
} Work;

struct AnmCtl;
struct Ctx;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Obj;
struct Rec;
struct Tagged;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u16 func_02080C44(void);
extern void func_02080294(u32 bank);
extern void *func_02046DB8(u32 a0, u32 a1);
extern u16 func_02188C84(u8 *p);
extern void *func_0202E560(u32 heap, u32 sel);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0202E610(u32 a0, u32 a1);
extern u32 func_021899F0(u8 *p);
extern void func_021899F8(u8 *p, u32 v);
extern int func_02047888(int *a, int idx, int *out);
extern void func_020061E4(u32 id);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern int func_020478B8(void *a, int idx, int amount);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);

int func_021F5334(void *task, int *st)
{
    Work *w;
    s32 end;
    s32 frame;
    s32 cur;

    w =(Work *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            w->f0 = w->f0 + 1;
            if (w->f0 < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *st = 1;
            } else {
                *st = *st + 1;
            }
        }
        break;
    case 3:
        w->f8 = func_02080C44();
        w->fC = 0;
        if ((w->f8 & 8) == 0) {
            w->fC = 1;
            w->f8 |= 8;
            func_02080294(w->f8);
        }
        w->f14 = func_02046DB8(0x81, w->f2C);
        w->f1C = func_02046DB8(0x81, w->f30);
        w->f18 = func_0202E560(func_02188C84(w->f4), 3);
        w->f20 = func_02047400(w->f14, 0, w->f18);
        w->f24 = func_02047564(w->f20, w->f1C, 0);
        w->f28 = func_0204767C((u32)w->f20, (u32 *)(&w->f24), 1);
        func_020477A4(w->f28, 0);
        func_0202E610(3, 3);
        w->f10 = func_021899F0(w->f4);
        func_021899F8(w->f4, 2);
        w->f38 = 0;
        func_02047888(w->f28, 0, &end);
        w->f3C = end - 0x14000;
        if (w->f40 != -1) {
            func_020061E4(w->f40);
        }
        *st = *st + 1;
        break;
    case 4:
        func_02047828(w->f28, 0, &frame);
        cur = frame;
        if (w->f38 == 0 && cur >= w->f3C) {
            func_0204E720(w->f34, 0, 0x10, 3);
            w->f38 = 1;
        }
        if (func_020478B8(w->f28, 0, 0x1000) == 0 && func_0204E804() == 0) {
            *st = *st + 1;
        }
        break;
    case 5:
        if (w->fC == 1) {
            w->f8 &= ~8;
            func_02080294(w->f8);
        }
        func_02047738(w->f28);
        func_0204762C(w->f24);
        func_02047504(w->f20);
        func_02046EFC(w->f1C);
        func_02046EFC(w->f18);
        func_02046EFC(w->f14);
        func_021899F8(w->f4, w->f10);
        return 1;
    }
    return 0;
}
