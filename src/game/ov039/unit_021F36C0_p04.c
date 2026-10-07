/*
 * file:     unit_021F36C0_p04.c
 * unit:     yes
 * function: func_021F4740, func_021F47D8
 * address:  0x021F4740
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4894  0x021F4894  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021F3DE4  0x021F3DE4  thumb
 *   func_021F3E04  0x021F3E04  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B4  0x021BE6B4  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */
struct Big;
struct Ctx;
struct Rec94;
typedef unsigned int u32;

typedef unsigned char u8;

typedef signed char s8;

typedef signed int     s32;

typedef unsigned short u16;

extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021F4894(void *p, int i, u8 j);
extern int func_021F3DE4(void *p, u16 delta, u16 i);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern void func_021BE700(void *a, int b, int c, int d, int e);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern u8 func_021BE6B4(u8 *p);
extern void func_021BE6B0(u8 *p, int v);
void func_021F4740(u32 a, void *b);
void func_021F47D8(void *a, int f, int i);


void func_021F4740(u32 a, void *b)
{
    s8 *p;
    u8 *q;
    u8 *arr;
    u8 v;
    s8 i;

    p = (s8 *)func_021897BC((char *)a, 1);
    q = (u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 2);
    i = p[5];
    if (i == -1) {
        return;
    }
    arr = q + 0x10;
    v = arr[i];
    arr[i] = (v + 1) % 2;
    if (func_021F4894(b, (u8)i, *((u8 *)p + p[5] + 0x21EC)) != 0) {
        func_021F47D8(b, v, (u8)p[5]);
        i = p[5];
        *((u8 *)p + i + 0x21EC) = i * 2 + *(u8 *)(q + i + 0x10);
    } else {
        u8 *r = (u8 *)p + 0x21E8;

        i = p[5];
        if (r[i] != 0) {
            r[i] = 0;
        } else {
            r[i] = 1;
        }
    }
}


void func_021F47D8(void *a, int f, int i)
{
    u8 r7;
    u8 r6;
    u8 r4;
    u8 v;
    int d;

    if (f == 0) {
        r7 = i * 2 + 1;
        r6 = r7 + 1;
    } else {
        r6 = i * 2 + 1;
        r7 = r6 + 1;
    }
    r4 = i;
    d = func_021F3DE4(a, r4, r7);
    func_021BE700(a, 0, r4, r7, 0);
    func_021BE700(a, 0, r4, r6, 1);
    func_021F3E04(a, r4, r6, d);
    v = func_021BE6B4(func_021BE674(a, 0, r4, r7));
    func_021BE6B0(func_021BE674(a, 0, r4, r6), v);
}
