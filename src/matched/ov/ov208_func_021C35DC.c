/*
 * function: func_021C35DC
 * address: 0x021C35DC
 * packet: pkt_ov208_021C35DC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02043678 0x02043678 arm
 *   func_021C3678 0x021C3678 thumb ov208
 *   data_021C8E28 0x021C8E28 data ov208 a1
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
extern void *func_02030734(u32 heap,u32 size,int clear,const char *file,u16 line);
extern u32 func_020450F0(u32 layer,u32 x,u32 y,u32 width,u8 height,u8 pal,u8 slot);
extern struct Bmp *func_02043678(u32 width,u32 height,u32 depth,u32 heap);
extern void func_021C3678(u16 *heap,u8 *p,int key);
extern const char data_021C8E28[];
void func_021C35DC(u16 *heap,u8 *p,int key)
{
    ((struct Obj00146 *)p)->f14=func_02030734(*heap,0x3a2,1,data_021C8E28,0x8a1);
    *(u32 *)&((struct Obj00146 *)p)->f20=func_020450F0(3,1,2,31,15,1,1);
    func_021C3678(heap,p,key);
    *(struct Bmp * *)&((struct Obj00146 *)p)->f2C=func_02043678(121,15,32,*heap);
}
