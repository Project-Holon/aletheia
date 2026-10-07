/*
 * file:     weather_task_p12.c
 * unit:     yes
 * function: func_021A2564, func_021A25BC, func_021A25CC, func_021A25DC, func_021A2604, func_021A2630, func_021A2638
 * address:  0x021A2564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 *   func_021A2C30 0x021A2C30 thumb ov021
 *   func_021A2C6C  0x021A2C6C  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   func_020061F0  0x020061F0  thumb
 *   func_021A2C24 0x021A2C24 thumb ov021
 */
#include "../../matched/include/Obj19740.h"
#include "../../matched/include/Obj18003.h"
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj12714.h"

struct Actor;
struct Pt;
struct SoundSys2;
typedef struct { short x, y; } Pt;

typedef struct { char pad[0x774]; int *list; } Obj;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

u32 func_021A2C28(u8 *p);
void func_0204B53C(const struct Actor *actor, struct Pt *out);
void func_0204B528(struct Actor *actor, const struct Pt *src);
extern void func_021A2C30(unsigned char *o, int a, int b);
extern void func_021A2C6C(u8 *p, u32 v);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_020061F0(u32 a, u32 b);
extern unsigned char *func_021A2C24(unsigned char *o);
void func_021A2564(Obj *obj, int px, int py);
void func_021A25BC(unsigned char *o, int arg);
void func_021A25CC(u8 *p);
void func_021A25DC(u8 *p, int a);
void func_021A2604(u8 *p, int a, int b);
unsigned char *func_021A2630(unsigned char *o);
unsigned int func_021A2638(unsigned char *o);


void func_021A2564(Obj *obj, int px, int py)
{
    int *p = obj->list;
    int h;
    int y;
    int x;
    Pt pt;

    if (p != 0) {
        x = (short)px;
        y = (short)py;
        do {
            h = func_021A2C28((u8 *)((int)p));
            func_0204B53C((const struct Actor *)h, (struct Pt *)(&pt));
            pt.x = pt.x - x;
            pt.y = pt.y - y;
            func_0204B528((struct Actor *)h, (const struct Pt *)(&pt));
            p = (int *)p[0x34 / 4];
        } while (p != obj->list);
    }
}


/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
void func_021A25BC(unsigned char *o, int arg)
{
    func_021A2C30(o + 0x40, ((struct Obj19740 *)o)->fC, arg);
}


/*
 * Tail call with the object displaced by 0x40 and the word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A25CC(u8 *p)
{
    func_021A2C6C(p + 0x40, ((struct Obj18003 *)p)->fC);
}


void func_021A25DC(u8 *p, int a)
{
    if (func_02005C64() == 0) {
        if (((struct Obj00954 *)p)->f48 != 0)
            func_02028A7C((struct SoundSys2 *)(((struct Obj00954 *)p)->fC), a);
        else
            func_020061E4(a);
    }
}


void func_021A2604(u8 *p, int a, int b)
{
    if (func_02005C64() == 0) {
        if (((struct Obj12714 *)p)->f48 != 0)
            func_02028ACC((struct SoundSys2 *)(((struct Obj12714 *)p)->fC), a, b);
        else
            func_020061F0(a, b);
    }
}


unsigned char *func_021A2630(unsigned char *o)
{
    return func_021A2C24(o);
}


unsigned int func_021A2638(unsigned char *o)
{
    return func_021A2C28(o);
}
