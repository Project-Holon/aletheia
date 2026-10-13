/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F532C, func_021F5340, func_021F5368, func_021F5390, func_021F5400, func_021F542C, func_021F5488, func_021F54CC, func_021F556C
 * address:  0x021F5260
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02010F94  0x02010F94  thumb
 *   sub_02010E14   0x02010E14  thumb
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02010FA0  0x02010FA0  thumb
 *   func_0201292C  0x0201292C  thumb
 *   sub_02007F1C   0x02007F1C  thumb
 *   func_021652C4  0x021652C4  thumb  ov010
 *   func_021657B0  0x021657B0  thumb  ov010
 *   func_02010F8C  0x02010F8C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0216D9E4 0x0216D9E4 thumb ov010
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201104C  0x0201104C  thumb
 *   func_020110CC  0x020110CC  thumb
 *   func_02190FA0 0x02190FA0 thumb ov021
 *   func_0219103C 0x0219103C thumb ov021
 *   func_021910C0 0x021910C0 thumb ov021
 *   func_02191008 0x02191008 thumb ov021
 *   func_021907C4 0x021907C4 thumb ov021
 *   func_02190854 0x02190854 thumb ov021
 *   func_0219082C 0x0219082C thumb ov021
 *   func_021F55D4 0x021F55D4 thumb ov083
 *   func_020362DC 0x020362DC arm
 *   func_0201F184  0x0201F184  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190844  0x02190844  thumb  ov021
 */
#include "../../matched/include/Obj13226.h"
#include "../../matched/include/Obj05165.h"
#include "../../matched/include/Obj00815.h"

struct Ctx;
struct Rec02010F94;
struct BigObj;
struct Desc;
struct Obj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct Fx;
struct Obj2;
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
} Work;

