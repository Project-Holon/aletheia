/*
 * file:     camera_system_p02.c
 * unit:     yes
 * function: func_021B6390, func_021B6398, func_021B63A0, func_021B63A8, func_021B63B0, func_021B63B8, func_021B6424, func_021B642C, func_021B6434, func_021B643C, func_021B6444, func_021B644C, func_021B649C, func_021B64A4, func_021B64AC, func_021B655C, func_021B6564, func_021B656C, func_021B6574, func_021B657C, func_021B65C4, func_021B65D8, func_021B6608, func_021B6610, func_021B6618, func_021B6620, func_021B662C, func_021B6698, func_021B66A0, func_021B66A8, func_021B66B0, func_021B6724, func_021B672C, func_021B6734, func_021B673C, func_021B6744, func_021B674C, func_021B67BC, func_021B680C, func_021B6814, func_021B6850, func_021B6858, func_021B6860, func_021B6868, func_021B6884, func_021B688C, func_021B68A0, func_021B6918, func_021B6920, func_021B6928, func_021B6930, func_021B6938, func_021B6944, func_021B6950
 * address:  0x021B6390
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020351F8 0x020351F8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02034FB8 0x02034FB8 arm
 *   func_020307B0 0x020307B0 arm
 *   g_021C88E0 0x021C88E0 data a4
 *   func_020490A8 0x020490A8 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02048F4C 0x02048F4C arm
 *   func_020862F0 0x020862F0 arm
 *   d_021C71C0 0x021C71C0 data a4
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_02088234 0x02088234 arm
 *   func_02030734 0x02030734 arm
 *   func_021B697C 0x021B697C thumb ov172
 *   func_021B699C 0x021B699C thumb ov172
 *   func_021B6974 0x021B6974 arm ov172
 */
#include "../../matched/include/Obj01264.h"
#include "../../matched/include/Obj01559.h"
#include "../../matched/include/Obj02504.h"
#include "../../matched/include/Obj14292.h"
#include "../../matched/include/Obj03311.h"
#include "../../matched/include/Obj02879.h"
#include "../../matched/include/Obj14293.h"
#include "../../matched/include/Obj08253.h"
#include "../../matched/include/Obj24060.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_020351F8(u32 a, u32 b);
extern int func_02085D3C();
extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
extern u32 func_020490A8(u32 a, u32 b);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_020862F0(void *, u32);
extern void func_0203D7FC(void *p);
extern void func_02088234(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021B697C(void *);
extern int func_021B699C(void *);
extern void func_021B6974(int, int, int);
#pragma thumb off
asm int func_021B6390(void);
asm void func_021B6398(void);
asm void func_021B63A0(void);
asm void func_021B63A8(int);
asm void func_021B63B0(void);
#pragma thumb on
void func_021B63B8(char *p);
#pragma thumb off
asm void func_021B6424(void);
asm void func_021B642C(void);
asm void func_021B6434(void);
asm void func_021B643C(int);
asm void func_021B6444(void);
#pragma thumb on
void func_021B644C(char *p);
#pragma thumb off
asm u32 func_021B649C(u32);
asm void func_021B64A4(int, u32, u32, u32, int, void (*)(void), int);
#pragma thumb on
void func_021B64AC(char *p);
#pragma thumb off
asm void func_021B655C(int, int);
asm int func_021B6564(void);
asm void func_021B656C(int, int);
asm int func_021B6574(void);
#pragma thumb on
void func_021B657C(char *obj, int mode);
void func_021B65C4(void *p);
void func_021B65D8(void);
#pragma thumb off
asm void func_021B6608(void);
asm u32 func_021B6610(u32 a);
asm void func_021B6618(void);
#pragma thumb on
void func_021B6620(int x);
void func_021B662C(void);
#pragma thumb off
asm int func_021B6698(u32);
asm void func_021B66A0(void);
asm void func_021B66A8(void);
#pragma thumb on
void func_021B66B0(void);
#pragma thumb off
asm void func_021B6724(int);
asm int func_021B672C(void);
asm int func_021B6734(int);
asm void func_021B673C(int);
#pragma thumb on
void func_021B6744(void *p, u32 a, u32 b);
void func_021B674C(char *p, int count, u16 heap);
void func_021B67BC(char *p);
#pragma thumb off
asm int func_021B680C(void);
#pragma thumb on
void func_021B6814(void *a0);
#pragma thumb off
asm int func_021B6850(void);
asm int func_021B6858(int a);
asm int func_021B6860(int a);
#pragma thumb on
void func_021B6868(char *p);
#pragma thumb off
asm void func_021B6884(void);
#pragma thumb on
int func_021B688C(void *p);
void func_021B68A0(char *p);
#pragma thumb off
asm int func_021B6918(void);
asm void func_021B6920(int);
asm int func_021B6928(u32, u32);
asm void func_021B6930(int);
#pragma thumb on
u16 func_021B6938(void *p);
u16 func_021B6944(void *p);
void func_021B6950(char *p, int v);
extern void *g_021C88E0;
extern const char d_021C71C0[];

#pragma thumb off




asm int func_021B6390(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706324
}





/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027072E0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6398(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027072E0
}





/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700BD0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B63A0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700BD0
}



