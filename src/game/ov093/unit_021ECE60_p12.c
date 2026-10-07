/*
 * file:     unit_021ECE60_p12.c
 * unit:     yes
 * function: func_021EDB3C, func_021EDBE8, func_021EDC28, func_021EDCA8
 * address:  0x021EDB3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049DB4  0x02049DB4  arm
 *   func_02043678  0x02043678  arm
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EDF4C  0x021EDF4C  thumb  ov093
 *   func_021EDE54  0x021EDE54  thumb  ov093
 *   func_021F8AE8  0x021F8AE8  thumb  ov094
 *   func_02040B1C 0x02040B1C arm
 *   func_02040618 0x02040618 arm
 *   func_020437D4 0x020437D4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02021ED8 0x02021ED8 thumb
 */
#include "../../matched/include/Obj01044.h"
#include "../../matched/include/Obj00341.h"

struct Bmp;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct X {
    u8 pad00[0x14];
    char *f14;
};

struct E {
    struct S *f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    char *f10;
    u8 pad14[8];
    char *f1c;
    u8 pad20[2];
    u8 f22_0 : 1;
};

struct S {
    u8 pad00[0x90];
    struct E e[2];
    int fd8;
    struct X *fdc;
    u8 pade0[0x13c - 0xe0];
    u16 f13c;
};

struct W {
    char *f00;
    u8 pad04[4];
    u16 f08;
    u8 pad0a[2];
    u8 f0c;
    u8 f0d;
    u8 pad0e[0x14];
    u8 f22_0 : 1;
    u8 f22_1 : 1;
};

typedef signed short s16;

struct Flags { u8 shown : 1; u8 close : 1; };

extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021EDF4C(struct W *w);
extern void func_021EDE54(u8 *p);
extern void func_021F8AE8(int a, u32 b);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040618(u32, u32, u32);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_020061E4(u32 a);
extern int func_02006254(u32 a);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *ptr);
void func_021EDB3C(struct S *s, char *a1);
void func_021EDBE8(char *s);
void func_021EDC28(struct W *w, u8 a1, int flag);
int func_021EDCA8(u8 *p);


void func_021EDB3C(struct S *s, char *a1)
{
    u32 i;

    s->fd8 = (int)func_02049DB4(0xb, 0xd5, 0, (u32)(&s->fdc), s->f13c);
    for (i = 0; i < 2; i++) {
        s->e[i].f00 = s;
        s->e[i].f0a = i;
        s->e[i].f0b = (i == 0) ? 2 : 3;
        s->e[i].f10 = s->fdc->f14 + i * 0x900;
        s->e[i].f04 = (int)func_02043678(0x12, 4, 0x20, s->f13c);
        s->e[i].f08 = 0;
        s->e[i].f0c = 0x1f;
        s->e[i].f1c = a1 + i * 0x48;
        s->e[i].f22_0 = 0;
    }
}


void func_021EDBE8(char *s)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(s + i * 0x24 + 0x94) != 0) {
            func_020437AC((struct Obj020437AC *)(*(int *)(s + i * 0x24 + 0x94)));
            *(int *)(s + i * 0x24 + 0x94) = 0;
        }
    }
    if (((struct Obj01044 *)s)->fD8 != 0) {
        func_020307B0((void *)(((struct Obj01044 *)s)->fD8));
        ((struct Obj01044 *)s)->fD8 = 0;
    }
}


/*
 * note:     a1 is a narrow (u8/u16, both give EXACT*) parameter: it pins the
 *           spill store to the front of the prologue; flag is int, cast (u8)
 *           at the bitfield store.
 */
void func_021EDC28(struct W *w, u8 a1, int flag)
{
    u8 *t;
    u16 h;
    u8 k;

    t = func_021B98AC(*(char *const **)(w->f00 + 0x138), a1);
    h = func_021D59B4(t, 0x10);
    k = func_021D5440(t);
    if (w->f22_0) {
        if (k == w->f0c) {
            return;
        }
        func_021EDF4C(w);
    }
    if (h != w->f08 || k != w->f0c) {
        w->f08 = h;
        w->f0c = k;
        func_021EDE54((u8 *)w);
    }
    w->f22_1 = (u8)flag;
    w->f0d = 0;
    func_021F8AE8(a1, h);
}

/*
 * volatile: 021EDDC6 rereads flags after setting bit 0.
 */
int func_021EDCA8(u8 *p)
{
    u32 i;
    u8 *src;
    u32 dst;
    void *pal;
    void *ctx;
    u16 mask;
    switch (p[0xd]) {
    case 0:
        func_02040B1C(p[0xb], ((struct Obj00341 *)p)->f10, 0x900, ((struct Obj00341 *)p)->f1C);
        p[0xd]++;
        break;
    case 1:
        p[0x20] = 8;
        if (p[0xa] == 0) {
            ((struct Obj00341 *)p)->f14 = 0x90000;
            ((struct Obj00341 *)p)->f18 = -0x12000;
        } else {
            ((struct Obj00341 *)p)->f14 = -0x90000;
            ((struct Obj00341 *)p)->f18 = 0x12000;
        }
        func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
        func_02040618(p[0xb], 3, 0);
        func_020061E4(0x573);
        p[0xd]++;
        break;
    case 2:
        if (p[0x20] != 0) {
            ((struct Obj00341 *)p)->f14 += ((struct Obj00341 *)p)->f18;
            func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
            p[0x20]--;
        } else {
            func_02040618(p[0xb], 0, 0);
            p[0x21] = 0;
            p[0xd]++;
        }
        break;
    case 3:
        if (p[0x21] < 17) {
            src = (u8 *)func_020437D4(((struct Obj00341 *)p)->f4);
            dst = ((struct Obj00341 *)p)->f1C + p[0x21];
            src += p[0x21] * 32;
            for (i = 0; i < 4; i++) {
                func_02040B1C(p[0xb], src + i * 0x240, 32, dst + i * 18);
            }
            p[0x21]++;
        } else {
            ((struct Flags *)(p + 0x22))->shown = 1;
            if (((volatile struct Flags *)(p + 0x22))->close == 0) return 1;
            p[0xd]++;
        }
        break;
    case 4:
        pal = (void *)func_021F86E0();
        ctx = func_021F86D4();
        mask = 1 << (p[0xa] + 1);
        func_020061E4(0x54d);
        func_0202173C(pal, 1, mask, 0, 16, 0, 0x7fff, ctx);
        p[0xd]++;
        break;
    case 5:
        if (func_02021ED8((const char *)func_021F86E0()) == 0) p[0xd]++;
        break;
    case 6:
        if (func_02006254(0x54d) == 0 && func_02006254(0x573) == 0) return 1;
        break;
    }
    return 0;
}
