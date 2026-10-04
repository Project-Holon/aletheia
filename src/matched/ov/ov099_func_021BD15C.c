/*
 * function: func_021BD15C
 * address:  0x021BD15C
 * packet:   pkt_ov099_021BD15C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BBE7C  0x021BBE7C  thumb  ov099
 *   func_02012934  0x02012934  thumb
 *   func_021BBD0C  0x021BBD0C  thumb  ov099
 */
#include "../include/Obj07946.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_021BA928(char *p, int v);
extern void func_021BBE7C(char *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void func_021BBD0C(char *p, int a, int b);

int func_021BD15C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }
    ((struct Obj07946 *)p)->f1354 = 2;
    func_021BBE7C(p);
    func_021BBD0C(p, (int)func_02012934(((struct Obj07946 *)p)->fC4), ((struct Obj07946 *)p)->fCC);
    ((struct Obj07946 *)p)->f1CC = 0x66;
    return v;
}
