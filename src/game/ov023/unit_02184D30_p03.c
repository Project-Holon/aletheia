/*
 * file:     unit_02184D30_p03.c
 * unit:     yes
 * function: func_02185354, func_02185378, func_021853D0, func_021853F0, func_02185420, func_02185454, func_02185584, func_021855C8, func_021855EC
 * address:  0x02185354
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02185EA0 0x02185EA0 thumb ov023
 *   func_02185DE8 0x02185DE8 thumb ov023
 *   func_02039338  0x02039338  arm
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_020061E4  0x020061E4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02186304 0x02186304 thumb ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 *   func_021865B4  0x021865B4  thumb  ov023
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020278F4  0x020278F4  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_021864A8  0x021864A8  thumb  ov023
 *   func_02186660  0x02186660  thumb  ov023
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02082BCC  0x02082BCC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */
#include "../../matched/include/Obj00525.h"
#include "../../matched/include/Obj00336.h"
#include "../../matched/include/Obj20348.h"
#include "../../matched/include/Obj02742.h"
#include "../../matched/include/Obj02741.h"
#include "../../matched/include/Obj20349.h"
#include "../../matched/include/Obj09769.h"

struct P;
struct Obj;
struct Descriptor;
struct Cfg;
struct Entry;
struct e6 { unsigned char b[4]; unsigned char c:3, n:3, d:2; unsigned char pad; };

struct o4 { unsigned char x, y; unsigned short n; };

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Bits;

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

extern void func_02185EA0(struct P *p);
extern void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag);
extern u16 func_02039338(void);
extern void func_021861C4(u8 *w, u32 msg, int mode);
extern void func_02186444(char *p, u32 v);
extern void func_02186480(char *p);
extern void func_020061E4(u32 a);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02186304(char *p, int a);
extern int  func_021862B0(char *p);
extern int func_021865B4(char *p);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_020278F4(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_021852F4(void *p, int flag);
extern int  func_021864A8(char *p);
extern int  func_02186660(char *p);
extern void func_02184560(char *p, int a);
extern void func_02082BCC(void *p, int v, int n);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02185354(char *p);
int func_02185378(char *p, int x);
int func_021853D0(char *p, int a1);
int func_021853F0(char *p, int result);
int func_02185420(char *p, int a1);
int func_02185454(char *p, int x);
int func_02185584(char *p, int x);
int func_021855C8(unsigned char *p, int a1);
int func_021855EC(unsigned char *p, int a1);

void func_02185354(char *p)
{
    func_02185EA0((struct P *)p);
    func_02185DE8(*(char * *)&((struct Obj00525 *)p)->f118, (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 0);
}


int func_02185378(char *p, int x)
{
    if (((struct Obj00336 *)p)->f1B4 == func_02039338())
        func_021861C4((u8 *)p, 0xd, 0);
    else
        func_021861C4((u8 *)p, 0, 0);
    func_02186444(p, 2);
    func_02186480(p);
    func_020061E4(0x54c);
    func_0207D658(0x04000050, 14, -6);
    func_02185354(p);
    return x;
}


int func_021853D0(char *p, int a1)
{
    int i;

    for (i = 0; i < 5; i++)
        func_0204B3DC(*(void **)(p + 0x60 + i * 4), 0);
    return a1;
}

/*
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 */
int func_021853F0(char *p, int result)
{
    *(volatile u16 *)0x04000050 = 0;
    func_02186304(p, 1);
    func_02186444(p, 4);
    func_02185354(p);
    ((struct Obj20348 *)p)->f9E7C = 0;
    return result;
}


int func_02185420(char *p, int a1)
{
    if (func_021862B0(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)func_021865B4(p);
        func_02186444(p, 6);
    }
    func_02185354(p);
    return a1;
}


int func_02185454(char *p, int x)
{
    u32 w;

    ((Bits *)(p + 0x4210))->mid = 0;
    if (((struct Obj02741 *)p)->f4217 == 2 && func_02039338() != 0) {
        func_02185354(p);
        func_020278F4(((struct Obj02741 *)p)->f178);
        if (func_021864A8(p))
            func_020061E4(0x54b);
        return x;
    }
    if (func_02039338() == 0 && ((struct Obj02741 *)p)->f9280 != 0) {
        func_02185354(p);
        func_020278F4(((struct Obj02741 *)p)->f178);
        return x;
    }
    switch (func_02186660(p)) {
    case 0:
        if (func_02039338() == 0) {
            func_02186444(p, 0xf);
            func_021861C4((u8 *)p, 4, 1);
        } else {
            func_02186444(p, 8);
            func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        }
        w = ((struct Obj02741 *)p)->f118;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(((struct Obj02741 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        w = ((struct Obj02741 *)p)->f118;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            ((struct Obj02741 *)p)->f9E6C = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}


int func_02185584(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 0;
    b[0] = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)((void *)b)))
        func_02186444(p, 7);
    func_02185354(p);
    return x;
}


int func_021855C8(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj20349 *)p)->f9286 = 0;
    func_02185354((char *)p);
    return a1;
}


int func_021855EC(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj09769 *)p)->f9286 += 1;
    if (((struct Obj09769 *)p)->f9286 > 0x1e) {
        func_02186444((char *)p, 0xa);
        ((struct Obj09769 *)p)->f9286 = 0;
    }
    func_02185354((char *)p);
    return a1;
}
