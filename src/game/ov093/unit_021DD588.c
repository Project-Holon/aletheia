/*
 * file:     unit_021DD588.c
 * unit:     yes
 * function: func_021DD588, func_021DD608, func_021DD614, func_021DD624, func_021DD63C, func_021DD648, func_021DD658, func_021DD670, func_021DD67C, func_021DD68C, func_021DD6A4, func_021DD6B0, func_021DD6C0, func_021DD6D8, func_021DD6E4, func_021DD6F4, func_021DD70C, func_021DD744, func_021DD77C, func_021DD7B8, func_021DD870
 * address:  0x021DD588
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
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   d_021F1C2C 0x021F1C2C data a4
 *   d_021F1C54 0x021F1C54 data a4
 *   d_021F1C7C 0x021F1C7C data a4
 *   d_021F1CA4 0x021F1CA4 data a4
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_020189D0  0x020189D0  thumb
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   d_021F1C04     0x021F1C04  data   ov093  a4
 *   d_021F1CCC     0x021F1CCC  data   ov093  a4
 */
#include "../../matched/include/Obj12151.h"
#include "../../matched/include/Obj07817.h"

struct S;
struct QQ;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
int func_021DCFF8(int a, int b);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);
extern u16 func_021D70A8(struct QQ *p);
int func_0209C2B0(int a, int b);
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern void func_021DDE30(int, int, int, int, int);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
extern int func_021D7B74(u8 *p, u32 k);
extern void *func_021D5844(void *m);
extern int func_020189D0(void *m, int b);
extern void func_021D7DC0(int a, void *b, void *out);
void func_021DD588(void *a, int b, int c);
int *func_021DD608(int *p);
void func_021DD614(int a, u8 *b, int c, int *d);
void func_021DD624(int a, u8 *b, int c, int *d);
void *func_021DD63C(int *p);
void func_021DD648(int a, u8 *b, int c, int *d);
void func_021DD658(int a, u8 *b, int c, int *d);
void *func_021DD670(int *p);
void func_021DD67C(int a, u8 *b, int c, int *d);
void func_021DD68C(int a, u8 *b, int c, int *d);
void *func_021DD6A4(int *p);
void func_021DD6B0(int a, u8 *b, int c, int *d);
void func_021DD6C0(int a, u8 *b, int c, int *d);
void *func_021DD6D8(int *p);
void func_021DD6E4(int a, u8 *b, int c, int *d);
void func_021DD6F4(int a, void *b, int c, int *d);
void func_021DD70C(int a, void *b, int c, int *d);
void func_021DD744(int a, void *b, int c, int *d);
void func_021DD77C(int a, void *b, int c, int *d);
void func_021DD7B8(int a, u8 *b, int c, int *d, int e);
int *func_021DD870(int *p);
extern u8 d_021F1C2C[];
extern u8 d_021F1C54[];
extern u8 d_021F1C7C[];
extern u8 d_021F1CA4[];
extern int d_021F1C04[];
extern int d_021F1CCC[];


void func_021DD588(void *a, int b, int c)
{
    void *p;
    int m;
    u8 v;

    if (c != func_021D775C(2))
        return;
    m = func_021D59B4(func_021C7CF4((int *)b, c), 0xe);
    v = (u8)func_021DCFF8((int)a, 2);
    p = func_021C88A4((char *)b, 5, c);
    ((struct Obj12151 *)p)->f6 = c;
    ((struct Obj12151 *)p)->f4 = func_0209C2B0(m * v, 0x64);
    func_021C8838((u8 *)p + 8, 2, 0xe3 << 2);
    func_021C8860((struct S *)((u8 *)p + 8), c);
    func_021C8860((struct S *)((u8 *)p + 8), func_021D70A8(a));
    func_021C88C8((void *)b, p);
}


int *func_021DD608(int *p)
{
    *p = 5;
    return d_021F1C04;
}


/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DD614(int a, u8 *b, int c, int *d) { func_021DD7B8(a, b, c, d, 0); }










void func_021DD624(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 0);
}










void *func_021DD63C(int *p) { *p = 5; return d_021F1C2C; }









/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DD648(int a, u8 *b, int c, int *d) { func_021DD7B8(a, b, c, d, 1); }








void func_021DD658(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 1);
}








void *func_021DD670(int *p) { *p = 5; return d_021F1C54; }







/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DD67C(int a, u8 *b, int c, int *d) { func_021DD7B8(a, b, c, d, 2); }






void func_021DD68C(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 2);
}






void *func_021DD6A4(int *p) { *p = 5; return d_021F1C7C; }





/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DD6B0(int a, u8 *b, int c, int *d) { func_021DD7B8(a, b, c, d, 3); }




void func_021DD6C0(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 3);
}




void *func_021DD6D8(int *p) { *p = 5; return d_021F1CA4; }



/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021DD7B8; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DD6E4(int a, u8 *b, int c, int *d) { func_021DD7B8(a, b, c, d, 4); }




/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
void func_021DD6F4(int a, void *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 4);
}





void func_021DD70C(int a, void *b, int c, int *d)
{
    if (*d == 0 && func_021D62C4(func_021C7CF4(b, c), 15) == 0) func_021DDE30(a, (int)b, c, 2, 1);
}





void func_021DD744(int a, void *b, int c, int *d)
{
    if (*d == 0 && func_021D62C4(func_021C7CF4(b, c), 15) == 0) func_021DDE30(a, (int)b, c, 2, 0);
}





void func_021DD77C(int a, void *b, int c, int *d)
{
    if (*d == 0 && func_021D62C4(func_021C7CF4(b, c), 15) == 0 && func_021DDEA4(b, c, 2) != 0) func_021DD044((void *)a, b, c);
}





void func_021DD7B8(int a, u8 *b, int c, int *d, int e)
{
    void *m;
    u8 *p;
    if (*d == 0 && c == func_021D775C(2)) {
        m = func_021C7CF4((int *)b, c);
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        *(u16 *)&((struct Obj07817 *)p)->f4 = func_021D7B74(m, func_021DCFF8(a, 2));
        func_021C8838(p + 8, 2, 908);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8((void *)a));
        func_021C88C8(b, p);
        if (func_020189D0(func_021D5844(m), e) == -1) {
            p = func_021C88A4((char *)b, 0xc, c);
            p[0xf] = c;
            ((struct Obj07817 *)p)->f4 = 6;
            func_021D7DC0(6, m, p + 8);
            func_021C88C8(b, p);
        }
        *d = 1;
    }
}


int *func_021DD870(int *p)
{
    *p = 5;
    return d_021F1CCC;
}
