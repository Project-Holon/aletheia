/*
 * function: NET_PARTY_COMMAND_Init
 * address: 0x021DC888
 * packet: pkt_ov134_021DC888
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   NET_PARTY_COMMAND_BuildPartyList 0x021DCB48 thumb ov134
 *   NET_PARTY_COMMAND_BuildStatusParam 0x021DCC48 thumb ov134
 *   sNetPartyCommandTable 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
#include "../include/Obj05411.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[11]; } Args;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern void *PROCSYS_Create(int a0);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void NET_PARTY_COMMAND_BuildPartyList(const Args *, void *, void *);
extern void NET_PARTY_COMMAND_BuildStatusParam(u8 *p, void *unused, u8 *out);
extern const u32 sNetPartyCommandTable[];
extern u32 g_02FFFC3C;
int NET_PARTY_COMMAND_Init(void *ctx, int unused, const Args *args)
{
    u8 *p;
    p = PROCSYS_AllocProcWork(ctx, 0x100, 4);
    MI_CpuFill8(p, 0, 0x100);
    *(Args *)(p + 0xd0) = *args;
    ((struct Obj05411 *)p)->fFC = 4;
    ((struct Obj05411 *)p)->fCC = PROCSYS_Create(((struct Obj05411 *)p)->fFC);
    GFL_NET_COMMAND_AddCommandTable(0x2f00, (u32)sNetPartyCommandTable, 1, (u32)p);
    NET_PARTY_COMMAND_BuildPartyList(args, p, p + 4);
    NET_PARTY_COMMAND_BuildStatusParam((u8 *)args, p, p + 0x9c);
    p[0xc4] = 0;
    ((struct Obj05411 *)p)->fC8 = g_02FFFC3C;
    ((struct Obj05411 *)p)->f0 = 0;
    return 1;
}