asm void func_021B63A8(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}


asm void func_021B63B0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700B34
}


#pragma thumb on

void func_021B63B8(char *p)
{
    func_020351F8(0, 0);
    if (func_02085D3C() != 0) func_021B6424();
    if (func_02085D3C() != 0) func_021B642C();
    func_021B6868(p);
    if (func_02085D3C() == 1) func_021B6434();
    func_021B643C(1);
    if (func_02085D3C() == 1) func_021B6444();
    func_021B65C4(p);
    func_021B67BC(p);
    func_02034FB8(0x40);
    func_020307B0(p);
    g_021C88E0 = 0;
}

#pragma thumb off


asm void func_021B6424(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027062C8
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027072E0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B642C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027072E0
}


asm void func_021B6434(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700BD0
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B643C(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700B34, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6444(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700B34
}


#pragma thumb on

void func_021B644C(char *p)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u32 offset = func_02085D3C() == 1 ? func_021B649C(width) : 0;
    width *= 2;
    func_021B64A4(1, (*(u32 **)(p + 4))[((struct Obj01264 *)p)->f18], offset >> 2,
                 width * height, 0, func_021B66B0, 0);
}

#pragma thumb off


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0270234C, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm u32 func_021B649C(u32)
{
    ldr pc, [pc, #-4]
    dcd 0x0270234C
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FE54, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B64A4(int, u32, u32, u32, int, void (*)(void), int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FE54
}


#pragma thumb on


void func_021B64AC(char *p)
{
    int b;
    int a;
    int d;
    int c;
    int r;
    switch (((struct Obj01559 *)p)->f44) {
    case 1:
        func_021B657C(p, 1);
        a = *(int *)&((struct Obj01559 *)p)->f4C;
        b = *(int *)&((struct Obj01559 *)p)->f48;
        if (func_02085D3C() != 0) func_021B655C(b, a);
        ((struct Obj01559 *)p)->f44 = 2;
        break;
    case 2:
        r = 0;
        if (func_02085D3C() != 0) r = func_021B6564();
        if (r == 0) {
            func_021B65C4(p);
            ((struct Obj01559 *)p)->f44 = 3;
        }
        break;
    case 4:
        func_021B657C(p, 0);
        c = *(int *)&((struct Obj01559 *)p)->f4C;
        d = *(int *)&((struct Obj01559 *)p)->f48;
        if (func_02085D3C() != 0) func_021B656C(d, c);
        ((struct Obj01559 *)p)->f44 = 5;
        break;
    case 5:
        r = 0;
        if (func_02085D3C() != 0) r = func_021B6574();
        if (r == 0) {
            func_021B65C4(p);
            ((struct Obj01559 *)p)->f44 = 6;
        }
        break;
    case 0:
    case 3:
    case 6:
    default:
        break;
    }
}

#pragma thumb off


asm void func_021B655C(int, int)
{
    ldr pc, [pc, #-4]
    dcd 0x02706174
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02706324, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function like the other veneers under src/matched/ov.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6564(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706324
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02706174, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function like the other veneers under src/matched/ov.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B656C(int, int)
{
    ldr pc, [pc, #-4]
    dcd 0x02706174
}



asm int func_021B6574(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706324
}


#pragma thumb on


void func_021B657C(char *obj, int mode)
{
    char *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    func_021B65C4(p);
    which = (u16)which;
    size = func_020490A8(0xD4, which);
    ((struct Obj01559 *)p)->f4C = size;
    ((struct Obj01559 *)p)->f48 = func_0203D7C8(((struct Obj01559 *)p)->f0, size, d_021C71C0, 0x13B);
    func_02048F4C(((struct Obj01559 *)p)->f48, 0xD4, which);
    func_020862F0(((struct Obj01559 *)p)->f48, ((struct Obj01559 *)p)->f4C);
}



/*
 * Release the word at +0x48 through 0x0203D7FC and clear it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B65C4(void *p)
{
    u32 v = ((struct Obj02504 *)p)->f48;
    if (v != 0) {
        func_0203D7FC((void *)v);
        ((struct Obj02504 *)p)->f48 = 0;
    }
}



void func_021B65D8(void)
{
    u32 *p = (u32 *)g_021C88E0;

    if (func_02085D3C(&g_021C88E0) == 1)
        func_021B6608();
    if (func_02085D3C((void *)func_021B6610(1)) == 1)
        func_021B6618();
    ((struct Obj14292 *)p)->f24 = 1;
    ((struct Obj14292 *)p)->f1C = 1;
}

#pragma thumb off



asm void func_021B6608(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0270212C
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm u32 func_021B6610(u32 a)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}


asm void func_021B6618(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027021E4
}


#pragma thumb on



/*
 * Delegate to func_021B65D8 unless the argument is 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6620(int x)
{
    if (x != 7) {
        func_021B65D8();
    }
}


void func_021B662C(void)
{
    char *p = g_021C88E0;
    u32 v;
    if (((struct Obj03311 *)p)->f10 != 0) {
        if (((struct Obj03311 *)p)->f28 <= 30) ++((struct Obj03311 *)p)->f28;
        if (((struct Obj03311 *)p)->f20 != 0) {
            v = ((struct Obj03311 *)p)->f2C;
            if ((func_02085D3C() == 1 ? func_021B6698(v) : 7) == 7)
                func_02088234();
            ((struct Obj03311 *)p)->f28 = 0;
            ((struct Obj03311 *)p)->f20 = 0;
        }
        if (((struct Obj03311 *)p)->f1C != 0) {
            func_021B644C(p);
            if (func_02085D3C() == 1) func_021B66A0();
            if (func_02085D3C() == 1) func_021B66A8();
            ((struct Obj03311 *)p)->f1C = 0;
        }
    }
}

#pragma thumb off



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700DB8, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6698(u32)
{
    ldr pc, [pc, #-4]
    dcd 0x02700DB8
}



asm void func_021B66A0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027021E4
}


asm void func_021B66A8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02702108
}


#pragma thumb on

void func_021B66B0(void)
{
    char *p = g_021C88E0;
    int one;
    func_021B6724(1);
    if ((func_02085D3C() == 1 ? func_021B672C() : 0) == 1) {
        one = 1;
        if (func_021B6734(one) != 0) func_021B673C(one);
        if (((struct Obj02879 *)p)->f24 != 0) {
            ((struct Obj02879 *)p)->f24 = 0;
        } else if (((struct Obj02879 *)p)->f28 > 4) {
            if (*(void (**)(u32, u32))(p + 0x3C) != 0)
                (*(void (**)(u32, u32))(p + 0x3C))((*(u32 **)(p + 4))[((struct Obj02879 *)p)->f18], ((struct Obj02879 *)p)->f40);
            ((struct Obj02879 *)p)->f18 = (((struct Obj02879 *)p)->f18 + 1) % ((struct Obj02879 *)p)->f8;
        }
        if (((struct Obj02879 *)p)->f10 == 1) func_021B644C(p);
    }
}

#pragma thumb off



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6724(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}




/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027020F0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B672C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}




/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FC90, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6734(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FC90
}


asm void func_021B673C(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}


#pragma thumb on




void func_021B6744(void *p, u32 a, u32 b)
{
    ((struct Obj14293 *)p)->f3C = a;
    ((struct Obj14293 *)p)->f40 = b;
}



void func_021B674C(char *p, int count, u16 heap)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u8 i;
    if (*(u32 *)&((struct Obj01264 *)p)->f4 == 0) {
        ((struct Obj01264 *)p)->f4 = func_02030734(((struct Obj01264 *)p)->f0, count * 4, 0, d_021C71C0, 0x1D7);
        ((struct Obj01264 *)p)->f8 = count;
        for (i = 0; i < count; i++)
            (*(void ***)(p + 4))[i] = func_0203D7C8(heap, height * (width * 2), d_021C71C0, 0x1DC);
        ((struct Obj01264 *)p)->fC = 1;
    }
}


void func_021B67BC(char *p)
{
    u8 i;
    if (((struct Obj02504 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_021B680C() : 0) != 0) return;
    if (((struct Obj02504 *)p)->fC == 1) {
        for (i = 0; i < ((struct Obj02504 *)p)->f8; i++)
            func_0203D7FC((void *)(*(u32 **)(p + 4))[i]);
    }
    func_020307B0(((struct Obj02504 *)p)->f4);
    ((struct Obj02504 *)p)->f8 = 0;
    *(u32 *)&((struct Obj02504 *)p)->f4 = 0;
}

#pragma thumb off



asm int func_021B680C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}


#pragma thumb on


void func_021B6814(void *a0)
{
    char *p = (char *)a0;
    int one = 1;

    if (((struct Obj08253 *)p)->f10 != 0)
        return;
    if ((func_02085D3C() == 1 ? func_021B6850() : 0) != 0)
        return;
    if (func_021B6858(one) == 1)
        func_021B6860(one);
    ((struct Obj08253 *)p)->f10 = one;
    ((struct Obj08253 *)p)->f1C = one;
    ((struct Obj08253 *)p)->f28 = 0;
}

#pragma thumb off


asm int func_021B6850(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FC90, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6858(int a)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FC90
}


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6860(int a)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}


#pragma thumb on


void func_021B6868(char *p)
{
    if (((struct Obj02504 *)p)->f10 == 1) {
        ((struct Obj02504 *)p)->f10 = 0;
        ((struct Obj02504 *)p)->f1C = 0;
        if (func_02085D3C(p, 0) == 1) {
            func_021B6884();
        }
    }
}

#pragma thumb off



asm void func_021B6884(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0270212C
}


#pragma thumb on



int func_021B688C(void *p)
{
    u8 v = ((struct Obj24060 *)p)->f44;
    return v == 6 || v == 0;
}


void func_021B68A0(char *p)
{
    int result;
    u32 width;
    u32 height;
    if (((struct Obj01264 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_021B6918() : 0) != 0) return;
    if (func_02085D3C() == 1) func_021B6920(0);
    result = 0;
    ((struct Obj01264 *)p)->f34 = 0;
    ((struct Obj01264 *)p)->f36 = func_021B697C(p);
    ((struct Obj01264 *)p)->f38 = 0;
    ((struct Obj01264 *)p)->f3A = func_021B699C(p);
    width = func_021B6938(p);
    height = func_021B6944(p);
    if (func_02085D3C() == 1) result = func_021B6928(width, height);
    if (func_02085D3C() == 1) func_021B6930(result);
    ((struct Obj01264 *)p)->f14 = 0;
}

#pragma thumb off



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027020F0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6918(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}




asm void func_021B6920(int)
{
    ldr pc, [pc, #-4]
    dcd 0x02702158
}




/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027022F8, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm int func_021B6928(u32, u32)
{
    ldr pc, [pc, #-4]
    dcd 0x027022F8
}


asm void func_021B6930(int)
{
    ldr pc, [pc, #-4]
    dcd 0x0270229C
}


#pragma thumb on




u16 func_021B6938(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f36 - ((struct Obj01264 *)p)->f34);
}




/*
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021B6944(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f3A - ((struct Obj01264 *)p)->f38);
}



void func_021B6950(char *p, int v)
{
    if (func_02085D3C() == 1) func_021B6974(3, 3, v);
    ((struct Obj01264 *)p)->f30 = v;
    func_021B68A0(p);
}
