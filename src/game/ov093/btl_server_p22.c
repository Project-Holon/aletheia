/*
 * file:     btl_server_p22.c
 * unit:     yes
 * function: func_021CC008, func_021CC098, func_021CC0A8, func_021CC0B8, func_021CC0C8, func_021CC0D8, func_021CC0E8, func_021CC0F8, func_021CC178, func_021CC214, func_021CC2C0, func_021CC350, func_021CC398
 * address:  0x021CC008
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C84E0  0x021C84E0  thumb  ov093
 *   func_021CC438   0x021CC438  thumb
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D5FE4  0x021D5FE4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D5F38  0x021D5F38  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D5450  0x021D5450  thumb  ov093
 *   func_021D5568  0x021D5568  thumb  ov093
 *   func_021D54D0  0x021D54D0  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021CC418  0x021CC418  thumb  ov093
 *   func_021CC428  0x021CC428  thumb  ov093
 */
#include "../../matched/include/Obj06229.h"
#include "../../matched/include/Obj09981.h"
#include "../../matched/include/Obj05195.h"
#include "../../matched/include/Obj09983.h"

struct S;
struct UtilWork;
struct Work;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Rec {
    int f00;
    u32 f04;
    u8 f08;
    u8 pad[11];
    u8 f14;
} Rec;

