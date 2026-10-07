/*
 * file:     field_effect_p16.c
 * unit:     yes
 * function: func_021AA6F8, func_021AA728, func_021AA778, func_021AA77C, func_021AA794, func_021AA7AC, func_021AA7CC
 * address:  0x021AA6F8
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
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   d_021DDFB4  0x021DDFB4  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AA7DC  0x021AA7DC  thumb  ov021
 *   func_021AAB74  0x021AAB74  thumb  ov021
 *   func_021AAB54  0x021AAB54  thumb  ov021
 *   func_021AAFFC  0x021AAFFC  thumb  ov021
 */
#include "../../matched/include/Obj18071.h"
#include "../../matched/include/Obj07219.h"
#include "../../matched/include/Obj09585.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Pos { u16 x, y, z; u16 f06; u32 f08; };

extern void *func_021A3074(u8 *p);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern int func_0216D83C(void *p);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02082BCC(u32, u32, u32, u32);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021AA7DC(u32, u32);
extern u32 func_021AAB74(u32, u32);
extern u32 func_021AAB54(u32, u32, u32, u32);
extern u32 func_021AAFFC(u32);
void func_021AA6F8(struct Pos *p, void *q);
void func_021AA728(struct Pos *p, void *q);
u32 func_021AA778(u8 *p);
void *func_021AA77C(int heap);
int func_021AA794(void *a, u32 b, u32 c, u32 d);
int func_021AA7AC(u32 a, u32 b);
int func_021AA7CC(u32 a, u32 b, u32 c, u32 d);
extern char d_021DDFB4[];


/*
 * Addresses are Black-image addresses.
 */
void func_021AA6F8(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    MI_CpuFill8(p, 0, sizeof(*p));
    p->x = func_0216D83C(o);
    p->y = func_0216D854(o);
    p->z = func_0216D86C(o);
}


void func_021AA728(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    if (p->f06 != 0) {
        if (p->f08 < 0xA000)
            p->f08++;
        return;
    }
    if (p->x != func_0216D83C(o) || p->y != func_0216D854(o) || p->z != func_0216D86C(o)) {
        p->f06 = 1;
        p->f08++;
    }
}


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021AA778(u8 *p)
{
    return ((struct Obj18071 *)p)->f8;
}


void *func_021AA77C(int heap)
{
    return func_02030734(heap, 0x5c0, 1, d_021DDFB4, 0x6e);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AA794(void *a, u32 b, u32 c, u32 d)
{
func_02082BCC((u32)a, 0, (23 << 6), d);
return func_020307B0(a);
}


int func_021AA7AC(u32 a, u32 b)
{
((struct Obj09585 *)((u8 *)(b)))->f0 = func_02188CD0((u8 *)(*(u32 *)&((struct Obj07219 *)((u8 *)(a)))->f0));
func_021AA7DC(a, b);
return func_021AAB74(a, b);
}


int func_021AA7CC(u32 a, u32 b, u32 c, u32 d)
{
func_021AAB54(a, b, c, d);
return func_021AAFFC(b);
}
