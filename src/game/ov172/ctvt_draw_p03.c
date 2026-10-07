/*
 * file:     ctvt_draw_p03.c
 * unit:     yes
 * function: func_021BD0C4, func_021BD134, func_021BD1AC, func_021BD3B8, func_021BD43C, func_021BD5AC
 * address:  0x021BD0C4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_021BD5D8 0x021BD5D8 thumb ov172
 *   func_021BD844 0x021BD844 thumb ov172
 *   func_021BDBC4 0x021BDBC4 thumb ov172
 *   func_02027F60 0x02027F60 thumb
 *   func_021B6EE0 0x021B6EE0 thumb ov172
 *   func_021B7BA8 0x021B7BA8 thumb ov172
 *   func_021B8C3C 0x021B8C3C thumb ov172
 *   func_021BA280 0x021BA280 thumb ov172
 *   func_021BBA6C 0x021BBA6C thumb ov172
 *   func_021B6BE0 0x021B6BE0 thumb ov172
 *   func_020056A0 0x020056A0 thumb
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021B80DC 0x021B80DC thumb ov172
 *   func_021B80EC 0x021B80EC thumb ov172
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A70 0x02028A70 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02005D90 0x02005D90 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021B6C34 0x021B6C34 thumb ov172
 *   func_021BBA88 0x021BBA88 thumb ov172
 *   func_021BA2B8 0x021BA2B8 thumb ov172
 *   func_021B8CB0 0x021B8CB0 thumb ov172
 *   func_021B7DCC 0x021B7DCC thumb ov172
 *   func_021B70A8 0x021B70A8 thumb ov172
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021BDC70 0x021BDC70 thumb ov172
 *   func_021BDB5C 0x021BDB5C thumb ov172
 *   func_021BD7D0 0x021BD7D0 thumb ov172
 *   func_021B7E34  0x021B7E34  thumb  ov172
 *   func_021B9044  0x021B9044  thumb  ov172
 *   func_021BBF2C  0x021BBF2C  thumb  ov172
 *   func_021BA9EC  0x021BA9EC  thumb  ov172
 *   func_021B80CC  0x021B80CC  thumb
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffixu         0x0209C4C8  arm
 *   func_021BDD6C  0x021BDD6C  thumb  ov172
 *   func_021B6C48  0x021B6C48  thumb  ov172
 *   func_021B712C  0x021B712C  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021BDCB8  0x021BDCB8  thumb  ov172
 *   func_02061CA4  0x02061CA4  arm
 *   g_020A1B38     0x020A1B38  data
 *   func_021B71B8  0x021B71B8  thumb  ov172
 *   func_021B6C4C  0x021B6C4C  thumb  ov172
 *   func_021B9574  0x021B9574  thumb  ov172
 */
#include "../../matched/include/Obj00543.h"
#include "../../matched/include/Obj01266.h"
#include "../../matched/include/Obj03855.h"
#include "../../matched/include/Obj10666.h"

#define W(o) (*(u32_021BD1AC *)(self + (o)))
#define B(o) (*(u8 *)(self + (o)))
#define F(o) (*(u32_021BD43C *)(ctx + (o)))
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct BigObj;
struct R;
struct SoundSys;
struct Node;
struct TaskMenuState;
struct PrintSys;
struct Tcbl;
struct S;
struct Q;
typedef unsigned int u32_021BD0C4;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long u32_021BD134;

typedef unsigned int u32_021BD1AC;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

typedef unsigned int u32_021BD3B8;

typedef unsigned int   u32_021BD43C;

typedef signed short   s16;

typedef signed int     s32;

typedef unsigned int u32_021BD5AC;

