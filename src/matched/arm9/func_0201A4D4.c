/*
 * function: POKE_REGULATION_CreateText
 * address:  0x0201A4D4
 * packet:   pkt_0201A4D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734 0x02030734  arm
 *   STRBUF_Create 0x020457B0  arm
 *   STRBUF_Delete 0x02045808  arm
 *   func_02045B38 0x02045B38  arm
 *   func_02045EC0 0x02045EC0  arm
 *   POKE_REGULATION_LineFns  0x0209E444  data
 *
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */
#include "../include/Obj06868.h"
#include "../include/Obj11261.h"
#include "../include/Obj15718.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 POKE_REGULATION_LineFns[];

u8 *POKE_REGULATION_CreateText(u8 *a0, u32 a1, u16 a2, u32 a3)
{
    u8 *v7;
    u32 v10;
    int i;
    u32 f;

    v7 = (u8 *)func_02030734(a2, 0x38, 1, (const char *)0x020A72F0, 0x312);
    ((struct Obj06868 *)v7)->f0 = (u32)func_02045B38(0, 2, 0xa5, a2);
    v10 = (u32)STRBUF_Create(0x40, a2);
    f = ((struct Obj15718 *)a0)->fAB;
    if (f == 2)
        ((struct Obj06868 *)v7)->f34 = a3;
    else
        ((struct Obj06868 *)v7)->f34 = f;
    for (i = 0; i < 6; i++) {
        int off = i * 4;
        u8 *q = v7 + off;

        ((struct Obj11261 *)q)->f4 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06868 *)v7)->f0), i);
        ((struct Obj11261 *)q)->f1C =
            ((u32 (*)(u8 *, u32, u8 *, u32, u32))
                 (*(u32 *)(POKE_REGULATION_LineFns + off)))(a0, a1, v7, v10, a2);
    }
    STRBUF_Delete((struct U16Vec *)v10);
    return v7;
}
