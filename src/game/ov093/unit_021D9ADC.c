/*
 * file:     unit_021D9ADC.c
 * unit:     yes
 * function: func_021D9ADC, func_021D9B40, func_021D9BA4, func_021D9BBC, func_021D9BC8, func_021D9BEC, func_021D9BF8, func_021D9C80, func_021D9C8C, func_021D9CB0, func_021D9CBC, func_021D9CE0, func_021D9CEC, func_021D9D10, func_021D9D1C, func_021D9DA4, func_021D9DB0, func_021D9DFC, func_021D9E08, func_021D9E80, func_021D9F10, func_021D9F1C, func_021D9FB8, func_021D9FC4, func_021DA040, func_021DA04C, func_021DA0F0, func_021DA0FC, func_021DA114, func_021DA120, func_021DA138, func_021DA144, func_021DA150
 * address:  0x021D9ADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0878     0x021F0878  data   ov093  a4
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F0870     0x021F0870  data   ov093  a4
 *   d_021F0860 0x021F0860 data a4
 *   func_021D5D50   0x021D5D50  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   d_021F0868     0x021F0868  data   ov093  a4
 *   d_021F0850 0x021F0850 data a4
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   d_021F0848 0x021F0848 data a4
 *   d_021F0840 0x021F0840 data a4
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   d_021F0838     0x021F0838  data   ov093  a4
 *   func_021D78AC   0x021D78AC  thumb ov093
 *   d_021F0858     0x021F0858  data   ov093  a4
 *   func_0201BEB8   0x0201BEB8  thumb
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   d_021F0830     0x021F0830  data   ov093  a4
 *   d_021F0828     0x021F0828  data   ov093  a4
 *   func_021E85F8   0x021E85F8  thumb ov093
 *   func_021D5814   0x021D5814  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021E8CF0   0x021E8CF0  thumb ov093
 *   d_021F0820     0x021F0820  data   ov093  a4
 *   func_021E8A78   0x021E8A78  thumb ov093
 *   d_021F0818     0x021F0818  data   ov093  a4
 *   d_021F0810     0x021F0810  data   ov093  a4
 *   d_021F0808     0x021F0808  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021DA2D0 0x021DA2D0 thumb ov093
 *   func_021DA2E0 0x021DA2E0 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021B9A6C 0x021B9A6C thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C815C 0x021C815C thumb ov093
 *   d_021F0800     0x021F0800  data   ov093  a4
 *   d_021F07F8     0x021F07F8  data   ov093  a4
 */
#include "../../matched/include/Obj06251.h"
#include "../../matched/include/Obj10058.h"
#include "../../matched/include/Obj04137.h"
#include "../../matched/include/Obj06252.h"
#include "../../matched/include/Obj10059.h"
#include "../../matched/include/Obj06253.h"
#include "../../matched/include/Obj12144.h"
#include "../../matched/include/Obj07810.h"
#include "../../matched/include/Obj06254.h"

struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef union Slot { u32 raw; struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s; } Slot;

