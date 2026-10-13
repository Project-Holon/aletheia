/*
 * function: func_021DC888
 * address: 0x021DC888
 * packet: pkt_ov134_021DC888
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   func_021DCB48 0x021DCB48 thumb ov134
 *   func_021DCC48 0x021DCC48 thumb ov134
 *   tbl_021DCC9C 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
#include "../include/Obj05411.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[11]; } Args;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void *PROCSYS_Create(int a0);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void func_021DCB48(const Args *, void *, void *);
extern void func_021DCC48(u8 *p, void *unused, u8 *out);
extern const u32 tbl_021DCC9C[];
extern u32 g_02FFFC3C;
int func_021DC888(void *ctx, int unused, const Args *args)
{
    u8 *p;
    p = PROCSYS_AllocProcWork(ctx, 0x100, 4);
    func_02082BCC(p, 0, 0x100);
    *(Args *)(p + 0xd0) = *args;
    ((struct Obj05411 *)p)->fFC = 4;
    ((struct Obj05411 *)p)->fCC = PROCSYS_Create(((struct Obj05411 *)p)->fFC);
    GFL_NET_COMMAND_AddCommandTable(0x2f00, (u32)tbl_021DCC9C, 1, (u32)p);
    func_021DCB48(args, p, p + 4);
    func_021DCC48((u8 *)args, p, p + 0x9c);
    p[0xc4] = 0;
    ((struct Obj05411 *)p)->fC8 = g_02FFFC3C;
    ((struct Obj05411 *)p)->f0 = 0;
    return 1;
}
