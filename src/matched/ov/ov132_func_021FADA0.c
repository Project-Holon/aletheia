/*
 * function: STA_ACT_SCRIPT_AddTask
 * address: 0x021FADA0
 * packet: pkt_ov132_021FADA0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_020307B0 0x020307B0 arm
 *   NNS_FndAppendListObject 0x020604AC arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 */
#include "../include/Obj10542.h"
#include "../include/Obj14095.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDCEC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct Ctx;
struct Node;
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern u32 func_020307B0(void *p);
extern void NNS_FndAppendListObject(void *, void *);
void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key)
{
    char *q;
    q = func_02030734(((struct Obj14095 *)p)->f0, 16, 0, d_021FDCEC, 0x115);
    ((struct Obj10542 *)q)->fC = func_02030DA8(((struct Obj14095 *)p)->f4, fn, arg, key);
    if (((struct Obj10542 *)q)->fC != 0) {
        ((struct Obj10542 *)q)->f8 = arg;
        NNS_FndAppendListObject(p + 0x38, q);
        return q;
    }
    func_020307B0(q);
    return 0;
}
