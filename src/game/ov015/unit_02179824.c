/*
 * file:     unit_02179824.c
 * unit:     yes
 * function: func_02179824, func_02179840, func_0217984C, func_02179860, func_02179868, func_02179870, func_02179878, func_02179880, func_02179888, func_02179890, func_02179898, func_021798A0, func_021798B4, func_021798BC, func_021798C4, func_021798CC, func_021798D4, func_021798DC, func_0217993C, func_0217998C, func_02179998, func_021799B4, func_021799C0, func_021799CC, func_021799F0, func_021799FC, func_02179A08, func_02179A18, func_02179A4C, func_02179AAC, func_02179B24, func_02179B38
 * address:  0x02179824
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02179D3C  0x02179D3C  thumb  ov015
 *   func_02179CAC  0x02179CAC  thumb  ov015
 *   func_02179D80  0x02179D80  thumb  ov015
 *   func_02179D68  0x02179D68  thumb  ov015
 *   func_02179D78  0x02179D78  thumb  ov015
 *   func_02179CE4  0x02179CE4  thumb  ov015
 *   d_0217A9E0  0x0217A9E0  data  a4
 *   d_0217AAAC     0x0217AAAC  data   ov015  a1
 *   d_0217AAC0     0x0217AAC0  data   ov015  a4
 *   d_0217AAD2     0x0217AAD2  data   ov015  a1
 *   d_0217AAC6     0x0217AAC6  data   ov015  a1
 *   d_0217AAC4     0x0217AAC4  data   ov015  a1
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0217A148  0x0217A148  arm    ov015
 *   d_0217AB40     0x0217AB40  data   ov015  a4
 *   d_0217ABA0     0x0217ABA0  data   ov015  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_02179F74  0x02179F74  arm    ov015
 *   func_0217A584  0x0217A584  arm    ov015
 *   func_020056EC  0x020056EC  thumb
 *   d_0217AB80 0x0217AB80 data ov015 a1
 *   func_0217A134 0x0217A134 arm ov015
 *   g_0217AB80  0x0217AB80  data  a4
 *   func_02179D14  0x02179D14  thumb  ov015
 *   func_02179C98  0x02179C98  thumb  ov015
 */
#include "../../matched/include/G_s_ab40.h"
#include "../../matched/include/G_s_aba0.h"
#include "../../matched/include/G_State.h"
#include "../../matched/include/Obj03560.h"
#include "../../matched/include/Obj01643.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct s_aac0 {
    unsigned int   f0;     /* +0x00 receive callback, stored as a word */
    unsigned short h4;
    unsigned char  b6;
    unsigned char  b7;
    unsigned int   f8;
    unsigned int   fC;
    unsigned char  f10;
};

struct flags_ab80 {
    u8 pad[0xE];
    u8 fE;
    u8 b0 : 1;
    u8 b1 : 1;
};

typedef int (*filter_fn)(u8 a, u8 b);

typedef int (*recv_fn)(u16 id, u8 *data, u16 len);

int func_02179D3C(void);
extern int func_02179CAC(void);
extern void func_02179D80(void);
extern unsigned char func_02179D68(void);
extern int func_02179D78(void);
extern void func_02179CE4(void);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern void func_02082D44(void *dst, void *src, int n);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0217A148(int a0, int a1, int a2);
extern void func_02082BCC(void *p, int v, u32 n);
extern u16 func_0208F1B4(void);
extern void func_02179F74(u8 unitId);
extern void func_0217A584(void (*cb)(void));
extern u32 func_020056EC(u32 x);
extern void func_0217A134(void);
extern void func_02179D14(void);
extern int func_02179C98(void);
int func_02179824(void *dst, int a, int unused, void (*cb)(int));
int func_02179840(int v);
int func_0217984C(void);
int func_02179860(void);
void func_02179868(void);
int func_02179870(void);
unsigned char func_02179878(void);
unsigned char func_02179880(void);
int func_02179888(void);
int func_02179890(void);
unsigned char func_02179898(void);
int func_021798A0(void);
unsigned char func_021798B4(void);
void func_021798BC(void);
void func_021798C4(int v);
void func_021798CC(int a);
void *func_021798D4(void);
void func_021798DC(void *dst, int n, u8 a, u8 b);
void func_0217993C(u32 a, u8 b);
void func_0217998C(int v);
void func_02179998(void);
void func_021799B4(unsigned v);
void func_021799C0(int a);
void func_021799CC(void);
unsigned char func_021799F0(void);
u8 func_021799FC(void);
u8 func_02179A08(void);
int func_02179A18(void);
void func_02179A4C(void *dst, u8 a, u8 b);
void func_02179AAC(void);
int func_02179B24(void);
void func_02179B38(u8 *pkt, u32 len, u32 type);
extern u8 d_0217AAAC[];
extern struct s_aac0 d_0217AAC0;
extern u8 d_0217AAD2[];
extern u8 d_0217AAC6[];
extern u8 d_0217AAC4[];
extern struct s_ab40 d_0217AB40;
extern struct s_aba0 d_0217ABA0;
extern struct State d_0217AB80;