typedef struct { int x; } S;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int key, u32 val);
extern int func_021D7B74(u8 *p, u32 k);
int func_021D5D50(s8 *p, int i);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
extern Slot func_021D7D18(int);
extern int func_021C83D4(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D7DC0(int, void *, Slot *);
extern u32 func_021D78AC(u32 range);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D5B68(void *p);
int func_021E85F8(int c);
int func_021D5814(void *p, int k);
void func_021C88B4(void *a, int k, int b);
int func_021E8CF0(int k);
extern int func_021E8A78(S a);
extern u16 func_021C7D00(void *, int);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int func_021DA2D0(u16);
extern int func_021DA2E0(u16);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021B9A6C(int a, u32 b);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
void func_021D9ADC(int a, void *b, int c);
int *func_021D9B34(int *p);
void func_021D9B40(int a, void *b, int c);
int *func_021D9B98(int *p);
void func_021D9BA4(int a, int b, int c);
int *func_021D9BBC(int *p);
void func_021D9BC8(int a,int b,int c);
void *func_021D9BEC(int *p);
void func_021D9BF8(void *a, int b, int c);
int *func_021D9C80(int *p);
void func_021D9C8C(int a,int b,int c);
void *func_021D9CB0(int *p);
void func_021D9CBC(int a,int b,int c);
void *func_021D9CE0(int *p);
void func_021D9CEC(int a,int b,int c);
void *func_021D9D10(int *p);
void func_021D9D1C(int a, void *b, int c);
int *func_021D9DA4(int *p);
void func_021D9DB0(int a, int b, int c);
int *func_021D9DFC(int *p);
void func_021D9E08(int a, int b, int c, Slot d, u8 e);
void func_021D9E80(int a, int b, int c);
int *func_021D9F10(int *p);
void func_021D9F1C(int a, int b, int c);
int *func_021D9FB8(int *p);
void func_021D9FC4(void *a, int b, int c);
int *func_021DA040(int *p);
void func_021DA04C(int a, int b, int c);
int *func_021DA0F0(int *p);
void func_021DA0FC(int a, int b, int c);
int *func_021DA114(int *p);
void func_021DA120(int a, int b, int c);
int *func_021DA138(int *p);
int *func_021DA144(int *p);
void func_021DA150(int a, void *b, int c, int *d);
extern int d_021F0878[];
extern int d_021F0870[];
extern unsigned int d_021F0860;
extern int d_021F0868[];
extern unsigned int d_021F0850;
extern unsigned int d_021F0848;
extern unsigned int d_021F0840;
extern int d_021F0838[];
extern int d_021F0858[];
extern int d_021F0830[];
extern int d_021F0828[];
extern int d_021F0820[];
extern int d_021F0818[];
/* 021DA0FC  shape F1: gate on func_021D775C(3) */
extern int d_021F0810[];
/* 021DA120  shape F1: gate on func_021D775C(2) */
extern int d_021F0808[];
extern int d_021F0800[];
extern int d_021F07F8[];












void func_021D9ADC(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(2)) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            if (func_021D85C0((int)b, 0x21)) {
                p = func_021C88A4(b, 0xb, c);
                ((struct Obj06251 *)p)->f0 |= 0x800000;
                ((struct Obj06251 *)p)->f0 |= 0x2000000;
                ((struct Obj06251 *)p)->f4 = 0x24;
                p[8] = c;
                p[0x14] = 1;
                func_021C88C8(b, p);
            }
        }
    }
}












int *func_021D9B34(int *p)
{
    *p = 1;
    return d_021F0878;
}












void func_021D9B40(int a, void *b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x1d) == 5) {
        q = func_021C7CF4(b, c);
        func_021D76BC(0x32, 0);
        p = func_021C88A4(b, 5, c);
        ((struct Obj10058 *)p)->f4 = func_021D7B74(q, 8);
        p[6] = c;
        ((struct Obj10058 *)p)->f0 |= 0x800000;
        func_021C88C8(b, p);
    }
}












int *func_021D9B98(int *p)
{
    *p = 1;
    return d_021F0870;
}











/* 021D9BA4  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D9BBA; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D9BA4(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x41, 1);
}










int *func_021D9BBC(int *p)
{
    *p = 1;
    return d_021F0868;
}










void func_021D9BC8(int a,int b,int c) { unsigned char v; if(c==func_021D775C(3)) { v=func_021D775C(0x2c)+1; func_021D76BC(0x2c,v); } }










void *func_021D9BEC(int *p) { *p=1; return &d_021F0860; }











/*
 * Three gates on func_021D775C (4, 0x46 zero, 0x45 non-zero); the signed
 * func_021D5D50(func_021C7CF4(b,c),1) must be positive and its byte goes to the
 * record's +0xc.  Record #0xe also sets the 1<<23 header flag and the two-
 * string tail (c) at +0x18.
 */
void func_021D9BF8(void *a, int b, int c)
{
    void *r;
    u8 *p;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_021D775C(0x45) == 0)
        return;
    r = func_021C7CF4((int *)b, c);
    if (func_021D5D50(r, 1) <= 0)
        return;
    p = func_021C88A4((char *)b, 0xe, c);
    ((struct Obj04137 *)p)->f4 = 1;
    ((struct Obj04137 *)p)->fC = func_021D5D50(r, 1);
    ((struct Obj04137 *)p)->fE = 1;
    ((struct Obj04137 *)p)->fF = 1;
    ((struct Obj04137 *)p)->f10 = c;
    ((struct Obj04137 *)p)->fD = 1;
    ((struct Obj04137 *)p)->f0 |= 1 << 23;
    func_021C8838(p + 0x18, 2, 0x1e1);
    func_021C8860((struct S *)(p + 0x18), c);
    func_021C88C8((void *)b, p);
}









