/*
 * file:     btl_server_p21.c
 * unit:     yes
 * function: func_021CBA40, func_021CBB34, func_021CBCF4, func_021CBD48, func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50, func_021CBF60, func_021CBF70, func_021CBF80, func_021CBF90, func_021CBFA0
 * address:  0x021CBA40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8778 0x021B8778 thumb ov093
 *   func_021B98A4 0x021B98A4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D6E24 0x021D6E24 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02019C90 0x02019C90 thumb
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_020111BC 0x020111BC thumb
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   func_021D78AC 0x021D78AC thumb ov093
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B873C  0x021B873C  thumb  ov093
 *   func_021D5814 0x021D5814 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_020113F0 0x020113F0 thumb
 *   func_021CBE98 0x021CBE98 thumb ov093
 *   _fflt 0x0209BDBC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021CC350   0x021CC350  thumb
 *   func_021CC398   0x021CC398  thumb
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj02784.h"
#include "../../matched/include/Obj09980.h"

struct Unk021B8CB0;
struct QF;
struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed long long s64;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *);
extern void *func_021B86B8(void ***p);
extern int func_021B8724(char *p, void *m);
extern void func_021D6E24(void **p, int value);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D59B4(u8 *p, int k);
extern int func_021BA1A8(char **p, int m);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_020111BC(int);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 func_021D78AC(u32);
extern u32 func_021B873C(char **p);
extern int func_021D5814(void *,int);
extern char *func_021B8714(char **);
extern int func_020113F0(int row, int col);
extern int func_021CBE98(u16);
extern unsigned char func_021B9A40(unsigned int x);
extern Word func_021E8940(int v);
extern int func_021CBFF8(int a, int b, Word c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
int func_021CBA40(u8 *p, void *a, u16 b);
int func_021CBB34(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag);
u32 func_021CBCF4(u8 *p);
int func_021CBD48(u8 *p, void *unused, void *q, int k);
int func_021CBEA8(u8 *p, int x);
void func_021CBF30(int a, int b, int c, int d);
void func_021CBF40(int a, int b, int c, int d);
void func_021CBF50(int a, int b, int c, int d);
void func_021CBF60(int a, int b, int c, int d);
void func_021CBF70(int a, int b, int c, int d);
void func_021CBF80(int a, int b, int c, int d);
void func_021CBF90(int a, int b, int c, int d);
int func_021CBFA0(u8 *p, u8 *q);


/*
 * lever: Separate six-byte selection and two-byte output arrays reproduce
 * the unaligned stack base; a u16 third parameter pins its early home store.
 */
