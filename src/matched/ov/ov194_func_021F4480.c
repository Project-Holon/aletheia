/*
 * function: func_021F4480
 * address:  0x021F4480
 * packet:   pkt_021F4480
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045874  0x02045874  arm
 *   func_020458F8  0x020458F8  arm
 *   func_02045EC0  0x02045EC0  arm
 *   d_020A7370     0x020A7370  data
 */
#include "../include/Obj01287.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern u16 func_020458F8(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32  d_020A7370;

int func_021F4480(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (func_020458F8((struct U16Vec *)(((struct Obj01287 *)p)->f2D0)) == 0)
            return (int)func_02045EC0((struct MsgBank *)d_020A7370,
                                 *(u16 *)(*(u32 *)&((struct Obj01287 *)p)->f2C4 + 4));
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 2:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 3:
        return 0;
    case 4:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 5:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 6:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 7:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    default:
        return 0;
    }
}
