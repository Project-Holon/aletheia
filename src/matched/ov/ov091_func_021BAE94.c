/*
 * function: func_021BAE94
 * address:  0x021BAE94
 * packet:   pkt_ov091_021BAE94
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BB554  0x021BB554  thumb  ov091
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj03183.h"
#include "../include/Obj20875.h"
#include "../include/Obj20876.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bmp;
extern int func_021B9A84(u32 p);
extern u8 func_021BB554(u8 *s);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021BAE94(u8 *a, u8 *s)
{
    u8 r;
    int x;
    int y;
    int h;
    u32 w;

    if (func_021B9A84((u32)a) != 0)
        return;
    if (((struct Obj20876 *)(*(u8 * *)&((struct Obj20875 *)a)->f280))->f34 == 6)
        return;
    r = func_021BB554(s);
    h = func_0202D01C(((struct Obj03183 *)s)->f6, func_02017E1C((void *)((struct Obj03183 *)s)->f0, 0xa1, 0), 0x30);
    w = (u32)func_02045770((struct Descriptor *)((struct Obj03183 *)s)->f20);
    if (r == 2 || r == 3) {
        x = 0xe;
        y = 0xf;
    } else if (r == 1) {
        x = 0xc;
        y = 0xd;
    } else {
        x = 0xa;
        y = 0xb;
    }
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1b, h, 1, x);
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1c, h, 1, y);
    func_0204B3DC((struct Obj *)((struct Obj03183 *)s)->f38, 1);
}
