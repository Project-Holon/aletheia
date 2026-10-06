/*
 * function: func_021E6F0C
 * address: 0x021E6F0C
 * packet: pkt_ov119_021E6F0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02041090 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204047C 0x0204047C arm
 *   func_02049238 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 f0, f4, size; u16 data[1]; } Pal;
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern u32 func_020307B0(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02049238(void *);
extern void func_02041B6C(u32 bit);
void func_021E6F0C(char *p, int side, void *mon)
{
    void *h = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    void *f;
    Pal *pal;
    u16 *d;
    u32 i;
    if (side == 0)
        f = func_02049EF4(h, 5, 0, (void **)&pal, ((struct Obj00001 *)p)->f5F4);
    else
        f = func_02049EF4(h, 6, 0, (void **)&pal, ((struct Obj00001 *)p)->f5F4);
    d = pal->data;
    for (i = 0; i < pal->size / 2; i++)
        d[i] += (u16)*(int *)&((struct Obj00001 *)p)->f86C;
    if (!side)
        func_02041090(1, (u32)d, 0, 0, 16, 24);
    else
        func_02041090(1, (u32)pal->data, 16, 0, 16, 24);
    func_020307B0(f);
    func_0204047C(3, 2);
    func_0204047C(2, 3);
    func_0204047C(1, 1);
    func_0204047C(0, 0);
    func_02049238(h);
    func_02041B6C(1);
}