extern int func_021D5B68(void *p);
extern u8 func_021D5440(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern void func_021C84E0(unsigned char *p, unsigned int v);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D5F38(struct S *p, int n);
extern void func_021CD64C(void *w, u8 id, ...);
extern u8 func_021D5450(struct Work *p);
extern u8 func_021D5568(u8 *p, u32 i);
extern u32 func_021D54D0(u8 *p, u8 i);
extern int func_021D5B48(u8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021CC418(void *p, int id);
extern u32 func_021CC428(int i);
int func_021CC008(u8 *p, u8 *q, u16 s);
void func_021CC098(int a, int b, int c, int d);
void func_021CC0A8(int a, int b, int c, int d);
void func_021CC0B8(int a, int b, int c, int d);
void func_021CC0C8(int a, int b, int c, int d);
void func_021CC0D8(int a, int b, int c, int d);
void func_021CC0E8(int a, int b, int c, int d);
int func_021CC0F8(char *p, void *m, int c, int n);
int func_021CC178(void *a, void *m, void *s, int d, u8 n);
int func_021CC214(void *a, void *m, void *s);
int func_021CC2C0(void *a, void *m, void *s);
int func_021CC350(void *a, void *m, int c, int d, u32 v);
int func_021CC398(char *p, void *m);




/*
 * The switch stores into w+6 in every arm (as func_021CC2C0 does), which
 * lays the arms out as the original has them; the default arm calls
 * func_021D805C again. s is narrow: as u32 (or a pointer, as the sibling
 * handlers func_021CC2C0/CC178/CC214 declare it) its `ldr r0,[sp]` reload
 * is hoisted above `strb r7,[r4,#4]`; u16 and u8 both keep it below.
 * Nothing in the image fixes the width; u16 chosen. The function sits in
 * the handler table at 0x021EFE28.
 */
int func_021CC008(u8 *p, u8 *q, u16 s)
{
    int id;
    u8 *w;
    u32 r;
    if (func_021D5B68(q)) {
        id = func_021D5440(q);
        w = func_021C88A4((char *)p, 0x2c, id);
        w[4] = id;
        r = func_021D805C((void *)s, 0x3a);
        switch (r) {
        case 0xff:
            ((struct Obj06229 *)w)->f6 = func_021D59B4(q, 0xe);
            break;
        case 0xfe:
            ((struct Obj06229 *)w)->f6 = func_021D7B74(q, 2);
            break;
        case 0xfd:
            ((struct Obj06229 *)w)->f6 = func_021D7B74(q, 4);
            break;
        default:
            ((struct Obj06229 *)w)->f6 = func_021D805C((void *)s, 0x3a);
            break;
        }
        func_021C8838(w + 8, 2, 3);
        func_021C8860((struct S *)(w + 8), id);
        func_021C88C8(p, w);
        func_021C84E0(p, id);
        return 1;
    }
    return 0;
}




/* 021CC098  stack-arg wrapper: func_021CC438(a, b, c, d, 0x1) */
void func_021CC098(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x1); }




/* 021CC0A8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0A8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x2); }




/* 021CC0B8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0B8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x3); }




/* 021CC0C8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0C8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x4); }




/* 021CC0D8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0D8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x5); }




/* 021CC0E8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0E8(int a, int b, int c, int d) { func_021CC438(a, b, c, d, 0x6); }




int func_021CC0F8(char *p, void *m, int c, int n)
{
    int flag;

    flag = 0;
    if (func_021D5BDC(m, 9) == 0) {
        func_021D5FE4(m, 9);
        func_021CD4B0(((struct Obj09981 *)p)->fC, 0x19, func_021D5440(m), 9);
        flag = 1;
    }
    if (n > 1) {
        if (func_021D5F38(m, n - 1) != 0) {
            func_021CD4B0(((struct Obj09981 *)p)->fC, 0xe, func_021D5440(m), n - 1);
            flag = 1;
        }
    }
    if (flag) {
        func_021CD64C(((struct Obj09981 *)p)->fC, 0x5b, 0x411, func_021D5440(m), 0xffff0000);
        return 1;
    }
    return 0;
}




int func_021CC178(void *a, void *m, void *s, int d, u8 n)
{
    u8 id;
    u32 cnt;
    u32 lim;
    u8 *r;

    if (func_021D5450(m) > n) {
        id = func_021D5440(m);
        cnt = func_021D5568(m, n);
        lim = (u8)func_021D805C(s, 0x3b);
        if (lim != 0x7f && cnt > lim)
            cnt = lim;
        if (cnt != 0) {
            r = (u8 *)func_021C88A4(a, 9, id);
            r[4] = cnt;
            r[5] = id;
            r[6] = n;
            r[7] |= 2;
            func_021C8838(r + 8, 2, 390);
            func_021C8860((struct S *)(r + 8), id);
            func_021C8860((struct S *)(r + 8), func_021D54D0(m, n));
            func_021C88C8(a, r);
            return 1;
        }
    }
    return 0;
}




int func_021CC214(void *a, void *m, void *s)
{
    u8 id;
    u32 n;
    int ok;
    u32 lim;
    u32 c;
    u32 i;
    u8 *r;

    id = func_021D5440(m);
    lim = (u8)func_021D805C(s, 0x3b);
    ok = 0;
    n = func_021D5450(m);
    for (i = 0; i < n; i++) {
        c = (u32)func_021D5568(m, (u8)i);
        if (c > lim)
            c = lim;
        if (c != 0) {
            r = (u8 *)func_021C88A4(a, 9, id);
            r[6] = i;
            r[5] = id;
            r[4] = c;
            r[7] |= 2;
            func_021C88C8(a, r);
            ok = 1;
        }
    }
    if (ok) {
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, 393);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
    }
    return ok;
}



int func_021CC2C0(void *a, void *m, void *s)
{
    int id;
    u8 *r;
    u32 k;

    if (func_021D5B48(m) == 0 && func_021D5B68(m) == 0) {
        id = func_021D5440(m);
        r = (u8 *)func_021C88A4(a, 5, id);
        r[6] = id;
        r[7] = 1;
        k = func_021D805C(s, 0x3a);
        switch (k) {
        case 0xff:
            ((struct Obj05195 *)r)->f4 = func_021D59B4(m, 14);
            break;
        case 0xfe:
            ((struct Obj05195 *)r)->f4 = func_021D7B74(m, 2);
            break;
        case 0xfd:
            ((struct Obj05195 *)r)->f4 = func_021D7B74(m, 4);
            break;
        default:
            ((struct Obj05195 *)r)->f4 = k;
            break;
        }
        func_021C8838(r + 8, 2, 387);
        func_021C8860((struct S *)(r + 8), id);
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}



int func_021CC350(void *a, void *m, int c, int d, u32 v)
{
    u8 id;
    Rec *r;

    if (func_021D5B68(m) == 0 && func_021D62C4(m, v) != 0) {
        id = func_021D5440(m);
        r = (Rec *)func_021C88A4(a, 11, id);
        r->f14 = 1;
        r->f08 = id;
        r->f04 = v;
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}



int func_021CC398(char *p, void *m)
{
    u32 k;
    int ret;
    int id;
    u8 *r;
    int i;

    if (func_021D5B68(m) == 0) {
        if (func_021CC418(p + 0x1ab8, func_021D5440(m)) == 0) {
            ret = 0;
            i = 0;
            for (;;) {
                k = func_021CC428(i++);
                if (k == 0)
                    break;
                if (func_021D62C4(m, k) != 0) {
                    id = func_021D5440(m);
                    r = (u8 *)func_021C88A4(p, 11, id);
                    r[0x14] = 1;
                    r[8] = id;
                    ((struct Obj09983 *)r)->f4 = k;
                    func_021C88C8(p, r);
                    ret = 1;
                }
            }
            return ret;
        }
    }
    return 0;
}
