/*
 * file:     townmap_p05.c
 * unit:     yes
 * function: func_021BA488, func_021BA48C, func_021BA490, func_021BA570, func_021BA5AC, func_021BA5B0
 * address:  0x021BA488
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB778  0x021BB778  thumb  ov072
 *   func_021BB790  0x021BB790  thumb  ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   d_021BBD60     0x021BBD60  data  ov072
 *   func_021BA86C  0x021BA86C  thumb  ov072
 *   func_021BA7F8  0x021BA7F8  thumb  ov072
 *   func_021BAE9C  0x021BAE9C  thumb  ov072
 *   func_021BA7D4  0x021BA7D4  thumb  ov072
 *   func_021BAF24 0x021BAF24 thumb ov072
 *   func_021BAA14 0x021BAA14 thumb ov072
 *   func_020307B0 0x020307B0 arm
 *   func_021BA638  0x021BA638  thumb  ov072
 *   func_021BAD10  0x021BAD10  thumb  ov072
 *   func_021BAD84  0x021BAD84  thumb  ov072
 *   func_021BAF3C  0x021BAF3C  thumb  ov072
 *   d_021BBB78     0x021BBB78  data  ov072
 */
#include "../../matched/include/Obj09906.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    u8 pad10[8];
    u16 f18;
    u16 f1A;
    u16 f1C;
    u16 f1E;
} W_021BA490;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    int f10;
    int f14;
    short f18;
    short f1A;
    u16 f1C;
    u16 f1E;
} W_021BA5B0;

extern u32 func_021BB778(char *p, int n);
extern void func_021BB790(char *p, int *a, int *b, int *c);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021BA86C(char *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5);
extern void *func_021BA7F8(char *p, u32 b, int y);
extern void func_021BAE9C(void *p, int a, int b, int c, int s0, int s1, u16 s2);
extern void func_021BA7D4(char *p);
extern void func_021BAF24(unsigned int *p);
extern void func_021BAA14(unsigned int *p);
extern u32 func_020307B0(void *p);
extern void func_021BA638(W_021BA5B0 *p, int *v);
extern void func_021BAD10(char *p, int s, char *r);
extern void func_021BAD84(int *p, int *b);
extern void func_021BAF3C(u32 *p, const u32 *v);
int func_021BA488(int *p);
void func_021BA48C(int *p, int x);
void func_021BA490(W_021BA490 *p, u16 x, u16 y, int a, u32 b, u32 c, u16 heap, int flag);
void func_021BA570(char *p);
void func_021BA5AC(void *a0);
void func_021BA5B0(W_021BA5B0 *p, u32 s, const int *v);
extern char d_021BBD60[];
extern char d_021BBB78[];

int func_021BA488(int *p)
{
    return p[5];
}

void func_021BA48C(int *p, int x)
{
    p[4] = x;
}


void func_021BA490(W_021BA490 *p, u16 x, u16 y, int a, u32 b, u32 c, u16 heap, int flag)
{
    u32 i;
    u32 n;
    int s0, s1, s2;
    int t0, t1, t2;
    int e;

    i = 0;
    n = func_021BB778((char *)b, 0);
    func_02082BCC(p, 0, 0x28);
    p->fC = 0x3d;
    p->f0 = c;
    p->f8 = func_02030734(heap, p->fC * 0x44, 0, d_021BBD60, 0x8C5);
    func_02082BCC(p->f8, 0, p->fC * 0x44);
    func_021BB790((char *)b, &s0, &s1, &s2);
    for (; i < p->fC; i++) {
        func_021BA86C(p->f8 + i * 0x44, a, i, n, s0, s1, s2, (void *)c, heap, flag);
    }
    e = (int)func_021BA7F8((char *)p, x, y);
    func_021BB790((char *)b, &t0, &t1, &t2);
    func_021BAE9C((char *)p + 0x20, e, n, t0, t1, t2, heap);
    p->f18 = 0;
    p->f1A = 0;
    p->f1C = 0;
    p->f1E = 0;
    func_021BA7D4((char *)p);
}

void func_021BA570(char *p) { u32 i; func_021BAF24((unsigned int *)(p+32)); for(i=0;i<((struct Obj09906 *)p)->fC;i++) func_021BAA14((void *)(*(u32 *)&((struct Obj09906 *)p)->f8+i*0x44)); func_020307B0(((struct Obj09906 *)p)->f8); func_02082BCC(p,0,40); }

/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_021BA5AC(void *a0)
{
}


void func_021BA5B0(W_021BA5B0 *p, u32 s, const int *v)
{
    u32 i;
    int t[2];

    if (s == 0x1000) {
        p->f18 = 0;
        p->f1A = 0;
        p->f1C = 0;
        p->f1E = 0;
    } else {
        p->f18 = -0x48;
        p->f1A = -0x80;
        p->f1C = 0x80;
        p->f1E = 0x60;
    }
    t[0] = -v[0];
    t[1] = -v[1];
    func_021BA638(p, t);
    for (i = 0; i < p->fC; i++) {
        func_021BAD10(p->f8 + i * 0x44, s, d_021BBB78);
        func_021BAD84((int *)(p->f8 + i * 0x44), &p->f10);
    }
    func_021BAF3C((u32 *)((char *)p + 0x20), (const u32 *)((int *)&p->f10));
}
