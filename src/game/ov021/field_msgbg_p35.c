/*
 * file:     field_msgbg_p35.c
 * unit:     yes
 * function: func_0218E188, func_0218E18C, func_0218E260, func_0218E284, func_0218E298, func_0218E2B4, func_0218E358
 * address:  0x0218E188
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218EC7C  0x0218EC7C  thumb ov021
 *   func_0218EC68  0x0218EC68  thumb ov021
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048B78  0x02048B78  arm
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   _ll_mul        0x0209C054  arm
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_0218F1BC  0x0218F1BC  thumb  ov021
 *   func_0218F1DC  0x0218F1DC  thumb  ov021
 */
#include "../../matched/include/Obj19558.h"
#include "../../matched/include/Obj01347.h"
#include "../../matched/include/Obj09175.h"
#include "../../matched/include/Obj00428.h"

struct Light;
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16_0218E18C;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    u8 e;
    u8 mode;
    u16 ang;
    int f;
    int g;
    int has;
    Vec v;
} Info;

typedef unsigned int   u32;

typedef signed short   s16_0218E260;

typedef signed char    s8;

typedef signed short   s16_0218E284;

typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

typedef signed short   s16_0218E298;

typedef short s16_0218E2B4;

typedef struct { int x, y, z; } V;

extern void func_0218EC7C(u8 *a, unsigned int first, ...);
extern void func_0218EC68(u8 *a, unsigned int first, ...);
extern void func_02046BE0(u32 a, u32 b);
extern int func_02048B78(struct Light *l);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *, u32, u32, u32, void *);
extern void func_0207CCA4(V *a, V *b);
extern void func_0207CEE4(int e, V *v, V *a, V *o);
extern void func_0218F1BC(u32 *a, u32 b);
extern void func_0218F1DC(u32 *a, u32 b);
int func_0218E188(unsigned char *o);
void func_0218E18C(char *p, Vec *src);
void func_0218E260(void *a, void *b);
void func_0218E284(u8 *a);
int func_0218E298(u8 *a);
void func_0218E2B4(V *a, V *out, int i, int j, int e);
void func_0218E358(u8 *a);
extern s16_0218E18C tbl_020A1B38[];
extern s16_0218E2B4 d_020A1B38[];


/*
 * Unlabelled leaf (ldr r0,[r0,#0x10]; bx lr), filed for lane S30 (callee of
 * func_021A2148).
 */
int func_0218E188(unsigned char *o)
{
    return ((struct Obj19558 *)o)->f10;
}


void func_0218E18C(char *p, Vec *src)
{
    Info info;

    func_0218E260(p, &info);
    ((struct Obj01347 *)p)->f7C = info.a << 12;
    ((struct Obj01347 *)p)->f78 = info.b;
    ((struct Obj01347 *)p)->f7A = info.c;
    ((struct Obj01347 *)p)->f80 = info.ang;
    func_0218EC7C((u8 *)p, info.g);
    func_0218EC68((u8 *)p, info.f);
    switch (info.mode) {
    case 0:
        func_02046BE0(0, 0);
        break;
    case 1:
        func_02046BE0(0, 1);
        break;
    }
    if (func_02048B78((struct Light *)(((struct Obj01347 *)p)->fC)) == 0) {
        func_02048B80((struct Light *)(((struct Obj01347 *)p)->fC), tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2]);
        func_02048B94((struct Light *)(((struct Obj01347 *)p)->fC), tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (info.has != 0) {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = src;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = src;
        *(Vec *)(p + 0x48) = *src;
        *(Vec *)(p + 0x60) = info.v;
    } else {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = 0;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = 0;
        *(Vec *)(p + 0x48) = info.v;
        ((Vec *)(p + 0x60))->x = 0;
        ((Vec *)(p + 0x60))->y = 0;
        ((Vec *)(p + 0x60))->z = 0;
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E260(void *a, void *b)
{
func_020493D4((struct ArcFile *)(((struct Obj09175 *)((u8 *)(a)))->f4), 0);
func_0204944C((struct ArcFile *)((struct Obj09175 *)((u8 *)(a)))->f4, 0, (44 * ((struct Obj09175 *)((u8 *)(a)))->f10), 44, b);
}


void func_0218E284(u8 *a)
{
    Vec3 *p = *(Vec3 * *)&((struct Obj00428 *)a)->f1C;
    if (p != 0)
        *(Vec3 *)(a + 0x48) = *p;
}


int func_0218E298(u8 *a)
{
    Vec3 *p = *(Vec3 * *)&((struct Obj00428 *)a)->f20;
    if (p != 0) {
        *(Vec3 *)(a + 0x24) = *p;
        return 1;
    }
    return 0;
}


/*
 * Builds a vector from two sin/cos table rows (fx 20.12 products), normalises it and copies it out.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E2B4(V *a, V *out, int i, int j, int e)
{
    V v;
    int x, y;
    s16_0218E2B4 p, q;
    int k;

    k = (i >> 4) * 2;
    x = d_020A1B38[k];
    y = d_020A1B38[k + 1];
    p = d_020A1B38[(j >> 4) * 2];
    q = d_020A1B38[(j >> 4) * 2 + 1];
    if (q < 0) q = -q;
    if (q < 0x200) q = 0x200;
    v.x = (int)(((long long)x * q + 0x800) >> 12);
    v.y = p;
    v.z = (int)(((long long)y * q + 0x800) >> 12);
    func_0207CCA4(&v, &v);
    func_0207CEE4(e, &v, a, &v);
    *out = v;
}


/*
 * Copies +0x48 to +0x54, updates 24-byte children, rebuilds +0x24 then copies it to +0x3c and updates children again.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E358(u8 *a)
{
    int i;

    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
    func_0218E2B4((V *)(a + 0x54), (V *)(a + 0x24), ((struct Obj00428 *)a)->f7A, ((struct Obj00428 *)a)->f78, ((struct Obj00428 *)a)->f7C);
    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
}
