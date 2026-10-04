/*
 * function: func_021BA9C8
 * address: 0x021BA9C8
 * packet: pkt_ov093_021BA9C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_020457B0 0x020457B0 arm
 *   func_021D787C 0x021D787C thumb ov093
 *   func_021BB828 0x021BB828 thumb ov093
 *   func_021BB968 0x021BB968 thumb ov093
 *   func_021BC550 0x021BC550 thumb ov093
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BAC04 0x021BAC04 thumb ov093
 */
#include "../include/Obj01234.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Copy24 { int x[6]; };
extern u8 d_021F3A60[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int func_020457B0(int, int);
extern void func_021D787C(void *);
extern void func_021BB828(u8 *p);
extern u8 *func_021BB968(u8 *, void *, void *, void *, int, u16);
extern u8 *func_021BC550(u8 *p);
extern void func_021BABEC(void *, void *);
extern int func_021BAC04(char *p, int *st);

u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap)
{
    u8 *p;
    int i;
    p = func_02030734(heap, 0xcc4, 1, (const char *)d_021F3A60, 0xad);
    ((struct Obj01234 *)p)->fC = a;
    ((struct Obj01234 *)p)->f10 = c;
    ((struct Obj01234 *)p)->fCC0 = heap;
    ((struct Obj01234 *)p)->fCB0 = p + 0xf0;
    p[0xed] = 0;
    *(int *)&((struct Obj01234 *)p)->f44 = 0;
    p[0xcba] = 0;
    p[0xcbf] = 0;
    ((struct Obj01234 *)p)->f4C = d;
    *(struct Copy24 *)(p + 0x50) = *b;
    ((struct Obj01234 *)p)->fAC = func_020457B0(0x20, heap);
    func_021D787C(b);
    for (i = 0; i < 4; i++)
        func_021BB828(p + 0x14 + i * 12);
    *(u8 * *)&((struct Obj01234 *)p)->f44 = func_021BB968(p, ((struct Obj01234 *)p)->fC, ((struct Obj01234 *)p)->f10, p + 0xf0, ((struct Obj01234 *)p)->f4C, ((struct Obj01234 *)p)->fCC0);
    ((struct Obj01234 *)p)->fB0 = func_021BC550(*(u8 * *)&((struct Obj01234 *)p)->f44);
    func_021BABEC(p, (void *)func_021BAC04);
    return p;
}
