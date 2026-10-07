/*
 * file:     unit_021B95A0_p05.c
 * unit:     yes
 * function: func_021BA318, func_021BA354, func_021BA390, func_021BA4AC, func_021BA558, func_021BA594, func_021BA5E8, func_021BA6F0, func_021BA83C, func_021BAA00, func_021BAA54, func_021BAAC0, func_021BAAD0, func_021BAAE0
 * address:  0x021BA318
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203630C 0x0203630C arm
 *   func_02045770 0x02045770 arm
 *   func_020437D4 0x020437D4 arm
 *   func_021B9DCC 0x021B9DCC thumb ov181
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021BAB40 0x021BAB40 data a2
 *   func_0207D63C 0x0207D63C arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021B9A80 0x021B9A80 thumb ov181
 *   func_020434DC 0x020434DC arm
 *   func_0207D534 0x0207D534 arm
 *   func_02051E74 0x02051E74 arm
 *   func_02040860 0x02040860 arm
 *   func_021B9FD8 0x021B9FD8 thumb ov181
 *   func_021BA2A8 0x021BA2A8 thumb ov181
 */
#include "../../matched/include/Obj04570.h"
#include "../../matched/include/Obj01071.h"
#include "../../matched/include/Obj06590.h"
#include "../../matched/include/Obj14412.h"
#include "../../matched/include/Obj08305.h"
#include "../../matched/include/Obj01274.h"
#include "../../matched/include/Obj00784.h"
#include "../../matched/include/Obj00682.h"
#include "../../matched/include/Obj06591.h"
#include "../../matched/include/Obj06592.h"
#include "../../matched/include/Obj10725.h"
#include "../../matched/include/Obj14414.h"
#include "../../matched/include/Obj24511.h"
#include "../../matched/include/Obj24512.h"
#include "../../matched/include/Obj24513.h"
#include "../../matched/include/Obj14415.h"

struct Descriptor;
struct MsgBank;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bmp { void *pixels; u16 width, height, depth, kind; };

typedef signed char s8;

struct CharBuf { u8 *pixels; u16 width, height, tileSize; };

struct Mtx22 { int m[4]; };

extern u32 func_0203630C(void);
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *);
extern void func_021B9DCC(char *, unsigned);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *, short, short, void *, void *, unsigned short);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_021B9A80(void *, int);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02051E74(struct Mtx22 *, unsigned, const void *, const void *, u8);
extern void func_02040860(unsigned, unsigned, unsigned, unsigned);
extern void func_021B9FD8(u8 *,int,int);
extern void func_021BA2A8(u8 *,u32);
void func_021BA318(u8 *p);
void func_021BA354(u8 *p,u8 *out,u32 n);
void func_021BA390(char *p);
void func_021BA4AC(char *p, unsigned char *q, void *s, int y);
void func_021BA558(char *p,u8 *q);
void func_021BA594(char *p, unsigned char *q);
int func_021BA5E8(char *p);
int func_021BA6F0(char *p);
int func_021BA83C(char *p);
int func_021BAA00(char *p, unsigned char *q);
int func_021BAA54(char *p, unsigned char *q);
int func_021BAA84(char *p, unsigned char *q);
int func_021BAA98(char *p);
int func_021BAAA4(char *p);
int func_021BAAB0(char *p);
int func_021BAABC(void);
int func_021BAAC0(void);
int func_021BAAD0(void);
int func_021BAAE0(u8 *p,u8 *q);
extern const unsigned short d_021BAB40[];

void func_021BA318(u8 *p){if(**(int **)p){enum {K=0x2d1} k=K;if(p[k]==0)p[k+1]=(func_0203630C()&3)?1:0;p[0x2d1]=(p[0x2d1]+1)&3;}}

void func_021BA354(u8 *p,u8 *out,u32 n){u32 i;if(out){for(i=0;i<n;i++)*(u32 *)(out+(8-n)*4+i*4)=*(u32 *)(p+i*4);}for(i=0;i<8-n;i++)*(u32 *)(p+i*4)=*(u32 *)(p+n*4+i*4);}

/*
 * extent: two zero alignment bytes at 021BA4AA, then labelled 021BA4AC.
 */
