/*
 * file:     beacon_view_p05.c
 * unit:     yes
 * function: func_021F0BA8, func_021F0C04, func_021F0C70, func_021F0CF8, func_021F0D38, func_021F0D5C, func_021F0D9C, func_021F0DC0, func_021F0DD8, func_021F0DE0, func_021F0DF4, func_021F0E04, func_021F0E24, func_021F0E7C, func_021F0EA4, func_021F0ED0
 * address:  0x021F0BA8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_02041FF4  0x02041FF4  arm
 *   func_0202800C  0x0202800C  thumb
 *   func_0202846C  0x0202846C  thumb
 *   func_02028178  0x02028178  thumb
 *   func_0202824C  0x0202824C  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02028230  0x02028230  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02165E24 0x02165E24 thumb ov010
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02025774 0x02025774 thumb
 */
#include "../../matched/include/Obj13061.h"
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj20418.h"

struct Obj;
struct Vec2;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { short x,y; } Pair;

extern u32 func_02035D20(u32 *x, u32 *y);
extern u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags);
extern u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                          u16 a8);
extern u32 func_0202846C(u8 *p);
extern void func_02028178(u8 *p);
extern u32 func_0202824C(void **p);
extern void func_0202822C(char *p, int v);
extern u32 func_02028230(u8 *p);
extern void func_02028148(u8 *p);
extern int func_02165E24(int a0);
extern void func_020061E4(unsigned int a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02025774(unsigned char *,unsigned);
int func_021F0BA8(u8 *p);
void func_021F0C04(char *p, int flag);
int func_021F0C70(char *p, int flag);
int func_021F0CF8(char *p, int i);
void func_021F0D38(char *p);
int func_021F0D5C(char *p, int i);
void func_021F0D9C(char *p);
int func_021F0DC0(void *p);
void func_021F0DD8(unsigned int a);
void func_021F0DE0(void *p, short x, short y);
void func_021F0DF4(void *p, unsigned short v);
void func_021F0E04(char *p, unsigned a);
void func_021F0E24(char *p);
void func_021F0E7C(char *p);
void func_021F0EA4(char *p,unsigned a);
void func_021F0ED0(char *p, int a);


int func_021F0BA8(u8 *p)
{
    u32 x;
    u32 y;
    u16 v = 0xFFFE;
    u8 c = p[0];

    p[0] = c - 1;
    if (c == 0) {
        p[0] = 0;
        return 1;
    }
    if (func_02035D20(&x, &y) != 0) {
        if (func_02041FF4(6, x, y + 0x40, &v) != 0) {
            p[0] = 0;
            return 1;
        }
    }
    return 0;
}


void func_021F0C04(char *p, int flag)
{
    int i;
    int n;
    int base;
    char *q;

    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
        base = 8;
    } else {
        q = p + 0xf0;
        n = 2;
        base = 0x10;
    }
    for (i = 0; i < n; i++) {
        *(u32 *)(q + i * 16) = (u32)func_0202800C(((struct Obj13061 *)p)->fB8, (u32)(q + i * 16 + 4),
                                      (u8)(base + i * 8), 0x15, 8, 3, 1, 0,
                                      ((struct Obj13061 *)p)->f98);
    }
}


int func_021F0C70(char *p, int flag)
{
    int s;
    char *q;
    int n;
    int i;

    s = -1;
    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
    } else {
        q = p + 0xf0;
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_0202846C(*(u8 **)(q + i * 16)) == 1) {
            func_02028178((u8 *)(*(u32 *)(q + i * 16)));
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (func_0202824C((void **)(*(u32 **)(q + i * 16))) != 0) {
            if (i < n - 1) {
                func_021F0DD8(0x54c);
                s = i;
            } else {
                func_0202822C(*(char **)(q + i * 16), 1);
                func_021F0DD8(0x54c);
                s = i;
            }
        }
        func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    }
    return s;
}


int func_021F0CF8(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xc0;
    func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    if (func_02028230(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 3; j++) {
            func_02028148((u8 *)(*(u32 *)(p + j * 16 + 0xc0)));
            *(u32 *)(p + j * 16 + 0xc0) = 0;
        }
        return 1;
    }
    return 0;
}

void func_021F0D38(char *p) { int i; for(i=0;i<3;i++) { func_02028148(*(unsigned char **)(p+i*16+0xc0)); *(unsigned *)(p+i*16+0xc0)=0; } }


int func_021F0D5C(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xf0;
    func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    if (func_02028230(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 2; j++) {
            func_02028148((u8 *)(*(u32 *)(p + j * 16 + 0xf0)));
            *(u32 *)(p + j * 16 + 0xf0) = 0;
        }
        return 1;
    }
    return 0;
}

void func_021F0D9C(char *p) { int i; for(i=0;i<2;i++) { func_02028148(*(unsigned char **)(p+i*16+0xf0)); *(unsigned *)(p+i*16+0xf0)=0; } }

int func_021F0DC0(void *p) { int a; a=func_02165E24((int)p); if(a==0 || a>=0x33) return 0x12; return a+0x11; }


void func_021F0DD8(unsigned int a)
{
    func_020061E4(a);
}

void func_021F0DE0(void *p, short x, short y) { Pair d; d.x=x; d.y=y; func_0204B404(p,(const struct Vec2 *)(&d),0); }

void func_021F0DF4(void *p, unsigned short v) { func_0204B878(p,v); func_0204B9A0(p); }

void func_021F0E04(char *p, unsigned a) { int i; for(i=0;i<=3;i++) func_0204B3DC(*(void **)(p+i*4+0x2bc),a); }


void func_021F0E24(char *p)
{
    if (((struct Obj00007 *)p)->f7C == 0) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0x10);
    } else {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0xd);
    }
    if (((struct Obj00007 *)p)->f7C + ((struct Obj00007 *)p)->f7D < ((struct Obj00007 *)p)->f7B) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x11);
        return;
    }
    func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x14);
}

void func_021F0E7C(char *p) { if(((struct Obj00007 *)p)->f7B==0) func_0204B878(((struct Obj00007 *)p)->f2C4,9); else func_0204B878(((struct Obj00007 *)p)->f2C4,7); }

void func_021F0EA4(char *p,unsigned a) { func_02025774(*(unsigned char * *)&((struct Obj00225 *)p)->f18,a); func_0204B3DC(((struct Obj00225 *)p)->f10,a); func_0204B3DC(((struct Obj00225 *)p)->fC,a); if(a==0) func_021F0ED0(p,a); }


void func_021F0ED0(char *p, int a)
{
    func_0204B3DC(((struct Obj20418 *)p)->f14, a);
}
