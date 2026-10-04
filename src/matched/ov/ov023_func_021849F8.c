/*
 * function: func_021849F8
 * address:  0x021849F8
 * packet:   pkt_ov023_021849F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02045CAC  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   d_02186F58     0x02186F58  data  ov023  a4
 */
#include "../include/Obj00049.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 e:3; u8 f:3; u8 g:2; u8 h[5]; } Rec;

extern char d_02186F58[];
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int  func_02186558(u8 *);
extern u16 func_02039338(void);
extern void func_02186444(u8 *, u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void func_021849F8(u8 *p)
{
    int i = 0;
    int z = i;

    for (; i < 5; i++) {
        *(u32 *)(p + i * 4 + 0x18) = (u32)func_020457B0(8, 0x28);
        ((Rec *)(p + 0x4216))[i].f = 0;
        *(u16 *)(p + i * 4 + 0x4232) = z;
        *(u32 *)(p + 0x1C8 + i * 8) = z;
        *(u32 *)(p + 0x1CC + i * 8) = z;
    }
    ((struct Obj00049 *)p)->f2C = (u32)func_020457B0(0xA, 0x28);
    ((struct Obj00049 *)p)->f30 = (u32)func_020457B0(0x50, 0x28);
    ((struct Obj00049 *)p)->f420A = z;
    ((struct Obj00049 *)p)->f420B = 1;
    ((struct Obj00049 *)p)->f9E6C = 1;
    ((struct Obj00049 *)p)->f9E70 = z;
    ((struct Obj00049 *)p)->f1AC = 2;
    ((struct Obj00049 *)p)->f1B0 = func_02186558(p);
    ((struct Obj00049 *)p)->f9E74 = z;
    ((struct Obj00049 *)p)->f9E78 = z;
    ((struct Obj00049 *)p)->f198 = z;
    ((struct Obj00049 *)p)->f9E7C = z;
    ((struct Obj00049 *)p)->f9E80 = z;
    ((struct Obj00049 *)p)->f178 = z;
    func_02039338();
    func_02186444(p, 4);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00049 *)p)->f14), 7, (void *)(((struct Obj00049 *)p)->f2C));
    ((struct Obj00049 *)p)->f4288 = func_02030734(0x28, 0x3C00, z, d_02186F58, 0x31D);
    ((struct Obj00049 *)p)->f1A8 = z;
}
