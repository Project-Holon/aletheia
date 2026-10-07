/*
 * function: func_021EF204
 * address:  0x021EF204
 * packet:   pkt_ov093_021EF204
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 */

#include "../../../matched/include/G_ov093_021F6398.h"
#include "../../../matched/include/G_H.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
} H;

extern struct G_ov093_021F6398 d_021F6398;
extern struct H d_021F63D8;
struct WordSet;
extern u8 func_021B8DDC(u32 x);
extern int func_021B8CE8(int a, int b, int c);
extern void *func_021B86B8(void ***p);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void func_021EF204(u32 a, u32 b, u32 *p)
{
    int x;
    u8 k = *p;

    if (d_021F63D8.f18 == 0
        && func_021B8CE8(d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k)) != 0) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    func_02045CAC((void *)d_021F6398.t[1], (u16)(b + x), (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, p, (void *)d_021F6398.f08);
    func_0201F250((void *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}
