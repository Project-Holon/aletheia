/*
 * file:     unit_06899DD8_p02.c
 * unit:     yes
 * function: func_06899ED0, func_06899F28, func_06899F64
 * address:  0x06899ED0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06899E48  0x06899E48  thumb  ov095
 *   func_0689A030  0x0689A030  thumb  ov095
 *   func_0689A76C  0x0689A76C  thumb  ov095
 *   func_0689A84C  0x0689A84C  thumb  ov095
 *   func_06899E68 0x06899E68 thumb ov095
 *   func_0689A988 0x0689A988 thumb ov095
 *   func_0689A878 0x0689A878 thumb ov095
 *   func_06899FA4  0x06899FA4  thumb  ov095
 *   func_06899FB4  0x06899FB4  thumb  ov095
 *   func_06899FC4  0x06899FC4  thumb  ov095
 *   func_0689ABA0  0x0689ABA0  thumb  ov095
 *   func_0689AB48  0x0689AB48  thumb  ov095
 */
#include "../../matched/include/Obj07912.h"
#include "../../matched/include/Obj21889.h"
#include "../../matched/include/Obj07913.h"

struct Q;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[0x6c];
    int f6c;
    int f70;
    u8 pad74[0x8b - 0x74];
    u8 f8b;
    u8 pad8c[0x91 - 0x8c];
    u8 f91;
    u8 pad92[0x98 - 0x92];
    int f98;
} Obj;

typedef struct Slot { int (*f0)(void *,int); int (*f1)(void *,int); int arg; int data; } Slot;

typedef struct Q { u8 pad[0x20]; Slot tab[4]; int n; } Q;

extern int func_0689A030(int unused, u8 *p);
extern int func_0689A76C(int *st, u8 *s);
extern int func_0689A84C(u32 unused, u32 p);
extern void func_06899E48(struct Q *p, void *a, void *b);
extern int func_06899E68(Q *);
extern int func_0689A988(int,u8 *);
extern int func_0689A878(int,u8 *);
extern void func_06899FA4(void *);
extern void func_06899FB4(void *);
extern void func_06899FC4(void *);
extern int func_0689ABA0(int unused, u8 *s);
extern int func_0689AB48(int unused, u8 *s);
void func_06899ED0(Obj *o, int a, u8 b, u8 c, int d);
void func_06899F00(Obj *o, int a, u8 b, int c);
u32 func_06899F28(u8 *p);
void func_06899F40(u8 *p, void *a, void *b);
void func_06899F64(u8 *s, u8 *a, void *b);


/*
 * Two functions: 0x06899ED0 and the unlabelled tail-call stub 0x06899F00
 * (the extent 0x06899ED0..0x06899F28 is code and pool only).
 */
void func_06899ED0(Obj *o, int a, u8 b, u8 c, int d)
{
    o->f6c = a;
    o->f70 = d;
    o->f98 = 0;
    o->f8b = b;
    o->f91 = c;
    func_06899E48((struct Q *)o, func_0689A030, (void (*)(void))func_0689A76C);
}


void func_06899F00(Obj *o, int a, u8 b, int c)
{
    o->f6c = a;
    o->f70 = c;
    o->f98 = 0;
    o->f8b = b;
    func_06899E48((struct Q *)o, func_0689A030, (void (*)(void))func_0689A84C);
}

/*
 * Unlabelled setter follower at 06899F40 lies inside the handed extent.
 */
u32 func_06899F28(u8 *p) {
 if(func_06899E68((Q *)p)) return ((struct Obj21889 *)p)->f98;
 return 0;
}

void func_06899F40(u8 *p, void *a, void *b) {
 ((struct Obj07912 *)p)->f6C=a;
 ((struct Obj07912 *)p)->f70=b;
 ((struct Obj07912 *)p)->f98=0;
 ((struct Obj07912 *)p)->f68=(void *)func_0689A988;
 func_06899E48((struct Q *)p,(void *)func_0689A878,(void *)func_0689A988);
}


void func_06899F64(u8 *s, u8 *a, void *b)
{
    ((struct Obj07913 *)s)->f98 = 0;
    *(u8 * *)&((struct Obj07913 *)s)->f7C = a;
    ((struct Obj07913 *)s)->f70 = b;
    ((struct Obj07913 *)s)->f68 = (void *)func_0689ABA0;
    func_06899FA4(b);
    func_06899FB4(a + 0x18);
    func_06899FC4(a + 0x1c);
    func_06899E48((struct Q *)s, (void *)func_0689AB48, (void *)func_0689ABA0);
}
