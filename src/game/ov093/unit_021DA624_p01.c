/*
 * file:     unit_021DA624_p01.c
 * unit:     yes
 * function: func_021DA624, func_021DA6EC, func_021DA748, func_021DA780, func_021DA7DC, func_021DA808, func_021DA820, func_021DA838, func_021DA844, func_021DA868, func_021DA89C, func_021DA8A8, func_021DA8DC, func_021DA96C, func_021DA9E0, func_021DAA70, func_021DAA94, func_021DAAC0, func_021DAAEC, func_021DAB24, func_021DAB48, func_021DAB78, func_021DABE8, func_021DABF4, func_021DAC1C, func_021DAC6C, func_021DAC90, func_021DAD20, func_021DAD2C, func_021DAD58, func_021DAD84, func_021DADD8, func_021DAE04, func_021DAE38, func_021DAE94
 * address:  0x021DA624
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
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021DAEC4  0x021DAEC4  thumb  ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F09B0 0x021F09B0 data a4
 *   d_021F0B00 0x021F0B00 data a4
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7B08   0x021D7B08  thumb ov093
 *   d_021F0B18     0x021F0B18  data   ov093  a4
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   d_021F0B30 0x021F0B30 data a4
 *   d_021F0730 0x021F0730 data a4
 *   d_021F0798 0x021F0798 data a4
 *   d_021F0790 0x021F0790 data a4
 *   func_0201BEB8  0x0201BEB8  thumb
 *   d_021F09D0     0x021F09D0  data   ov093  a4
 *   d_021F0A10 0x021F0A10 data a4
 *   func_0201C314   0x0201C314  thumb
 *   d_021F0788     0x021F0788  data   ov093  a4
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   d_021F0B94 0x021F0B94 data a4
 *   d_021F0660     0x021F0660  data   ov093  a4
 */
#include "../../matched/include/Obj10060.h"
#include "../../matched/include/Obj21303.h"
#include "../../matched/include/Obj04368.h"
#include "../../matched/include/Obj06256.h"
#include "../../matched/include/Obj21310.h"
#include "../../matched/include/Obj21314.h"
#include "../../matched/include/Obj21317.h"