extern u32_021BD0C4  func_021BE034(void *p);
extern u32_021BD0C4  func_021BE03C(void *p);
extern u32_021BD0C4  func_021BE044(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32_021BD0C4 index);
extern void func_0201C724(void *owner, u32_021BD0C4 a, u32_021BD0C4 b, u32_021BD0C4 c, u32_021BD0C4 d, u32_021BD0C4 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021BE34C(void *p);
extern void func_021BD5D8(u8 *p);
extern void func_021BD844(u8 *p);
extern void func_021BDBC4(u8 *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32_021BD1AC a2, u32_021BD1AC a3, u16 heap);
extern char *func_021B6EE0(void *a, u16 b);
extern char *func_021B7BA8(void *p, u16 heap);
extern char *func_021B8C3C(char *unused, u16 heap);
extern u32_021BD1AC func_021BA280(char *, u16);
extern void *func_021BBA6C(int unused, void *p);
extern u32_021BD1AC func_021B6BE0(Params *);
extern u32_021BD1AC func_020056A0(void (*)(int, char *), char *, int);
extern int func_0202EB14(void);
extern void func_0203D34C(u32_021BD1AC a, u32_021BD1AC b);
extern void func_021B80DC(int unused, char *p, u32_021BD1AC v);
extern void func_021B80EC(int unused, char *p, const u8 *src);
extern u32_021BD1AC func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern u32_021BD1AC func_020450F0(u32_021BD1AC, u32_021BD1AC, u32_021BD1AC, u32_021BD1AC, u8, u8, u8);
extern void func_02005D90(u32_021BD1AC, u32_021BD1AC);
extern u32_021BD3B8 func_020452E8(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void func_021B6C34(char *);
extern void func_021BBA88(int unused, int v);
extern void func_021BA2B8(int unused, int v);
extern void func_021B8CB0(void *, char *);
extern void func_021B7DCC(void *p, char *q);
extern void func_021B70A8(int unused, char *q);
extern u32_021BD3B8 func_02027FD8(struct TaskMenuState *s);
extern void func_021BDC70(u32_021BD3B8 *a0);
extern void func_021BDB5C(u8 *);
extern void func_021BD7D0(void *);
extern void func_021B7E34(void *p, char *q);
extern u32_021BD43C func_021B9044(void *p, struct S *s);
extern int func_021BBF2C(void *a0, char *p);
extern int func_021BA9EC(void *a0, char *p);
extern u32_021BD43C func_021B80CC(int unused, char *p);
extern void func_021BDD6C(u8 *p);
extern void func_021B6C48(u32_021BD43C a);
extern void func_021B712C(int unused, char *q);
extern int func_021B7590(int x, char *p);
extern void func_021BDCB8(u8 *p);
extern u32_021BD43C  func_020221A4(void);
extern void func_0204A600(void);
extern u32_021BD43C func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern u32_021BD43C  func_02005728(u32_021BD43C v);
extern void sub_02040618(u32_021BD43C layer, u32_021BD43C a, u32_021BD43C b);
extern s32 sub_02061CA4(void *p, u32_021BD43C a, u32_021BD43C b, s32 size);
extern void func_021B71B8(void *p, struct Q *q);
extern void func_0204A648(void);
extern void func_021B6C4C(char *p);
extern void func_021B9574(int unused, char *p);
void func_021BD0C4(void *a0, char *a1, int a2);
void func_021BD134(void *ctx, char *st, u32_021BD134 msgId);
void func_021BD1AC(char *self);
void func_021BD3B8(u8 *p);
int func_021BD43C(char *ctx);
void func_021BD5AC(int unused, char *ctx);
extern s16 g_020A1B38[];


void func_021BD0C4(void *a0, char *a1, int a2)
{
    u32_021BD0C4 x = func_021BE034(a0);
    u32_021BD0C4 y = func_021BE03C(a0);
    u32_021BD0C4 z = func_021BE044(a0);
    u32_021BD0C4 w;

    func_02043B5C((struct CharBuf *)((u32_021BD0C4)func_02045770((struct Descriptor *)((struct Obj00543 *)a1)->f2C)), 0xf);
    w = (u32_021BD0C4)func_02045EC0((struct MsgBank *)y, a2);
    func_0201C724((void *)z, (u32_021BD0C4)func_02045770((struct Descriptor *)((struct Obj00543 *)a1)->f2C), 0, 0, w, x, 0x440);
    func_02045808((struct U16Vec *)w);
    func_0201F73C((void *)(((struct Obj00543 *)a1)->f2C), 2, 0x140, 9);
    ((struct Obj00543 *)a1)->f20 = 1;
}


void func_021BD134(void *ctx, char *st, u32_021BD134 msgId)
{
    u32_021BD134 font = func_021BE034(ctx);
    u32_021BD134 msgs = func_021BE03C(ctx);
    u32_021BD134 sys = func_021BE044(ctx);
    u32_021BD134 str;

    func_02043B5C((struct CharBuf *)((u32_021BD134)func_02045770((struct Descriptor *)((struct Obj01266 *)st)->f30)), 0xf);
    str = (u32_021BD134)func_02045EC0((struct MsgBank *)msgs, msgId);
    func_0201C724((void *)sys, (u32_021BD134)func_02045770((struct Descriptor *)((struct Obj01266 *)st)->f30), 0, 0, str, font, 0x440);
    func_02045808((struct U16Vec *)str);
    func_0201F73C((void *)(((struct Obj01266 *)st)->f30), 2, 0x140, 9);
    ((struct Obj01266 *)st)->f24 = 1;
    ((struct Obj01266 *)st)->f38 = 0;
    func_021BE34C(ctx);
}

#define H(o) (*(u16 *)(self + (o)))

/*
 * note 2026-10-05 wD5 lane12: the loop argument and the two byte stores are the literal 0 (the
 *   original copies r5=0 into r6 before the loop label; it is not the last index).
 */
void func_021BD1AC(char *self)
{
    int z = 0;
    int one = 1;
    u8 i;
    u32_021BD1AC h2;
    Params st;
    B(0x18) = one;
    B(0x19) = z;
    W(0x1c) = z;
    func_021BD5D8((u8 *)self);
    func_021BD844((u8 *)self);
    func_021BDBC4((u8 *)self);
    W(0x1d4) = (u32_021BD1AC)func_02027F60(4, 7, W(0x1c8), W(0x1d0), H(0));
    W(0x1e0) = (u32_021BD1AC)func_021B6EE0(self, H(0));
    W(0x1e4) = (u32_021BD1AC)func_021B7BA8(self, H(0));
    W(0x1e8) = (u32_021BD1AC)func_021B8C3C(self, H(0));
    W(0x1ec) = func_021BA280(self, H(0));
    W(0x1f0) = (u32_021BD1AC)func_021BBA6C((int)self, (void *)H(0));
    st.heap = H(0);
    st.kind = 2;
    st.count = 0x64;
    st.a = z;
    st.b = 0x100;
    st.c = z;
    st.d = 0xc0;
    W(0x1f4) = func_021B6BE0(&st);
    W(4) = func_020056A0(func_021BD5AC, self, 8);
    W(8) = z;
    H(0x38) = z;
    H(0x3a) = z;
    W(0x10) = one;
    W(0x20) = z;
    W(0x24) = z;
    W(0x28) = z;
    W(0x2c) = z;
    W(0x30) = z;
    W(0x34) = z;
    if (func_0202EB14() == 1) W(0x30) = one;
    func_0203D34C(0, H(0));
    switch (*(u32_021BD1AC *)(W(0x1f8) + 4)) {
    case 0:
        func_021B80DC((int)self, (char *)W(0x1e4), 3);
        W(0xc) = 1;
        break;
    case 1:
        func_021B80DC((int)self, (char *)W(0x1e4), 2);
        W(0xc) = 2;
        break;
    case 2:
        func_021B80DC((int)self, (char *)W(0x1e4), 4);
        func_021B80EC((int)self, (char *)W(0x1e4), (const u8 *)(W(0x1f8) + 8));
        W(0xc) = 2;
        func_02028A70((struct SoundSys *)func_02012A30((const struct BigObj *)(*(u32_021BD1AC *)W(0x1f8))));
        break;
    case 3:
        func_021B80DC((int)self, (char *)W(0x1e4), 5);
        W(0xc) = 2;
        break;
    }
    W(0x1b8) = func_020450F0(0, 2, 10, 12, 2, 10, 1);
    W(0x1bc) = func_020450F0(0, 0x12, 10, 12, 2, 10, 1);
    W(0x1c0) = func_020450F0(0, 2, 0x16, 12, 2, 10, 1);
    W(0x1c4) = func_020450F0(0, 0x12, 0x16, 12, 2, 10, 1);
    for (i = 0; i < 4; i++) {
        func_02043B5C(func_02045770((struct Descriptor *)(*(u32_021BD1AC *)(self + i * 4 + 0x1b8))), 0);
    }
    B(0x1b4) = 0;
    B(0x1b5) = 0;
    func_02005D90(0x3e9, 0xffff);
}

void func_021BD3B8(u8 *p)
{
    u8 i;
    for (i=0; i<4; i++) func_020452E8((struct Descriptor *)(*(u32_021BD3B8 *)(p + i*4 + 0x1b8)));
    func_02030EAC((struct Node *)(((struct Obj03855 *)p)->f4));
    func_021B6C34(*(char * *)&((struct Obj03855 *)p)->f1F4);
    func_021BBA88((int)p, ((struct Obj03855 *)p)->f1F0);
    func_021BA2B8((int)p, ((struct Obj03855 *)p)->f1EC);
    func_021B8CB0(p, *(char * *)&((struct Obj03855 *)p)->f1E8);
    func_021B7DCC(p, (char *)(((struct Obj03855 *)p)->f1E4));
    func_021B70A8((int)p, (char *)(((struct Obj03855 *)p)->f1E0));
    func_02027FD8((struct TaskMenuState *)(((struct Obj03855 *)p)->f1D4));
    func_021BDC70((u32_021BD3B8 *)p);
    func_021BDB5C(p);
    func_021BD7D0(p);
}

#undef H
#define H(o) (*(u16 *)(ctx + (o)))


int func_021BD43C(char *ctx)
{
    u32_021BD43C idx;
    s32 v;
    u8 pal;

    func_021B7E34(ctx, (char *)F(0x1e4));
    switch (F(8)) {
    case 1:
        F(0xc) = func_021B9044(ctx, (struct S *)F(0x1e8));
        break;
    case 2:
        F(0xc) = func_021BBF2C(ctx, (char *)F(0x1f0));
        break;
    case 3:
        F(0xc) = func_021BA9EC(ctx, (char *)F(0x1ec));
        break;
    case 4:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1
            && func_020221A4() == 1) {
            return 1;
        }
        break;
    }
    if (F(0x14) == 1 && func_020221A4() == 1) {
        F(0xc) = 5;
    }
    if (F(8) != F(0xc)) {
        func_021BDCB8((u8 *)ctx);
    }
    func_021B712C((int)ctx, (char *)F(0x1e0));
    func_021B6C48(F(0x1f4));
    func_0204A600();
    func_0201C4E4((struct PrintSys *)F(0x1d0));
    func_021BDD6C((u8 *)ctx);
    H(0x38) += 0x200;
    idx = H(0x38) >> 4;
    v = (g_020A1B38[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(u32_021BD43C)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != H(0x3a)) {
        H(0x3a) = pal;
        sub_02061CA4((void *)0x1f, 0x40, (u32_021BD43C)(ctx + 0x3c + pal * 32), 0x20);
    }
    func_020310C4((struct Tcbl *)F(0x1d8));
    sub_02040618(1, 0, func_02005728(0x100));
    sub_02040618(1, 3, func_02005728(0x100));
    return 0;
}


void func_021BD5AC(int unused, char *ctx)
{
    func_021B71B8(ctx, (struct Q *)(((struct Obj10666 *)ctx)->f1E0));
    func_0204A648();
    func_021B6C4C((char *)(((struct Obj10666 *)ctx)->f1F4));
    func_021B9574((int)ctx, (char *)(((struct Obj10666 *)ctx)->f1E8));
}
