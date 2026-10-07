/*
 * file:     unit_021B9AE4_p03.c
 * unit:     yes
 * function: func_021BA384, func_021BA3B4, func_021BA400, func_021BA420, func_021BA44C, func_021BA4D4, func_021BA4EC, func_021BA528
 * address:  0x021BA384
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAB94     0x021BAB94  data  a4
 *   d_021BABB4     0x021BABB4  data  a4
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02043B5C  0x02043B5C  arm
 */
#include "../../matched/include/Obj20762.h"
#include "../../matched/include/Obj20763.h"
#include "../../matched/include/Obj20764.h"
#include "../../matched/include/Obj09901.h"
#include "../../matched/include/Obj13189.h"
#include "../../matched/include/Obj03178.h"
#include "../../matched/include/Obj06193.h"

struct PrintSys;
struct S020315D4;
struct BgTemplate;
struct Descriptor;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct Big;
struct CharBuf;
struct Ctx;
struct Rec1B0;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    int h[3];
    struct {
        int h;
        u8 on;
        u8 pad[3];
    } e[3];
} S;

extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_02043534(unsigned int);
extern void func_020315D4(struct S020315D4 *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(int a, int b, int c, int d, int e, int f, int g);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 func_0200BF10(struct Rec1B0 *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
int func_021BA384(void *a, void *b, char *c, void **d);
void func_021BA3B4(void);
void func_021BA400(void);
void func_021BA420(char *p);
void func_021BA44C(int a, S *p);
void func_021BA4D4(void **p);
void func_021BA4EC(char *p, char *q);
void func_021BA528(u32 **a, u8 *b, u8 *c);
extern char d_021BAB94[];
extern char d_021BABB4[];


int func_021BA384(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20763 *)(*(char * *)&((struct Obj20762 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    func_021BA4D4(d);
    func_021BA400();
    func_020315D4(a);
    return 1;
}


void func_021BA3B4(void)
{
    func_0203FCA0(0, (const struct BgTemplate *)d_021BAB94, 0);
    func_0203FCA0(2, (const struct BgTemplate *)d_021BABB4, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void func_021BA400(void) {
    func_02040588(0, 0); func_02040588(2, 0);
    func_020403F4(0); func_020403F4(2);
}

void func_021BA420(char *p) {
    func_020498F4((void *)(((struct Obj20764 *)p)->f30),13,2,0,0,1,0x61);
    func_020409B4(0); func_020409B4(2);
}


void func_021BA44C(int a, S *p)
{
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(0, 2, 4, 0x1c, 8, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    p->h[2] = func_020450F0(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[2]);
    func_02045374((struct Cfg *)p->h[2]);
    for (i = 0; i < 3; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}

void func_021BA4D4(void **p) {
    int i;
    for (i = 0; i < 3; i++) func_020452E8(p[i]);
}

/*
 * note: trailing two-byte alignment padding.
 */
void func_021BA4EC(char *p, char *q) {
    unsigned s, h;
    s = (unsigned int)func_02045EC0((struct MsgBank *)(((struct Obj09901 *)p)->f28),38);
    h = ((struct Obj09901 *)p)->f8;
    func_0201C6FC((struct PrintSys *)h,(unsigned)func_02045770((struct Descriptor *)((struct Obj13189 *)q)->fC),0,4,(void *)s,((struct Obj09901 *)p)->fC);
    q[16] = 1;
    func_02045808((struct U16Vec *)s);
}


void func_021BA528(u32 **a, u8 *b, u8 *c)
{
    u32 s;
    u32 s2;
    u32 k;
    u32 h;

    k = func_0200BF10((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4((const struct Ctx *)(**a)))));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f4)), 0);
    if (k == 0x30) {
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f28), 0x27);
    } else {
        int off = k * 12;
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f20), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 4));
        s2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f24), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 6));
        h = ((struct Obj03178 *)b)->f8;
        func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0x10, (void *)s2, ((struct Obj03178 *)b)->fC);
        c[0x18] = 1;
        func_02045808((struct U16Vec *)s2);
    }
    h = ((struct Obj03178 *)b)->f8;
    func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0, (void *)s, ((struct Obj03178 *)b)->fC);
    c[0x18] = 1;
    func_02045808((struct U16Vec *)s);
}