struct QI;
struct S;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D78AC(u32);
extern void func_021C88B4(void *, int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
extern int func_021D76BC(int key, u32 val);
extern int func_021D5B48(u8 *p);
extern void func_021D7704(int, int);
extern int func_021D7B08(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_0201BEB8(u16 id, u32 bit);
u32 func_0201C314(void *p);
extern int func_021D5BB0(struct UtilWork *,unsigned int);
void func_021DA624(int a, void *b, int c);
int *func_021DA6D4(int *p);
int *func_021DA6E0(int *p);
void func_021DA6EC(int a, int b, int c);
void func_021DA748(int a, int *b, int c, int *d);
void func_021DA780(int a, int b, int c, int *d);
void func_021DA7DC(int a, int b, int c);
void func_021DA808(int a, int b, int c);
void func_021DA820(int a, int b, int c);
int *func_021DA838(int *p);
void func_021DA844(int a, int b, int c);
void func_021DA868(int a, int b, int c);
int *func_021DA89C(int *p);
int func_021DA8A8(int a, int b, int c);
void func_021DA8DC(int a, int b, int c);
void func_021DA96C(void *a, int id, u32 e, int d);
void func_021DA9E0(int unused, void *a, int id);
void func_021DAA70(int a, int b, int c);
void func_021DAA94(int a, int b, int c);
void *func_021DAAB4(int *p);
void func_021DAAC0(int a, int b, int c);
void *func_021DAAE0(int *p);
void func_021DAAEC(int a, int b, int c);
void *func_021DAB0C(int *p);
void *func_021DAB18(int *p);
void func_021DAB24(int a, void *b, int c);
void func_021DAB48(int a, int b, int c);
void *func_021DAB6C(int *p);
void func_021DAB78(int unused, void *a, int id);
int *func_021DABE8(int *p);
void func_021DABF4(int a, int b, int c, int *d);
void func_021DAC1C(int unused, void *a, int id, int *f);
void func_021DAC6C(int a, int b, int c, int *d);
const unsigned int *func_021DAC84(int *n);
void func_021DAC90(void *a, int b, int c);
int *func_021DAD20(int *p);
void func_021DAD2C(int a, int b, int c, int *d);
void func_021DAD58(int a, int *b, int c, int *d);
void func_021DAD84(int unused, void *a, int id, int *f);
void func_021DADD8(int a, int b, int c, int *d);
const unsigned int *func_021DADF8(int *n);
void func_021DAE04(int a, int b, int c, int *d);
void func_021DAE38(int unused, void *a, int id, int *f);
extern int d_021F09B0, d_021F0B00;
extern int d_021F0B18[];
extern unsigned char d_021F0B30[];
extern unsigned char d_021F0730[];
extern unsigned char d_021F0798[];
extern unsigned char d_021F0790[];
extern int d_021F09D0[];
extern const unsigned int d_021F0A10[];
extern int d_021F0788[];
extern const unsigned int d_021F0B94[];
extern int d_021F0660[];





void func_021DA624(int a, void *b, int c)
{
    u16 values[4];
    u8 buf[4];
    u8 n;
    u8 count;
    u8 i;
    u8 choice;
    u8 *p;
    void *q;
    if (c != func_021D775C(2)) return;
    n = func_021C7D54(b, (u8 *)c, buf);
    count = 0;
    for (i = 0; i < n; i++) {
        q = func_021C7CF4(b, buf[i]);
        values[count] = func_021D5B40(q);
        if (values[count] != 0) count++;
    }
    if (count == 0) return;
    choice = func_021D78AC(count);
    func_021C88B4(b, 2, c);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x1b7);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), values[choice]);
    func_021C88C8(b, p);
    func_021C88B4(b, 3, c);
}





int *func_021DA6D4(int *p) { *p = 2; return &d_021F09B0; }





int *func_021DA6E0(int *p) { *p = 3; return &d_021F0B00; }






void func_021DA6EC(int a, int b, int c)
{
    u8 *p;
    int m = 4;

    if (c != func_021D775C(4))
        return;
    if (func_021D76BC(0x41, 1) == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, m, c);
    func_021C8838(p + 4, 2, 0xd2);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}






/*
 * extent: trailing two-byte alignment padding.
 */
void func_021DA748(int a, int *b, int c, int *d)
{
    int k = 4;
    if (c == func_021D775C(k)) {
        if (func_021D5B48(func_021C7CF4(b, c)) != 0) {
            *d = func_021D76BC(0x3a, k);
            return;
        }
        *d = 0;
    }
}






void func_021DA780(int a, int b, int c, int *d)
{
    u8 *p;

    if (c != func_021D775C(2))
        return;
    if (*d == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x202);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
    *d = 0;
}






void func_021DA7DC(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        func_021D76BC(0x28, 6);
        return;
    }
    if (c == func_021D775C(4))
        func_021D76BC(0x27, 6);
}






/* 021DA808  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DA81E; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DA808(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x51, 1);
}




/* 021DA820  shape F1: gate on func_021D775C(3) */
void func_021DA820(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}



int *func_021DA838(int *p)
{
    *p = 3;
    return d_021F0B18;
}



void func_021DA844(int a, int b, int c)
{
    int k = 4;
    if (c == func_021D775C(k) && func_021D775C(0x16) == 9)
        func_021D7704(0x31, k << 9);
}




void func_021DA868(int a, int b, int c)
{
    int t;

    if (c != func_021D775C(2))
        return;
    if (func_021D775C(0x1d) != 4)
        return;
    t = func_021D775C(0x32);
    func_021D76BC(0x32, func_021D7B08(t / 2, 1));
}