/*
 * extent: two zero alignment bytes at 0217983E.
 */
int func_02179824(void *dst, int a, int unused, void (*cb)(int))
{
    func_02179A4C(dst, (u8)a, 0);
    if (cb != 0) cb(1);
    return 1;
}





int func_02179840(int v)
{
    func_021799B4(v);
    return 1;
}




/*
 * Guard/forward wrapper: returns the follower's result only when the predicate
 * holds, otherwise zero.
 */
int func_0217984C(void)
{
    if (func_02179D3C())
        return func_02179B24();
    return 0;
}



int func_02179860(void)
{
    return func_02179CAC();
}



void func_02179868(void)
{
    func_02179D80();
}



int func_02179870(void)
{
    return func_02179A18();
}



unsigned char func_02179878(void)
{
    return func_021799FC();
}



unsigned char func_02179880(void)
{
    return func_02179D68();
}



int func_02179888(void)
{
    return func_02179D78();
}



int func_02179890(void)
{
    return func_02179D3C();
}



unsigned char func_02179898(void)
{
    return func_021799F0();
}



int func_021798A0(void)
{
    if (func_02179D3C())
        return 3;
    return 0;
}



unsigned char func_021798B4(void)
{
    return func_02179A08();
}



void func_021798BC(void)
{
    func_02179CE4();
}



void func_021798C4(int v)
{
    func_0217998C(v);
}



void func_021798CC(int a)
{
    func_021799C0(a);
}








void *func_021798D4(void)
{
    return (void *)0x0217A9E0;
}









void func_021798DC(void *dst, int n, u8 a, u8 b)
{
    if ((unsigned)n >= 0xA6)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    d_0217AAC0.b6 = a;
    d_0217AAC0.b7 = b;
    if (dst != 0)
        func_02082D44(dst, d_0217AAD2, 0xA6);
    d_0217AAC0.h4 = func_0203F1FC(d_0217AAC6, n + 12);
    func_0217A148((int)d_0217AAC4, (u8)(n + 14), a);
}









void func_0217993C(u32 a, u8 b)
{
    func_02082BCC(&d_0217AAC0, 0, 0xE8);
    d_0217AB40.f3c = a;
    d_0217ABA0.b6 = func_0208F1B4();
    func_02179F74(3);
    func_0217A584((void (*)(void))func_02179B38);
    d_0217AAC0.f8 = func_020056EC(0);
    if (d_0217AAC0.f8 == 0)
        d_0217AAC0.f8 = 1;
    d_0217AAC0.f10 = b;
}









/*
 * Unlabelled leaf setter (hidden in a .word run); helper for the call in
 * ov010 func_02157A78.
 */
void func_0217998C(int v)
{
    *(int *)(((u8 *)&d_0217AB40) + 0x3C) = v;
}








void func_02179998(void)
{
    if (((unsigned char *)&d_0217AB80)[0xC] == 1) func_0217A134();
    ((unsigned char *)&d_0217AB80)[0xC] = 0;
}








/*
 * extent: follower 021799C0 already filed separately.
 */
void func_021799B4(unsigned v) { d_0217AAC0.f0 = v; }








void func_021799C0(int a) { d_0217AB40.f48 = (int (*)(unsigned char, unsigned char))a; }









void func_021799CC(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] != 0)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    ((unsigned char *)&d_0217AB80)[0xc] = 1;
}








/*
 * Unlabelled leaf getter: returns the byte at +0xC of d_0217AB80.  Its
 * unlabelled followers at 021799FC, 02179A08 and 02179A18 (two more
 * getters and a predicate over the same block) make the extent run long.
 */
unsigned char func_021799F0(void)
{
    return ((unsigned char *)&d_0217AB80)[0xc];
}





u8 func_021799FC(void) { return d_0217AB80.f14; }




u8 func_02179A08(void) { return ((struct flags_ab80 *)&d_0217AB80)->b0; }



int func_02179A18(void)
{
    if (d_0217AB80.f14 == 1 && ((struct flags_ab80 *)&d_0217AB80)->b0 == 0 && ((u32 *)&d_0217AB40)[0x40 / 4] == 0 && d_0217ABA0.b1 == 0)
        return 1;
    return 0;
}





