/*
 * function: func_021C41E0
 * address: 0x021C41E0
 * packet: pkt_ov136_021C41E0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_021C4184 0x021C4184 thumb ov136
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0203F8F4 0x0203F8F4 arm
 */
#include "../include/Obj01064.h"
#include "../include/Obj08198.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0203064C(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082AC0(unsigned, void *, unsigned);
extern signed char func_02012FFC(void);
extern void func_021C4184(void *, u8 *);
typedef unsigned int   u32;
struct GfFont;
struct Tcbl;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0203F8F4(u16);
int func_021C41E0(void *a, void *b, u8 *p)
{
    u8 *q;
    u8 v;
    func_0203064C(1, 0x64, 0x20000);
    q = func_0203159C(a, 0x15C, 0x64);
    func_02082AC0(0, q, 0x15C);
    ((struct Obj01064 *)q)->f0 = 0x64;
    ((struct Obj01064 *)q)->f1C = p;
    q[0xB] = ((struct Obj08198 *)p)->f0;
    q[0xC] = q[0xB];
    q[0x16] = p[2];
    q[0x17] = p[3];
    v = q[0x16];
    q[0x1A] = v;
    q[0x1B] = v;
    ((struct Obj08198 *)p)->f0 = 0xFFFF;
    q[0x15] = func_02012FFC();
    func_021C4184(q, *(u8 * *)&((struct Obj01064 *)q)->f1C);
    ((struct Obj01064 *)q)->f24 = func_0201D7EC((unsigned)0x17, (unsigned)0, (unsigned)0, (unsigned)0, (u16)(((struct Obj01064 *)q)->f0));
    ((struct Obj01064 *)q)->f100 = func_0203101C((u16)(((struct Obj01064 *)q)->f0), ((struct Obj01064 *)q)->f0, 0x20, 0x20);
    q[0xA] = 1;
    func_0203F8F4(((struct Obj01064 *)q)->f0);
    return 1;
}
