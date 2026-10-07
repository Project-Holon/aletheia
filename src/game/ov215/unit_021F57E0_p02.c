/*
 * file:     unit_021F57E0_p02.c
 * unit:     yes
 * function: func_021F5E68, func_021F5E90, func_021F5EB8, func_021F5EC8, func_021F5ECC, func_021F5F74, func_021F5F84, func_021F5FB0, func_021F5FDC, func_021F5FEC, func_021F6000, func_021F602C
 * address:  0x021F5E68
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B908 0x0204B908 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02005E30 0x02005E30 thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_020063B4  0x020063B4  thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DF8 0x02005DF8 thumb
 */
#include "../../matched/include/Obj25739.h"
#include "../../matched/include/Obj04634.h"
#include "../../matched/include/Obj25740.h"
#include "../../matched/include/Obj25741.h"
#include "../../matched/include/Obj25742.h"
#include "../../matched/include/Obj14707.h"
#include "../../matched/include/Obj25743.h"
#include "../../matched/include/Obj14708.h"
#include "../../matched/include/Obj25744.h"
#include "../../matched/include/Obj25745.h"
#include "../../matched/include/Obj25746.h"

struct Actor;
struct Obj;
struct S021F5E68
{
    char pad[0x38];
    void *slots[6];
};

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_0204B908(int a0, int a1);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_02005E30(u32 a);
extern void func_02005D28(void);
extern void func_02005DE4(void *p);
extern int  func_02005E50(void);
extern int func_02005E64(void);
extern int  func_02005F38(void);
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
extern void func_02005D90(unsigned, unsigned);
extern int func_02005E9C(void);
extern void func_02005DF8(u32 a);
void func_021F5E68(int unused, struct S021F5E68 *p);
int func_021F5E90(int unused, struct S021F5E68 *p);
int func_021F5EB8(int a, char *b);
void func_021F5EC8(void);
void func_021F5ECC(u8 *p, u8 *q);
int func_021F5F74(void *unused,char *p);
void func_021F5F84(void *unused, char *p);
int func_021F5FA0(void *unused, char *p);
void func_021F5FB0(void *unused, char *p);
int func_021F5FCC(void *unused, char *p);
void func_021F5FDC(void *a0, void *a1);
void func_021F5FEC(void *a0, void *a1);
void func_021F6000(void *unused, char *p);
int func_021F601C(void *unused, char *p);
void func_021F602C(void *unused, char *p);
int func_021F603C(void *unused, char *p);


void func_021F5E68(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        func_0204B908((int)p->slots[i], 0);
        func_0204B92C(p->slots[i], 1);
    }
}


int func_021F5E90(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    int r = 1;
    for (i = 0; i < 6; i++)
    {
        if (func_0204B98C(p->slots[i]) != 0)
        {
            r = 0;
            break;
        }
    }
    return r;
}


int func_021F5EB8(int a, char *b)
{
    func_02005E30(0x1e);
    ((struct Obj25739 *)b)->f18 = 1;
    return 1;
}

void func_021F5EC8(void)
{

}


void func_021F5ECC(u8 *p, u8 *q)
{
    switch (((struct Obj04634 *)q)->f18) {
    case 0:
        break;
    case 1:
        if (func_02005E50() == 0) {
            func_02005DE4((void *)1);
            func_02005E64();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            ((struct Obj04634 *)q)->f18 = 0;
        break;
    case 3:
        if (func_020063B4((u8 *)0x3F3, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 4;
        break;
    case 4:
        break;
    case 5:
        if (func_020063B4((u8 *)0x519, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 6;
        break;
    case 6:
        if (func_02005F38() == 0) {
            func_021F5FEC(p, q);
            ((struct Obj04634 *)q)->f18 = 4;
        }
        break;
    case 7:
        if (func_02005E50() == 0) {
            func_02005D28();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    }
}

/*
 * leaf: sole blocker set of concrete MATCH900 ov215021F5884; parent claim.
 * extent: 14-byte predicate then two zero alignment bytes at 021F5F82.
 */
int func_021F5F74(void *unused,char *p)
{
    if(((struct Obj25740 *)p)->f18==1)return 1;
    return 0;
}

void func_021F5F84(void *unused, char *p)
{
    func_02005D90(0x3f2, 0xffff);
    ((struct Obj25741 *)p)->f18 = 2;
}


int func_021F5FA0(void *unused, char *p)
{
    if (((struct Obj25742 *)p)->f18 == 2) return 1;
    return 0;
}

void func_021F5FB0(void *unused, char *p)
{
    ((struct Obj14707 *)p)->f24 = 0;
    func_020063B4((u8 *)0x3f3, (u32 *)(p + 0x24), 1);
    ((struct Obj14707 *)p)->f18 = 3;
}


int func_021F5FCC(void *unused, char *p)
{
    if (((struct Obj25743 *)p)->f18 == 4) return 1;
    return 0;
}


void func_021F5FDC(void *a0, void *a1)
{
    func_02005DE4((void *)1);
    func_02005E64();
}


void func_021F5FEC(void *a0, void *a1)
{
    func_02005E9C();
    func_02005DE4(0);
    func_02005DF8(6);
}

void func_021F6000(void *unused, char *p)
{
    ((struct Obj14708 *)p)->f24 = 0;
    func_020063B4((u8 *)0x519, (u32 *)(p + 0x24), 1);
    ((struct Obj14708 *)p)->f18 = 5;
}


int func_021F601C(void *unused, char *p)
{
    int state = ((struct Obj25744 *)p)->f18;
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}

void func_021F602C(void *unused, char *p)
{
    func_02005E30(0x3c);
    ((struct Obj25745 *)p)->f18 = 7;
}


int func_021F603C(void *unused, char *p)
{
    if (((struct Obj25746 *)p)->f18 == 7) return 1;
    return 0;
}