void func_021BA390(char *p)
{
    char *a, *b;
    unsigned n;
    u16 i, j, k, l, m, o;
    unsigned x, y;
    if (((struct Obj04570 *)p)->f2E0 == 0) return;
    ((struct Obj04570 *)p)->f2DC += 0x1000;
    if (((struct Obj04570 *)p)->f2DC < 0x1000) return;
    ((struct Obj04570 *)p)->f2DC -= 0x1000;
    n = 1;
    if (((struct Obj04570 *)p)->f2D2) n = 4;
    a = func_020437D4(func_02045770(((struct Obj04570 *)p)->f2BC));
    b = func_020437D4(func_02045770(((struct Obj04570 *)p)->f2C4));
    x = 0;
    for (i = 0; i < 32; i++, x += 32) func_021BA354((u8 *)(a + x), 0, n);
    for (j = 1; j < 25; j++) {
        x = j * 1024;
        y = (j - 1) * 1024;
        for (k = 0; k < 32; k++, x += 32, y += 32) func_021BA354((u8 *)(a + x), (u8 *)(a + y), n);
    }
    x = 0;
    y = 0x6000;
    for (l = 0; l < 32; l++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(a + y), n);
    for (m = 1; m < 28; m++) {
        x = m * 1024;
        y = (m - 1) * 1024;
        for (o = 0; o < 32; o++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(b + y), n);
    }
    func_021B9DCC(p, 3);
}

void func_021BA4AC(char *p, unsigned char *q, void *s, int y)
{
    int x;
    unsigned w;
    func_02045CAC(((struct Obj06590 *)p)->fB0, ((struct Obj01071 *)q)->f0, ((struct Obj06590 *)p)->fB4);
    if (((struct Obj01071 *)q)->fA == 0) {
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE;
    } else if (((struct Obj01071 *)q)->fA == 1) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w;
    } else if (((struct Obj01071 *)q)->fA == 2) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w / 2;
    }
    func_0201C7D0(s, x, y, ((struct Obj06590 *)p)->fB4, *(void **)(p + q[9] * 4 + 0xa8), d_021BAB40[q[8]]);
}

void func_021BA558(char *p,u8 *q){if(q[9]==0)func_021BA4AC(p,q,func_02045770(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),192);else func_021BA4AC(p,q,func_02045770(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),194);}

void func_021BA594(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (((struct Obj01071 *)q)->f4 < 0x100) {
        s = func_02045770(((struct Obj08305 *)p)->f2BC);
        y = ((struct Obj01071 *)q)->f4;
        ((struct Obj08305 *)p)->f2CF |= 1;
    } else {
        s = func_02045770(((struct Obj08305 *)p)->f2C4);
        y = ((struct Obj01071 *)q)->f4 - 0x100;
        ((struct Obj08305 *)p)->f2CF |= 2;
    }
    func_021BA4AC(p, q, s, y);
}

/*
 * volatile: display registers 04000052 and 04001052 are hardware.
 */
