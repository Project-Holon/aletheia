/*
 * file:     unit_021743B4_p01.c
 * unit:     yes
 * function: func_021743B4, func_021743E4, func_0217440C, func_0217443C, func_0217446C, func_0217449C, func_021744D0, func_02174514, func_0217456C, func_021745B0, func_021745F8
 * address:  0x021743B4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021780FC 0x021780FC thumb ov014
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0202E7E0  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0202E7C4  0x0202E7C4  thumb
 *   func_02082D44  0x02082D44  arm
 */
struct Entry;
struct Link;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u8 low : 4; u8 flags : 2; u8 high : 2; } F93F;

typedef struct F {
    unsigned char f0 : 1;
    unsigned char f1 : 7;
} F;

u32 func_02026478(void *obj);
int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(u8 value);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D1A4(struct Link *p);
int func_02012F20(int a);
void *func_02012B38(const struct BigObj *p);
u8 func_02014484(struct Sub02014444Obj *o);
int func_0202E7E0(int a);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0202E7C4(int a, int b, int c);
void func_02082D44(void *d, void *s, int n);
int func_021743B4(char *p);
void func_021743E4(int a, int b, void *c, signed char *p);
u32 func_0217440C(void);
void func_0217443C(int a, int b, void *c, signed char *p);
u32 func_0217446C(void);
void func_0217449C(int a, int b, u8 *c, u8 *p);
int func_021744D0(int a, int b, int c, ...);
void func_02174514(int a, int b, int *c, char *d);
int func_0217456C(int a, int b, int c, ...);
void func_021745B0(int a, int b, void *c, char *d);
int func_021745F8(u32 a, u32 b);

int func_021743B4(char *p)
{
    func_02026478((void *)(((int *)p)[1]));
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x21d, 4, (u32)(p + 0x354));
}

void func_021743E4(int a, int b, void *c, signed char *p)
{
    p[0x93d]++;
    if (p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        func_021780FC(1);
    }
}

u32 func_0217440C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21e, 0, 0, 0, 0, 0);
}

void func_0217443C(int a, int b, void *c, signed char *p)
{
    p[0x93d]--;
    if (p[0x93d] == 0 && p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), (void *)1);
        func_021780FC(0);
    }
}

u32 func_0217446C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21f, 0, 0, 0, 0, 0);
}

/*
 * extent: existing follower ov011_func_021744D0.c stays separate.
 */
void func_0217449C(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        ((F93F *)(p + 0x93f))->flags |= *c;
    }
}


/*
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 */
int func_021744D0(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x220, 1, (u32)(&c), 0, 0, 0);
}


/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; only unresolved relocations are arm9 leaves 0x0202E7E0 and 0x0202E7C4 (no witness outside range). Needs labels seeded. Source is byte-correct; no C change possible.
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (Ilias's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 */
void func_02174514(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = func_02026478((void *)(((int *)d)[1]));
    q = func_02012F20(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        if (func_02014484(func_02012B38((const struct BigObj *)p)) == 1) {
            t = func_0202E7E0(q);
            if (t == 0 || t == 3) {
                func_0202E7C4(q, *c, (int)func_02012950((struct Sub24 *)p, a));
            }
        }
    }
}


/*
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 */
int func_0217456C(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x221, 4, (u32)(&c), 0, 0, 0);
}


void func_021745B0(int a, int b, void *c, char *d)
{
    func_02026478((void *)(((int *)d)[1]));
    if (((unsigned char)d[0x8fb] & (1 << a)) && ((F *)(d + 0x8f8))->f0 == 0) {
        func_02082D44(c, d + 0x8e4, 0x14);
        ((F *)(d + 0x8f8))->f0 = 1;
    }
}

int func_021745F8(u32 a, u32 b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x222, 0x14, b, 0, 0, 0);
}
