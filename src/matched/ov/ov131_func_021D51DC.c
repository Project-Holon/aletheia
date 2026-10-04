/*
 * function: func_021D51DC
 * address: 0x021D51DC
 * packet: pkt_ov131_021D51DC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Block-local enum color and enum palette base preserve the literal
 *   pool order and +0x12/+0x14 stores. Plain constant casts fold to +0x00/+0x02.
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201C450 0x0201C450 thumb
 */
#include "../include/Obj03814.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 pad[9]; u16 x,y; } Palette;
struct GfFont;
struct MsgBank;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void *func_0201C450(u16,u32);
void func_021D51DC(char *p)
{
    ((struct Obj03814 *)p)->f80=func_0201D7EC(23,0,0,0,((struct Obj03814 *)p)->f0);
    ((struct Obj03814 *)p)->f7C=func_02045B38(0,2,158,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,0,448,32,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,4,448,32,((struct Obj03814 *)p)->f0);
    {
        enum { COLOR=0x4e59 } color=COLOR;
        enum { BASE=0x050005c0 } base=BASE;
        ((Palette *)base)->x=color;
        ((Palette *)base)->y=0x6a52;
    }
    ((struct Obj03814 *)p)->f84=func_0201C450(4096,((struct Obj03814 *)p)->f0);
}
