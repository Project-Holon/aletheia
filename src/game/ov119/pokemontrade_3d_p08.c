/*
 * file:     pokemontrade_3d_p08.c
 * unit:     yes
 * function: func_021E3004, func_021E3034, func_021E3070, func_021E30EC, func_021E31B4, func_021E31BC, func_021E31FC
 * address:  0x021E3004
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087A3C  0x02087A3C  arm
 *   func_020056BC  0x020056BC  thumb
 *   func_02051360  0x02051360  arm
 *   func_02050ED4  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02050B80  0x02050B80  arm
 *   func_02030734  0x02030734  arm
 *   func_02050C04  0x02050C04  arm
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *   d_021E81C0  0x021E81C0  data a1
 *   func_021E2B14 0x021E2B14 thumb ov119
 *   func_02047CFC 0x02047CFC arm
 *   func_02048A24 0x02048A24 arm
 *   d_021E7AF4 0x021E7AF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E7AC4 0x021E7AC4 data a4
 *   func_021E32EC  0x021E32EC  thumb  ov119
 *   func_02048AC4 0x02048AC4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_021E2F2C 0x021E2F2C thumb ov119
 *   func_021E2B68 0x021E2B68 thumb ov119
 *   func_021E3838  0x021E3838  thumb  ov119
 */
#include "../../matched/include/Obj13911.h"
#include "../../matched/include/Obj04482.h"
#include "../../matched/include/Obj03778.h"

struct Rec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    void *a[9];         /* 0x000 */
    void *b[6];         /* 0x024 */
    u16 pad3C[0x3F];    /* 0x03C */
    u16 heap;           /* 0x0BA */
} S;

typedef short s16;

typedef struct {u32 x,y,z;} Vec;

typedef struct {void (*call)(char *);u32 other;} Callback;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

extern void func_02087A3C(int clear, u32 flags);
extern u32 func_020056BC(void);
extern void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
extern void func_02050ED4(void);
extern u32 func_020307B0(void *p);
extern void func_02050B80(u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(void *, void *, int, int);
extern void func_021E2B14(int);
extern void *func_02047CFC(u16,u16,u16);
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
extern void func_021E32EC(char *p);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02047E54(struct Rec *p);
extern void func_021E2F2C(void *);
extern void func_021E2B68(void);
extern void func_021E3838(char *p, int count);
void func_021E3004(char *p);
void func_021E3034(u32 *p, int a1);
void func_021E3070(S *p);
void func_021E30EC(char *p);
void func_021E31B4(void *p);
void func_021E31BC(char *p);
void func_021E31FC(void *p);
extern const char d_021E81C0[];
extern Vec d_021E7AF4;
extern const s16 d_020A1EB8[];
extern Callback d_021E7AC4[];


void func_021E3004(char *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        func_02087A3C(1, 1);
        func_02051360(((void **)p)[i], (unsigned int)(((struct Obj13911 *)p)->fB4), 1, func_020056BC());
    }
}


/*
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of func_021D6C78's second call (ov119).
 *
 * Addresses are Black-image addresses.
 */
void func_021E3034(u32 *p, int a1)
{
    int i;

    func_02050ED4();
    if (p[0x2d] != 0) {
        func_020307B0((void *)p[0x2d]);
        p[0x2d] = 0;
    }
    for (i = 0; i < 9; i++) {
        if (p[9 + i] != 0) {
            func_020307B0((void *)p[9 + i]);
            p[9 + i] = 0;
        }
    }
}


void func_021E3070(S *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    func_02050B80(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->a[i];
        buf = func_02030734(p->heap, 0x4800, 1, d_021E81C0, 0x273);
        q[9] = buf;
        *q = (void *)func_02050C04((int)buf, 0x4800, 0, p->heap);
    }
    h = (void *)func_0205121C(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        func_02051230(p->a[i], h, 1, 0);
}

void func_021E30EC(char *p)
{
    ((struct Obj04482 *)p)->f824=0xffff;
    ((struct Obj04482 *)p)->f109C=~0u;
    func_021E2B14(0x91);
    ((struct Obj04482 *)p)->f820=func_02047CFC(20,20,0x91);
    if (!((struct Obj04482 *)p)->f83C) {
        Vec a={0,0,0};
        Vec b={0,0,0};
        Vec c;
        u16 heap;
        heap=((struct Obj04482 *)p)->f5F4;
        c=d_021E7AF4;
        ((struct Obj04482 *)p)->f83C=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (((struct Obj04482 *)p)->f109C!=~0u)
        d_021E7AC4[*(u32 *)(p+0x109c)].call(p);
}

void func_021E31B4(void *p) { func_021E32EC(p); }

void func_021E31BC(char *p) {
    if (((struct Obj03778 *)p)->f83C) func_02048AC4(((struct Obj03778 *)p)->f83C);
    func_02047E54(((struct Obj03778 *)p)->f820);
    if (((struct Obj03778 *)p)->fC) {
        func_021E3034(((struct Obj03778 *)p)->fC,6);
        func_021E2F2C(((struct Obj03778 *)p)->fC);
        func_020307B0(((struct Obj03778 *)p)->fC);
        ((struct Obj03778 *)p)->fC=0;
    }
    func_021E2B68();
}

void func_021E31FC(void *p) { func_021E3838(p, 0x19); }
