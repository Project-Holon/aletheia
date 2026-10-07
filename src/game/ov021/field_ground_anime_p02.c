/*
 * file:     field_ground_anime_p02.c
 * unit:     yes
 * function: func_021A7410, func_021A7418, func_021A7420, func_021A7484, func_021A74C0
 * address:  0x021A7410
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
 *   func_021A753C  0x021A753C  thumb  ov021
 *   func_021A75B0  0x021A75B0  thumb  ov021
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0206E9A4  0x0206E9A4  arm
 *   func_02030734  0x02030734  arm
 *   func_021A7508  0x021A7508  thumb  ov021
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *   func_021A752C  0x021A752C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021A75BC  0x021A75BC  thumb  ov021
 */
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 w[3];
} E;

typedef struct {
    E *arr;
    u32 n;
    void *p8;
} S;

extern u32 func_021A753C(struct Ctx *s, u32 b, u32 c, u32 d);
extern void func_021A75B0(u32 *p);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u8 *func_0206E9A4(u8 *p, u32 idx);
extern void *func_02030734(u32 heap, u32 size, int one, const char *file, u16 line);
extern void func_021A7508(u32 a, u32 b, u32 c);
extern int func_021A752C(u32 a);
extern u32 func_020307B0(void *p);
extern u32 func_021A75BC(u32 p, u32 t);
int func_021A7410(u32 a, u32 b, u32 c, u32 d);
void func_021A7418(void *p);
void func_021A7420(u32 *s, u32 a, u32 b, u32 n, u32 heap);
void func_021A7484(S *s);
void func_021A74C0(u32 *s, u32 dt);
extern char d_021DDF7C;


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A7410(u32 a, u32 b, u32 c, u32 d)
{
return func_021A753C((struct Ctx *)a, b, c, d);
}


/*
 * Tail-call thunk: forwards to func_021A75B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A7418(void *p)
{
    func_021A75B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A7420(u32 *s, u32 a, u32 b, u32 n, u32 heap)
{
    u32 i;
    u32 h;
    i = 0;
    s[2] = func_0204A1BC(a, b, 0, heap);
    h = (u32)func_0206E9A4((u8 *)s[2], 0);
    s[0] = (u32)func_02030734(heap, n * 12, 1, &d_021DDF7C, 0x196);
    s[1] = n;
    for (i = 0; i < s[1]; i++)
        func_021A7508(s[0] + i * 12, h, heap);
}


void func_021A7484(S *s)
{
    u32 i;
    if (s->p8 != 0) {
        for (i = 0; i < s->n; i++) {
            func_021A752C((u32)(&s->arr[i]));
        }
        func_020307B0(s->arr);
        s->arr = 0;
        func_020307B0(s->p8);
        s->p8 = 0;
    }
}


void func_021A74C0(u32 *s, u32 dt)
{
    u32 i;
    s[3] += dt;
    if (s[2] != 0) {
        for (i = 0; i < s[1]; i++)
            s[3] = func_021A75BC(s[0] + i * 12, s[3]);
    }
}
