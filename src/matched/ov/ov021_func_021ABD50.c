/*
 * function: func_021ABD50
 * address:  0x021ABD50
 * packet:   pkt_ov021_021ABD50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   func_021ABEAC  0x021ABEAC  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 */
#include "../include/Obj04240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x; int y; int z; } V;

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, u16 heap);
struct Sub020140BCObj;
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013B38(u32 id);
extern void *func_02188C80(void *p);
extern int func_0202E83C(void *a0);
extern u32 func_02188D58(u8 *p);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void func_021ABEAC(char *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204ED70(int a, V *v);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern char d_021DE018[];
extern V d_021D8F04;

char *func_021ABD50(int a, int b, u16 c)
{
    char *p;
    int h;
    V v;
    u8 z;

    p = (char *)func_02030734(c, 0x28, 1, d_021DE018, 0x7e);
    ((struct Obj04240 *)p)->f0 = b;
    ((struct Obj04240 *)p)->f4 = c;
    ((struct Obj04240 *)p)->f8 = a;
    ((struct Obj04240 *)p)->fC = (int)func_020490F4(0x4b, c);
    func_02013B38(func_02188C9C((u8 *)a));
    ((struct Obj04240 *)p)->f16 = func_0202E83C(func_02188C80((void *)a));
    ((struct Obj04240 *)p)->f17 = func_020140D8((struct Sub020140BCObj *)func_02188D58((u8 *)a));
    func_021ABEAC(p);
    h = func_02050080((u32 *)func_02188C88((u8 *)(((struct Obj04240 *)p)->f8)));
    func_0204EDBC((u8 *)h, 0);
    v = d_021D8F04;
    func_0204ED70(h, &v);
    z = 0;
    func_0204EDB0((u8 *)h, &z);
    return p;
}
