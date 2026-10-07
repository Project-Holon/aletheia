/*
 * file:     field_place_name_p02.c
 * unit:     yes
 * function: func_021BBFB0, func_021BBFB4, func_021BBFB8
 * address:  0x021BBFB0
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
 *   d_021D9B64  0x021D9B64  data
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Arg { u32 a; u32 b; u32 c; u32 d; u32 e; } Arg;

extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
void func_021BBFB0(void);
void func_021BBFB4(void *p);
void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
extern u8 d_021D9B64[];


/*
 * An empty function.
 */
void func_021BBFB0(void)
{
}


void func_021BBFB4(void *p)
{
}


void func_021BBFB8(u32 a, u32 b, u32 c, u32 d)
{
    Arg s;

    s.b = d;
    s.c = b;
    s.d = a;
    s.e = func_0219C9DC((u8 *)func_0216D520((void *)a));
    s.a = func_021ABEA0(c, 6);
    func_021ABFA8(c, d_021D9B64, 0, 0, &s, 0);
}