typedef signed int     s32;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02010F7C(u32 heap);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern unsigned int func_02010F94(struct Rec02010F94 *p, int idx);
extern void sub_02010E14(int slot, u8 *rec, int select);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02158F74(void *p);
extern u16   func_02010FA0(void *rec, int slot);
extern void *func_0201292C(const struct BigObj *p);
extern u32 sub_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021652C4(void *a0);
extern void  func_021657B0(int a0);
extern void  func_02010F8C(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02188C54(u8 *p);
extern void *func_02188C7C(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0216D9A0(void *map);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 *func_0216D9E4(void *c);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int  func_0204E804(void);
extern void func_020061E4(u32 a);
extern void *func_02012934(const struct BigObj *p);
extern u32   func_0201AB08(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern u32   func_0201104C(void *p);
extern u32   func_020110CC(void *p);
extern struct Obj2 *func_02190FA0(struct Fx *a, u32 b, u32 c);
extern void func_0219103C(u32 *, u32, u32, u32);
extern u32 func_021910C0(u32 *);
extern int func_02191008(u32 a);
extern struct Obj *func_021907C4(struct Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f);
extern void func_02190854(u32 *p);
extern int func_0219082C(void *a);
extern void func_021F55D4(char *);
extern u32 func_020362DC(void);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190844(struct Slot **p, int x, int y, u32 z);
void *func_021F5260(void *a0, int *a1);
void func_021F532C(void *p);
void *func_021F5340(void *p);
void *func_021F5368(void *p,void *q);
void func_021F5390(Work *p, int a1, int a2);
void func_021F5400(u8 *p);
int func_021F542C(int a0, int *p);
void func_021F5488(void *a0, void *a1, int a2);
int func_021F54CC(void *task, u32 *st, u8 *p);
void func_021F556C(char *p, u32 a1, u32 a2, int a3, u8 a4);






void *func_021F5260(void *a0, int *a1)
{
    void *h;
    void *s;
    void *obj;
    void *rec;
    int id;
    int x;
    u16 q;

    obj = func_020120F4(a0);
    rec = func_02010F7C(0x8015);
    id = a1[0];
    h = func_02158768((int)a0, 0x28B9, 0, 0x15);
    s = (void *)func_021589D0((int)h);
    if (id == 0x30 || id > 0x2D) {
        id = 0;
    }
    x = func_02010F94(rec, id);
    sub_02010E14(id, rec, a1[1]);
    if (id == 0x27) {
        func_02159058((int)s, (u16)id, (u16)0xB, (u16)a1[1], (u32)0);
    } else {
        func_02159058((int)s, (u16)id, (u16)x, (u16)a1[1], (u32)0);
    }
    func_021F5488(a0, func_02158F74(s), x);
    if (a1[1] != 0) {
        q = func_02010FA0(rec, id);
        sub_02007F1C(func_0201292C(obj), 0x23F, q, 0x8015);
        func_021652C4((void *)id);
    } else {
        func_021657B0(id);
    }
    func_02010F8C(rec);
    return h;
}





void func_021F532C(void *p) { func_02158768((int)p,0x28ba,0,0x15); }




void *func_021F5340(void *p) { void *task; u8 *w; task=func_020122C0(p,0,(void *)func_021F542C,12); w=func_020124E8(task); ((struct Obj13226 *)w)->f8=func_020120F4(p); ((struct Obj13226 *)w)->f4=p; return task; }



void *func_021F5368(void *p,void *q) { void *task=func_020122C0(p,0,(void *)func_021F54CC,60); func_021F5390((Work *)(func_020124E8(task)), (int)p, (int)q); return task; }



/*
 * Byte-correct. Only blocker: func_02010F7C (arm9, thumb, unlabelled tail-call
 * stub, 0x02010F7C..0x02010F8C; the integrator's leaf). Its verified body (EXACT with
 */
void func_021F5390(Work *p, int a1, int a2)
{
    p->f2 = 0x15;
    p->f4 = (p->f2 & 0x7FFF) | 0x8000;
    p->f10 = a2;
    p->f8 = a1;
    p->fC = (int)func_020120F4((const struct Ctx *)a1);
    p->f14 = func_02188C54((u8 *)p->f10);
    p->f1C = (int)func_02188C7C((u8 *)p->f10);
    p->f30 = (int)func_02010F7C(p->f2);
    p->f28 = (int)func_02045B38(0, 3, 0x108, p->f2);
    p->f2C = (int)func_0201EC64(p->f2);
    p->f34 = (int)func_020457B0(0x81, p->f2);
    p->f38 = (int)func_020457B0(0x81, p->f2);
    func_0216D9A0((void *)p->f1C);
}


void func_021F5400(u8 *p) { func_02045808(((struct Obj05165 *)p)->f38);func_02045808(((struct Obj05165 *)p)->f34);func_0201ED04(((struct Obj05165 *)p)->f2C);func_02045C04(((struct Obj05165 *)p)->f28);func_02010F8C(((struct Obj05165 *)p)->f30);func_0216D9E4(((struct Obj05165 *)p)->f1C); }



int func_021F542C(int a0, int *p)
{
    switch (*p) {
    case 0:
        func_0204E720(4, 10, 16, 4);
        func_020061E4(0x5E0);
        (*p)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_0204E720(4, 16, 0, 8);
        (*p)++;
    case 2:
        if (func_0204E804() != 0)
            break;
    default:
        return 1;
    }
    return 0;
}



void func_021F5488(void *a0, void *a1, int a2)
{
    void *h = func_02012934(func_020120F4(a0));
    u8 i;

    i = func_0201AB08(h);
    func_0201EEF4(a1, 1, func_0201AB28(h, i));
    switch (a2) {
    case 5:
        func_0201104C(h);
        break;
    case 6:
        func_020110CC(h);
        break;
    }
}


int func_021F54CC(void *task, u32 *st, u8 *p) {
    void *v;
    switch (*st) {
    case 0:
        v = func_02190FA0(*(struct Fx **)(p+20),*(u32 *)(p+40),19);
        *(void **)(p+32) = v;
        func_0219103C(v,0,0,3);
        *st += 1;
        break;
    case 1:
        if (func_021910C0(*(u32 **)(p+32))) {
            func_02191008((u32)(*(void **)(p+32)));
            *st += 1;
        }
        break;
    case 2:
        v = func_021907C4(*(struct Fx **)(p+20),*(u32 *)(p+40),4,1,24,22);
        *(void **)(p+24) = v;
        func_02190854(v);
        func_021F55D4((char *)p);
        *st += 1;
        break;
    case 3:
        if (func_020362DC() & 3) *st += 1;
        break;
    default:
        func_02190854(*(void **)(p+24));
        func_0219082C((void *)(*(void **)(p+24)));
        func_021F5400(p);
        return 1;
    }
    return 0;
}



void func_021F556C(char *p, u32 a1, u32 a2, int a3, u8 a4)
{
    func_0201F184((struct WordSet *)(((struct Obj00815 *)p)->f2C), 0, a2);
    func_0201EFA4((struct WordSet *)(((struct Obj00815 *)p)->f2C), 1, a3 / 60, 2, 1, 1);
    func_0201EFA4((struct WordSet *)(((struct Obj00815 *)p)->f2C), 2, a3 % 60, 2, 2, 1);
    func_0201F250((struct WordSet *)(((struct Obj00815 *)p)->f2C), (void *)(((struct Obj00815 *)p)->f38), (void *)a1);
    func_02190844((struct Slot **)(((struct Obj00815 *)p)->f18), 8, (u16)(a4 << 4), ((struct Obj00815 *)p)->f38);
}
