/*
 * function: WORLDTRADE_SEARCH_CreateStrings
 * address:  0x021FE118
 * packet:   pkt_021FE118
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02030734  0x02030734  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable  0x021F84EC  thumb
 *   WORLDTRADE_ENTER_ClearListRange  0x021F8990  thumb
 *   g_02203E18     0x02203E18  data  ov135
 */
#include "../include/Obj05416.h"
#include "../include/Obj23412.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_02203E18[];

struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern u8 *WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(u32 id);
extern void WORLDTRADE_ENTER_ClearListRange(u8 *p);

void WORLDTRADE_SEARCH_CreateStrings(u8 *p)
{
    ((struct Obj05416 *)p)->fB88 = STRBUF_Create(0xb4, 0x48);
    ((struct Obj05416 *)p)->fB8C = func_02045EC0(((struct Obj05416 *)p)->fB6C, 0x30);
    ((struct Obj05416 *)p)->fE00 = func_02030734(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    MIi_CpuClearFast(0, ((struct Obj05416 *)p)->fE00, 0x30);
    *(u8 * *)&((struct Obj23412 *)(*(u8 * *)&((struct Obj05416 *)p)->fE00))->f14 = WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(0x48);
    WORLDTRADE_ENTER_ClearListRange(p + 0xeec);
}