int *func_021D9C80(int *p)
{
    *p = 1;
    return d_021F0858;
}









void func_021D9C8C(int a,int b,int c) { Slot s; s=func_021D7D18(5); func_021D9E08(b,c,5,s,30); }











void *func_021D9CB0(int *p) { *p=1; return &d_021F0850; }











void func_021D9CBC(int a,int b,int c) { Slot s; s=func_021D7D18(1); func_021D9E08(b,c,1,s,30); }











void *func_021D9CE0(int *p) { *p=1; return &d_021F0848; }










void func_021D9CEC(int a,int b,int c) { Slot s; s=func_021D7D18(4); func_021D9E08(b,c,4,s,30); }










void *func_021D9D10(int *p) { *p=1; return &d_021F0840; }











void func_021D9D1C(int a, void *b, int c)
{
    void *q;
    void *r;
    u8 x;
    u8 y;
    Slot s;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021C83D4(b) == 0) {
        q = func_021C7CF4(b, c);
        r = func_021C7CF4(b, (u8)func_021D775C(3));
        x = func_021D59B4(q, 0x12);
        y = func_021D59B4(r, 0x12);
        if (x != 2 && y != 2 && x != y) {
            func_021D7DC0(7, q, &s);
            func_021D9E08((int)b, c, 7, s, 0x1e);
        }
    }
}











int *func_021D9DA4(int *p)
{
    *p = 1;
    return d_021F0838;
}











void func_021D9DB0(int a, int b, int c)
{
    u32 r;
    int k;
    Slot s;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    r = func_021D78AC(0x1e);
    if (r > 0x14) {
        k = 5;
    } else {
        k = 1;
        if (r <= 10)
            k = 2;
    }
    s = func_021D7D18(k);
    func_021D9E08(b, c, k, s, 0x1e);
}








int *func_021D9DFC(int *p)
{
    *p = 1;
    return d_021F0830;
}








void func_021D9E08(int a, int b, int c, Slot d, u8 e)
{
    u8 *p;
    u32 m = 4;

    if (b != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_0201BEB8(func_021D775C(0x12), 0) == 0)
        return;
    if (func_021D85C0(a, e) == 0)
        return;
    p = func_021C88A4((char *)a, 0xc, b);
    ((struct Obj06252 *)p)->f0 |= m << 21;
    ((struct Obj06252 *)p)->f4 = c;
    ((struct Obj06252 *)p)->f8 = d.raw;
    ((struct Obj06252 *)p)->fC = 0;
    ((struct Obj06252 *)p)->fF = func_021D775C(3);
    func_021C88C8((void *)a, p);
}









void func_021D9E80(int a, int b, int c)
{
    u8 *p;
    u8 k;
    void *m;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_0201BEB8(func_021D775C(0x12), 0) == 0)
        return;
    k = func_021D775C(3);
    m = func_021C7CF4((int *)b, k);
    if (func_021D5B68(m) != 0)
        return;
    p = func_021C88A4((char *)b, 7, c);
    ((struct Obj10059 *)p)->f0 |= 4 << 21;
    ((struct Obj10059 *)p)->f6 = k;
    ((struct Obj10059 *)p)->f4 = func_021D7B74(m, 8);
    func_021C8838(p + 0xc, 2, 0x1ae);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C88C8((void *)b, p);
}







int *func_021D9F10(int *p)
{
    *p = 1;
    return d_021F0828;
}







void func_021D9F1C(int a, int b, int c)
{
    u8 *p;
    u8 k;
    void *m;

    if (c != func_021D775C(4))
        return;
    if (func_021D5B68(func_021C7CF4((int *)b, c)) == 0)
        return;
    if (func_0201BEB8(func_021D775C(0x12), 0) == 0)
        return;
    k = func_021D775C(3);
    m = func_021C7CF4((int *)b, k);
    p = func_021C88A4((char *)b, 7, c);
    ((struct Obj06253 *)p)->f0 |= 4 << 21;
    ((struct Obj06253 *)p)->f6 = k;
    ((struct Obj06253 *)p)->f4 = func_021D7B74(m, 4);
    p[7] = (p[7] & ~1) | 1;
    func_021C8838(p + 0xc, 2, 0x192);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C88C8((void *)b, p);
}






int *func_021D9FB8(int *p)
{
    *p = 1;
    return d_021F0820;
}






