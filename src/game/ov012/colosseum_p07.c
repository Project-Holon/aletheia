/*
 * file:     colosseum_p07.c
 * unit:     yes
 * function: func_021750D8, func_02175110, func_02175144, func_021751B4, func_021751DC, func_02175208, func_02175214, func_02175240, func_02175280, func_0217534C
 * address:  0x021750D8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_02174D2C 0x02174D2C thumb ov012
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02174ED8  0x02174ED8  thumb  ov012
 *   func_02174E9C  0x02174E9C  thumb  ov012
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0201A948  0x0201A948  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034714  0x02034714  arm
 *   func_02175358  0x02175358  thumb  ov012
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 */
#include "../../matched/include/Obj07341.h"

struct Entry;
struct Link;
struct Party;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { int w[5]; } E;

typedef unsigned short u16;

extern u32 func_0203D378(void);
extern int func_02174D2C(char *a, u32 b, u32 c);
extern int func_0203D1B4(void);
extern u32 func_02174ED8(void);
extern u32 func_02174E9C(int v);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_0201A948(struct Party *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02175358(u8 *a, u8 *slot, u8 i, int d);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
int func_021750D8(u8 *p, int slot, int value);
void func_02175110(u8 *p);
void func_02175144(u8 *p);
void func_021751B4(u8 *p, int i, const E *src);
int func_021751DC(char *a0, int a1, E *out);
void func_02175208(u8 *p);
int func_02175214(u8 *p);
void func_02175240(u8 *a, int b);
void func_02175280(u8 *a, void *b, u8 *out, int d);
void func_0217534C(void *p);

/*
 * Two trailing alignment bytes. Duplicated store arms preserve the branch stub.
 */
int func_021750D8(u8 *p, int slot, int value)
{
    int i;
    int result;
    if (value == 255) {
        (p+slot)[0xcc] = value;
        result = 1;
    } else {
        for (i = 0; i < 4; i++) {
            if ((p+i)[0xcc] == value) { result = 0; break; }
        }
    if (i == 4) {
        (p+slot)[0xcc] = value;
        result = 1;
    }
    }
    (p+slot)[0xd0] = result;
    return result;
}

void func_02175110(u8 *p)
{
    int i;
    if (func_0203D378()) {
        for (i=0;i<4;i++) {
            if ((p+i)[0xd0] != 255 && func_02174D2C((char *)p,i,(p+i)[0xd0]) == 1)
                (p+i)[0xd0] = 255;
        }
    }
}


void func_02175144(u8 *p)
{
    int cnt;
    int i;
    int z;

    if (func_0203D378() == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (p[0xd4 + i] == 1) {
            cnt++;
        }
    }
    if (cnt == func_0203D1B4()) {
        if (func_02174ED8() == 1) {
            z = 0;
            for (i = 0; i < 4; i++) {
                p[0xd4 + i] = z;
                p[0xd8 + i] = z;
            }
        }
    } else {
        z = 0;
        for (i = 0; i < 4; i++) {
            if (p[0xd8 + i] == 1 && func_02174E9C(i) == 1) {
                p[0xd8 + i] = z;
            }
        }
    }
}

/*
 * The flag address groups base plus index before the constant offset.
 */
void func_021751B4(u8 *p, int i, const E *src)
{
    *(E *)(p + 0xe0 + i * 20) = *src;
    (p + i)[0x130] = 1;
}


/*
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +0024. Only ov012
 * has a function start here (ov011 holds the interior of a larger function,
 * ov009 ARM data), so the ov012 shard makes that site attest as `matched`.
 * The caller's scratch buffer is u32[5] and this leaf copies exactly 0x14
 * bytes into it.
 */
int func_021751DC(char *a0, int a1, E *out)
{
    E *e = (E *)(a0 + 0xE0 + a1 * 0x14);
    u8 old;

    *out = *e;
    old = *(u8 *)(a0 + 0x130 + a1);
    *(u8 *)(a0 + 0x130 + a1) = 0;
    return old;
}


/*
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 func_0217E440.
 */
void func_02175208(u8 *p)
{
    p[0x161] = 0;
}

/*
 * Two trailing alignment bytes.
 * Caller consumes 0203D1B4's live r0 despite its filed void return.
 */
int func_02175214(u8 *p)
{
    int n = 0;
    int i;
    for (i = 0; i < 4; i++) if (p[0x158 + i] == 1) n++;
    if (n >= func_0203D1B4()) return 1;
    return 0;
}


void func_02175240(u8 *a, int b)
{
    int self;
    int i;

    self = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    for (i = 0; i < 4; i++) {
        if (b == 0 || self != i) {
            func_0201A948(*(void **)(a + i * 4 + 0x148));
        }
        a[i + 0x158] = 0;
    }
}


void func_02175280(u8 *a, void *b, u8 *out, int d)
{
    int count;
    int i;
    int v;
    int self;
    int base;
    int y;

    count = 0;
    func_02082BCC(out, 0, 0x58);
    ((struct Obj07341 *)out)->f44 = 3;
    for (i = 0; i < 4; i++) {
        if (a[0x158 + i] == 0) {
            ((struct Obj07341 *)out)->f44 = 1;
            break;
        }
        count++;
    }
    if (count != 2 && count != 4) {
        func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
    }
    self = (a + func_0203D1A4((struct Link *)((u32)func_020399A8())))[0x15C];
    for (i = 0; i < count; i++) {
        y = a[0x15C + i];
        if ((y & 1) == (self & 1)) {
            base = 0;
        } else if (((struct Obj07341 *)out)->f44 == 1) {
            base = 1;
        } else {
            base = 2;
        }
        v = base + (y >> 1);
        if (v >= count) {
            func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
        }
        func_02175358(a, out + v * 16, (u8)i, d);
    }
    ((struct Obj07341 *)out)->f54 = (int)func_02012F2C(func_020120F4(b));
}


/*
 * evidence: unlabelled Thumb tail-call leaf (ldr r3,=func_02082BCC; bx r3) after
 * func_02175280; called by the bl at 0x02174A94 in func_02174744.
 */
void func_0217534C(void *p)
{
    func_02082BCC(p, 0, 0x58);
}
