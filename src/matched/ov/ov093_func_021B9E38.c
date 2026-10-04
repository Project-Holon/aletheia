/*
 * function: func_021B9E38
 * address:  0x021B9E38
 * packet:   pkt_ov093_021B9E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200846C  0x0200846C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   func_0202428C  0x0202428C  thumb
 */
#include "../include/Obj01371.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *func_0200846C(int a);
extern void func_02008494(void *src, void *dst);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02008510(void *a, int tag);
extern void func_0202428C(void *a);

void func_021B9E38(char *p, int a, int b)
{
    u16 f;

    void *h = func_0200846C(a);

    ((struct Obj01371 *)p)->f0 = h;
    func_02008494((void *)b, h);
    f = 0;
    ((struct Obj01371 *)p)->fA = 0;
    if (func_02008550(((struct Obj01371 *)p)->f0))
        f = 1;
    ((struct Obj01371 *)p)->f8 = f;
    ((struct Obj01371 *)p)->f4 = (int)func_02008510(((struct Obj01371 *)p)->f0, 0x12);
    func_0202428C(p + 0x18);
    func_0202428C(p + 0x20);
}
