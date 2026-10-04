/*
 * function: func_021B9178
 * address:  0x021B9178
 * packet:   pkt_ov070_021B9178
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 */
#include "../include/Obj06174.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

void func_021B9178(char *p, int bg)
{
    int a, b, c, t;
    int r = func_02008550((const struct Sub0200852CObj *)(((struct Obj06174 *)p)->f8));
    if (r == 0) {
        a = 4;
        b = 3;
        c = 5;
    } else if (r == 1) {
        a = 1;
        b = 0;
        c = 2;
    }
    func_02049B68((void *)bg, a, 0, 0, 0x20, ((struct Obj06174 *)p)->f544);
    t = func_02049740((void *)bg, b, 0, 0, 0, ((struct Obj06174 *)p)->f544);
    ((struct Obj06174 *)p)->f7F8 = t;
    func_02049990((void *)bg, c, 0, 0, (unsigned short)t, 0, 0, ((struct Obj06174 *)p)->f544);
}
