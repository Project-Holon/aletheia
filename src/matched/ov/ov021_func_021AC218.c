/*
 * function: func_021AC218
 * address:  0x021AC218
 * packet:   pkt_ov021_021AC218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_021AC274  0x021AC274  thumb  ov021
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 */
#include "../include/Obj04241.h"

typedef struct { int x; int y; int z; } V;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef unsigned char  u8;
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
struct Ctl;
extern void func_021AC274(struct Ctl *p);
extern char d_021DE028[];
extern V d_021D908C;

char *func_021AC218(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)&((struct Obj04241 *)p)->f0 = a;
    *(V *)(p + 4) = d_021D908C;
    ((struct Obj04241 *)p)->f10 = func_02188C88((u8 *)func_021ABE14((u8 *)a));
    ((struct Obj04241 *)p)->f14 = func_02050080((u32 *)(((struct Obj04241 *)p)->f10));
    func_021AC274((struct Ctl *)p);
    return p;
}
