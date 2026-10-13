/*
 * function: P_STA_SKILL_ApplyStatsScreen
 * address: 0x021D9E44
 * packet: pkt_ov131_021D9E44
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041570 0x02041570 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00136.h"
#include "../include/Obj04512.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Cfg;
struct Descriptor;
struct Obj;
extern void func_02041570(int channel, u16 val);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_02041B6C(u32);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_0204B3DC(struct Obj *p, u32 v);
void P_STA_SKILL_ApplyStatsScreen(u8 *a,u8 *p)
{
    u8 i;
    void *cell;
    i=0;
    func_02041570(4,0);
    for(;i<=7;i++) {
        cell=*(void **)(p+0x5c+i*4);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    func_02040AE0(6,*(u8 * *)&((struct Obj04512 *)p)->f3C+12,*((u32 *)(*(u8 * *)&((struct Obj04512 *)p)->f3C+8)));
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,((struct Obj04512 *)p)->f4C+12,0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(((struct Obj04512 *)p)->f90,1);
    func_0204B3DC(((struct Obj04512 *)p)->f94,0);
    func_0204B3DC(((struct Obj00136 *)a)->f198,0);
    func_0204B3DC(((struct Obj00136 *)a)->f19C,0);
}