/*
 * Four gates before the body (func_021E85F8(c) non-zero, func_021C83D4(b)
 * zero, record valid, and the (u8) of func_021D775C(0x16) neither 0x11 nor
 * rejected by func_021D5814), then the 2-event, record, 3-event sequence of
 * func_021D96FC with the halfword from func_021E8CF0 in the record.
 */
void func_021D9FC4(void *a, int b, int c)
{
    void *r, *p;
    u8 k;

    if (func_021E85F8(c) == 0)
        return;
    if (func_021C83D4((u8 *)b) != 0)
        return;
    r = func_021C7CF4((int *)b, c);
    if (func_021D5B68(r) != 0)
        return;
    k = (u8)func_021D775C(0x16);
    if (k == 0x11)
        return;
    if (func_021D5814(r, k) != 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 0x14, c);
    ((struct Obj12144 *)p)->f4 = func_021E8CF0(k);
    ((struct Obj12144 *)p)->f6 = c;
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}





int *func_021DA040(int *p)
{
    *p = 1;
    return d_021F0818;
}





void func_021DA04C(int a, int b, int c)
{
    u8 *p;
    int m;
    u8 k;
    void *s;
    S t;

    if (c != func_021D775C(4))
        return;
    m = func_021D775C(0x1d);
    if (m != 5 && m != 1 && m != 4)
        return;
    k = func_021D775C(3);
    if (k == 0x1f || k == c)
        return;
    s = func_021C7CF4((int *)b, c);
    t.x = func_021D775C(0x1e);
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 0xc, c);
    p[0xf] = k;
    ((struct Obj07810 *)p)->f4 = m;
    if (m == 5 && func_021E8A78(t))
        ((struct Obj07810 *)p)->f8 = t.x;
    else
        func_021D7DC0(m, s, (Slot *)(p + 8));
    p[0xc] = 1;
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}




int *func_021DA0F0(int *p)
{
    *p = 1;
    return d_021F0810;
}




/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DA112; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DA0FC(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x41, 1);
}



int *func_021DA114(int *p)
{
    *p = 1;
    return d_021F0808;
}



/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DA136; movs r0, #0x16; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DA120(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x16, 0);
}


int *func_021DA138(int *p)
{
    *p = 1;
    return d_021F0800;
}


int *func_021DA144(int *p)
{
    *p = 1;
    return d_021F07F8;
}


void func_021DA150(int a, void *b, int c, int *d)
{
    u8 buf[3];
    u8 selected[3];
    u8 chosen;
    u32 move;
    u8 active;
    u8 count, i, choice;
    u32 n;
    u16 mask;
    int slot;
    void *q;
    int candidate;
    u8 *p;
    active = func_021D775C(2);
    chosen = 31;
    move = 0;
    if (active == c) {
        mask = func_021C7D00(b, c);
        n = func_021C7F68(b, (u16)(mask | 0x100), buf);
        for (count = 0, i = 0; i < n; i++) {
            if (!func_021DA2D0((u16)func_021D59B4(func_021C7CF4(b, buf[i]), 16))) selected[count++] = buf[i];
        }
        if (count != 0) {
            choice = count == 1 ? 0 : func_021D78AC(count);
            q = func_021C7CF4(b, selected[choice]);
            move = func_021D59B4(q, 16);
            chosen = func_021D5440(q);
        } else {
            *d = 1;
        }
    } else if (!func_021B9A24(active, c) && *d == 1) {
        slot = func_021C8010(b, active);
        mask = func_021C7D00(b, c);
        if (slot != 6 && (func_021C815C(b) != 2 || func_021B9A6C(mask, slot))) {
            candidate = func_021D59B4(func_021C7CF4(b, active), 16);
            if (!func_021DA2E0((u16)candidate)) { move = candidate; chosen = active; }
        }
    }
    if (move != 0 && c != 31) {
        p = func_021C88A4(b, 31, c);
        p[6] = c;
        ((struct Obj06254 *)p)->f4 = move;
        p[8] = 1;
        ((struct Obj06254 *)p)->f0 |= 1 << 23;
        func_021C8838(p + 12, 2, 0x17d);
        func_021C8860((struct S *)(p + 12), chosen);
        func_021C8860((struct S *)(p + 12), ((struct Obj06254 *)p)->f4);
        func_021C88C8(b, p);
    }
}