int func_021CBA40(u8 *p, void *a, u16 b)
{
    void *m = 0;
    u8 chosen = 6;
    u8 buf[6];
    u8 out[2];
    u8 count;
    u8 i;
    u8 result;
    u8 flag;
    count = func_021B8778(((struct Obj02784 *)p)->f4, (unsigned short)((chosen << 8) | func_021B8D8C(((struct Obj02784 *)p)->f4, ((struct Obj02784 *)p)->f8, func_021D5440(a))), buf);
    for (i = 0; i < count; i++) {
        m = func_021B98A4(*(char *const * *)&((struct Obj02784 *)p)->f8, buf[i]);
        if (!func_021D5B68(m)) { chosen = buf[i]; break; }
    }
    if (!func_021B86B8(((struct Obj02784 *)p)->f4)) {
        if (chosen != 6) {
            result = func_021CBB34(p, a, m, b, &out[1], &out[0]);
            if (result) {
                ((struct Obj02784 *)p)->f14 = 6;
                p[0x784] = chosen;
                flag = func_021B8724(((struct Obj02784 *)p)->f4, m) == 0 ? 1 : 0;
                func_021D6E24(m, b);
            } else { flag = 0; }
            func_021CD4B0(((struct Obj02784 *)p)->fC, 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) func_021CD4B0(((struct Obj02784 *)p)->fC, 0x47, chosen, b);
    return 0;
}


/*
 * lever: A u16 mode homes its spill early; named u16 form avoids an
 * argument copy. Ternary count selection shares the flag read across
 * the preceding threshold branch and settles the register allocation.
 */
int func_021CBB34(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag)
{
    u32 a, t;
    int rate, factor, v;
    u32 count, i;
    u16 species, form;
    *flag = 0;
    if (mode == 1) { *out = 3; return 1; }
    a = func_021D59B4((void *)m, 14) * 3;
    t = a - func_021D59B4((void *)m, 13) * 2;
    v = (int)(t != 0 ? 0.5f + (float)(t << 12) : (float)(t << 12) - 0.5f);
    if (func_021BA1A8(((struct Obj09980 *)p)->f4, 32)) {
        factor = func_021CBCF4(p);
        v = ((s64)v * factor + 0x800) >> 12;
    }
    species = func_021D5444((void *)m);
    form = func_021D59B4((void *)m, 19);
    v *= (u16)func_02019C90(species, form, 8);
    factor = func_021CBD48(p, q, (void *)m, mode);
    v = ((s64)v * factor + 0x800) >> 12;
    v = (u32)v / a;
    switch (func_021D62A8((void *)m)) {
    case 2: case 3: v = ((s64)v * 0x2800 + 0x800) >> 12; break;
    case 1: case 4: case 5: v = ((s64)v * 0x1800 + 0x800) >> 12; break;
    }
    rate = func_020111BC(v);
    *flag = func_021CBEA8(p, rate);
    if (rate >= 0xff000) { *out = *flag ? 1 : 3; return 1; }
    count = *flag ? 1 : 3;
    rate = FX_Div(0x10000000, FX_Sqrt(FX_Sqrt(FX_Div(0xff000, rate)))) >> 12;
    *out = 0;
    for (i = 0; i < count; i++) {
        if (func_021D78AC(0x10000) < (u32)rate) (*out)++;
        else return 0;
    }
    return 1;
}



u32 func_021CBCF4(u8 *p)
{
    u32 v = func_021B873C(*(char ** *)&((struct Obj09980 *)p)->f4);
    if (v > 600) return 0x1000;
    if (v > 450) return 0xe66;
    if (v > 300) return 0xccd;
    if (v > 150) return 0xb33;
    if (v > 30) return 0x800;
    return 0x4cd;
}


/*
 * outside covered regions. Its call has no external witness; tu split
 * census reports zero witnesses and no viable partition. The trailing
 * 16 bytes are that veneer, not compiled C.
 */
int func_021CBD48(u8 *p, void *unused, void *q, int k)
{
    u16 n;
    float f;
    int value;
    u8 flag;
    switch (k) {
    case 3: return 0x1800;
    case 2: return 0x2000;
    case 6:
        if (func_021D5814(q,10) || func_021D5814(q,6)) return 0x3000;
        break;
    case 7:
        if (func_021BA1A8(*(void **)(p+4),1)) return 0x3800;
        if (*(int *)(func_021B8714(*(char ***)(p+4))+4) == 6) return 0x3800;
        break;
    case 8:
        n = func_021D59B4(q,15);
        if (n < 30) {
            n = 41 - n;
            if (n > 40) n = 40;
            if (n != 0) f = 0.5f + (float)(n << 12);
            else f = (float)(n << 12) - 0.5f;
            return (int)f / 10;
        }
        break;
    case 9:
        if (func_021B8724(*(void **)(p+4),q)) return 0x3000;
        break;
    case 10:
        value = *(int *)(p+0x10)*0x4cd+0x1000;
        if (value > 0x4000) value = 0x4000;
        return value;
    case 13:
        p = (u8 *)func_021B8714(*(char ***)(p+4));
        flag = func_020113F0(p[9],p[12]);
        if ((unsigned)(*(int *)p - 4) <= 1) return 0x3800;
        if (func_021CBE98(*(int *)p)) {
            if ((u8)(flag + 253) <= 1) return 0x3800;
        }
        break;
    case 15:
        if (*(int *)(p+0x10) == 0) return 0x5000;
        break;
    default: break;
    }
    return 0x1000;
}





/*
 * note:     the divide by 6 belongs to the fixed-point multiply's statement
 *           (`x = FX_MUL(x, k) / 6;`); the `>> 12` goes inside the compare.
 *           A separate `q = x / 6;` statement lets the compiler move the
 *           divide after the call, and a separate shift statement moves the
 *           shift before it.
 */
int func_021CBEA8(u8 *p, int x)
{
    u32 v = func_021B873C(*(char ** *)&((struct Obj09980 *)p)->f4);
    int k;
    if (v > 600) k = 0x2800;
    else if (v > 450) k = 0x2000;
    else if (v > 300) k = 0x1800;
    else if (v > 150) k = 0x1000;
    else if (v > 30) k = 0x800;
    else return 0;
    if (x > 0xff000) x = 0xff000;
    x = (int)(((long long)x * k + 0x800) >> 12) / 6;
    if (func_021D78AC(256) < (u32)(x >> 12))
        return 1;
    return 0;
}





/* 021CBF30  stack-arg wrapper: func_021CC350(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF30(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x2); }





/* 021CBF40  stack-arg wrapper: func_021CC350(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF40(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x5); }





/* 021CBF50  stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF50(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x4); }





/* 021CBF60  stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF60(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x3); }





/* 021CBF70  stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF70(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x1); }





/* 021CBF80  stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF80(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x6); }




/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF90(int a, int b, int c, int d) { func_021CC398(a, b, c, d, 0x7); }




int func_021CBFA0(u8 *p, u8 *q)
{
    int m;
    u8 *w;
    Word t;
    m = func_021B9A40(func_021D5440(q));
    t = func_021E8940(5);
    if (func_021CBFF8(m, 3, t)) {
        w = func_021C88A4((char *)p, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S *)(w + 4), m);
        func_021C88C8(p, w);
        return 1;
    }
    return 0;
}
