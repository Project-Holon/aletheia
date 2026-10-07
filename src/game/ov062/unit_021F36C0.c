/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3738
 * address:  0x021F36C0
 * region:   ov062
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   d_021F3768     0x021F3768  data  a4
 *   d_021F3790     0x021F3790  data  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 */
struct Big;
struct Ctx;
struct Rec94;
typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_02188D2C(int *p);
extern void func_021BE760(int a, void *b, int c);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void func_021BE418(unsigned char *p, unsigned short i);
void func_021F36C0(int a);
void func_021F3738(void *p);
extern V3 d_021F3768;
extern V3 d_021F3790;


void func_021F36C0(int a)
{
    int *q;
    int s;

    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x34);
    s = func_02188D2C((int *)a);
    func_021BE760(s, &d_021F3768, 0);
    *(V3 *)func_021BE480((char *)s, 0, 0) = d_021F3790;
    func_021BE4A4((char *)s, 0, 0, 1);
    func_021BE700((void *)s, 0, 0, 0, 1);
    if (*q != 0)
        func_021BE4B4((char *)s, 0, 0, 1);
}


void func_021F3738(void *p)
{
    func_021BE418((unsigned char *)func_02188D2C(p), 0);
}
