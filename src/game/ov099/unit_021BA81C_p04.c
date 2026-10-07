/*
 * file:     unit_021BA81C_p04.c
 * unit:     yes
 * function: func_021BAB04, func_021BABDC
 * address:  0x021BAB04
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA8D4 0x021BA8D4 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021C27E0  0x021C27E0  thumb  ov099
 *   func_02020268  0x02020268  thumb
 */
#include "../../matched/include/Obj22019.h"

#define P(k) (*(void **)((u8 *)p+(k)))
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct WordSet;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32_021BAB04;

typedef unsigned long  u32_021BABDC;

extern void func_021BA8D4(void *);
extern int func_021BA8BC(void *);
extern u32_021BAB04 func_020450F0(u32_021BAB04,u32_021BAB04,u32_021BAB04,u32_021BAB04,u8,u8,u8);
extern void func_02049B40(u32_021BAB04,u32_021BAB04,u32_021BAB04,u32_021BAB04,u32_021BAB04,u16);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_020456F8(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045CAC(struct MsgBank *,u32_021BAB04,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_0201DD68(void);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *);
extern u32_021BABDC func_02020D0C(u8 *p);
extern int func_021C27E0(void *a);
extern void func_02020268(struct Obj *obj, u8 a, u8 b, u8 c);
void func_021BAB04(void *p, int message);
void func_021BABDC(void *obj, int k);

void func_021BAB04(void *p, int message)
{
    func_021BA8D4(p);
    P(0x19c)=(void *)func_021BA8BC(P(0x19c));
    P(0x190)=(void *)func_021BA8BC(P(0x190));
    P(0x19c)=(void *)func_020450F0(2,4,4,23,16,15,1);
    func_02049B40(23,5,0,480,32,33);
    func_02043B5C(func_02045770(P(0x19c)),255);
    func_020456F8(P(0x19c));
    func_02045374(P(0x19c));
    func_0201F73C(P(0x19c),1,(u16)*(u32_021BAB04 *)((u8 *)p+0x1334),14);
    func_02045CAC(P(0xe4),message,P(0xf0));
    func_0201F250(P(0xdc),P(0xf4),P(0xf0));
    func_0201DD68();
    func_0201C7A4(func_02045770(P(0x19c)),4,4,P(0xf4),P(0xe8));
    func_02045334(P(0x19c));
}


void func_021BABDC(void *obj, int k)
{
    u8 *w = (u8 *)func_02020D0C(obj);

    if (func_021C27E0(((struct Obj22019 *)w)->f8) == 0) {
        switch (k) {
        case 4:
        case 5:
            func_02020268(obj, 2, 15, 2);
            break;
        default:
            func_02020268(obj, 1, 15, 2);
            break;
        }
    } else {
        func_02020268(obj, 1, 15, 2);
    }
}
