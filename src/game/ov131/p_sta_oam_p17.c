/*
 * file:     p_sta_oam_p17.c
 * unit:     yes
 * function: func_021D7B00, func_021D7B34, func_021D7B48, func_021D7B4C, func_021D7BF0
 * address:  0x021D7B00
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201AF80 0x0201AF80 thumb
 *   d_021DC824 0x021DC824 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_021D7E84 0x021D7E84 thumb ov131
 *   func_02045C04 0x02045C04 arm
 */
#include "../../matched/include/Obj23143.h"
#include "../../matched/include/Obj00776.h"
#include "../../matched/include/Obj03285.h"
#include "../../matched/include/Obj02844.h"

struct MsgBank;
struct Rec;
typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);
extern void *func_02049EF4(void *, unsigned int, unsigned int, void **, unsigned short);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021D7E84(void *p, void **q);
extern unsigned int func_02045C04(struct Rec *rec);
void **func_021D7B00(u16 *a);
void func_021D7B34(int a, char *p);
void func_021D7B48(void *context, void *child);
void func_021D7B4C(unsigned char *a, unsigned char *p, void *arc);
void func_021D7BF0(void *a, unsigned char *p);
extern const char d_021DC824[];

void **func_021D7B00(u16 *a) {
 void **p=func_02030734(*a,0x6c,0,d_021DC824,0xc1);
 p[0]=0;
 p[1]=0;
 p[2]=func_0201AF80(*a,0);
 return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D7B34(int a, char *p)
{
    func_020307B0(((struct Obj23143 *)p)->f8);
    func_020307B0(p);
}

/*
 * interface: caller 021D44C8 loads r0=context,r1=child; complete leaf
 *   021D7B48 is bx lr, consumes neither input and supplies no return value.
 */
void func_021D7B48(void *context, void *child) {}

void func_021D7B4C(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj03285 *)p)->f50 = func_02049EF4(arc, 63, 0, (void **)(p+0x4c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f58 = func_02049EF4(arc, 72, 0, (void **)(p+0x54), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f60 = func_02049EF4(arc, 64, 0, (void **)(p+0x5c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f68 = func_02049EF4(arc, 65, 0, (void **)(p+0x64), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f38 = func_02045B38(0, 2, 188, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f3C = func_02045B38(0, 2, 89, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f40 = func_02045B38(0, 2, 92, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f44 = func_02045B38(0, 2, 90, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f48 = func_02045B38(0, 2, 91, ((struct Obj00776 *)a)->f0);
}

void func_021D7BF0(void *a, unsigned char *p)
{
    if (((struct Obj02844 *)p)->f4 == 1) func_021D7E84(a, (void **)p);
    func_02045C04(((struct Obj02844 *)p)->f38);
    func_02045C04(((struct Obj02844 *)p)->f3C);
    func_02045C04(((struct Obj02844 *)p)->f40);
    func_02045C04(((struct Obj02844 *)p)->f44);
    func_02045C04(((struct Obj02844 *)p)->f48);
    func_020307B0(((struct Obj02844 *)p)->f50);
    func_020307B0(((struct Obj02844 *)p)->f58);
    func_020307B0(((struct Obj02844 *)p)->f60);
    func_020307B0(((struct Obj02844 *)p)->f68);
}
