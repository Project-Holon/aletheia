/*
 * function: func_021E40EC
 * address: 0x021E40EC
 * packet: pkt_ov119_021E40EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   d_021E7DD0 0x021E7DD0 data a4
 */
#include "../include/Obj00001.h"
typedef struct { unsigned int w[2]; } Tbl2;
typedef unsigned short u16;

extern const Tbl2 d_021E7DD0;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02040618(u32 layer, u32 a, u32 b);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02049238(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021E40EC(char *p, int a1, int a2)
{
    Tbl2 tbl = d_021E7DD0;
    void *v;
    v = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    func_02049990(v, tbl.w[a2], 4, 0, (unsigned short)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    if (a1 != 0) {
        func_02040618(4, 0, 0x80);
    } else {
        func_02040618(4, 0, 0);
    }
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04, 0);
    func_02049238(v);
    func_02040588(4, 1);
}
