/*
 * file:     scrcmd_screeneffects_p21.c
 * unit:     yes
 * function: func_021B09EC, func_021B0A40
 * address:  0x021B09EC
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
 *   func_0216D88C  0x0216D88C  thumb  ov010
 */
struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct T { int a; int b; int c; } T;

typedef struct Q { int f0; int f4; int f8; } Q;

extern void func_0216D88C(const struct Actor *a, struct VecFx32 *t);
void func_021B09EC(int sel, int *a, int *b);
int func_021B0A40(u32 a, Q *q);

void func_021B09EC(int sel, int *a, int *b)
{
    *a = 0;
    *b = 0;
    switch (sel) {
    case 3:
        *b = 7;
        break;
    case 4:
        *a = 1;
        *b = 5;
        break;
    case 5:
        *b = 8;
        break;
    case 6:
        *a = 1;
        *b = 6;
        break;
    case 2:
        *a = 1;
        break;
    case 1:
        break;
    case 0:
        *a = 1;
        *b = 2;
        break;
    }
}


int func_021B0A40(u32 a, Q *q)
{
    T t;
    int r = 2;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&t);
    if (q->f8 < t.c)
        r = 1;
    return r;
}
