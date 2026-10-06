/*
 * function: func_021B9EF8
 * address:  0x021B9EF8
 * packet:   pkt_ov100_021B9EF8
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021B95B8  0x021B95B8  thumb  ov100
 *   func_021BA290  0x021BA290  thumb  ov100
 *   func_021B9EA4  0x021B9EA4  thumb  ov100
 *   func_021B9DB8  0x021B9DB8  thumb  ov100
 */
#include "../include/Obj00060.h"

typedef unsigned short u16;

extern int func_020279E8(int);
typedef unsigned char  u8;
struct TaskMenu;
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
typedef unsigned int   u32;
struct Entry;
struct Link;
extern void func_02041B6C(u32 bit);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void func_021B95B8(int, void (*)(void));
extern void func_021BA290(int, int);
extern void func_021B9EA4(int a);
extern void func_021B9DB8(int a);

void func_021B9EF8(int a)
{
    if (((struct Obj00060 *)a)->fCC0 != 0) {
        if (func_020279E8(((struct Obj00060 *)a)->fCC0) != 0) {
            func_02027A04((const u8 *)(((struct Obj00060 *)a)->fCC0));
            func_02027858((struct TaskMenu *)(((struct Obj00060 *)a)->fCC0));
            ((struct Obj00060 *)a)->fCC0 = 0;
            func_02041B6C(6);
            func_021B95B8(a, (void (*)(void))func_021B9EA4);
            return;
        }
    } else {
        func_021BA290(a, 0);
        return;
    }
    {
        int k = 0xc;

        if (func_02039CB4((struct Link *)func_020399A8(), 0x78, k) != 0) {
            if (func_0203D3A8(func_020399A8(), k << 8, 4, a + 0x24c) != 0) {
                func_02039C68((struct Link *)func_020399A8(), 0x7c, k);
                func_021B95B8(a, (void (*)(void))func_021B9DB8);
            }
        }
    }
}
