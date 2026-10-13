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
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   func_02045EC0  0x02045EC0  arm
 *   gSpeciesNameBank     0x020A7370  data
 */
#include "../include/Obj01287.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32  gSpeciesNameBank;

int func_021F4480(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (STRBUF_GetLength((struct U16Vec *)(((struct Obj01287 *)p)->f2D0)) == 0)
            return (int)func_02045EC0((struct MsgBank *)gSpeciesNameBank,
                                 *(u16 *)(*(u32 *)&((struct Obj01287 *)p)->f2C4 + 4));
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 2:
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 3:
        return 0;
    case 4:
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 5:
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 6:
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 7:
        return (int)STRBUF_Clone((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    default:
        return 0;
    }
}
