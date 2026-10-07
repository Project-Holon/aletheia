/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37F8, func_021F381C, func_021F384C, func_021F3888, func_021F38C4, func_021F3908, func_021F3938, func_021F39A8, func_021F39B8
 * address:  0x021F36C0
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B50     0x021F3B50  data  ov045
 *   d_021F3B80     0x021F3B80  data  ov045  a4
 *   d_021F3BA4     0x021F3BA4  data  ov045  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_021F3A68 0x021F3A68 thumb ov045
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CF0  0x02188CF0  thumb  ov021
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_021A6DC4  0x021A6DC4  thumb  ov021
 *   d_021F3B60  0x021F3B60  data  ov045
 *   d_021F3B62  0x021F3B62  data
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */
struct Ctx;
struct Big;
struct Rec94;
struct Desc;
struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef signed int     s32;

typedef unsigned char  u8;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned char *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern int *func_021897BC(char *, int);
extern void func_021897A0(u8 *, int);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3A68(void *,int *);
extern int func_02188CF0(u32 a);
extern u32 func_02188CA4(u8 *p);
extern void func_021A6DC4(u32 *b, void *a);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void *func_020124E4(struct Obj *p);
extern int func_021BE6BC(int *p);
void func_021F36C0(void *a0);
void func_021F37F8(u8 *p);
void func_021F381C(u32 a);
void *func_021F384C(void *a,int b);
void *func_021F3888(void *a,int b);
void func_021F38C4(void *a0, int a1);
int func_021F3908(char *a0, int a1);
void func_021F3938(void *a0, int a1, int a2, int a3);
int func_021F39A8(int *p, int i);
int func_021F39B8(void *a0, int *a1);
extern int d_021F3B50;
extern V d_021F3B80[];
extern V d_021F3BA4[];
extern unsigned short d_021F3B60[];
extern unsigned short d_021F3B62[];


void func_021F36C0(void *a0)
{
    void *r4;
    int *q;
    int i;
    int j;
    int k;
    void *b;
    V *e;

    r4 = (void *)func_02188D2C(a0);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)func_020120F4(func_02188C80(a0))), 9);
    func_02189764(a0, 1, func_02188C84(a0), 4);
    func_021BE760(r4, &d_021F3B50, 0);
    for (i = 0; i < 3; i++) {
        e = func_021BE480(r4, 0, i);
        *e = d_021F3B80[i];
        func_021BE4A4(r4, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r4, 0, i, j);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        k = i + 3;
        e = func_021BE480(r4, 0, k);
        *e = d_021F3BA4[i];
        func_021BE4A4(r4, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r4, 0, k, j);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        func_021F3938(r4, q[i], i, 1);
        func_021F3938(r4, q[i], i, 0);
    }
}

void func_021F37F8(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897BC((char *)p, 1);
    func_021897A0(p, 1);
    func_021BE418((u8 *)x, 0);
}

void func_021F381C(u32 a) { u32 p; p=func_02188D2C((int *)a); func_021897BC((char *)a,1); func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),9); func_021BE580((void *)p); }

void *func_021F384C(void *a,int b)
{
    u32 p;
    int *q;
    p=(u32)func_0201210C(a);
    func_02012EC4(func_020120F4(func_02188C80((void *)p)));
    q=func_021897BC((char *)p,1);
    if(b>=3)return 0;
    *q=b;
    return func_020122C0(a,0,func_021F39B8,0);
}

void *func_021F3888(void *a,int b)
{
    u32 p;
    int *q;
    p=(u32)func_0201210C(a);
    func_02012EC4(func_020120F4(func_02188C80((void *)p)));
    q=func_021897BC((char *)p,1);
    if(b>=3)return 0;
    *q=b;
    return func_020122C0(a,0,func_021F3A68,0);
}


void func_021F38C4(void *a0, int a1)
{
    void *r6;
    int r4;
    void *p;

    r6 = func_0201210C(a0);
    r4 = func_02188CF0((u32)r6);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(r6))), 9);
    if (a1 < 8 && r4 == 2) {
        if (func_021F3908(p, a1)) {
            func_021A6DC4((u32 *)func_02188CA4(r6), r6);
        }
    }
}


int func_021F3908(char *a0, int a1)
{
    unsigned short v = (unsigned short)(*(unsigned int *)(a0 + d_021F3B60[a1 * 2] * 4) != 0);

    return v == d_021F3B62[a1 * 2];
}


void func_021F3938(void *a0, int a1, int a2, int a3)
{
    int r4, r7;

    if (a1) {
        r4 = 1;
        r7 = 0;
    } else {
        r4 = 0;
        r7 = 1;
    }
    if (a3 != 1) {
        a2 += 3;
    }
    func_021BE700(a0, 0, a2, r4, 1);
    func_021BE700(a0, 0, a2, r7, 0);
    func_021BE6CC((int)a0, 0, (u16)a2, (u16)r4, 0);
    func_021BE6B0(func_021BE674(a0, 0, a2, r4), 1);
}

int func_021F39A8(int *p, int i)
{
    return p[i] != 0;
}


int func_021F39B8(void *a0, int *a1)
{
    void *r7;
    void *r6;
    int *s;
    int *p;
    int flag;
    int idx;
    u8 v;

    r7 = func_0201210C(func_020124E4(a0));
    r6 = (void *)func_02188D2C(r7);
    s = func_021897BC(r7, 1);
    flag = 1;
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(r7))), 9);
    switch (*a1) {
    case 0:
        idx = s[0];
        v = func_021F39A8(p, idx);
        func_021BE6B0(func_021BE674(r6, 0, (u8)(idx + 3), v), 0);
        *a1 = *a1 + 1;
        break;
    case 1:
        idx = s[0];
        v = func_021F39A8(p, idx);
        if (func_021BE6BC(func_021BE674(r6, 0, (u8)(idx + 3), v))) {
            if (p[s[0]]) {
                flag = 0;
            }
            func_021F3938(r6, flag, s[0], 0);
            return 1;
        }
        break;
    }
    return 0;
}