void func_02179A4C(void *dst, u8 a, u8 b)
{
    if (((u8 *)&d_0217AB80)[0xE] != 1)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    func_021798DC(dst, a, b, (u8)(d_0217ABA0.b2 | (d_0217ABA0.b3 << 4)));
    d_0217AB40.f44 = (u32)dst;
    ((u8 *)&d_0217AB80)[0x1E] = a;
    ((u8 *)&d_0217AB80)[0x1F] = b;
    d_0217ABA0.b0 = d_0217ABA0.b2;
    d_0217ABA0.b1 = 1;
    ((u8 *)&d_0217AB80)[0xE] = 0;
}





void func_02179AAC(void)
{
    u8 *p;

    p = (u8 *)&d_0217AAC0;
    if (((u8 *)&d_0217AB80)[0xE] == 1) {
        if (p[0xE4] == 1) {
            func_021798DC((void *)(((struct Obj03560 *)p)->fC4), p[0xDE], p[0xDF], p[0xE0] | (((u8 *)&d_0217ABA0)[3] << 4));
            p[0xE4] = 0;
        } else {
            func_021798DC(0, 0, 0xEE, p[0xE0] | (((u8 *)&d_0217ABA0)[3] << 4));
        }
        p[0xCE] = 0;
    }
}




int func_02179B24(void) { if (((u8 *)&d_0217AB80)[0x1c] != 1) return 1; return 0; }





/*
 * Receive handler for one packet: rejects a length of 0 or over 0xB4 (the
 * over-length case also reports through func_02034714), checks the header
 * checksum at +0 against func_0203F1FC over the rest, filters on the byte
 * at +0xC (through the optional hook at d_0217AB40+0x48), tracks the
 * session words at +4/+8, then hands the payload at +0xE to the callback
 * at d_0217AAC0+0 once per new low nibble of the byte at +3.
 */
void func_02179B38(u8 *pkt, u32 len, u32 type)
{
    u8 buf[6] = {0, 0, 0, 0, 0, 0};
    int lo;
    int hi;
    filter_fn filter;
    recv_fn recv;

    lo = pkt[3] & 0xF;
    hi = pkt[3] >> 4;
    ((struct flags_ab80 *)((u8 *)&d_0217AB80))->fE = 1;

    if (len > 0xB4)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    if (!(len != 0 && len <= 0xB4))
        return;
    if (((struct Obj01643 *)pkt)->f0 != func_0203F1FC(pkt + 2, len - 2))
        return;

    filter = d_0217AB40.f48;
    if (filter != 0) {
        if (!filter(d_0217AAC0.f10, pkt[0xC]))
            return;
    } else {
        if (d_0217AAC0.f10 != pkt[0xC])
            return;
    }

    if (((struct Obj01643 *)pkt)->f8 == d_0217AAC0.f8 &&
        ((struct Obj01643 *)pkt)->f4 == d_0217AB40.f38) {
        if (!((struct flags_ab80 *)((u8 *)&d_0217AB80))->b1) {
            func_02179D14();
            ((struct flags_ab80 *)((u8 *)&d_0217AB80))->b1 = 1;
        }
    } else if (((struct Obj01643 *)pkt)->f8 == 0 && d_0217AB40.f38 == 0) {
        d_0217AAC0.fC = ((struct Obj01643 *)pkt)->f4;
        d_0217AB40.f38 = ((struct Obj01643 *)pkt)->f4;
        return;
    } else if (((struct Obj01643 *)pkt)->f8 == d_0217AAC0.f8 &&
               d_0217AB40.f38 == 0) {
        d_0217AAC0.fC = ((struct Obj01643 *)pkt)->f4;
        d_0217AB40.f38 = ((struct Obj01643 *)pkt)->f4;
    } else {
        if (((struct flags_ab80 *)((u8 *)&d_0217AB80))->b1)
            return;
        if (d_0217AB40.f38 == ((struct Obj01643 *)pkt)->f4)
            return;
        d_0217AB40.f38 = 0;
        return;
    }

    if (type >= 0xF0)
        return;

    if (((u8 *)&d_0217ABA0)[1] == 1 && ((u8 *)&d_0217ABA0)[4] == 0) {
        if (hi == ((u8 *)&d_0217ABA0)[2]) {
            if (((u8 *)&d_0217ABA0)[2] < 0xF)
                ((u8 *)&d_0217ABA0)[2] = ((u8 *)&d_0217ABA0)[2] + 1;
            else
                ((u8 *)&d_0217ABA0)[2] = 0;
            ((u8 *)&d_0217ABA0)[1] = 0;
        } else {
            ((u8 *)&d_0217ABA0)[4] = 1;
        }
    }

    if (type == 0xEE)
        return;
    if (((u8 *)&d_0217ABA0)[3] == lo)
        return;

    {
        int id = func_02179C98();
        recv = (recv_fn)d_0217AAC0.f0;
        if (recv == 0 || recv((u16)id, pkt + 0xE, (u16)(len - 0xE)) != 0)
            ((u8 *)&d_0217ABA0)[3] = lo;
    }
}