int *func_021DA89C(int *p)
{
    *p = 2;
    return d_021F09D0;
}




int func_021DA8A8(int a, int b, int c)
{
    if (b == func_021D775C(4) && b != func_021D775C(3) && c == func_021D775C(0x16))
        return func_021D76BC(0x40, 1);
    return 0;
}









void func_021DA8DC(int a, int b, int c)
{
    void *m;
    u8 *p;
    u8 *q;

    m = func_021C7CF4((int *)a, b);
    if (func_021D5B48(m) == 0) {
        p = func_021C88A4((char *)a, 5, b);
        p[6] = b;
        ((struct Obj10060 *)p)->f4 = func_021D7B74(m, c);
        ((struct Obj10060 *)p)->f0 |= 2 << 22;
        func_021C8838(p + 8, 2, 0x183);
        func_021C8860((struct S *)(p + 8), b);
        func_021C88C8((void *)a, p);
    } else {
        q = func_021C88A4((char *)a, 4, b);
        func_021C8838(q + 4, 2, 0xd2);
        func_021C8860((struct S *)(q + 4), b);
        ((struct Obj21303 *)q)->f0 |= 2 << 22;
        func_021C88C8((void *)a, q);
    }
    func_021D76BC(0x51, 1);
}









void func_021DA96C(void *a, int id, u32 e, int d)
{
    u8 *r;

    if (func_021D5D14(func_021C7CF4(a, id), e, d) != 0) {
        r = (u8 *)func_021C88A4(a, 14, id);
        r[0xf] = 1;
        r[0x10] = id;
        r[0xe] = 1;
        ((struct Obj04368 *)r)->f4 = e;
        r[0xc] = d;
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        func_021C88C8(a, r);
    } else {
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, 0xd2);
        func_021C8860((struct S *)(r + 4), id);
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        func_021C88C8(a, r);
    }
}








void func_021DA9E0(int unused, void *a, int id)
{
    u8 *r;
    void *m;
    u8 c;

    if (id == func_021D775C(2)) {
        m = func_021C7CF4(a, id);
        c = func_021D775C(0x39);
        if (c == 1) {
            func_021C88B4(a, 2, id);
            r = (u8 *)func_021C88A4(a, 7, id);
            r[6] = id;
            ((struct Obj06256 *)r)->f4 = func_021D7B74(m, 8);
            func_021C88C8(a, r);
            func_021C88B4(a, 3, id);
        } else if (c == 2) {
            r = (u8 *)func_021C88A4(a, 5, id);
            ((struct Obj06256 *)r)->f0 |= 0x800000;
            r[6] = id;
            ((struct Obj06256 *)r)->f4 = func_021D7B74(m, 8);
            func_021C88C8(a, r);
        }
    }
}








void func_021DAA70(int a, int b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x16) == 9)
        func_021D7704(0x31, 5 << 10);
}








/*
 * extent: includes store-and-return followers 021DAAB4.
 */
void func_021DAA94(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}








void *func_021DAAB4(int *p)
{
    *p = 3;
    return d_021F0B30;
}








/*
 * extent: includes store-and-return followers 021DAAE0.
 */
void func_021DAAC0(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}








void *func_021DAAE0(int *p)
{
    *p = 1;
    return d_021F0730;
}








/*
 * extent: includes store-and-return followers 021DAB0C, 021DAB18.
 */
void func_021DAAEC(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 12))
        func_021DA8DC(b, c, 4);
}








void *func_021DAB0C(int *p)
{
    *p = 1;
    return d_021F0798 + 8;
}








void *func_021DAB18(int *p)
{
    *p = 1;
    return d_021F0798;
}







void func_021DAB24(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 0xc))
        func_021DA96C(b, c, 5, 1);
}







/*
 * extent: includes store-and-return followers 021DAB6C.
 */
void func_021DAB48(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x15) == 7)
        func_021D76BC(0x4b, 1);
}







void *func_021DAB6C(int *p)
{
    *p = 1;
    return d_021F0790;
}





