/*
 * file:     field_effect_p05.c
 * unit:     yes
 * function: func_021A9080, func_021A90A4
 * address:  0x021A9080
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
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021A8E78  0x021A8E78  thumb
 */
struct Obj;
struct Vec2;
typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0x124];
    int f124;
    int pad128[3];
    int f134;
} S_021A9080;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    int pad0;
    int f0;
    int pad8[5];
} E;

typedef struct {
    int pad0[3];
    int fc;
    int pad10[3];
    char pad1c[2];
    u8 b1e;
    u8 b1f;
    int pad20[2];
    int f28;
    int pad2c;
    int f30;
    int pad34;
    E e[7];
    char padfc[0x128 - 0xfc];
    int f128;
} S_021A90A4;

typedef unsigned short u16;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021A8E78(u32 a, u32 b);
void func_021A9080(S_021A9080 *s, s16 x, s16 y);
void func_021A90A4(S_021A90A4 *s, int m);


void func_021A9080(S_021A9080 *s, s16 x, s16 y)
{
    P v;
    v.x = x;
    v.y = y;
    func_0204B404((struct Obj *)s->f124, (const struct Vec2 *)(&v), 0);
    s->f134 = 0;
}


void func_021A90A4(S_021A90A4 *s, int m)
{
    if (m == 1) {
        s->f28 = 1;
        s->fc = 4;
        func_0204B878((struct Obj *)s->f128, 8);
    } else {
        s->f28 = 0;
        s->fc = 5;
        s->f30 = s->e[func_021A8E78(s->b1e, s->b1f)].f0;
    }
}