int func_021BA5E8(char *p)
{
    int a, b;
    switch (((struct Obj01274 *)p)->f2CE) {
    case 0:
        if (((struct Obj01274 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 0, 16);
        if (((struct Obj01274 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 0, 16);
        ((struct Obj01274 *)p)->f2CC = ((struct Obj01274 *)p)->f2CF;
        ++((struct Obj01274 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj01274 *)p)->f2D2 == 1) ((struct Obj01274 *)p)->f2D0 += 16;
        else ((struct Obj01274 *)p)->f2D0 += 4;
        a = ((struct Obj01274 *)p)->f2D0;
        if (a > 16) { a = 16; b = 0; }
        else b = 16 - a;
        if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2D0 >= 16) {
            if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
            if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
            *(u8 *)&((struct Obj01274 *)p)->f2D0 = 0;
            ((struct Obj01274 *)p)->f2CE = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int func_021BA6F0(char *p)
{
    int a, b;
    switch (((struct Obj00784 *)p)->f2CE) {
    case 0:
        if (((struct Obj00784 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 16, 0);
        if (((struct Obj00784 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 16, 0);
        ++((struct Obj00784 *)p)->f2CE;
    case 1:
        if (((struct Obj00784 *)p)->f2D2 == 1) ((struct Obj00784 *)p)->f2D0 += 16;
        else ((struct Obj00784 *)p)->f2D0 += 4;
        b = ((struct Obj00784 *)p)->f2D0;
        if (b > 16) { a = 0; b = 16; }
        else a = 16 - b;
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2D0 >= 16) {
            if (((struct Obj00784 *)p)->f2CF & 1) func_02043B5C(func_02045770(((struct Obj00784 *)p)->f2BC), 0);
            if (((struct Obj00784 *)p)->f2CF & 2) func_02043B5C(func_02045770(((struct Obj00784 *)p)->f2C4), 0);
            ((struct Obj00784 *)p)->f2CC = ((struct Obj00784 *)p)->f2CF;
            *(u8 *)&((struct Obj00784 *)p)->f2D0 = 0;
            ++((struct Obj00784 *)p)->f2CE;
        }
        break;
    case 2:
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
        ((struct Obj00784 *)p)->f2CF = 0;
        ((struct Obj00784 *)p)->f2CE = 0;
        return 0;
    }
    return 1;
}

/*
 * volatile: display register stores at 04000050 and 04000052.
 */
int func_021BA83C(char *p)
{
    struct Mtx22 matrix;
    int v;
    unsigned scale;
    switch (((struct Obj00682 *)p)->f2CE) {
    case 0:
        func_021B9A80(p, 1);
        func_0207D63C(0x04000050, 8, 0x20, 0, 16);
        func_020434DC(8, 1);
        func_0207D534((void *)0x0400006c, 0);
        func_0207D534((void *)0x0400106c, 0);
        *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
        ++((struct Obj00682 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000052 = 16;
            func_02051E74(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            *(u16 *)&((struct Obj00682 *)p)->f2DA = 0xa6;
            ++((struct Obj00682 *)p)->f2CE;
        } else {
            *(volatile u16 *)0x04000052 = v | ((16 - v) << 8);
            scale = 8 - ((struct Obj00682 *)p)->f2D0 / 2;
            func_02051E74(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    case 2:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2DA -= 4;
        else --((struct Obj00682 *)p)->f2DA;
        if (((struct Obj00682 *)p)->f2DA <= 0) {
            ((struct Obj00682 *)p)->f2DA = 0;
            ++((struct Obj00682 *)p)->f2CE;
        }
        break;
    case 3:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000050 = 0;
            func_020434DC(8, 0);
            func_02051E74(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            func_021B9A80(p, 0);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            ((struct Obj00682 *)p)->f2CE = 0;
            return 0;
        } else {
            *(volatile u16 *)0x04000052 = (16 - v) | (v << 8);
            scale = ((struct Obj00682 *)p)->f2D0 / 2 + 1;
            func_02051E74(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    }
    return 1;
}

int func_021BAA00(char *p, unsigned char *q)
{
    if (((struct Obj06592 *)q)->f0 == 0xffff) {
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    if (((struct Obj06591 *)p)->f2DA == 0)
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
    func_021BA558(p, q);
    if (q[0x16] != 0 || ((struct Obj06592 *)q)->f14 != 0) {
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    return 0;
}

int func_021BAA54(char *p, unsigned char *q)
{
    if (((struct Obj10725 *)p)->f2EC == 0) {
        ((struct Obj10725 *)p)->f2CD = q[7];
        ((struct Obj10725 *)p)->f2EC = 2;
    }
    func_021BA594(p, q);
    if (q[0x16] != 1)
        return 1;
    return 0;
}

int func_021BAA84(char *p, unsigned char *q)
{
    ((struct Obj14414 *)p)->f2CD = q[7];
    ((struct Obj14414 *)p)->f2EC = 3;
    return 1;
}

int func_021BAA98(char *p)
{
    ((struct Obj24511 *)p)->f2E0 = 1;
    return 0;
}

int func_021BAAA4(char *p)
{
    ((struct Obj24512 *)p)->f2E0 = 0;
    return 0;
}

int func_021BAAB0(char *p)
{
    ((struct Obj24513 *)p)->f2EC = 5;
    return 1;
}

int func_021BAABC(void)
{
    return 1;
}


int func_021BAAC0(void)
{
    func_020434DC(1, 1);
    return 1;
}


int func_021BAAD0(void)
{
    func_020434DC(1, 0);
    return 1;
}

int func_021BAAE0(u8 *p,u8 *q){u8 *s=(u8 *)((u32)p+0x28);func_021B9FD8(s,q[7],((struct Obj14415 *)q)->f4);func_021BA2A8(s,1);return 1;}
