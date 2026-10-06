/*
 * function: func_02210608
 * address: 0x02210608
 * packet: pkt_ov198_02210608
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_020490F4 0x020490F4 arm
 *   sub_02049658 0x02049658 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_0220B120 0x0220B120 thumb ov198
 *   func_0220B3B4 0x0220B3B4 thumb ov198
 *   func_020307B0 0x020307B0 arm
 *   func_02021640 0x02021640 thumb
 *   func_02049238 0x02049238 arm
 *   func_02021728 0x02021728 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020216D4 0x020216D4 thumb
 */
#include "../include/Obj02535.h"
#include "../include/Obj25247.h"
#include "../include/Obj25248.h"
#include "../include/Obj25249.h"
#include "../include/Obj25250.h"
#include "../include/Obj25251.h"
#include "../include/Obj25252.h"
#include "../include/Obj25253.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *sub_020490F4(u32 id, u32 heap);
extern u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern void func_0220B120(char *,u16 *);
extern void func_0220B3B4(char *,u16 *);
extern u32 func_020307B0(void *p);
extern void func_02021640(struct PalAnmSlot *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern int func_02021728(char *,int);
extern void func_02082D44(const void *,void *,u32);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_020216D4(struct PalAnmSlot *,u32,u32,u32);
void func_02210608(char *p)
{
    void *owner=sub_020490F4(100,(u16)((((struct Obj25247 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10&0x7fff)|0x8000));
    void *handle;
    char *data;
    sub_02049658(owner,18,7,0,0,1,((struct Obj25248 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    handle=func_02049EF4(owner,16,1,(void **)&data,((struct Obj25249 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_0220B120(p,(u16 *)(data+12));
    func_020307B0(handle);
    handle=func_02049EF4(owner,17,1,(void **)&data,((struct Obj25250 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_0220B3B4(p,(u16 *)(data+12));
    func_020307B0(handle);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,100,19,((struct Obj25251 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,0x1e0,0);
    func_02049238(owner);
    func_02082D44((void *)(func_02021728(*(char * *)&((struct Obj02535 *)p)->f1D8,1)+0x180),p+0x1e78,32);
    func_0201F5BC(4,1,14,0,((struct Obj25252 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,1,0xe0,32);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,23,5,((struct Obj25253 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,32,0xd0);
}
