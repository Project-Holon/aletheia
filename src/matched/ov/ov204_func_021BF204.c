/*
 * function: func_021BF204
 * address:  0x021BF204
 * packet:   pkt_021BF204
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_02045B38 0x02045B38 arm
 */
#include "../include/Obj08384.h"

struct Rec;
extern void func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

void func_021BF204(char *p, void *a, void *b)
{
    if (((struct Obj08384 *)p)->fC != 0)
    {
        func_02045C04(((struct Obj08384 *)p)->fC);
    }
    ((struct Obj08384 *)p)->fC = func_02045B38((u32)a, 2, (u32)b, ((struct Obj08384 *)p)->f0);
}