void func_021DAB78(int unused, void *a, int id)
{
    u8 *r;

    if (id == func_021D775C(4)) {
        if (func_0201BEB8(func_021D775C(0x12), 8) != 0 && func_021D76BC(0x40, 1) != 0) {
            func_021C88B4(a, 2, id);
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0xd2);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
            func_021C88B4(a, 3, id);
        }
    }
}




int *func_021DABE8(int *p)
{
    *p = 1;
    return d_021F0788;
}




void func_021DABF4(int a, int b, int c, int *d)
{
    int k;
    if (c == func_021D775C(2)) {
        k = 0x51;
        if (func_021D775C(k) == 0)
            *d = func_021D76BC(k, 1);
    }
}







void func_021DAC1C(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (id == func_021D775C(2) && *f != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21310 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0xd2);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        *f = 0;
    }
}






void func_021DAC6C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) *d = 0; }






const unsigned int *func_021DAC84(int *n) { *n = 3; return d_021F0A10; }





/*
 * Gate on func_021D775C(4) then a re-test on func_021D775C(3); the
 * func_021C7CF4(b, c) call's value is dropped, only the (u16) of
 * func_021D775C(0x12) is kept.  Five more rejections, then the 2-event,
 * record, 3-event tail.  The trailing event's constant 3 is live across the
 * whole body, which is why the image keeps it in r7.
 */
void func_021DAC90(void *a, int b, int c)
{
    void *q;
    u16 v;

    if (c != func_021D775C(4))
        return;
    if (c == func_021D775C(3))
        return;
    func_021C7CF4((int *)b, c);
    v = (u16)func_021D775C(0x12);
    if (func_0201C314((void *)v) == 0)
        return;
    if (v == 0xa5)
        return;
    if (func_021D775C(0x38) > 3)
        return;
    if (func_021D76BC(0x40, 1) == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    q = func_021C88A4((char *)b, 4, c);
    func_021C8838((u8 *)q + 4, 2, 0xd2);
    func_021C8860((struct S *)((u8 *)q + 4), c);
    func_021C88C8((void *)b, q);
    func_021C88B4((void *)b, 3, c);
}



int *func_021DAD20(int *p)
{
    *p = 1;
    return d_021F0660;
}



void func_021DAD2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) { if (*d != 0) { d[1] = func_021D76BC(34,19); *d = 0; } else *d = 1; } }




/*
 * interface: func_021C7CF4 uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 */
void func_021DAD58(int a, int *b, int c, int *d) { if (c == func_021D775C(2)) { if (func_021D5BB0(func_021C7CF4(b,c),0)) *d = 1; } }





void func_021DAD84(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (id == func_021D775C(2) && f[1] != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21314 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x1bd);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        f[1] = 0;
    }
}




void func_021DADD8(int a, int b, int c, int *d) { if (c == func_021D775C(2) && func_021D775C(12) == 7) *d = 0; }




const unsigned int *func_021DADF8(int *n) { *n = 4; return d_021F0B94; }




void func_021DAE04(int a, int b, int c, int *d) { unsigned short k; k = func_021D775C(18); *d = 0; if (k == 153 || k == 120) { if (func_021D775C(34) == 0) { *d = func_021D76BC(34,19); d[1] = k; } } }





void func_021DAE38(int unused, void *a, int id, int *f)
{
    u8 *r;
    u32 k;

    if (*f != 0) {
        k = (u8)func_021D775C(2);
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21317 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x389);
        func_021C8860((struct S *)(r + 4), k);
        func_021C8860((struct S *)(r + 4), f[1]);
        func_021C88C8(a, r);
        *f = 0;
    }
}


void func_021D7320(void *p, u32 v);
int func_021DAEC4(int a, int b, int c, int d, unsigned short e);
void func_021DAE94(void *p);

void func_021DAE94(void *p)
{
    func_021D7320(p, (u32)func_021DAEC4);
}
