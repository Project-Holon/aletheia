/*
 * file:     battle_rec_tool_p03.c
 * unit:     yes
 * function: func_021EEFE4, func_021EF014, func_021EF090, func_021EF0F4, func_021EF140, func_021EF1AC, func_021EF1D8, func_021EF1F4
 * address:  0x021EEFE4
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEF2C  0x021EEF2C  thumb  ov188
 *   func_02008494 0x02008494 thumb
 *   func_02045A38 0x02045A38 arm
 *   func_02045924 0x02045924 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02082D44  0x02082D44  arm
 *   func_02008314  0x02008314  thumb
 */
#include "../../matched/include/Obj08341.h"
#include "../../matched/include/Obj14492.h"
#include "../../matched/include/Obj02238.h"
#include "../../matched/include/Obj02528.h"
#include "../../matched/include/Obj01970.h"
#include "../../matched/include/Obj02529.h"
#include "../../matched/include/Obj14493.h"
#include "../../matched/include/Obj24896.h"
#include "../../matched/include/Obj02907.h"
#include "../../matched/include/Obj24897.h"

struct U16Vec;
struct Strbuf;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u32 w[4]; } Block16;

typedef struct { u32 w[6]; } Block24;

typedef struct { unsigned char low:5, high:3; } Bits50;

typedef struct { unsigned char low:4, mid:3, high:1; } Bits51;

extern void func_021EEF2C(u8 *a, void *b, u32 c);
extern void func_02008494(void *, void *);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02082D44(void *, void *, int);
extern void func_02008314(void *a, void *b);
void func_021EEFE4(void *p, char *b, u32 c);
void func_021EF014(u8 *a, u8 *b);
void func_021EF090(u8 *a, u8 *b);
void func_021EF0F4(u8 *a, u8 *b);
void func_021EF140(u8 *a, u8 *b);
int func_021EF1AC(char *p, char *q);
int func_021EF1D8(char *p, char *a1);
int func_021EF1F4(const u8 *a, u8 *b);


void func_021EEFE4(void *p, char *b, u32 c)
{
    char *base;
    u32 i = 0;

    base = b + 0xc38;
    for (; i < 4; i++) {
        u32 v = *(u32 *)((char *)p + i * 4 + 0x24);

        if (v != 0)
            func_021EEF2C((u8 *)(base + i * 0x2a4), (void *)v, c);
    }
}

void func_021EF014(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        if (*(void **)(a+0x48+i*4)) {
            func_021EF0F4(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 2;
        } else if (*(void **)(a+0x34+i*4)) {
            func_02008494(*(void **)(a+0x34+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 1;
        } else {
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 0;
        }
        ((struct Obj08341 *)p)->f16CA = a[0x44+i];
    }
}

void func_021EF090(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        p = b+i*0x44;
        switch(((struct Obj14492 *)p)->f16C8) {
        case 1: func_02008494(b+0x16CC+i*0x44, *(void **)(a+0x34+i*4)); break;
        case 2: func_021EF140(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44); break;
        }
        a[0x44+i] = ((struct Obj14492 *)p)->f16CA;
    }
}

void func_021EF0F4(u8 *a, u8 *b)
{
    unsigned i;
    ((struct Obj02528 *)b)->f4 = ((struct Obj02238 *)a)->f0;
    ((struct Obj02528 *)b)->f6 = ((struct Obj02238 *)a)->f4;
    ((struct Obj02528 *)b)->f0 = ((struct Obj02238 *)a)->f8;
    ((struct Obj02528 *)b)->f30 = ((struct Obj02238 *)a)->f18;
    ((struct Obj02528 *)b)->f32 = ((struct Obj02238 *)a)->f1A;
    ((struct Obj02528 *)b)->f34 = ((struct Obj02238 *)a)->f1C;
    ((struct Obj02528 *)b)->f36 = ((struct Obj02238 *)a)->f1E;
    ((struct Obj02528 *)b)->f38 = ((struct Obj02238 *)a)->f20;
    ((struct Obj02528 *)b)->f3A = ((struct Obj02238 *)a)->f22;
    ((struct Obj02528 *)b)->f3C = ((struct Obj02238 *)a)->f24;
    ((struct Obj02528 *)b)->f3E = ((struct Obj02238 *)a)->f26;
    for(i=0;i<4;i++) *(u16 *)(b+8+i*2) = *(u16 *)(a+12+i*2);
    func_02045A38(((struct Obj02238 *)a)->f14, (u16 *)(b+16), 16);
}

void func_021EF140(u8 *a, u8 *b)
{
    unsigned i;
    u16 *p;
    ((struct Obj01970 *)a)->f0 = ((struct Obj02529 *)b)->f4;
    ((struct Obj01970 *)a)->f4 = ((struct Obj02529 *)b)->f6;
    ((struct Obj01970 *)a)->f8 = ((struct Obj02529 *)b)->f0;
    ((struct Obj01970 *)a)->f18 = ((struct Obj02529 *)b)->f30;
    ((struct Obj01970 *)a)->f1A = ((struct Obj02529 *)b)->f32;
    ((struct Obj01970 *)a)->f1C = ((struct Obj02529 *)b)->f34;
    ((struct Obj01970 *)a)->f1E = ((struct Obj02529 *)b)->f36;
    ((struct Obj01970 *)a)->f20 = ((struct Obj02529 *)b)->f38;
    ((struct Obj01970 *)a)->f22 = ((struct Obj02529 *)b)->f3A;
    ((struct Obj01970 *)a)->f24 = ((struct Obj02529 *)b)->f3C;
    ((struct Obj01970 *)a)->f26 = ((struct Obj02529 *)b)->f3E;
    for(i=0;i<4;i++) *(u16 *)(a+12+i*2) = *(u16 *)(b+8+i*2);
    func_02045924(((struct Obj01970 *)a)->f14, (u16 *)(b+16));
    p = func_02045A90(((struct Obj01970 *)a)->f14);
    while (*p != func_02045A98()) p++;
}


int func_021EF1AC(char *p, char *q)
{
    u32 a = ((struct Obj14493 *)p)->f94;

    if (a != 0) {
        u32 b = ((struct Obj14493 *)p)->f98;

        if (b < 0xc00) {
            ((struct Obj24896 *)q)->f34 = b;
            func_02082D44((void *)a, q + 0x38, b);
            return 1;
        }
    }
    return 0;
}


int func_021EF1D8(char *p, char *a1)
{
    int v = ((struct Obj24897 *)a1)->f34;

    ((struct Obj02907 *)p)->f98 = v;
    func_02082D44(a1 + 0x38, ((struct Obj02907 *)p)->f94, v);
    return 1;
}


int func_021EF1F4(const u8 *a, u8 *b)
{
    int f;
    *(Block16 *)(b + 24) = *(const Block16 *)(a + 8);
    *(Block24 *)b = *(const Block24 *)(a + 156);
    *(u16 *)(b + 44) = *(const u16 *)(a + 24);
    *(u16 *)(b + 46) = *(const u16 *)(a + 26);
    ((Bits50 *)(b + 50))->low = *(const u32 *)a;
    ((Bits51 *)(b + 51))->low = *(const u32 *)(a + 4);
    ((Bits51 *)(b + 51))->mid = a[34];
    *(u16 *)(b + 48) = *(const u16 *)(a + 134);
    ((Bits50 *)(b + 50))->high = a[33];
    f = (a[127] != 0);
    ((Bits51 *)(b + 51))->high = f;
    func_02008314(*(void **)(a + 92), b + 40);
    return 1;
}
