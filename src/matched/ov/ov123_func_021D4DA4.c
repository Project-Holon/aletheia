/*
 * function: func_021D4DA4
 * address: 0x021D4DA4
 * packet: pkt_ov123_021D4DA4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00626.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_02045808(struct U16Vec *vec);
void func_021D4DA4(char *p)
{
    Descriptor desc;
    desc.heap = ((struct Obj00626 *)p)->fC;
    desc.mode = 2;
    desc.data = p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    ((struct Obj00626 *)p)->f23C = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 4, ((struct Obj00626 *)p)->f23C);
    ((struct Obj00626 *)p)->f240 = 0x39e0;
    ((struct Obj00626 *)p)->f248 = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 5, ((struct Obj00626 *)p)->f248);
    ((struct Obj00626 *)p)->f24C = 0x39e0;
    ((struct Obj00626 *)p)->f238 = func_02027778((struct TaskMenuTmpl *)(&desc), ((struct Obj00626 *)p)->f254);
    func_02027CD8((int)(((struct Obj00626 *)p)->f238), 1);
    func_02045808(((struct Obj00626 *)p)->f23C);
    func_02045808(((struct Obj00626 *)p)->f248);
}
